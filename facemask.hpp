#ifndef OPENFACE_FACEMASK_HPP
#define OPENFACE_FACEMASK_HPP

#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <vector>

class FaceMask {
public:
    FaceMask(std::string name);
    virtual ~FaceMask() {};

    virtual void SetMask(std::vector<cv::Point> &_points,
                         cv::Mat frame) = 0;
    cv::Mat getIco();

protected:
    cv::Mat ico;
    cv::Mat original_object;
    cv::Mat transform_object;
    cv::Mat mask;
};

class Glasses: public FaceMask {
public:
    Glasses();
    ~Glasses();

    void SetMask(std::vector<cv::Point> &_points, cv::Mat frame);

private:
    cv::Point2f* OriginalPoints;
};

#endif //OPENFACE_FACEMASK_HPP
