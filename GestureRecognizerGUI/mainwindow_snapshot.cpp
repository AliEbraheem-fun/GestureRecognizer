#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_pbSnapshotPath_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"), recordingPath, QFileDialog::ShowDirsOnly);
    if(!dir.isEmpty())
    {
        snapshotPath=dir;
        ui->lblSnapshotPath->setText(dir);
    }
}


void MainWindow::on_pbSnapshot_clicked()
{
    takeSnapshot=true;
}

void MainWindow::saveImage(Mat frame)
{
    QString filepath;
    QDateTime now;
    filepath=snapshotPath;
    if((! recordingPath.endsWith("/")) && (! recordingPath.endsWith("//")))
    {
        filepath+="/";
    }
    filepath+="Gesture-Recognizer-"+now.currentDateTime().toString("yyyy-MM-dd-hh-mm-zzz")+".png";
    imwrite(filepath.toStdString().data(),frame);
}

