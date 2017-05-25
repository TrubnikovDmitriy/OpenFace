#include <cassert>
#include "OpenFace.hpp"
#include "Utils.hpp"


OpenFace::OpenFace() {

    data_face = {
            new Glasses,
            new Glasses_Red,
            new Glasses_Blue
    };
    current_mask = data_face[0];
    isActive = true;

    if(!face_cascade.load(face_cascade_name))
        throw MyException("face cascade");
    if(!eyes_cascade.load(eyes_cascade_name))
        throw MyException("eyes cascade");

    capture.open( -1 );
    if (!capture.isOpened())
        throw MyException("camera");

    interface = new Interface();
    interface->show();

    QObject::connect(this, SIGNAL(send_frame(cv::Mat&)), interface, SLOT(show_image(cv::Mat&)));
    QObject::connect(interface->signal_map, SIGNAL(mapped(int)), this, SLOT(change_mask(int)));
    QObject::connect(interface, SIGNAL(close()), this, SLOT(close()));

}
OpenFace::~OpenFace() {

    delete interface;
    for (u_int i = 0; i < data_face.size(); ++i)
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
bool OpenFace::NextStep() {

    capture.read(frame);
    if(frame.empty())
        throw MyException("frame empty");
//    frame = cv::imread("./bin/images/masks/1.jpg");
    getPivotPoints(frame);
    current_mask->SetMask(pivot_points, frame);
    // OpenCV использует канал BGR, а Qt канал RGB.
    // Для корректной цветопередачи необходимо конвертировать
    cv::cvtColor(frame, frame, cv::COLOR_BGR2RGB);
    emit send_frame(frame);
    return isActive;
}
void OpenFace::change_mask(int mask_id) {
    ChangeMask(mask_id);
}
void OpenFace::close() {
    isActive = false;
}