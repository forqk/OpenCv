#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main()
{
    cv::Mat img1, img2;

    cv::namedWindow("Exercies_3", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("lol", cv::WINDOW_AUTOSIZE);

    cv::VideoCapture capture(0); //  0 camera index

    double fps = capture.get(cv::CAP_PROP_FPS);
    cv::Size size(
        (int)capture.get( cv::CAP_PROP_FRAME_WIDTH)/2,
        (int)capture.get( cv::CAP_PROP_FRAME_HEIGHT)/2
    );

    //cv::pyrDown(img1, img2, cv::Size(img1.cols/2, img1.rows/2));

    cv::VideoWriter writer;
    writer.open("testwrite.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), fps, size); // or  M P E G

    cv::Mat original_image, reduced_image, reduced_image2, reduced_image3, r_i4, r_i5, r_i6;

    for(;;){
        capture >> original_image;
        cv::pyrDown(original_image, reduced_image);
        cv::pyrDown(reduced_image, reduced_image2);
        cv::pyrDown(reduced_image2, reduced_image3);
        cv::pyrDown(reduced_image3, r_i4);
        cv::pyrDown(r_i4, r_i5);
        cv::pyrDown(r_i4, r_i6);

        cv::imshow("Exercies_3", r_i6);

        cv::imshow("lol", reduced_image2);

        writer << reduced_image;
        char c = cv::waitKey(10);
        if(c == 27) break;
    }

    return 0;
}
