#-------------------------------------------------
#
# Project created by QtCreator 2018-03-07T04:20:42
#
#-------------------------------------------------

QT       -= gui

TARGET = GRSvmHogClassifier
TEMPLATE = lib

DEFINES += GRSVMHOGCLASSIFIER_LIBRARY

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
        grsvmhogclassifier.cpp \
    ../CommonFiles/grhelperimageprocessingfunctions.cpp

HEADERS += \
        grsvmhogclassifier.h \
    ../CommonFiles/grabstractrecognizerplugin.h \
    ../CommonFiles/grhelperimageprocessingfunctions.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
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

DESTDIR=$$PWD/../Binaries/plugins
