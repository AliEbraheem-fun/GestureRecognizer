#include "grdetector.h"
#include <cmath>

GRDetector::GRDetector()
{
    backgroundSet=false;
    backgroundSubstractionActivated=false;
    backgroundThreshold=0;
    this->LR=0;
    this->LG=0;
    this->LB=0;

    this->UR=0;
    this->UG=0;
    this->UB=0;
}

void GRDetector::setColorThresholds(unsigned char LR, unsigned char LG, unsigned char LB,
                                       unsigned char UR, unsigned char UG, unsigned char UB)
{
    this->LR=LR;
    this->LG=LG;
    this->LB=LB;

    this->UR=UR;
    this->UG=UG;
    this->UB=UB;
}

void GRDetector::setBackground(Mat bg)
{
    bg.copyTo(background);
    backgroundSet=true;
}

void GRDetector::setBackgroundThreshold(int threshold)
{
    backgroundThreshold=(threshold<0)?0:threshold;
}

void GRDetector::activateBackgroundSubstraction()
{
        backgroundSubstractionActivated=true;
}

void GRDetector::deactivateBackgroundSubstraction()
{
    backgroundSubstractionActivated=false;
}

bool GRDetector::detect(Mat &frame, Mat &mask, Mat &maskedImage)
{
    Mat rgb;
    bool isBackgroundPixel;
    bool isColorRight;
    int absoluteDifference;
    cvtColor(frame,rgb,CV_BGR2RGB);
    mask=Mat::zeros(rgb.rows,rgb.cols,CV_8UC1);
    maskedImage=Mat::zeros(rgb.rows,rgb.cols,CV_8UC3);
    if(backgroundSubstractionActivated && backgroundSet && (frame.size()!=background.size()) )
    {
        return false;
    }

    for(int i=0;i<rgb.cols;i++)
    {
        for(int j=0;j<rgb.rows;j++)
        {
            isColorRight=(rgb.at<Vec3b>(i,j)[0] >= LR);
            isColorRight&=(rgb.at<Vec3b>(i,j)[0] <= UR);
            isColorRight&=(rgb.at<Vec3b>(i,j)[1] >= LG);
            isColorRight&=(rgb.at<Vec3b>(i,j)[1] <= UG);
            isColorRight&=(rgb.at<Vec3b>(i,j)[2] >= LB);
            isColorRight&=(rgb.at<Vec3b>(i,j)[2] <= UB);

            isBackgroundPixel=false;
            if(backgroundSubstractionActivated && backgroundSet)
            {
                absoluteDifference=abs(int(rgb.at<Vec3b>(i,j)[0])-int(background.at<Vec3b>(i,j)[0]));
                absoluteDifference+=abs(int(rgb.at<Vec3b>(i,j)[1])-int(background.at<Vec3b>(i,j)[1]));
                absoluteDifference+=abs(int(rgb.at<Vec3b>(i,j)[2])-int(background.at<Vec3b>(i,j)[2]));
                if(absoluteDifference<=backgroundThreshold)
                {
                    isBackgroundPixel=true;
                }
            }

            if((!isBackgroundPixel) &&isColorRight)
            {
                mask.at<unsigned char>(i,j)=255;
                maskedImage.at<Vec3b>(i,j)=rgb.at<Vec3b>(i,j);
            }
        }
    }
    return true;
}
