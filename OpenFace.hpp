#ifndef OPENFACE_OPENFACE_HPP
#define OPENFACE_OPENFACE_HPP

#include <QtCore/QObject>
#include "facemask.hpp"
#include "Interface.hpp"

class OpenFace: public QWidget {
Q_OBJECT

public:
    OpenFace();
    ~OpenFace();

    void ChangeMask(int mask_id);
    void MakePhoto();
    bool NextStep();

private:
    void getPivotPoints(cv::Mat frame);

    std::vector<FaceMask*> data_face;
    std::vector<cv::Point> pivot_points;
    cv::VideoCapture capture;
    FaceMask* current_mask;
    Interface* interface;
    cv::Mat frame;
    bool isActive;

public slots:
    void change_mask(int mask_id);
    void close();
//    void make_photo();
signals:
    void send_frame(cv::Mat &frame);
};



#endif //OPENFACE_OPENFACE_HPP
