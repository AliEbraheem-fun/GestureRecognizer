#include "grrecognitionengine.h"

GRRecognitionEngine::GRRecognitionEngine():historyLength(15),engineStarted(false)
{
    connect(this,SIGNAL(finished()),this,SLOT(deleteLater()));
}

bool GRRecognitionEngine::addRecognizer(GRAbstractRecognizerPlugin *recognizer)
{
    if(isRunning())
    {
        return false;
    }
    recognizers.append(recognizer);
    return false;
}

void GRRecognitionEngine::startRecognitionEngine()
{
    stopFlag=false;
    engineStarted=true;
    start();
}

void GRRecognitionEngine::stopRecognitionEngine()
{
    stopFlag=true;
    while(isRunning());
}

bool GRRecognitionEngine::isStarted()
{
    return engineStarted;
}

void GRRecognitionEngine::addFrame(Mat frame)
{
    mtx.lock();
    buffer.enqueue(frame);
    mtx.unlock();
}

void GRRecognitionEngine::run()
{
    QVector<int> arbitrationVector;
    QVector<int> values;
    QVector<int> counts;
    bool isEmpty;
    Mat frame;
    int gest;
    while(!stopFlag)
    {
        mtx.lock();
        isEmpty=buffer.isEmpty();
        if(!isEmpty)
        {
            frame=buffer.dequeue();
        }
        mtx.unlock();
        if(!isEmpty)
        {
            arbitrationVector.clear();
            values.clear();
            counts.clear();
            for(int i=0;i<recognizers.length();i++)
            {
                if(recognizers[i]->trained())
                {
                    gest=recognizers[i]->getGesture(frame);
                    if(!values.contains(gest))
                    {
                        values.append(gest);
                    }
                    arbitrationVector.append(gest);
                    if(recognizers[i]->getTrustDegree()!=LOW)
                    {
                        arbitrationVector.append(gest);
                    }
                    if(recognizers[i]->getTrustDegree()==HIGH)
                    {
                        arbitrationVector.append(gest);
                    }
                }
            }
            if(values.length()>0)
            {
                for(int i=0;i<values.length();i++)
                {
                    counts.append(arbitrationVector.count(values[i]));
                }
                int max=counts[0],i_max=0;
                for(int i=1;i<values.length();i++)
                {
                    if(counts[i]>max)
                    {
                        max=counts[i];
                        i_max=i;
                    }
                }

                history.enqueue(values[i_max]);

                if(history.length()>=historyLength)
                {
                    history.dequeue();
                    values.clear();
                    for(int i=0;i<history.length();i++)
                    {
                        if(!values.contains(history[i]))
                        {
                            values.append(history[i]);
                        }
                    }
                    counts.clear();
                    for(int i=0;i<values.length();i++)
                    {
                        counts.append(history.count(values[i]));
                    }

                    max=counts[0],i_max=0;
                    for(int i=1;i<values.length();i++)
                    {
                        if(counts[i]>max)
                        {
                            max=counts[i];
                            i_max=i;
                        }
                    }

                    if(counts[i_max]> int(0.75*float(history.length())))
                    {
                        emit gestureRecognized(values[i_max]);
                    }
                    history.clear();
                }
            }
        }

        QThread::msleep(1);
    }

}
