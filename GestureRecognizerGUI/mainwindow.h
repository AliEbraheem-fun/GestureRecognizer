#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <opencv2/opencv.hpp>
#include <QMainWindow>
#include <QtCore>
#include <QtMultimedia>
#include <QtTextToSpeech>
#include <QFileDialog>
#include "grvideograbber.h"
#include "grvideorecorder.h"
#include "grrecognitionengine.h"
#include "grdetector.h"
#include "grhelperimageprocessingfunctions.h"
#include "grupdatemanager.h"
#include "grbackgroundloader.h"
#include "grwordsynthesizer.h"
#include "grtexttospeach.h"

using namespace std;
using namespace cv;

#define HAND_REGION_X_OFFSET    40l
#define HAND_REGION_Y_OFFSET    50l
#define HAND_REGION_HEIGHT      300l
#define HAND_REGION_WIDTH       300l
#define REBOOT_EXIT_CODE        5

namespace Ui {
class MainWindow;
}

/*!
 * \brief The MainWindow class builds and controlls the main applications user interface.
 *
 * The MainWindow class builds and controlls the main applications user interface by connecting
 * the different controls to the appropriate slots. It also provides other functionalies that
 * enable the program to achieve its purpose.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    /*!
     * Constructs the application main window.
     * \param parent Parent of the main window.
     */
    explicit MainWindow(QWidget *parent = 0);

    /*!
     * The destructor.
     */
    ~MainWindow();

public slots:
    /*!
     * Displays messages in the "Messages" section of the gui.
     * \param str The message to be displayed.
     */
    void log(QString str);

    /*!
     * A slot that is called after recognizing a gesture.
     * \param gest The integer that represents the recoginzed gesture.
     */
    void gestureRecognized(int gest);

    /*!
     * A slot that receives information about the update process.
     * \param bytesReceived Number of received bytes.
     * \param bytesTotal Total number of bytes to be downloaded.
     * \param speed Download speed.
     * \param unit Download speed unit.
     */
    void progressStatus(qint64 bytesReceived, qint64 bytesTotal,double speed,QString unit);

private slots:
    /*!
     * Searches for all plugins existent in the plugins folder and loads them.
     */
    void updateRecognizerList();

    /*!
     * Called when a new camera frame is grabbed from camera.
     * \param frame The frame grabbed from camera
     */
    void frameGrabbed(Mat frame);

    /*!
     * Searches for video acquisition devices and displays them.
     */
    void fillCaptureDevicesInformation();

    /*!
     * Sends a frame to the recording thread.
     * \param frame The frame to be recorded.
     */
    void recordFrame(Mat frame);

    /*!
     * Starts the recognition thread.
     */
    void recognitionEngineStarter();

    /*!
     * The handler for pbStartVideoAcquisition button clicked event.
     */
    void on_pbStartVideoAcquisition_clicked();

    /*!
     * The handler for pbStopVideoAcquisition button clicked event.
     */
    void on_pbStopVideoAcquisition_clicked();

    /*!
     * The handler for pbRefreshCaptureDevices button clicked event.
     */
    void on_pbRefreshCaptureDevices_clicked();

    /*!
     * The handler for pbRecord button clicked event.
     */
    void on_pbRecord_clicked();

    /*!
     * The handler for pbStopRecording button clicked event.
     */
    void on_pbStopRecording_clicked();

    /*!
     * The handler for pbRecordingPath button clicked event.
     */
    void on_pbRecordingPath_clicked();

    /*!
     * The handler for pbSnapshotPath button clicked event.
     */
    void on_pbSnapshotPath_clicked();

    /*!
     * The handler for pbSnapshot button clicked event.
     */
    void on_pbSnapshot_clicked();

    /*!
     * The handler for pbTestTextToSpeech button clicked event.
     */
    void on_pbTestTextToSpeech_clicked();

    /*!
     * The handler for pbUp button clicked event.
     */
    void on_pbUp_clicked();

    /*!
     * The handler for pbDown button clicked event.
     */
    void on_pbDown_clicked();

    /*!
     * The handler for pbRight button clicked event.
     */
    void on_pbRight_clicked();

    /*!
     * The handler for pbLeft button clicked event.
     */
    void on_pbLeft_clicked();

    /*!
     * The handler for pbStartRecognitionEngine button clicked event.
     */
    void on_pbStartRecognitionEngine_clicked();

    /*!
     * The handler for pbStopRecognitionEngine button clicked event.
     */
    void on_pbStopRecognitionEngine_clicked();

    /*!
     * The handler for updateThresholds button clicked event.
     */
    void updateThresholds();

    /*!
     * The handler for hsLtRed slider valueChanged event.
     * \param value The current value of the slider.
     */
    void on_hsLtRed_valueChanged(int value);

    /*!
     * The handler for hsLtGreen slider valueChanged event.
     * \param value The current value of the slider.
     */
    void on_hsLtGreen_valueChanged(int value);

    /*!
     * The handler for hsLtBlue slider valueChanged event.
     * \param value The current value of the slider.
     */
    void on_hsLtBlue_valueChanged(int value);

    /*!
     * The handler for hsGtRed slider valueChanged event.
     * \param value The current value of the slider.
     */
    void on_hsGtRed_valueChanged(int value);

    /*!
     * The handler for hsGtGreen slider valueChanged event.
     * \param value The current value of the slider.
     */
    void on_hsGtGreen_valueChanged(int value);

    /*!
     * The handler for hsGtBlue slider valueChanged event.
     * \param value The current value of the slider.
     */
    void on_hsGtBlue_valueChanged(int value);

    /*!
     * The handler for hsBS slider valueChanged event.
     * \param value The current value of the slider.
     */
    void on_hsBS_valueChanged(int value);

    /*!
     * The handler for chkBackgroundSubstractionActivated toggled event.
     * \param checked State of the check box.
     */
    void on_chkBackgroundSubstractionActivated_toggled(bool checked);

    /*!
     * The handler for pbSetBackground button clicked event.
     */
    void on_pbSetBackground_clicked();

    /*!
     * The handler for pbStartUpdate button clicked event.
     */
    void on_pbStartUpdate_clicked();

    /*!
     * The handler for pbEditColor button clicked event.
     */
    void on_pbEditColor_clicked();

    /*!
     * The handler for pbEditFont button clicked event.
     */
    void on_pbEditFont_clicked();

    /*!
     * The handler for pbSaveText button clicked event.
     */
    void on_pbSaveText_clicked();

    /*!
     * The handler for pbLoadText button clicked event.
     */
    void on_pbLoadText_clicked();

    /*!
     * The handler executed when video grabber is stopped.
     */
    void onGrabberStopped();

    /*!
     * Deletes the last character in the text resulting from the recognition process.
     */
    void on_pbDelLastCharacter_clicked();

    /*!
     * Clears the text resulting from the recogition process.
     */
    void on_pbReset_clicked();

    void on_pbSpeakAll_clicked();

    void on_actionExit_triggered();

private:

    Ui::MainWindow *ui;/*!< A pointer to class defining gui controls. */

    GRVideoGrabber *grabber; /*!< A pointer to the object responsible for video input. */

    GRVideoRecorder *recorder;/*!< A pointer to the object responsible for video recording. */

    QString recordingPath; /*!< The directory where the recorded video is stored. */

    QString snapshotPath; /*!< The directory where snapshots are stored. */

    int frameWidth; /*!< The width of grabbed frames. */

    int frameHeight; /*!< The height of grabbed frames. */

    int fps; /*!< Number of grabbed frames per second*/

    bool takeSnapshot; /*!< A flag used to save the frame that comes after setting it to true to a file.*/

    Rect roi; /*!< The area in which hand must be put in order for the recognition operation to occur. */

    GRRecognitionEngine *engine; /*!< A pointer the object responsible for the recognition process. */

    QStringList paths; /*!< Paths to the directories containing the training samples. Each directory contains images that belong to the same class. */

    vector<int> labels; /*!< Labels of the samples contained in the specified directoies. Each label corresponds to one directory only. */

    GRDetector detector; /*!< Hand detector.*/

    QList<GRAbstractRecognizerPlugin *> plugins; /*!< Recoginzers contained in the dynamic linking libraries. */

    GRBackgroundLoader* bgl; /*!< A pointer to the thread responsible for preparing the recognition methods. */

    bool setDetectorBackground; /*!< A flag that tells the program to set the next grabbed frame as a background image for the hand detector. */

    GRUpdateManager updateManager;/*!< The object responsible for updating the program */

    GRWordSynthesizer synthesizer; /*!< The object responsible for synthesizing meaningful words from gestures. */

    GRTextToSpeech *m_speech; /*!< A pointer to the object responsible for converting text to speech. */

    int currentRecognizer; /*!< Index of the currently used recognizer. */

    QList<QPluginLoader *> loaders;/*!< DLL loaders.*/
    /*!
     * Saves an image to a file.
     * \param frame The frame to be saved.
     */
    void saveImage(Mat frame);

    /*!
     * Initializes "paths" and "labels".
     */
    void initSamplesPath();

    /*!
     * Initializes "roi".
     */
    void initROI();

    /*!
     * Initializes "updateManager"
     */
    void initUpdateManager();

    /*!
     * Releases DLLs.
     */
    void unloadDlls();

    /*!
     * Loads DLLs.
     */
    void loadDlls();
};



#endif // MAINWINDOW_H
