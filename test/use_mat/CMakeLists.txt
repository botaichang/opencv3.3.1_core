cmake_minimum_required(VERSION 2.8)
set(OpenCV_DIR "/home/mli/opencv-3.3.1/build")
#set(OpenCV_INCLUDE_DIRS "/home/mli/opencv-3.3.1/include")
#include_directories( ${OpenCV_INCLUDE_DIRS})
#
#set(OpenCV_LIBS_DIR "/home/mli/opencv-3.3.1/build/lib")
#link_directories($OpenCV_LIBS_DIR)

#set(OpenCV_LIBS opencv_core opencv_imgproc opencv_calib3d opencv_video opencv_features2d opencv_ml opencv_highgui opencv_objdetect opencv_contrib opencv_legacy )

project(use_mat)
find_package( OpenCV REQUIRED )
add_executable(use_mat use_mat.cpp)
target_link_libraries(use_mat ${OpenCV_LIBS})
