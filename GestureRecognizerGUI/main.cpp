#include "mainwindow.h"
#include <QApplication>
#include <metadata.h>
int main(int argc, char *argv[])
{
    initMetaData();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
