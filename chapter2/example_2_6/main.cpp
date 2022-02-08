#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main()
{
    cv::Mat img1, img2;

    cv::namedWindow("Example2_6-in", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Example2_6-out", cv::WINDOW_AUTOSIZE);

    img1 = cv::imread("picture.jpg");
    cv::imshow("Example2_6-in", img1);

    cv::pyrDown(img1, img2, cv::Size(img1.cols/2, img1.rows/2));

    cv::imshow("Example2_6-out", img2);

    cv::waitKey(0);
    return 0;
}
