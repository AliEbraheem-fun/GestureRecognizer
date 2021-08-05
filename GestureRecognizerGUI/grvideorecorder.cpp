#include "grvideorecorder.h"

GRVideoRecorder::GRVideoRecorder(QString filename, int fps, int width, int height)
    :stopFlag(true)
{
    if(fps<=0)
    {
        this->fps=defaultFPS;
    }
    else if(fps>maxFPS)
    {
        this->fps=maxFPS;
    }
    else
    {
        this->fps=fps;
    }
    if(height<minimumHeight)
    {
       this->height=minimumHeight;
    }
    else
    {
        this->height=height;
    }
    if(width<minimumWidth)
    {
        this->width=minimumWidth;
    }
    else
    {
        this->width=width;
    }
    this->filename=filename;
}

void GRVideoRecorder::record(Mat frame)
{
    Mat resized_frame;
    if(!stopFlag && writer->isOpened())
    {
        if(frame.cols!=width || frame.rows!=height)
        {
        resize(frame,resized_frame,Size(width,height));
        }
        else
        {
            resized_frame=frame;
        }
        bufferMtx.lock();
        buffer.enqueue(resized_frame);
        bufferMtx.unlock();
    }
}

bool GRVideoRecorder::startRecorder()
{

    writer=new VideoWriter(filename.toStdString().data(),-1,this->fps,Size(this->width,this->height),true);
    if(writer->isOpened())
    {
        stopFlag=false;
        start();
        return true;
    }
    else
    {
        return false;
    }
}

void GRVideoRecorder::release()
{
    connect(this,SIGNAL(finished()),this,SLOT(deleteLater()));
    stopFlag=true;
    while(isRunning());
}

void GRVideoRecorder::run()
{
    Mat frame;
    bool emptyFlag;
    while(!stopFlag && writer->isOpened())
    {
        bufferMtx.lock();
        emptyFlag=buffer.isEmpty();
        if(!emptyFlag)
        {
            frame=buffer.dequeue();
        }
        bufferMtx.unlock();
       if(!emptyFlag)
       {
            writer->write(frame);
       }
        QThread::msleep(5);
    }
    writer->release();

}

