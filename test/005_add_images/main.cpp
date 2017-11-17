#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace cv;

int main(int argc, char * argv[])
{
   double input; 
   double alpha, beta;
   alpha  = 0;
   string img1 = "../../data/monalisa.jpg";
   string img2 = "../../data/len_top.jpg";
   Mat src1 = cv::imread(img1,cv::IMREAD_COLOR);
   Mat src2 = cv::imread(img2,cv::IMREAD_COLOR);
   cv::resize(src1, src1, Size(1000,1000));
   cv::resize(src2, src2, Size(1000,1000));
   
   Mat dst;

   std::cout<<"please input a nubmer between 0 and 1"<<endl;
   cin >> input ;
   if (input >= 0 && input <= 1)
       alpha = input ;
   beta = 1 - alpha;
   cv::addWeighted(src1, alpha, src2, beta, 0.0, dst);
   cv::imshow("Linear blend",src1);
   waitKey(0);
   cv::imshow("Linear blend",src2);
   waitKey(0);
   cv::imshow("Linear blend",dst);
   waitKey(0);
   return 0;
}

