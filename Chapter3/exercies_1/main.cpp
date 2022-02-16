#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

using namespace std;


int main()
{
    float testNumber = -2.4567;

    std::cout << "original_number: " << testNumber << std::endl;

    std::cout << "cv_abs: " <<cv::cv_abs(testNumber) << std::endl;

    std::cout <<"cvRound" <<  cvRound(testNumber) << std::endl;

    std::cout <<"cvFloor" <<  cvFloor(testNumber)<< std::endl;

    cv::RNG rng;

    double first = rng.uniform(1., 10.); // . - double, 1.f - float
    double second = rng.uniform(10., 50.);

    std::cout << "first rand: " << first << ", second rand: " << second << std::endl;

    cv::Point2f TestPoint2f(first, second);

    std::cout << "Point2f: " << TestPoint2f << std::endl;

    std::cout << "Point: " << static_cast<cv::Point>(TestPoint2f) << std::endl;

    std::cout << "Point2f: " << static_cast<cv::Point2f>(static_cast<cv::Point>(TestPoint2f)) << std::endl;

    return 0;
}
