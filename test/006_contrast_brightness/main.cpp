#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
   double alpha; //contrast control
   double beta;  //brightness control
   double gamma ;//for gamma correction nolinear transform 
   String imagename = "../../data/for_brightness.jpg"; 
   cv::Mat srcimg = cv::imread(imagename,cv::IMREAD_COLOR);
   cv::resize(srcimg, srcimg, Size(600,600) );
   cv::Mat dstimg = cv::Mat::zeros(srcimg.size(), srcimg.type());
   cv::Mat dst2img = cv::Mat::zeros(srcimg.size(), srcimg.type());

   std::cout<<"input alpha for contrast control [1-3]:"<<endl;
   cin >> alpha; 
   std::cout<<"input beta for brightness control [0-100]:"<<endl;
   cin >> beta;
   std::cout<<"gamma correction [0-100]:"<<endl;
   cin >> gamma;
    
   //==========================================    
   //linear transform 
   //==========================================    
   for (int i = 0; i < srcimg.rows; i++) {
      for (int j = 0; j < srcimg.cols; j++) {
         for (int c = 0; c < srcimg.channels(); c++) {
	    dstimg.at<Vec3b>(i,j)[c] = cv::saturate_cast<uchar>(alpha * srcimg.at<Vec3b>(i,j)[c] + beta);
         }
      }   
   }
   

   //==========================================    
   //gamma nonlinear transform 
   //==========================================    
   double t;   
   t = (double)cv::getTickCount(); 
   for (int i = 0; i < srcimg.rows; i++) {
      for (int j = 0; j < srcimg.cols; j++) {
         for (int c = 0; c < srcimg.channels(); c++) {
	    dst2img.at<Vec3b>(i,j)[c] = cv::saturate_cast<uchar>(pow(srcimg.at<Vec3b>(i,j)[c]/255.0,gamma)*255.0 );
         }
      }   
   }
   t = 1000*((double)cv::getTickCount() - t)/cv::getTickFrequency()/100; 
   std::cout<<"time for pixelwise gamma correction: "<<t<<endl;

   //==========================================    
   //gamma nonlinear transform  by LUT
   //==========================================    
   double t2;
   t2 = (double)cv::getTickCount(); 
   Mat LookUpTable(1,256,CV_8U);
   uchar *p = LookUpTable.ptr();
   for (int i = 0; i < 256; i++) {
      p[i] = saturate_cast<uchar>(pow(i/255.0,gamma)*255.0);
   }
   Mat dst3img = srcimg.clone();
   LUT(srcimg,LookUpTable,dst3img);
   t2 = 1000*((double)cv::getTickCount() - t2)/cv::getTickFrequency()/100; 
   std::cout<<"time for lookuptable gamma correction: "<<t2<<endl;

   //==========================================    
   //accelerate ratio
   //==========================================    
   double ratio; 
   ratio = t/t2; 
   std::cout<<"accelerate ratio: "<<ratio<<endl;

   //==========================================    
   //imshow 
   //==========================================    
   cv::namedWindow("srcimg",cv::WINDOW_AUTOSIZE);
   cv::imshow("srcimg", srcimg);
   cv::waitKey();
   cv::namedWindow("dstimg",cv::WINDOW_AUTOSIZE);
   cv::imshow("dstimg", dstimg);
   cv::waitKey();
   cv::namedWindow("dst2img",cv::WINDOW_AUTOSIZE);
   cv::imshow("dst2img", dst2img);
   cv::waitKey();
   cv::namedWindow("dst3img",cv::WINDOW_AUTOSIZE);
   cv::imshow("dst3img", dst3img);
   cv::waitKey();
   


}
