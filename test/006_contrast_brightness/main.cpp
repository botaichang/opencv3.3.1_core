#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
   double alpha; //contrast control
   double beta;  //brightness control
   String imagename = "../../data/monalisa.jpg"; 
   cv::Mat srcimg = cv::imread(imagename,cv::IMREAD_COLOR);
   cv::Mat dstimg = cv::Mat::zeros(srcimg.size(), srcimg.type());

   std::cout<<"input alpha for contrast control [1-3]:"<<endl;
   cin >> alpha; 
   std::cout<<"input beta for brightness control [0-100]:"<<endl;
   cin >> beta;
    
   for (int i = 0; i < srcimg.rows; i++) {
      for (int j = 0; j < srcimg.cols; j++) {
         for (int c = 0; c < srcimg.channels(); c++) {
	    dstimg.at<Vec3b>(i,j)[c] = cv::saturate_cast<uchar>(alpha * srcimg.at<Vec3b>(i,j)[c] + beta);
         }
      }   
   }
   cv::namedWindow("srcimg",cv::WINDOW_NORMAL);
   cv::imshow("srcimg", srcimg);
   cv::waitKey();
   cv::namedWindow("dstimg",cv::WINDOW_NORMAL);
   cv::imshow("dstimg", dstimg);
   cv::waitKey();
   


}
