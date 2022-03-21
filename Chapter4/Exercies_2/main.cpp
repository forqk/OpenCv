#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/core/types_c.h>
#include <string>

using namespace std;

int main(){

// cv::Mat img = cv::imread("pictur.jpg");

 cv::Mat_<uchar> img(100, 200, CV_8UC1);

// std::cout << img;

 cv::randu(img, 1, 200); // img filled random dots 1-200

 //cv::imshow("test", img);

 cv::Mat_<float> submatrix(img.cols, img.rows, CV_8UC1);


 imshow("My Windom Random", img);

  //  std::cout << "original_img" << std::endl << img << std::endl << std::endl;

  for(int rows = 1; rows <= img.rows; rows++){
      for(int cols = 1; cols <= img.cols; cols++){
            cv::Mat rect = img(cv::Rect(0,0, cols, rows));
            std::cout << "rows: " << rows << " cols: " << cols << std::endl;
            float summ_pixel = cv::sum(rect)[0];
            std::cout << summ_pixel << std::endl;
            submatrix.at<float>(rows-1, cols-1) = summ_pixel;
      }
  }

  //  std::cout << "sbm" << submatrix << std::endl;
  //  imshow("My window", img);

  imshow("My window", submatrix);

  cv::waitKey(0);
  return 0;
}

