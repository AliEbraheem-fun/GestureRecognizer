#ifndef ABSTRACTRECOGNIZER_H
#define ABSTRACTRECOGNIZER_H
#include <QtCore>
#include "opencv2/opencv.hpp"
#include "abstractrecognizerplugin.h"
using namespace cv;
using namespace std;

class AbstractRecognizer : public AbstractRecognizerPlugin
{
    Q_OBJECT
public:

     AbstractRecognizer();

     virtual ~AbstractRecognizer(){}



protected:
    TrustDegree trustDegree;/*!< How good is the classifier. */
    bool trainingNeeded;/*!< A flag that indicates if the classifier needs training before usage. */
    QString name;/*!< Name of the classifier. */
    int version;/*!< Version of the classifier. */
    QString description;/*!< Brief description on the classifier. */
    FeatureType featureType;/*!< Type of features used by the classifier. */
    bool isTrained; /*!< True if classifier is trained. */
 };

#endif // ABSTRACTRECOGNIZER_H
