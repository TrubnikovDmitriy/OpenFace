#ifndef OPENFACE_OPENFACE_HPP
#define OPENFACE_OPENFACE_HPP

#include "facemask.hpp"

class OpenFace {
public:
    OpenFace();
    ~OpenFace();

    void ChangeMask(FaceMask* new_mask);
    void MakeMask(cv::Mat frame);
    void MakePhoto();

private:
    FaceMask* current_mask;
    std::vector<cv::Point> getPivotPoints(cv::Mat frame);
};

#endif //OPENFACE_OPENFACE_HPP
