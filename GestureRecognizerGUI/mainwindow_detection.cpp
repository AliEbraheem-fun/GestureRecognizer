#include "mainwindow.h"
#include "ui_mainwindow.h"

static inline unsigned char fromInt(int val)
{
    unsigned char *ptr;
    ptr= (unsigned char *)(&val);
    return ptr[0];
}



void MainWindow::on_hsLtRed_valueChanged(int value)
{
    ui->lblLtRedValue->setText(QString::number(value));
    updateThresholds();
}

void MainWindow::on_hsLtGreen_valueChanged(int value)
{
    ui->lblLtGreenValue->setText(QString::number(value));
    updateThresholds();
}

void MainWindow::on_hsLtBlue_valueChanged(int value)
{
    ui->lblLtBlueValue->setText(QString::number(value));
    updateThresholds();
}

void MainWindow::on_hsGtRed_valueChanged(int value)
{
    ui->lblGtRedValue->setText(QString::number(value));
    updateThresholds();
}

void MainWindow::on_hsGtGreen_valueChanged(int value)
{
    ui->lblGtGreenValue->setText(QString::number(value));
    updateThresholds();
}

void MainWindow::on_hsGtBlue_valueChanged(int value)
{
    ui->lblGtBlueValue->setText(QString::number(value));
    updateThresholds();
}

void MainWindow::on_hsBS_valueChanged(int value)
{
    ui->lblBSValue->setText(QString::number(value));
    updateThresholds();
}

void MainWindow::on_chkBackgroundSubstractionActivated_toggled(bool checked)
{
    if(checked)
    {
        detector.activateBackgroundSubstraction();
    }
    else
    {
        detector.deactivateBackgroundSubstraction();
    }
}


void MainWindow::on_pbSetBackground_clicked()
{
    setDetectorBackground=true;
}

void MainWindow::updateThresholds()
{
    unsigned char LR;
    unsigned char LG;
    unsigned char LB;
    unsigned char UR;
    unsigned char UG;
    unsigned char UB;
    LR=fromInt(ui->hsLtRed->value());
    LG=fromInt(ui->hsLtGreen->value());
    LB=fromInt(ui->hsLtBlue->value());
    UR=fromInt(ui->hsGtRed->value());
    UG=fromInt(ui->hsGtGreen->value());
    UB=fromInt(ui->hsGtBlue->value());
    detector.setColorThresholds(LR,LG,LB,UR,UG,UB);
    detector.setBackgroundThreshold(ui->hsBS->value());
}
