TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp
INCLUDEPATH+=..\CommonFiles\opencv330\include
LIBS +=-L..\CommonFiles\opencv330\bin\
        -lopencv_core330    \
        -lopencv_videoio330 \
        -lopencv_highgui330 \
        -lopencv_imgproc330 \
        -lopencv_video330 \
        -lopencv_imgcodecs330

DESTDIR=$$PWD/../Binaries

