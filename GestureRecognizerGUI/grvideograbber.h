#ifndef GRVIDEOGRABBER_H
#define GRVIDEOGRABBER_H
#include <QThread>
#include <QElapsedTimer>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

/*!
 * \brief The GRVideoGrabber class is used to acquire frames from a video stream.
 *
 * The GRVideoGrabber class is used to acquire frames from either a file or an acquisition
 * device.
 */
class GRVideoGrabber: public QThread
{
    Q_OBJECT
public:
    /*!
     * Constructs a GRVideoGrabber objects that acquires frames from a camera.
     * \param fps Number of frames per second.
     * \param videoSource Id of the acquisition device.
     * \param isMirrored A flag to indicate whether the acquired frames should be mirrored.
     */
    GRVideoGrabber(int fps, int videoSource, bool isMirrored);

    /*!
     * Constructs a GRVideoGrabber objects that acquires frames from a file.
     * \param filename Path to the file from which video is to be acquired.
     */
    GRVideoGrabber(QString filename);

    /*!
     * Starts the grabber thread.
     */
    bool startGrabber();

    /*!
     * Stops the grabber thread.
     */
    void stopGrabber();

    /*!
     * Returns number of frames per seconds
     * \return Number of frames per seconds.
     */
    int getFPS();

protected:
    /*!
     * The function to be executed during the lifetime of the thread.
     */
    void run() override;

signals:
    /*!
     * A signal that occurs when a new frame is a acquired.
     * \param frame The acquired frame.
     */
    void frameGrabbed(Mat frame);

    /*!
     * A signal that occurs when the grabber thread exits.
     */
    void grabberStopped();

private:
    VideoCapture *cap; /*!< A pointer to the VideoCapture object used to grab frames from camera.*/
    static constexpr double defaultFPS=10;/*! Default frame rate. */
    static constexpr double maxFPS=50; /*!< Maximum allowed frame rate. */
    double fps; /*!< The used frame rate. */
    double width; /*!< Frame width. */
    double height; /*!< Frame height. */
    int frameCount; /*!< Number of frames when reading from a file. */
    bool isFile; /*!< A flag that indicates if the video source is a file. */
    qint64 msPeriod; /*!< period between two consective frames in ms. */
    bool stopFlag; /*!< A flag used to end the thread safely by returning normally from the run function. */
    bool mirrored; /*!< A flag that will cause the acquired images to be mirrored.*/


};

#endif // GRVIDEOGRABBER_H
