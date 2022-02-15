#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main(){
    int SliderValue  = 1;

    cv::namedWindow("Exercies_5", cv::WINDOW_AUTOSIZE);
    cv::resizeWindow("Exercies_5", 520, 380);

    cv::createTrackbar("Subdiscr", "Exercies_5", &SliderValue, 8);

    cv::VideoCapture capture(0); //  0 camera index

    cv::Mat original_image, reduced_image;

    for(;;){
        capture >> original_image;
            for(int i = 0; i != SliderValue; i++){
                cv::pyrDown(original_image, reduced_image);

                original_image = reduced_image;
            }

        cv::imshow("Exercies_5", reduced_image);

        char c = cv::waitKey(10);

        if(c == 27) break;
    }

    return 0;
}
