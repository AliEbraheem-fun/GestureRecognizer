#include <iostream>
#include <stdlib.h>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;
#define HAND_REGION_X_OFFSET    40
#define HAND_REGION_Y_OFFSET    50
#define HAND_REGION_HEIGHT      300
#define HAND_REGION_WIDTH       300
#define SAMPLE_WIDTH            100
#define SAMPLE_HEIGHT           100
#define COLORED_SAMPLE_WIDTH    125
#define COLORED_SAMPLE_HEIGHT    125


bool detectCandidate(Mat& binaryImage, Mat &coloredImage, Mat& sample, Mat &coloredSample)
{
    vector<Vec4i> hierarchy;
    vector<vector<Point>> contours;
    Mat img_resized;
    Mat newBinaryImage=Mat::zeros(binaryImage.rows,binaryImage.cols,CV_8UC1);
    Mat kernel=getStructuringElement(MORPH_ELLIPSE ,Size(3,3));
    erode(binaryImage,binaryImage,kernel);
    //dilate(binaryImage,binaryImage,kernel);
    findContours(binaryImage,contours,hierarchy,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_NONE);
    int cnt_i=-1;
    double area_i=0;
    double area=0;
    if(contours.size()>0)
    {
        cnt_i=0;
        area_i=contourArea(contours[0]);
        for(unsigned int i=1;i<contours.size();i++)
        {
            area=contourArea(contours[i]);
            if(area>area_i)
            {
                cnt_i=i;
                area_i=area;
            }
        }
    }
    if(cnt_i!=-1&& area_i >5000)
    {
        approxPolyDP(contours[cnt_i],contours[cnt_i],2,true);
        drawContours(newBinaryImage,contours,cnt_i,Scalar(255),-1);
        Rect roi=boundingRect(contours[cnt_i]);
        Mat img=Mat(newBinaryImage,roi);
        Mat coloredImg=Mat(coloredImage,roi);
        for(int i=0;i<coloredImg.rows;i++)
        {
            for(int j=0;j<coloredImg.cols;j++)
            {
                if(img.at<unsigned char>(i,j)==0)
                {
                    coloredImg.at<Vec3b>(i,j)[0]=coloredImg.at<Vec3b>(i,j)[1]=coloredImg.at<Vec3b>(i,j)[2]=255;
                }

            }
        }
        resize(img,sample,Size(SAMPLE_WIDTH,SAMPLE_HEIGHT));
        resize(coloredImg,coloredSample,Size(COLORED_SAMPLE_WIDTH,COLORED_SAMPLE_HEIGHT*1.25));
        return true;
    }
    return false;
}


int main()
{
    namedWindow("video");
    char path[256]="";
    char filename[256]="";
    char fullpath[512]="";
    int counter=0;
    Mat frame,tmp;
    int thresh=75;
    VideoCapture cap(0);
    bool first=true;//flag to detect first frame;
    Rect handRegion;//where user shoud place his hand
    int width;//frame width
    int height;//frame height
    createTrackbar("threshold","video",&thresh,255);
    if(!cap.isOpened())
    {
        cout<<"cannot connect to default capture device\n";
        return -1;
    }
    cout<<"Press (a,d,w,s) to move region of interest.\n"
        <<"Press (m) to set output folder and files initial name.\n"
        <<"Press (z) to save binary image.\n"
        <<"Press (r) to save colored image.\n"
        <<"Press (q) to quit.\n"<<endl;
    while(cap.isOpened())
    {
        cap>>frame;//extract image from capture device
        if(frame.empty()) continue;//frame not extracted successfully
        if(first)
        {
            first=false;
            width=frame.cols;
            height=frame.rows;
            cout<<"width: "<<width<<"\nheight: "<<height<<endl;
            if(width<(HAND_REGION_WIDTH+2*HAND_REGION_X_OFFSET) || height<(HAND_REGION_HEIGHT+2*HAND_REGION_Y_OFFSET))
            {
                cout<<"image size is small\n";
            }
            handRegion.x=width-HAND_REGION_X_OFFSET-HAND_REGION_WIDTH;
            handRegion.y=HAND_REGION_Y_OFFSET;
            handRegion.width=HAND_REGION_WIDTH;
            handRegion.height=HAND_REGION_HEIGHT;
        }
        flip(frame,frame,1);//[1<->flip around y axis][0<-> flip around x axis][negative value<->flip around both
        tmp=Mat(frame,handRegion);
        rectangle(frame,handRegion,Scalar(0,0,0));
        Mat mask=Mat::zeros(tmp.rows,tmp.cols,CV_8UC1);
        imshow("video",frame);//display image
        for(int i=0;i<tmp.rows;i++)
        {
            for(int j=0;j<tmp.cols;j++)
            {
                if(tmp.at<Vec3b>(i,j)[2]<thresh && tmp.at<Vec3b>(i,j)[1]<thresh && tmp.at<Vec3b>(i,j)[0]<thresh)
                {
                    mask.at<unsigned char>(i,j)=255;
                }
            }
        }
        Mat sample;
        Mat coloredSample;
        Mat maskedImage;
        if(detectCandidate(mask,tmp,sample,coloredSample))
        {
            imshow("mask",sample);

            imshow("masked image",coloredSample);
        }

        switch(waitKey(30))
        {
            case 'q':
            {
                cap.release();
                break;
            }
            case 'm':
            {
                cout<<"Enter path: ";
                cin>>path;
                cout<<"Enter initial name: ";
                cin>> filename;
                counter=0;
                break;
            }
            case 'z':
            {
                sprintf(fullpath,"%s/%s%d.bmp",path,filename,counter);
                cout<<fullpath<<endl;
                imwrite(String(fullpath),sample);
                counter++;
                break;
            }
            case 'r':
            {
                sprintf(fullpath,"%s/%s%d.bmp",path,filename,counter);
                cout<<fullpath<<endl;
                imwrite(String(fullpath),coloredSample);
                counter++;
                break;
            }
            case 'w':
            {
                handRegion.y--;
                break;
            }
            case 's':
            {
                handRegion.y++;
                break;
            }
            case 'd':
            {
                handRegion.x++;
                break;
            }
            case 'a':
            {
                handRegion.x--;
                break;
            }
        }
    }
}
