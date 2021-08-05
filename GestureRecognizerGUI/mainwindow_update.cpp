#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_pbStartUpdate_clicked()
{
    updateManager.startUpdate();
}

void MainWindow::initUpdateManager()
{
    updateManager.setOldFileListPath("fileList.xml");
    updateManager.setDownloadURL("http://localhost");
    updateManager.setUpdateFileName("fileList.xml");
    connect(&updateManager,SIGNAL(log(QString)),this,SLOT(log(QString)));
    connect(&updateManager,SIGNAL(progressStatus(qint64,qint64,double,QString)),this,SLOT(progressStatus(qint64,qint64,double,QString)));

}

void MainWindow::progressStatus(qint64 bytesReceived, qint64 bytesTotal, double speed, QString unit)
{
    Q_UNUSED(speed)
    Q_UNUSED(unit)
    if(bytesTotal!=0)
    {
        qint64 val=bytesReceived*100/bytesTotal;
        ui->progressBar->setValue((int)val);
    }
    else
    {
        ui->progressBar->setValue(0);
    }

}
