#include "grsvmhogclassifier.h"

GRSvmHogClassifier::GRSvmHogClassifier()
{
    isTrained=false;
}

bool GRSvmHogClassifier::needTrainig()
{
    return true;
}

TrustDegree GRSvmHogClassifier::getTrustDegree()
{
    return HIGH;
}

QString GRSvmHogClassifier::getName()
{
    QString str="SVM-HOG based classifier";
    return str;
}

int GRSvmHogClassifier::getVersion()
{
    return 1;
}

QString GRSvmHogClassifier::getDescription()
{
    QString str="Recognition system based on support vector machine (SVM)"
                " and HOG features (histogram of oriented gradients).\n";
    return str;
}

FeatureType GRSvmHogClassifier::getFeatureType()
{
    return HOG;
}

bool GRSvmHogClassifier::trained()
{
    return isTrained;
}

int GRSvmHogClassifier::getGesture(Mat frame)
{
    int gesture=-1;
    Mat features;
    computeHOGFeatures(frame, features);
    gesture=svm->predict(features);
    return gesture;
}

void GRSvmHogClassifier::train(Mat &data, Mat &labels)
{
    svm = SVM::create();
    svm->setType(SVM::C_SVC);
    svm->setC(0.1);
    svm->setKernel(SVM::LINEAR);
    svm->setDegree(2);
    svm->setTermCriteria(TermCriteria(TermCriteria::MAX_ITER, (int)1e7, 1e-6));
    svm->train(data, ROW_SAMPLE, labels);
    isTrained=true;
}

bool GRSvmHogClassifier::train(QStringList paths, vector<int> labels, String datafilename, String labelsFilename,bool saveData, bool saveLabels)
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
/*
bool GRSvmHogClassifier::trainII(QStringList paths, vector<int> labels, String savingPath)
{
    if(train(paths,labels))
    {
        svm->save(savingPath);
        return true;
    }
    else
    {
        return false;
    }
}

bool GRSvmHogClassifier::load(String path)
{
    svm->load(path);
    return true;
}
*/
