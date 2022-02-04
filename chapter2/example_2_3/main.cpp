#include <iostream>

using namespace std;
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

int main(){
        cv::namedWindow("Example3", cv::WINDOW_AUTOSIZE);
        cv::VideoCapture cap;
        cap.open("video.mp4");
        if(cap.isOpened() == false){
            std::cout << "video wasn't opened" << std::endl;
        }

        cv::Mat frame;
        for(;;){
            cap >> frame;
            if(frame.empty()){
                std::cout << "frame is empty";
                break;
            }
            cv::imshow("Example3", frame);
            if(cv::waitKey(33) >= 0) break;
        }

    return 0;
}
