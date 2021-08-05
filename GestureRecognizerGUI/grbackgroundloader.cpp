#include "grbackgroundloader.h"
#include "grhelperimageprocessingfunctions.h"
GRBackgroundLoader::GRBackgroundLoader(QStringList paths, vector<int> labels, QList<GRAbstractRecognizerPlugin *> plugins)
{
    this->recognizers=plugins;
    this->paths=paths;
    this->labels=labels;
    connect(this,SIGNAL(finished()),this,SLOT(deleteLater()));
}

bool GRBackgroundLoader::loadTrainingData(QStringList paths, vector<int> labels,Mat &trainingMat,Mat &labelsMat)
{

    QDir *dir;
    if(paths.length()!= int(labels.size()))
    {
        return false;
    }
    for(int i=0;i<paths.length();i++)
    {
        dir=new QDir(paths[i]);
        if(! dir->exists())
        {
            delete dir;
            return false;
        }
        delete dir;
    }
    for(int i=0;i<paths.length();i++)
    {
        add(paths[i].toStdString().data(),labels[i],trainingMat,labelsMat,true);
    }

    return true;
}

void GRBackgroundLoader::startLoader()
{
    start();
}

void GRBackgroundLoader::run()
{
    Mat trainingMat,labelsMat;
    QElapsedTimer timer;
    qint64 elapsed;
    timer.start();
    if(!recognizers.isEmpty())
    {
        if(loadTrainingData(paths,labels,trainingMat,labelsMat))
        {
            for(int i=0;i<recognizers.length();i++)
            {
                if(!recognizers[i]->trained())
                {
                    emit log(tr("%1 preparation started.").arg(recognizers[i]->getName()));
                    timer.restart();
                    recognizers[i]->train(trainingMat,labelsMat);
                    elapsed=timer.elapsed();
                    emit log(tr("%1 preparation ended.").arg(recognizers[i]->getName()));
                    emit log(tr("elapsed time: %1 ms.").arg(elapsed));

                }
            }
        }
    }

    emit complete();
}
