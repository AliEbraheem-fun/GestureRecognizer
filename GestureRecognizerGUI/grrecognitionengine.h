#ifndef GRRECOGNITIONENGINE_H
#define GRRECOGNITIONENGINE_H
#include <QThread>
#include "grabstractrecognizerplugin.h"
#include"opencv2/opencv.hpp"

/*!
 * \brief The GRRecognitionEngine class calls one or multiple AbstractRecognizer objects.
 *
 * The GRRecognitionEngine inherits QThread class and provides means to call multiple
 * AbstractRecognizer objects and apply an arbitration process on their results.
 */
class GRRecognitionEngine:public QThread
{
    Q_OBJECT
public:

    /*!
     * Construcs a GRRecognitionEngine object.
     */
    GRRecognitionEngine();

    /*!
     * Adds an AbstractRecognizer object to the recognizers vector.
     * \param recognizer A pointer to the AbstractRecognizer object to be added.
     * \return True if the operation is successfull (This function must never be called when the thread is running).
     */
    bool addRecognizer(GRAbstractRecognizerPlugin *recognizer);

    /*!
     * Starts the engine thread.
     */
    void startRecognitionEngine();

    /*!
     * Stops the engine thread.
     */
    void stopRecognitionEngine();

    /*!
     * Specifies whether the engine is started or not.
     * \return true if engine is started and false otherwise.
     */
    bool isStarted();

    /*!
     * Adds a frame to the internal buffer so it can be processed.
     * \param frame The frame containing the gesture
     */
    void addFrame(Mat frame);

private:
    QVector<GRAbstractRecognizerPlugin *> recognizers;/*!< A vector of recognizers. */

    QQueue<Mat> buffer; /*! A buffer to store the frames containing gestures. */

    QQueue<int> history; /*! A queue that stores a number of previous results used to add robustness to the current result. */

    bool stopFlag; /*! A flag used to stop the thread. */

    int historyLength; /*! maximum length of \ref history . */

    QMutex mtx; /*! A mutex to guard \ref buffer */

    bool engineStarted;
    
protected:

    /*!
     * The function to be executed when thread is started.
     */
    void run() override;

signals:
    /*!
     * The signal to be emitted when a gesture is recognized.
     * \param gesture The label of the recognized gesture.
     */
    void gestureRecognized(int gesture);
};

#endif // GRRECOGNITIONENGINE_H
