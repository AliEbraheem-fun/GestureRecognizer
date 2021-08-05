#ifndef GRBACKGROUNDLOADER_H
#define GRBACKGROUNDLOADER_H
#include <QThread>
#include <QElapsedTimer>
#include "grabstractrecognizerplugin.h"
#include <opencv2/opencv.hpp>
using namespace cv;

class GRBackgroundLoader:public QThread
{
    Q_OBJECT
public:
    /*!
     * Constructs a GRBackgroundLoader object.
     * \param paths Paths to the training data folders. Each folder must only have items of the same class.
     * \param labels Labels of the data contained in each folder.
     * \param plugins The recognizers to be trained.
     */
    GRBackgroundLoader(QStringList paths, vector<int> labels, QList<GRAbstractRecognizerPlugin *> plugins);

    /*!
     * Starts the the thread responsible for loading the training data and preparing the recognizers.
     */
    void startLoader();

protected:

    /*!
     * The function to be executed when thread is started. This is a reimplemented function.
     */
    void run() override;

signals:

    /*!
     * A signal that occurs when recognizers preparing process is done.
     */
    void complete();

    /*!
     * A signal that occurs to show certain message.
     * \param str The message to be shown.
     */
    void log(QString str);

private:
    QList<GRAbstractRecognizerPlugin *> recognizers;/*!< param paths paths to the training data folders. Each folder must only have items of the same class.*/
    QStringList paths;/*!< paths to the training data folders. */
    vector<int> labels;/*!< Labels of the data contained in each folder.*/

    /*!
     * Constructs the training matrices from images in the given folders.
     * \param paths Paths to the training data folders.
     * \param labels Labels of the data contained in each folder.
     * \param trainingMat The matrix containing the training data in its raws.
     * \param labelsMat The matrix containing the taining data labels as a one dimensional matrix.
     * \return true if the loading operation is successful and false otherwise.
     */
    bool loadTrainingData(QStringList paths, vector<int> labels, Mat &trainingMat, Mat &labelsMat);
};

#endif // GRBACKGROUNDLOADER_H
