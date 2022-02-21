#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

using namespace std;


int main()
{
    uchar mydata[]={1, 2, 1, 1, 2, 1, 1, 2, 1};
    cv::Mat mymat(3,3, CV_8UC(1), mydata);

    std::cout << "mat\n " << mymat << "\n\n";


     cv::Vec<int, 3> vec(1, 2, 3);
     std::cout << "Vect: "<<vec<<"\n\n";

     /*std::cout << vec * mymat << std::endl; Перемножить не получается
      std::cout << mymat* vec << std::endl; */

     cv::Mat m(3,1, CV_8UC(1), mydata);
     std::cout << "mat[3,1]"<< "\n" << m << "\n\n";

     cv::Mat z(vec);
     std::cout << "cast Vect to Mat\n" << z << "\n\n";

     cv::Mat one_channel_massive= cv::Mat::eye(10, 10, CV_32FC1); //одноканальный массив
     std::cout << one_channel_massive << std::endl;
     std::cout << "Елемент (3,3) равен: " << one_channel_massive.at<float>(3,3) << "\n\n ";

     cv::Mat multi_channel_massive = cv::Mat::eye(10, 10, CV_32FC2); //многоканальный массив(каждый элемент cv::Mat совокупность нескольких чисел)

     std::cout << "Елемент 3,3 равен: " << multi_channel_massive.at<cv::Vec2f>(3,3)[0]
                                        << multi_channel_massive.at<cv::Vec2f>(3,3)[1] << "\n\n";

}
