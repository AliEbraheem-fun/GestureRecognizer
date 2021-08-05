#ifndef GRABSTRACTRECOGNIZERPLUGIN_H
#define GRABSTRACTRECOGNIZERPLUGIN_H

#include <QObject>
#include <opencv2/opencv.hpp>
#include <grhelperimageprocessingfunctions.h>
using namespace cv;
using namespace std;

class GRAbstractRecognizerPlugin:public QObject
{
    Q_OBJECT
public:
    virtual ~GRAbstractRecognizerPlugin(){}
    /*!
     * Recognizes the gesture contained in a frame;
     * \param frame The image which contains a gesture.
     * \return The label of the gesture.
     */
     virtual int getGesture(Mat frame)=0;

    /*!
     * Trains a classifier.
     * \param data Sample data.
     * \param labels Data labels.
     */
    virtual void train(Mat &data, Mat &labels )=0;

    /*!
     * \Trains a classifier.
     * \param paths Paths to folders containig training images. Each folder must only contain data of the same type.
     * \param labels Labels of the corresponding folders.
     * \param datafilename The file to which training data will be saved.
     * \param labelsFilename The file to which data labels will be saved.
     * \param saveData If true training data will be saved to a file.
     * \param saveLabels If true data labels will be saved to a file.
     * \return True if the training and saving process is successful.
     */
    virtual bool train(QStringList paths, vector<int> labels, String datafilename="samples.xml", String labelsFilename="labels.xml", bool saveData=false, bool saveLabels=false)=0;

    //virtual bool trainII(QStringList paths, vector<int> labels,String saveingPath)=0;

    //virtual bool load(String path)=0;

    /*!
     * Specifies the need for classier training.
     * \return True If the classifier needs training before usage. False otherwise.
     */
    virtual bool needTrainig()=0;

    /*!
     * Specifies How much trust can be put in the classifiers.
     * \return Degree of trust in the classifier.
     */
    virtual TrustDegree getTrustDegree()=0;

    /*!
     * Specifies classifier name.
     * \return Name of the classifier.
     */
    virtual QString getName()=0;

    /*!
     * Specifies classifier version.
     * \return Classifier version.
     */
    virtual int getVersion()=0;

    /*!
     * Specifies the description of the classifier.
     * \return Classifier description.
     */
    virtual QString getDescription()=0;

    /*!
     * Specifies the type of features used by the classifier.
     * \return Feature type.
     */
    virtual FeatureType getFeatureType()=0;

    /*!
     * Specifies whether the classifier is trained or not.
     * \return true if the classifier is trained and false otherwise.
     */
    virtual bool trained()=0;


};
Q_DECLARE_INTERFACE(GRAbstractRecognizerPlugin,"GestureRecognizer.GRAbstractRecognizerPlugin")

#endif // GRABSTRACTRECOGNIZERPLUGIN_H
