#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main()
{
    cv::Mat img1, img2;

   // cv::namedWindow("Exercies_5", cv::WINDOW_AUTOSIZE);
   // cv::namedWindow("Example2_6-out", cv::WINDOW_AUTOSIZE);

    cv::VideoCapture capture(0); //  0 camera index

    double fps = capture.get(cv::CAP_PROP_FPS);
    cv::Size size(
        (int)capture.get( cv::CAP_PROP_FRAME_WIDTH)/2,
        (int)capture.get( cv::CAP_PROP_FRAME_HEIGHT)/2
    );

    cv::VideoWriter writer;
    writer.open("testwrite.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), fps, size); // or  M P E G

    cv::Mat original_image, reduced_image;

    for(;;){
        capture >> original_image;
        cv::pyrDown(original_image, reduced_image); //pyrDown для дискретизации применять на каждой итерации
        cv::imshow("Exercies_3", reduced_image);
        writer << reduced_image;
        char c = cv::waitKey(10);
        if(c == 27) break;
    }

    return 0;
}
