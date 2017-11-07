cmake_minimum_required(VERSION 2.8)
set(OpenCV_DIR "/home/mli/opencv-3.3.1/build")
#set(OpenCV_INCLUDE_DIRS "/home/mli/opencv-3.3.1/include")
#include_directories( ${OpenCV_INCLUDE_DIRS})
#
#set(OpenCV_LIBS_DIR "/home/mli/opencv-3.3.1/build/lib")
#link_directories($OpenCV_LIBS_DIR)

#set(OpenCV_LIBS opencv_core opencv_imgproc opencv_calib3d opencv_video opencv_features2d opencv_ml opencv_highgui opencv_objdetect opencv_contrib opencv_legacy )

project(DisplayImage)
find_package( OpenCV REQUIRED )
add_executable(DisplayImage DisplayImage.cpp)
target_link_libraries(DisplayImage ${OpenCV_LIBS})
