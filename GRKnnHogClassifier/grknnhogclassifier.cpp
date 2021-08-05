#include "grknnhogclassifier.h"


GRKnnHogClassifier::GRKnnHogClassifier()
{
    isTrained=false;
}

GRKnnHogClassifier::~GRKnnHogClassifier()
{
    delete knn;
}

bool GRKnnHogClassifier::needTrainig()
{
    return true;
}

TrustDegree GRKnnHogClassifier::getTrustDegree()
{
    return HIGH;
}

QString GRKnnHogClassifier::getName()
{
    QString str="KNN-HOG based classifier";
    return str;
}

int GRKnnHogClassifier::getVersion()
{
    return 1;
}

QString GRKnnHogClassifier::getDescription()
{
    QString str="Recognition system based on K Nearest Neighbor method"
                " and HOG features (histogram of oriented gradients).\n";
    return str;
}

FeatureType GRKnnHogClassifier::getFeatureType()
{
    return HOG;
}

bool GRKnnHogClassifier::trained()
{
    return isTrained;
}


void GRKnnHogClassifier::train(Mat &data, Mat &labels)
{
    knn=KNearest::create();
    knn->train(data, ml::ROW_SAMPLE, labels);
    isTrained=true;

}

bool GRKnnHogClassifier::train(QStringList paths, vector<int> labels, String datafilename, String labelsFilename,bool saveData, bool saveLabels)
{
    Mat trainingMat;
    Mat labelsMat;
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
    train(trainingMat,labelsMat);
    isTrained=true;
    if(saveData)
    {
        saveMat(datafilename,"data",trainingMat);
    }
    if(saveLabels)
    {
        saveMat(labelsFilename,"labels",labelsMat);
    }
    return true;
}


int GRKnnHogClassifier::getGesture(Mat frame)
{
    int gesture=-1;
    Mat features;
    Mat matCurrentChar;
    computeHOGFeatures(frame, features);
    knn->findNearest(features, 1, matCurrentChar,noArray());
    gesture = (int)matCurrentChar.at<float>(0, 0);
    return gesture;
}
