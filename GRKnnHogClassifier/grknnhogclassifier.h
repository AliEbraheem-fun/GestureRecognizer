#ifndef GRKNNHOGClASSIFIER_H
#define GRKNNHOGClASSIFIER_H
#include <QtCore>
#include "grabstractrecognizerplugin.h"
#include "opencv2/opencv.hpp"
using namespace  cv::ml;

class  GRKnnHogClassifier: public GRAbstractRecognizerPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "GestureRecognizer.AbstractRecognizerPlugin")
    Q_INTERFACES(GRAbstractRecognizerPlugin)
public:
    GRKnnHogClassifier();
    ~GRKnnHogClassifier();
    bool needTrainig();

    /*!
     * Specifies How much trust can be put in the classifiers.
     * \return Degree of trust in the classifier.
     */
    TrustDegree getTrustDegree();

    /*!
     * Specifies classifier name.
     * \return Name of the classifier.
     */
    QString getName();

    /*!
     * Specifies classifier version.
     * \return Classifier version.
     */
    int getVersion();

    /*!
     * Specifies the description of the classifier.
     * \return Classifier description.
     */
     QString getDescription();

    /*!
     * Specifies the type of features used by the classifier.
     * \return Feature type.
     */
    FeatureType getFeatureType();

    /*!
     * Specifies whether the classifier is trained or not.
     * \return true if the classifier is trained and false otherwise.
     */
     bool trained();
    int getGesture(Mat frame);
    void train(Mat &data, Mat &labels );
    bool train(QStringList paths, vector<int> labels, String datafilename="samples.xml", String labelsFilename="labels.xml", bool saveData=false, bool saveLabels=false);
private:
    Ptr<KNearest> knn;
    bool isTrained;
};

#endif // GRKNNHOGClASSIFIER_H
