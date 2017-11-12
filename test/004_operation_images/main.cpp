#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char * argv[])
{
	Mat img; 
	Mat dst;
	img = cv::imread(argv[1],cv::IMREAD_COLOR);


	cv::namedWindow("image",cv::WINDOW_NORMAL);
	imshow("image",img);
	cv::waitKey();

	cout<<img.size<<endl;
	cout<<img.channels()<<endl;
	Vec3b intensity = img.at<Vec3b>(Point(img.rows/2,img.cols/2));
	int blue  = intensity.val[0];
	int green = intensity.val[1];
	int red   = intensity.val[2];
	cout<<intensity<<endl;
	cout<<blue<<endl;
	cout<<green<<endl;
	cout<<red<<endl;

        cv::cvtColor(img, dst,cv::COLOR_BGR2HSV);
	cv::namedWindow("dst",cv::WINDOW_NORMAL);
	imshow("dst",dst);
	cv::waitKey();

	Rect r(10,10,50,50);
	Mat roi = img(r);
	cv::imwrite("rect.jpg", roi);
	cv::namedWindow("roi",cv::WINDOW_NORMAL);
	imshow("roi",roi);
	cv::waitKey();

	return 0;
	
}

