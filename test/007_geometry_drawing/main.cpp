#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#define W 400 

using namespace std; 
using namespace cv; 

void myEllipse(cv::Mat img, double angle);
void myCircle(cv::Mat img, Point center);

int main()
{
	char atom_window[] = "Drawing 1: atom";
	cv::Mat atom_img = cv::Mat::zeros(W, W, CV_8UC3);

	myEllipse(atom_img, 90);
	myEllipse(atom_img, 0);
	myEllipse(atom_img, 45);
	myEllipse(atom_img, -45);

	myCircle(atom_img, Point(W/2,W/2));

	cv::namedWindow("ellipse",WINDOW_AUTOSIZE); 
	cv::imshow("ellipse", atom_img); 
	cv::waitKey(); 
	return 0;
}

void myEllipse(cv::Mat img, double angle)
{
	float start_angle = 0; 
	float end_angle = 360;
	Scalar color = Scalar(255,0,255);//color
	float thickness = 2;
	float line_type = 8;
	float shift = 0; 

 	cv::ellipse(
	img, 
	Point(W/2,W/2),
	Size(W/4,W/16),
	angle,
	start_angle ,
	end_angle ,
	color,
	thickness,
	line_type,
	shift
	);		
}

void myCircle(cv::Mat img,Point center)
{
	float radius = W/32; 
	Scalar color = Scalar(0,0,255);//color
	float thickness = 2;
	float line_type = 8;
	float shift = 0; 

	cv::circle(
	img,
	center,
	radius,
	color,
	thickness,
	line_type,
	shift
	);	
}
