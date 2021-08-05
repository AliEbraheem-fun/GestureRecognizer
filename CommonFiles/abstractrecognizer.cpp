#include "abstractrecognizer.h"

TrustDegree AbstractRecognizer::getTrustDegree()
{
    return trustDegree;
}

AbstractRecognizer::AbstractRecognizer()
{
    isTrained=false;
}

bool AbstractRecognizer::needTrainig()
{
    return trainingNeeded;
}

QString AbstractRecognizer::getName()
{
    return name;
}

int AbstractRecognizer::getVersion()
{
    return version;
}

QString AbstractRecognizer::getDescription()
{
    return description;
}

FeatureType AbstractRecognizer::getFeatureType()
{
    return featureType;
}

bool AbstractRecognizer::trained()
{
    return isTrained;
}
