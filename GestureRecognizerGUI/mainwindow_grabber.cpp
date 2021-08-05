#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_pbStartVideoAcquisition_clicked()
{
    int currentIndex=ui->cmbCaptureDevices->currentIndex();
    if(currentIndex>=0)
    {
        if(grabber!=0)
        {
            grabber->stopGrabber();
        }
        if(currentIndex==0)
        {
            QString fileName = QFileDialog::getOpenFileName(0, tr("Open File"),
                                                             QDir::currentPath(),
                                                             tr("Videos (*.avi *.mp4)"));
            if(fileName!=0)
            {
                grabber=new GRVideoGrabber(fileName);
            }
            else
            {
                return;
            }
        }
        else
        {
            grabber=new GRVideoGrabber(10,ui->cmbCaptureDevices->currentIndex()-1,ui->chkMirrored->isChecked());
        }
        if(grabber->startGrabber())
        {
            connect(grabber,SIGNAL(frameGrabbed(Mat )),this,SLOT(frameGrabbed(Mat )));
            connect(grabber,SIGNAL(grabberStopped()),this,SLOT(onGrabberStopped()));
            ui->pbRecord->setEnabled(true);
            ui->pbSnapshot->setEnabled(true);
            ui->pbStopVideoAcquisition->setEnabled(true);
            ui->pbStartVideoAcquisition->setEnabled(false);
            ui->pbRefreshCaptureDevices->setEnabled(false);
            ui->chkMirrored->setEnabled(false);
            ui->pbSetBackground->setEnabled(true);
        }
        else
        {
            delete grabber;
        }
    }
}

void MainWindow::on_pbStopVideoAcquisition_clicked()
{
    if(grabber!=0)
    {
        grabber->stopGrabber();
    }
}

void MainWindow::frameGrabbed(Mat frame)
{
    Mat rgbFrame;
    Mat tmp= Mat(frame,roi);
    Mat mask;
    Mat maskedImage;
    Mat sample;
    if(setDetectorBackground)
    {
        setDetectorBackground=false;
        detector.setBackground(tmp);
    }
    detector.detect(tmp,mask,maskedImage);
    QImage img((uchar*)mask.data,mask.cols,mask.rows,mask.step,QImage::Format_Indexed8);
    ui->lblVideo_2->setPixmap(QPixmap::fromImage(img).scaled(QSize(ui->lblVideo_2->width(),ui->lblVideo_2->height())));
    if(extractLargestContour(mask,sample,5000,Size(100,100)))
    {
            QImage img2((uchar*)sample.data,sample.cols,sample.rows,sample.step,QImage::Format_Indexed8);
            ui->lblVideo_3->setPixmap(QPixmap::fromImage(img2).scaled(QSize(ui->lblVideo_3->width(),ui->lblVideo_3->height())));
            if(engine!=0)
            {
                if(engine->isStarted())
                {
                    engine->addFrame(sample);
                }
            }
    }
    rectangle(frame,roi,Scalar(0,0,0),2);
    cvtColor(frame,rgbFrame,CV_BGR2RGB);
    QImage qImage((uchar*)rgbFrame.data,rgbFrame.cols,rgbFrame.rows,rgbFrame.step,QImage::Format_RGB888);
    ui->lblVideo->setPixmap(QPixmap::fromImage(qImage).scaled(QSize(ui->lblVideo->width(),ui->lblVideo->height())));
    if(takeSnapshot)
    {
        takeSnapshot=false;
        saveImage(frame);
    }
}


void MainWindow::fillCaptureDevicesInformation()
{
    ui->cmbCaptureDevices->clear();
    QList<QCameraInfo> available_cameras=QCameraInfo::availableCameras();
    ui->cmbCaptureDevices->addItem("Open File");
    foreach (const QCameraInfo &cameraInfo, available_cameras)
    {
        ui->cmbCaptureDevices->addItem(cameraInfo.description());
    }
}

void MainWindow::on_pbRefreshCaptureDevices_clicked()
{
    fillCaptureDevicesInformation();
}

void MainWindow::onGrabberStopped()
{
    grabber=0;
    if(recorder !=0)
    {
        recorder->release();
        recorder=0;
    }
    ui->chkMirrored->setEnabled(true);
    ui->pbRecord->setEnabled(false);
    ui->pbStopRecording->setEnabled(false);
    ui->pbSnapshot->setEnabled(false);
    ui->pbStopVideoAcquisition->setEnabled(false);
    ui->pbStartVideoAcquisition->setEnabled(true);
    ui->pbRefreshCaptureDevices->setEnabled(true);
    ui->pbRecordingPath->setEnabled(true);
    ui->pbSnapshotPath->setEnabled(true);
    ui->pbSetBackground->setEnabled(false);

}

