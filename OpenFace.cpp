#include <cassert>

#include "OpenFace.hpp"
#include "Interface.hpp"
#include "facemask.hpp"
#include "Utils.hpp"


OpenFace::OpenFace() {

    data_face = {

            new Glasses,
            new Glasses_Blue,
            new Glasses_Red
    };
    current_mask = data_face[0];

    if( !face_cascade.load( face_cascade_name ) ) {
        std::cout << "Error loading face cascade" << std::endl;
        throw MyException("face cascade");
    }
    if( !eyes_cascade.load( eyes_cascade_name ) ) {
        std::cout << "Error loading eyes cascade" << std::endl;
        throw MyException("eyes cascade");
    }

    capture.open( -1 );
    if ( ! capture.isOpened() ) {
        std::cout << "Error opening video capture" << std::endl;
        throw MyException("camera");

    }
    interface = new Interface((int)capture.get(cv::CAP_PROP_FRAME_WIDTH), (int)capture.get(cv::CAP_PROP_FRAME_HEIGHT));
    QObject::connect(this, SIGNAL(send_frame(cv::Mat&)), interface, SLOT(show_image(cv::Mat&)));

//    interface->show();

}
OpenFace::~OpenFace() {

    delete interface;
    for (int i = 0; i < data_face.size(); ++i)
        delete data_face[i];

}

void OpenFace::getPivotPoints(cv::Mat frame) {

    std::vector<cv::Rect> faces;
    cv::Mat frame_gray;

    cv::Point center(-1, -1);
    cv::Point eye_center_1(-1, -1);
    cv::Point eye_center_2(-1, -1);
    cv::Point down(-1, -1);

    cv::cvtColor( frame, frame_gray, cv::COLOR_BGR2GRAY );
    cv::equalizeHist( frame_gray, frame_gray );

    //-- Detect faces
    face_cascade.detectMultiScale( frame_gray, faces, 1.1, 2, 0, cv::Size(10, 10) );

    for( size_t i = 0; i < faces.size(); i++ )
    {
        cv::Mat faceROI = frame_gray( faces[i] );
        std::vector<cv::Rect> eyes;

        cv::Scalar blue(250, 250, 0);

        //-- In each face, detect eyes
        eyes_cascade.detectMultiScale( faceROI, eyes, 1.1, 2, 0 | cv::CASCADE_SCALE_IMAGE, cv::Size(15, 15), cv::Size() );
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
    pivot_points.clear();
    pivot_points = { center, eye_center_1, eye_center_2, down };
}
void OpenFace::ChangeMask(int mask_id) {

    assert((unsigned)mask_id < data_face.size());
    current_mask = data_face[mask_id];
}
void OpenFace::NextStep() {

    capture.read(frame);
    if(frame.empty())
        throw MyException("capture frame");
    getPivotPoints(frame);
    current_mask->SetMask(pivot_points, frame);
    emit send_frame(frame);
}

void OpenFace::change_mask(int mask_id) {
    ChangeMask(mask_id);
}