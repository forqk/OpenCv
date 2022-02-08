#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main()
{
    cv::Mat img_rgb, img_gry, img_cny;

    cv::namedWindow("Example Gray", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Example Canny", cv::WINDOW_AUTOSIZE);

    img_rgb = cv::imread("picture.jpg");

    cv::Mat out;


    cv::Mat img_pyr;
    cv::Mat img_pyr2;

    cv::cvtColor(img_rgb, img_gry, cv::COLOR_BGR2GRAY);
    cv::pyrDown(img_gry, img_pyr);
    cv::pyrDown(img_pyr, img_pyr2);

    cv::imshow( "Example Gray", img_pyr2 );

    cv::Canny(img_pyr2, img_cny, 10, 100, 3, true);
    /* так мы можем считать значения ргб в пикселе с коорд 16, 32*/
    int x = 16, y = 32;
    cv::Vec3b intensity = img_rgb.at<cv::Vec3b>(y, x);

    uchar blue = intensity[0];
    uchar green = intensity[1];
    uchar red = intensity[2];

    std::cout << "В позиции (x,y) = (" << x << ", "<< y <<
                 "): (blue, green, red) = (" <<
                 (unsigned int)blue <<
                 ", " << (unsigned int)green << ", "<<
                 (unsigned int)red << ")" << std::endl;

    std::cout <<"Полутоновый пиксель: " <<
                (unsigned int)img_gry.at<uchar>(y, x) << std::endl;
    x /= 4; y /=4;

    std::cout << "Пиксель pyramid2: " << (unsigned int)img_pyr2.at<uchar>(y,x) << std::endl;
    cv::imshow( "Example Canny", img_cny);

    cv::waitKey(0);
    return 0;
}
