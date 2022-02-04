#include <iostream>

using namespace std;
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

int main(){
    cv::Mat img = cv::imread("neon.jpg");
    if(img.empty()) return -1;
    cv::namedWindow("Example1", cv::WINDOW_AUTOSIZE);
    cv::imshow("Example1", img);
    cv::waitKey( 0 );
    cv::destroyWindow( "Example1");
    return 0;
}
