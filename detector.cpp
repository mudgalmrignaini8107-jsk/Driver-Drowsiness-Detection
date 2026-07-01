#include "DrowsinessDetector.h"
#include <opencv2/opencv.hpp>

DrowsinessDetector::DrowsinessDetector()
{
    threshold = 0.23;
    frameCounter = 0;
}

double DrowsinessDetector::calculateEAR(const std::vector<cv::Point2f>& eye)
{
    double A = cv::norm(eye[1] - eye[5]);
    double B = cv::norm(eye[2] - eye[4]);
    double C = cv::norm(eye[0] - eye[3]);

    return (A + B) / (2.0 * C);
}

bool DrowsinessDetector::isDrowsy(double ear)
{
    if (ear < threshold)
        frameCounter++;
    else
        frameCounter = 0;

    return frameCounter > 20;
}