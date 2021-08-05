#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    engine=0;
    grabber=0;
    recorder=0;
    recordingPath=QDir::current().absolutePath();
    snapshotPath=QDir::current().absolutePath();
    frameWidth=640;
    frameHeight=480;
    takeSnapshot=false;
    ui->lblRecordingPath->setText(QDir::current().absolutePath());
    ui->lblSnapshotPath->setText(QDir::current().absolutePath());
    fillCaptureDevicesInformation();
    m_speech=new GRTextToSpeech(ui->volume,ui->rate,ui->pitch,ui->language,ui->voice,ui->engine);
    initROI();
    initSamplesPath();
    initUpdateManager();
    updateManager.updateFilesDownloaded();
    updateRecognizerList();
    if(plugins.length()>0)
    {
        ui->listWidget->setCurrentRow(0);
    }
    updateThresholds();
    currentRecognizer=-1;
    connect(&synthesizer,SIGNAL(textChanged(QString)),ui->teText,SLOT(setText(QString)));
}

MainWindow::~MainWindow()
{
    if(grabber != 0)
    {
        grabber->stopGrabber();
    }
    if(recorder !=0)
    {
        recorder->release();
    }
    unloadDlls();
    delete ui;
}

void MainWindow::log(QString str)
{
    ui->teLog->append(str);
}



void MainWindow::on_actionExit_triggered()
{
    this->close();
}
