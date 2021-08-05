#-------------------------------------------------
#
# Project created by QtCreator 2018-01-07T19:03:21
#
#-------------------------------------------------

QT       += core gui network  texttospeech multimedia xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GestureRecognizerGUI
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    animatedqlabel.cpp \
    animatedqpushbutton.cpp \
    animatedqtextedit.cpp \
    grvideograbber.cpp \
    grvideorecorder.cpp \
    gryolodetector.cpp \
    main.cpp \
    mainwindow.cpp \
    mainwindow_grabber.cpp \
    mainwindow_recorder.cpp \
    mainwindow_snapshot.cpp \
    mainwindow_texttospeech.cpp \
    animatedqframe.cpp \
    animatedqcombobox.cpp \
    animatedqcheckbox.cpp \
    animatedqprogressbar.cpp \
    animatedqlistwidget.cpp \
    ../CommonFiles/grhelperimageprocessingfunctions.cpp \
    grbackgroundloader.cpp \
    mainwindow_recognition.cpp \
    mainwindow_update.cpp \
    grrecognitionengine.cpp \
    grtexttospeach.cpp \
    grwordsynthesizer.cpp \
    grdownloadmanager.cpp \
    grfileinfo.cpp \
    grfilelist.cpp \
    grupdatemanager.cpp \
    mainwindow_detection.cpp \
    mainwindow_text.cpp \
    grdetector.cpp

HEADERS += \
    ../CommonFiles/metadata.h \
    animatedqlabel.h \
    animatedqpushbutton.h \
    animatedqtextedit.h \
    grvideograbber.h \
    grvideorecorder.h \
    gryolodetector.h \
    mainwindow.h \
    ui_mainwindow.h \
    animatedqframe.h \
    animatedqcombobox.h \
    animatedqcheckbox.h \
    animatedqprogressbar.h \
    animatedqlistwidget.h \
    ../CommonFiles/grhelperimageprocessingfunctions.h \
    grbackgroundloader.h \
    grrecognitionengine.h \
    doc.h \
    grtexttospeach.h \
    grwordsynthesizer.h \
    grdownloadmanager.h \
    grfilelist.h \
    grfileinfo.h \
    grupdatemanager.h \
    ../CommonFiles/grabstractrecognizerplugin.h \
    grdetector.h

FORMS += \
        mainwindow.ui

INCLUDEPATH += $$PWD/../CommonFiles/opencv330/include
INCLUDEPATH += $$PWD/../CommonFiles

LIBS += -L$$PWD\..\CommonFiles\opencv330\bin\
 -lopencv_core330 \
 -lopencv_videoio330 \
 -lopencv_imgcodecs330 \
 -lopencv_highgui330 \
 -lopencv_imgproc330 \
 -lopencv_ml330 \
 -lopencv_objdetect330
 -lopencv_dnn330


DESTDIR=$$PWD/../Binaries

RESOURCES += \
    resources.qrc

DISTFILES += \
    Notes
