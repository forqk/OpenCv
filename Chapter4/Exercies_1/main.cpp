#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/core/types_c.h>
#include <string>

using namespace std;

int main(){
  int first_point_x = 0;
  int first_point_y = 20;

  int first_point_rectangle_y = 10;
  int last_point_rectangle_y = 10;

 cv::Mat_<char> img(500, 500, CV_8UC1);

 imshow("My window", img);

 char symbol = cv::waitKey(0);

 while(symbol != 27){ //esc
     if(first_point_x <= img.rows && first_point_y <= img.cols){
        if(std::isdigit(symbol)){
            cv::putText(img, std::string(1, symbol), {first_point_x, first_point_y+3}, 1,1, {255, 0,0}, 1, 1);

            cv::rectangle(img, {first_point_x, first_point_rectangle_y}, {first_point_x+10, last_point_rectangle_y+15}, {255,0,0}, 1, 1, 0);

            first_point_x += 10;
        }

        if(symbol == '\r'){ //enter

            first_point_x = 0;
            first_point_y += 20;

            first_point_rectangle_y += 20;
            last_point_rectangle_y +=20;
        }

        if(symbol == '\b'){ //backspace
            std::cout << "first_point_x: " << first_point_x << " first_point_rectangle_y: " << first_point_rectangle_y << std::endl;


            for(int x =  first_point_x-9; x <= first_point_x+10; x++){ // -9 вместо -10, чтобы граница рамки не стиралась.
                for(int y = first_point_y-10; y <= first_point_y+20; y++){
                    img.at<uchar>(y,x) = 000;
                }
            }

            first_point_x -= 10;

        }

        imshow("My window", img);
     }

     symbol = cv::waitKey(0);
 }

  cv::waitKey(0);
  return 0;
}
