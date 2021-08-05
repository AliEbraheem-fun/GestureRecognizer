#include "grhelperimageprocessingfunctions.h"


bool extractLargestContour(Mat& binaryImage, Mat& output, double minimumArea, Size outputSize)
{
    vector<Vec4i> hierarchy;
    vector<vector<Point>> contours;
    Mat img_resized;
    Mat newBinaryImage=Mat::zeros(binaryImage.rows,binaryImage.cols,CV_8UC1);
    Mat kernel=getStructuringElement(MORPH_ELLIPSE ,Size(3,3));
    erode(binaryImage,binaryImage,kernel);
    findContours(binaryImage,contours,hierarchy,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_NONE);
    int cnt_i=-1;
    double area_i=0;
    double area=0;
    if(contours.size()>0)
    {
        cnt_i=0;
        area_i=contourArea(contours[0]);
        for(unsigned int i=1;i<contours.size();i++)
        {
            area=contourArea(contours[i]);
            if(area>area_i)
            {
                cnt_i=i;
                area_i=area;
            }
        }
    }
    if(cnt_i!=-1&& area_i >minimumArea)
    {
        approxPolyDP(contours[cnt_i],contours[cnt_i],2,true);
        drawContours(newBinaryImage,contours,cnt_i,Scalar(255),-1);
        Rect roi=boundingRect(contours[cnt_i]);
        Mat img=Mat(newBinaryImage,roi);
        resize(img,output,outputSize);
        return true;
    }
    return false;
}

bool getMaskedImage(Mat& img,Mat &mask, Mat &maskedImage)
{
    if(mask.type()!=CV_8UC1 || img.size() != mask.size())
    {
        return false;
    }
    maskedImage=Mat::ones(img.rows,img.cols,CV_8UC3);
    for(int i=0;i<img.cols;i++)
    {
        for(int j=0;j<img.rows;j++)
        {

            if(mask.at<unsigned char>(i,j)>0)
            {
                maskedImage.at<Vec3b>(i,j)=img.at<Vec3b>(i,j);
            }
        }
    }
    return true;
}

void load_images(const String &dirname, vector<Mat> &img_lst, bool showImages)
{
    vector< String > files;
    glob( dirname, files );
    for ( size_t i = 0; i < files.size(); ++i )
    {
        Mat img = imread( files[i] ); // load the image
        if ( img.empty() )            // invalid image, skip it.
        {
            cout << files[i] << " is invalid!" << endl;
            continue;
        }
        if ( showImages )
        {
            imshow( "image", img );
            waitKey( 1000 );
        }
        img_lst.push_back( img );
    }
}

void convert_to_ml(const vector<Mat> &train_samples, Mat &trainData)
{
    Mat img;
    Mat flattened_img;
    for(size_t i=0;i<train_samples.size();i++)
    {
        img=train_samples[i];
        convert_to_ml(img,flattened_img);
        trainData.push_back(flattened_img);
    }
}

void convert_to_ml(const Mat &img, Mat &flattened_img)
{
    Mat f32_img;
    img.convertTo(f32_img,CV_32F);
    flattened_img = f32_img.reshape(1, 1);
}

void computeHOGFeatures(const vector<Mat> &img_lst, vector<Mat> &gradient_lst)
{
    Mat features;
    for( size_t i=0 ; i< img_lst.size(); i++ )
    {
        computeHOGFeatures(img_lst[i],features);
        gradient_lst.push_back( features );
    }
}

void computeHOGFeatures(const Mat &img, Mat &features)
{
    Mat gray;
    static HOGDescriptor hog;
    vector< float > descriptors;
    resize(img,gray,Size(75,75));
    hog.winSize=Size(64,64);
    hog.blockSize=Size(8,8);
    hog.blockStride=Size(4,4);
    hog.cellSize=Size(4,4);
    hog.compute( gray, descriptors, Size( 4, 4 ), Size( 0, 0 ) );
    features=Mat( descriptors ).clone();
    convert_to_ml(features,features);
}

void add(const vector<Mat> &train_samples, const vector<int> labels, Mat &trainingSamplesMat, Mat &labelsMat)
{
    Mat tmp;
    for(size_t i=0;i<train_samples.size();i++)
    {
        convert_to_ml(train_samples[i],tmp);
        trainingSamplesMat.push_back(tmp);
        labelsMat.push_back(labels[i]);
    }
}

void add(const String &dirname, int label, Mat &trainingSamplesMat, Mat &labelsMat,bool useHog)
{
    vector< Mat >  img_lst;
    vector<Mat> tmp;
    vector<int> lbl;
    cout<<label<<endl;
    load_images(dirname,img_lst,false);
    for(size_t i=0;i<img_lst.size();i++)
    {
        lbl.push_back(label);
    }
    if(useHog)
    {
        computeHOGFeatures(img_lst,tmp);
        add(tmp,lbl,trainingSamplesMat,labelsMat);

    }
    else
    {
        add(img_lst,lbl,trainingSamplesMat,labelsMat);

    }
}

bool loadDataAndLabels(QStringList paths, vector<int> labels, Mat &trainingSamplesMat, Mat &labelsMat, bool useHog)
{
    QDir *dir;
    Mat tmp;
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
        add(paths[i].toStdString().data(),labels[i],trainingSamplesMat,labelsMat,useHog);
    }
    return true;
}


bool saveMat(const String &filename, const String &section, Mat &matrix )
{
    FileStorage file(filename, FileStorage::WRITE);
    if(!file.isOpened())
    {
        file.release();
        return false;
    }
    file<<section<<matrix;
    file.release();
    return true;
}

bool loadMat(const String &filename, const String &section, Mat &matrix)
{
    FileStorage file(filename, cv::FileStorage::READ);
    if (!file.isOpened())
    {
        file.release();
        return false;
    }
    file[section] >> matrix;
    file.release();
    return true;
}
