#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main()
{

    cv::namedWindow("Example2-11", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Log_Polar", cv::WINDOW_AUTOSIZE);
    cv::VideoCapture capture(0); //  0 camera index
  //  capture.open(0);

    double fps = capture.get(cv::CAP_PROP_FPS);
    cv::Size size(
        (int)capture.get( cv::CAP_PROP_FRAME_WIDTH),
        (int)capture.get( cv::CAP_PROP_FRAME_HEIGHT)
    );

    cv::VideoWriter writer;
    writer.open("testwrite.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), fps, size); // or  M P E G

    cv::Mat logpolar_frame, bgr_frame;

    for(;;){
        capture >> bgr_frame;

        if(bgr_frame.empty()) break;

        cv::imshow("Example2-11", bgr_frame);

        cv::logPolar( // лог полярное преобразование
                    bgr_frame,
                    logpolar_frame,
                    cv::Point2f(
                        bgr_frame.cols/2,
                        bgr_frame.rows/2),
                    40,
                    cv::WARP_FILL_OUTLIERS
                    );
        cv::imshow("Log_Polar", logpolar_frame);
        writer << logpolar_frame;
        char c = cv::waitKey(10);
        if( c == 27) break;
    }

    capture.release();

    return 0;
}


