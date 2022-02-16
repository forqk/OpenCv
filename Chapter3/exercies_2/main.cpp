#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

using namespace std;


int main()
{

    cv::Ptr<cv::Matx33f> p = cv::makePtr<cv::Matx33f>();
    cv::Vec3f vec(1.1, 2.2, 3.3);

    std::cout << "Vec3f: " << vec << std::endl << '\n';

    *p = cv::Matx33f::randu(1.1, 5.5);

    std::cout << "Matrix 3x3: " << *p << std::endl << '\n';

    //Матрица на вектор перемножается, получается результирующий вектор.
    std::cout << "multiplication: " << (*p) * vec << std::endl;

    /*
     Матрица на вектор перемножается, вектор на матрицу нет.
     std::cout << "..." << vec * (*p) << std::endl;
    */

    return 0;
}
