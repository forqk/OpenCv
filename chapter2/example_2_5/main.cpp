#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main()
{
    cv::Mat image = cv::imread("picture.jpg");
    cv::namedWindow("Example2_5-in", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Example2_5-out", cv::WINDOW_AUTOSIZE);

    cv::imshow("Example2_5-in", image);

    cv::Mat out;

    cv::GaussianBlur(image, out, cv::Size(5, 5), 3, 3);
    cv::GaussianBlur(out, out, cv::Size(5,5), 3, 3);

    cv::imshow("Example2_5-out", out);

    cv::waitKey(0);
    return 0;
}
