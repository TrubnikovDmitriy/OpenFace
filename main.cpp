#include <opencv2/objdetect.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>
#include "facemask.hpp"
#include "Utils.hpp"


// Function Headers
std::vector<cv::Point> detect(cv::Mat frame);


// Global variables
cv::String face_cascade_name = "/home/dmitriy/Applications-CV/opencv-3.2.0/data/haarcascades/haarcascade_frontalface_alt.xml";
cv::String eyes_cascade_name = "/home/dmitriy/Applications-CV/opencv-3.2.0/data/haarcascades/haarcascade_eye_tree_eyeglasses.xml";
cv::CascadeClassifier face_cascade;
cv::CascadeClassifier eyes_cascade;
cv::String window_name2 = "Capture - Face detection2";


int main( void )
{
    cv::VideoCapture capture;
    cv::Mat frame;

    if( !face_cascade.load( face_cascade_name ) ) {
        std::cout << "Error loading face cascade" << std::endl;
        return EXIT_FAILURE;
    }
    if( !eyes_cascade.load( eyes_cascade_name ) ) {
        std::cout << "Error loading eyes cascade" << std::endl;
        return EXIT_FAILURE;
    }


    capture.open( -1 );
    if ( ! capture.isOpened() ) {
        std::cout << "Error opening video capture" << std::endl;
        return EXIT_FAILURE;
    }
    FaceMask* currrent_object;
    Glasses glass;
    currrent_object = &glass;

    try {

        std::vector<cv::Point> points;
        while ( capture.read(frame) )
        {

//            frame = imread("./masks/jenya.jpg");

            if( frame.empty() )
            {
                std::cout << "No captured frame!" << std::endl;
                break;
            }

            points = detect(frame);
            currrent_object->SetMask(points, frame);
            imshow(window_name2, frame);


            int c = cv::waitKey(33);
            if( c == 27 )
                break; // escape
        }

    }
    catch(MyException except) {
        except.ShowError();
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}


std::vector<cv::Point> detect(cv::Mat frame) {
    std::vector<Rect> faces;
    Mat frame_gray;

    Point center(-1, -1);
    Point eye_center_1(-1, -1);
    Point eye_center_2(-1, -1);
    Point down(-1, -1);

    cvtColor( frame, frame_gray, COLOR_BGR2GRAY );
    equalizeHist( frame_gray, frame_gray );

    //-- Detect faces
    face_cascade.detectMultiScale( frame_gray, faces, 1.1, 2, 0, Size(10, 10) );

    for( size_t i = 0; i < faces.size(); i++ )
    {
        Mat faceROI = frame_gray( faces[i] );
        std::vector<Rect> eyes;

        Scalar blue(250, 250, 0);

//        line(frame, Point(faces[i].x, faces[i].y), Point(faces[i].x + faces[i].width, faces[i].y), blue, 2, 8, 0);
//        line(frame, Point(faces[i].x, faces[i].y), Point(faces[i].x, faces[i].y + faces[i].height), blue, 2, 8, 0);
//        line(frame, Point(faces[i].x + faces[i].width, faces[i].y + faces[i].height),
//                    Point(faces[i].x + faces[i].width, faces[i].y), blue, 2, 8, 0);
//        line(frame, Point(faces[i].x + faces[i].width, faces[i].y + faces[i].height),
//                    Point(faces[i].x, faces[i].y + faces[i].height), blue, 2, 8, 0);




        //-- In each face, detect eyes
        eyes_cascade.detectMultiScale( faceROI, eyes, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(15, 15), Size() );
        if( eyes.size() ==  2)
        {
            //-- Draw the face

            center.x = faces[i].x + faces[i].width / 2;
            center.y = faces[i].y + faces[i].height * 2 /3;
            eye_center_1.x = faces[i].x + eyes[1].x + eyes[1].width/2;
            eye_center_1.y = faces[i].y + eyes[1].y + eyes[1].height/2;
            eye_center_2.x = faces[i].x + eyes[2].x + eyes[2].width/2;
            eye_center_2.y = faces[i].y + eyes[2].y + eyes[2].height/2;
            down.x = faces[i].x + faces[i].width / 2;
            down.y = faces[i].y + faces[i].height;
        }

    }
    vector<Point> points = { center, eye_center_1, eye_center_2, down };
    return points;
}
void DrawsLines(std::vector<cv::Point> points, cv::Mat frame) {

    Scalar yellow(0, 250, 250);
    Scalar red(167, 50, 150);

    if (!(points[1].x > points[0].x && points[2].x > points[0].x) &&
        !(points[1].x < points[0].x && points[2].x < points[0].x) ) {

        line(frame, points[1], points[2], yellow, 2, 8, 0);
        line(frame, points[1], points[0], yellow, 2, 8, 0);
        line(frame, points[2], points[0], yellow, 2, 8, 0);
        line(frame, points[2], points[3], yellow, 2, 8, 0);
        line(frame, points[1], points[3], yellow, 2, 8, 0);
        line(frame, points[3], points[0], yellow, 2, 8, 0);
    }
}