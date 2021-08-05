#include "grvideograbber.h"

GRVideoGrabber::GRVideoGrabber(QString filename):
    isFile(true),mirrored(false)
{
    cap=new VideoCapture(filename.toStdString());
    fps=cap->get(CV_CAP_PROP_FPS);
    width=cap->get(CV_CAP_PROP_FRAME_WIDTH);
    height=cap->get(CV_CAP_PROP_FRAME_HEIGHT);
    frameCount=(int) cap->get(CV_CAP_PROP_FRAME_COUNT);
    if(fps<=0)
    {
        fps=defaultFPS;
    }
    else if(fps>maxFPS)
    {
        fps=maxFPS;
        cap->set(CV_CAP_PROP_FPS,fps);
    }
    msPeriod=qint64(1000/this->fps);
    stopFlag=true;
    connect(this,SIGNAL(finished()),this,SLOT(deleteLater()));                
}


bool GRVideoGrabber::startGrabber()
{
    if(cap->isOpened())
    {
        stopFlag=false;
        start();
        return true;
    }
    return false;

}

void GRVideoGrabber::stopGrabber()
{
    stopFlag=true;
    connect(this,SIGNAL(finished()),this,SLOT(deleteLater()));
    while(isRunning());
}

int GRVideoGrabber::getFPS()
{
    return (int)fps;
}


GRVideoGrabber::GRVideoGrabber(int fps, int videoSource, bool isMirrored):
    isFile(false),mirrored(isMirrored)
{
    cap=new VideoCapture(videoSource);
    if(fps>0)
    {
        cap->set(CV_CAP_PROP_FPS,fps);
        this->fps=fps;
    }
    else
    {
        this->fps=cap->get(CV_CAP_PROP_FPS);
        if(this->fps<=0)
        {
            this->fps=defaultFPS;
        }
    }
    //width=cap->get(CV_CAP_PROP_FRAME_WIDTH);
    //height=cap->get(CV_CAP_PROP_FRAME_HEIGHT);
    cap->set(CV_CAP_PROP_FRAME_WIDTH,640);
    cap->set(CV_CAP_PROP_FRAME_HEIGHT,480);
    frameCount=-1;
    msPeriod=qint64(1000/this->fps);
    stopFlag=true;
    connect(this,SIGNAL(finished()),this,SLOT(deleteLater()));            
    
}

void GRVideoGrabber::run()
{
    Mat frame;
    QElapsedTimer elapsedTimer;
    qint64 elapsedTime;
    int i=0;
    elapsedTimer.start();
    while(!stopFlag && cap->isOpened())
    {
        elapsedTimer.restart();
        (*cap)>>frame;
        if(isFile)
        {
            i++;
        }
        if(!frame.empty())
        {
            if(mirrored)
            {
                flip(frame,frame,1);//[1<->flip around y axis][0<-> flip around x axis][negative value<->flip around both
            }
            cap->set(CV_CAP_PROP_FRAME_WIDTH,640);
            cap->set(CV_CAP_PROP_FRAME_HEIGHT,480);
            if(frame.cols != 640 || frame.rows!=480)
            {
                resize(frame,frame,Size(640,480));
            }
            emit frameGrabbed(frame);
        }
        else
        {
            if(isFile)
            {
                break;
            }
        }
        if(isFile && i>=frameCount)
        {
            break;
        }
        elapsedTime=elapsedTimer.elapsed();
        if(elapsedTime>=msPeriod)
        {
            //image processing is taking too long
            continue;
        }
        else
        {
            QThread::msleep((unsigned long)(msPeriod-elapsedTime));
        }
    }
    cap->release();
    emit grabberStopped();
}

