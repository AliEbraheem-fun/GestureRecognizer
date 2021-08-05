#ifndef GRVIDEORECORDER_H
#define GRVIDEORECORDER_H
#include <QThread>
#include <QMutex>
#include <QQueue>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

/*!
 * \brief The GRVideoRecorder class is used for video recording.
 *
 * The GRVideoRecorder class is used to record frames to a file.
 */
class GRVideoRecorder : public QThread
{
    Q_OBJECT
public:

    /*!
     * Constructs a GRVideoRecorder object.
     * \param filename The path to the file where frames are to be recorded.
     * \param fps Number of frames per second.
     * \param width Width of the frame.
     * \param height Height of the frame.
     */
    GRVideoRecorder(QString filename, int fps,int width,int height);

public slots:
    /*!
     * Saves a frame to the video file.
     * \param frame The frame to be recorded.
     */
    void record(Mat frame);

    /*!
     * Starts the recorder thread
     * \return true if the recording process was successfully created.
     */
    bool startRecorder();

    /*!
     * Stops the recorder thread.
     */
    void release();

protected:
    /*!
     * The function to be executed during the lifetime of the thread.
     */
    void run() override;
private:
    static constexpr double defaultFPS=10; /*!< Default number of recorded frames per second. */
    static constexpr double maxFPS=50; /*!< Maximum number of recorded frames per second. */
    static constexpr int defaultWidth=480; /*!< Default frame width. */
    static constexpr int defaultHeight=360; /*!< Default frame height. */
    static constexpr int minimumWidth=10; /*!< Minimum frame width. */
    static constexpr int minimumHeight=10; /*!< Minimum frame height. */
    VideoWriter *writer; /*!< A pointer to the VideoWriter that is used to save frames to file. */
    QQueue<Mat> buffer; /*!< The temporary buffer used to store frames before saving them.*/
    QMutex bufferMtx; /*!< The mutex used to guard the "buffer". */
    int fps; /*!< Number of frames per second. */
    int width; /*!< Frame width. */
    int height; /*!< Frame height. */
    bool stopFlag; /*!< A flag used to terminate the thread by normally exiting run function. */
    QString filename; /*!< Name of the video file where frames are stored. */
};

#endif // GRVIDEORECORDER_H
