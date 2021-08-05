#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_pbEditColor_clicked()
{
    const QColorDialog::ColorDialogOptions options = QFlag(QColorDialog::DontUseNativeDialog);
    const QColor color = QColorDialog::getColor(ui->teText->textColor(), this, "Select Color", options);

    if (color.isValid())
    {

        QTextCursor cursor = ui->teText->textCursor();
        ui->teText->selectAll();
        ui->teText->setTextColor(color);
        ui->teText->setTextCursor(cursor);
        ui->teText->setTextColor(color);
        ui->teText->setAutoFillBackground(true);
    }
}

void MainWindow::on_pbEditFont_clicked()
{
    const QFontDialog::FontDialogOptions options = QFlag(0);
    bool ok;
    QFont font = QFontDialog::getFont(&ok, QFont(ui->teText->currentFont()), this, "Select Font", options);
    if (ok)
    {
        QTextCursor cursor = ui->teText->textCursor();
        ui->teText->selectAll();
        ui->teText->setFont(font);
        ui->teText->setFontPointSize(font.pointSize());
        ui->teText->setTextCursor(cursor);
        ui->teText->setFont(font);
        ui->teText->setFontPointSize(font.pointSize());
    }
}

void MainWindow::on_pbSaveText_clicked()
{
    const QFileDialog::Options options = QFlag(QFileDialog::DontUseNativeDialog);
    QString selectedFilter;
    QString fileName = QFileDialog::getSaveFileName(this,
                                tr("Save"),
                                QDir::currentPath(),
                                tr("All Files (*);;Text Files (*.txt)"),
                                &selectedFilter,
                                options);
    if (!fileName.isEmpty())
    {
        if(!fileName.endsWith(".txt"))
        {
            fileName+=".txt";
        }
        QFile file(fileName);

        if (file.open(QIODevice::ReadWrite))
        {
            QTextStream stream(&file);
            stream << ui->teText->toPlainText();
            file.close();
        }
        else
        {
            QMessageBox::critical(this, tr("Error"), tr("Failed to save file."));
            return;
        }
    }
}

void MainWindow::on_pbLoadText_clicked()
{
    const QFileDialog::Options options = QFlag(QFileDialog::DontUseNativeDialog);
    QString selectedFilter;
    QString fileName = QFileDialog::getOpenFileName(this,
                                tr("Open"),
                                QDir::currentPath(),
                                tr("All Files (*);;Text Files (*.txt)"),
                                &selectedFilter,
                                options);
    if (!fileName.isEmpty())
    {
        QString line;
        QFile file(fileName);
        QString txt="";
        ui->teText->clear();
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream stream(&file);
            while (!stream.atEnd())
            {
                line = stream.readLine();
                txt+=line+"\n";
            }
            synthesizer.setText(txt);
        }
        else
        {
            QMessageBox::critical(this, tr("Error"), tr("Failed to open file."));
            return;
        }
        file.close();
    }
}

void MainWindow::on_pbDelLastCharacter_clicked()
{
    synthesizer.del();
}

void MainWindow::on_pbReset_clicked()
{
    synthesizer.clear();
}

