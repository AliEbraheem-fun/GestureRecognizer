#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_pbTestTextToSpeech_clicked()
{
    m_speech->speak("Hello world");
}

void MainWindow::on_pbSpeakAll_clicked()
{
    m_speech->speak(ui->teText->toPlainText());
}
