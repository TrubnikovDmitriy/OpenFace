//
// Created by dmitriy on 10.05.17.
//

#ifndef OPENFACE_UTILS_HPP
#define OPENFACE_UTILS_HPP

#include <opencv2/core/types.hpp>
#include <iostream>
#include <opencv2/objdetect.hpp>


// Global variables
static cv::String face_cascade_name = "/home/dmitriy/Applications-CV/opencv-3.2.0/data/haarcascades/haarcascade_frontalface_alt.xml";
static cv::String eyes_cascade_name = "/home/dmitriy/Applications-CV/opencv-3.2.0/data/haarcascades/haarcascade_eye_tree_eyeglasses.xml";
static cv::CascadeClassifier face_cascade;
static cv::CascadeClassifier eyes_cascade;

static cv::String window_name2 = "Capture - Face detection2";


class MyException {
public:
    MyException(std::string name = "file!"):
            error("Can't load ") { error += name; }

    void ShowError() { std::cout << error << std::endl; }

private:
    std::string error;
};

#endif //OPENFACE_UTILS_HPP
