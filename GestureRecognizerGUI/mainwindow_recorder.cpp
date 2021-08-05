#include "mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::on_pbRecord_clicked()
{
    QDateTime now;
    QString filepath;
    if(recorder!=0)
    {
        recorder->release();
    }
    filepath=recordingPath;
    if((! recordingPath.endsWith("/")) && (! recordingPath.endsWith("//")))
    {
        filepath+="/";
    }
    filepath+="Gesture-Recognizer-"+now.currentDateTime().toString("yyyy-MM-dd-hh-mm-zzz")+".avi";
    recorder=new GRVideoRecorder(filepath ,grabber->getFPS(),480,360);
    connect(grabber,SIGNAL(frameGrabbed(Mat)),recorder,SLOT(record(Mat)));
    recorder->startRecorder();
    ui->pbRecord->setEnabled(false);
    ui->pbRecordingPath->setEnabled(false);
    ui->pbStopRecording->setEnabled(true);
}

void MainWindow::recordFrame(Mat frame)
{
    if(recorder!=0)
    {
        recorder->record(frame);
    }
}

void MainWindow::on_pbStopRecording_clicked()
{
    if(recorder!=0)
    {
        recorder->release();
        recorder=0;
    }
    ui->pbRecord->setEnabled(true);
    ui->pbRecordingPath->setEnabled(true);
    ui->pbStopRecording->setEnabled(false);
}

void MainWindow::on_pbRecordingPath_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"), recordingPath, QFileDialog::ShowDirsOnly);
    if(!dir.isEmpty())
    {
        recordingPath=dir;
        ui->lblRecordingPath->setText(dir);
    }

}


