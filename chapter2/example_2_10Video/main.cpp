#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main()
{


    cv::namedWindow("Example2-10", cv::WINDOW_AUTOSIZE);

    cv::VideoCapture cap;

    cap.open(0);

    if(!cap.isOpened()){
        std::cerr << "Ошибка при открытии устройства захвата." << std::endl;
        return -1;
    }

    cv::Mat frame;
    for(;;){
        cap>>frame;
        if(frame.empty())break;
        cv::imshow("Example2-10", frame);
        if(cv::waitKey(33) >=0) break;
    }


    return 0;
}
