#ifndef GRDETECTOR_H
#define GRDETECTOR_H

#include "opencv2/opencv.hpp"
using namespace  cv;

/*!
 * \brief The GRDetector class is used to detect a possible hand in an image.
 *
 * The GRDetector class is used to detect a candidate hand in an image
 * by using thresholding and background substraction.
 */
class GRDetector
{
public:

    /*!< Constructs a GRDetector object. */
    GRDetector();

    /*!
     * Sets the color range for the thresholding process.
     * \param LR Lower red value.
     * \param LG Lower green value.
     * \param LB Lower blue value.
     * \param UR Upper red value.
     * \param UG Upper green value.
     * \param UB Upper blue value.
     */
    void setColorThresholds(unsigned char LR, unsigned char LG, unsigned char LB,
                       unsigned char UR, unsigned char UG, unsigned char UB);

    /*!
     * Sets the background image that will be substracted
     * from next images to detect a new object in the view.
     * \param bg The background image.
     */
    void setBackground(Mat bg);

    /*!
     * Sets the threshold used to determine if a pixel belongs to a new object
     * in the view.
     * \param threshold The threshold to be used.
     */
    void setBackgroundThreshold(int threshold);

    /*!
     * Include background substraction in the detection process.
     */
    void activateBackgroundSubstraction();

    /*!
     * Exclude background substraction from the detection process.
     */
    void deactivateBackgroundSubstraction();

    /*!
     * Detects candidate hand object in the view.
     * \param frame The image in which hand will be detected.
     * \param mask A binary image whose pixel values are 255 when
     * the corresponding pixel in "frame" belogns to a candidate hand.
     * \param maskedImage A colored image whose pixels' values are the
     * same as the corresponding pixlels' values in "frame" when the
     * corresponding pixlels' values in "mask" and zero otherwise.
     * \return true when a candidate hand is detected.
     */
    bool detect(Mat &frame, Mat &mask, Mat &maskedImage);

private:
   unsigned char LR;/*!< Lower red value. */
   unsigned char LG;/*!< Lower green value. */
   unsigned char LB;/*!< Lower blue value. */
   unsigned char UR;/*!< Upper red value. */
   unsigned char UG;/*!< Upper green value. */
   unsigned char UB;/*!< Upper blue value. */
   int backgroundThreshold; /*!< Background threshold. */
   bool backgroundSet; /*!< A flag that indicates that a background image is set. */
   bool backgroundSubstractionActivated;/*!< A flag that indicates that  background substraction is included in the detection process. */
   Mat background; /*!< The background image. */
};

#endif // GRDETECTOR_H
