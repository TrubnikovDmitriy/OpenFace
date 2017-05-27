//
// Created by dmitriy on 10.05.17.
//

#ifndef OPENFACE_UTILS_HPP
#define OPENFACE_UTILS_HPP

#include <opencv2/core/types.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

#define ICON_SIZE QSize(100, 100)
#define BUTTON_SIZE QSize(10, 50)
#define MIN_WINDOW_SIZE QSize(10, 10)
#define MASK_NUMBER 3
#define MIN_THRESEHOLD 100
#define MAX_THRESEHOLD 255


// Global variables
static cv::String face_cascade_name = "../haarcascades/haarcascade_frontalface_default.xml";
static cv::String eyes_cascade_name = "../haarcascades/haarcascade_eye_tree_eyeglasses.xml";
static cv::CascadeClassifier face_cascade;
static cv::CascadeClassifier eyes_cascade;

class MyException {
public:
    MyException(std::string name = "file!"):
            error("Can't load ") { error += name; }

    void ShowError() { std::cout << error << std::endl; }

private:
    std::string error;
};

#endif //OPENFACE_UTILS_HPP
