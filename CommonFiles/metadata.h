#ifndef METADATA_H
#define METADATA_H
#include <QtCore>
#include "opencv2/opencv.hpp"
using namespace cv;

static inline void initMetaData()
{
    qRegisterMetaType<Mat>("Mat");
}
#endif // METADATA_H
