#ifndef GRHELPERIMAGEPROCESSINGFUNCTIONS_H
#define GRHELPERIMAGEPROCESSINGFUNCTIONS_H
#include<QtCore>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

/*!
     * How much trust can be put in the recognizer.
     */
    enum TrustDegree
    {
        LOW=0,/*!< Not very trust worthy. Only one copy of the recognition result will be used in the arbitration process. */
        MEDIUM,/*!< Result is OK. Two copies of the recognition result will be used in the arbitration process. */
        HIGH /*!< Highly trust worthy. Three copies of the recognition result will be used in the arbitration process. */
    } ;

    /*!
     * The kind of features the recogizer uses.
     */
    enum FeatureType
    {
        RAW, /*!< Raw images not hog features are used. */
        HOG /*!< Hog features are used by the recognizer */
    };


bool extractLargestContour(Mat& binaryImage, Mat& output, double minimumArea, Size outputSize);
bool getMaskedImage(Mat& img,Mat &mask, Mat &maskedImage);
/*!
    * Reads images which exist in a specific folder.
    * \param dirname The path to the folder containing the imges.
    * \param img_lst A vector of Mat objects where images will be stored.
    * \param showImages When true the loaded images are displayed in a separate window one after the other.
    */
   void load_images(const String &dirname, vector<Mat> &img_lst, bool showImages=true);

   /*!
    * Converts a vector of Mat objects to the format used by machine learning algorithms in OpenCV.
    * \param train_samples A vector of Mat objects to be converted.
    * \param trainData The Mat object containing data after the conversion process.
    */
   void convert_to_ml(const vector<Mat> &train_samples, Mat &trainData);

   /*!
    * Converts a Mat object to the format used by machine learning algorithms in OpenCV.
    * \param img The Mat object to be converted
    * \param flattened_img The conversion results.
    */
   void convert_to_ml(const Mat &img, Mat &flattened_img);

   /*!
    * Extracts HOG (histogram of oriented gradients) features from a group of Mat objects.
    * \param img_lst  A vector of Mat objects from which features will be extracted.
    * \param gradient_lst The vector containing extraction results for each input Mat object.
    */
   void computeHOGFeatures(const vector<Mat> &img_lst, vector<Mat> &gradient_lst);

   /*!
    * Extracts HOG (histogram of oriented gradients) features from a Mat object.
    * \param img Image from which features will be extracted.
    * \param features Extraction results which represent HOG features.
    */
   void computeHOGFeatures(const Mat &img, Mat &features);

   /*!
    * Add a group of training samples along with their labels to the matrices that will be used to train the classifier.
    * \param train_samples A vector of images used for training the classifier.
    * \param labels A vector of labels which represent the expect result of each of the images.
    * \param trainingSamplesMat A matrix of data samples that will be used to train the classifier.
    * \param labelsMat A matrix of labeles for trainingSamplesMat.
    */
   void add(const vector<Mat> &train_samples, const vector<int> labels,Mat &trainingSamplesMat, Mat &labelsMat);

   /*!
    * Add a group of training samples which exist in a specific folder and that share the same label to
    *  the matrices that will be used to train the classifier.
    * \param dir A folder containing a set of images with the same label.
    * \param label The common label for all images in the folder.
    * \param trainingSamplesMat A matrix of data samples that will be used to train the classifier.
    * \param labelsMat A matrix of labeles for trainingSamplesMat.
    * \param useHog If true, extract hog features from images an use them as training samples instead of the actual images.
    */
    void add(const String &dirname, int label, Mat &trainingSamplesMat, Mat &labelsMat, bool useHog);

   /*!
    * \Trains a classifier.
    * \param paths Paths to folders containig training images. Each folder must only contain data of the same type.
    * \param labels Labels of the corresponding folders.
    * \param trainingSamplesMat A matrix of data samples that will be used to train the classifier.
    * \param labelsMat A matrix of labeles for trainingSamplesMat.
    * \param useHog If true, extract hog features from images an use them as training samples instead of the actual images.
    */
    bool loadDataAndLabels(QStringList paths, vector<int> labels, Mat &trainingSamplesMat, Mat &labelsMat, bool useHog);

   /*!
    * Saves a matrix to an xml file.
    * \param filename The file to which the matrix will be saved.
    * \param section The tag or section in which the matrix will be saved.
    * \param matrix The matrix to be saved.
    * \return True if the matrix was successfully saved.
    */
    bool saveMat(const String &filename, const String &section, Mat &matrix);

   /*!
    * Loads a matrix from an xml file.
    * \param filename The file from which the matrix will be loaded.
    * \param section The tag or section in which the matrix is saved.
    * \param matrix The matrix that will contain the loaded data.
    * \return True if the matrix was successfully loaded.
    */
    bool loadMat(const String &filename, const String &section, Mat &matrix);

#endif // GRHELPERIMAGEPROCESSINGFUNCTIONS_H
