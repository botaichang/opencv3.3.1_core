#include <stdio.h>
#include <opencv2/opencv.hpp>
#include </usr/include/c++/4.8/iostream>

using namespace cv; 
using namespace std;

int main()
{
  Mat M(2,3,CV_8UC3,Scalar(232,0,255)); 
  std::cout<< "M = "<<endl<< " "<< M <<endl;
  
  //===================================================
  // create 
  //===================================================
  M.create(4,4,CV_8UC(1));
  cout<< "M = "<<endl<< " "<< M <<endl;


  //===================================================
  // eye 
  //===================================================
  Mat E = Mat::eye(4, 4, CV_64F);
  cout<< "E = "<<endl<< " "<< E <<endl;

  //==================================================
  // ones  
  //===================================================
  Mat One = Mat::ones(4, 4, CV_64F);
  cout<< "One = "<<endl<< " "<< One <<endl;

  //==================================================
  // zeros 
  //===================================================
  Mat Zero = Mat::zeros(4, 4, CV_8UC1);
  cout<< "Zero = "<<endl<< " "<< Zero <<endl;

  Mat C = (Mat_<double>(3,3) << 0,1,2, 4,3,2, 3,2,1);
  cout<< "C = "<< endl << C << endl;

  //==================================================
  // row  
  //===================================================
  Mat Rowclone = C.row(2).clone();
  cout<< "C Row 1 = "<< endl << Rowclone << endl;

  //==================================================
  // random 
  //===================================================
  Mat R = Mat(3,2,CV_8UC2);
  randu(R,Scalar::all(0),Scalar::all(255));
  cout<< "R = "<< endl << R << endl;
  cout<< "R numpy = " << endl << format(R,Formatter::FMT_NUMPY)<<endl;

  Point2f P(5,1);
  cout<< "Point 2D = " << P <<endl;
  
  Point3f P3f(2,6,7);
  cout<< "Point 3D = " << P3f <<endl;

  vector<float> v;
  v.push_back((float)CV_PI);
  v.push_back(2.01f);
  v.push_back(3.01f);
  cout<< "Vector of floats via Mat = \n"<< Mat(v) <<endl;
 

  

  return 0;
}
