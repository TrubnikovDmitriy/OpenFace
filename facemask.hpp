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

protected:
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
class Glasses_Red: public FaceMask {
public:
    Glasses_Red();
    ~Glasses_Red();

    void SetMask(std::vector<cv::Point> &_points, cv::Mat frame);

private:
    cv::Point2f* OriginalPoints;
};
class Glasses_Blue: public FaceMask {
public:
    Glasses_Blue();
    ~Glasses_Blue();

    void SetMask(std::vector<cv::Point> &_points, cv::Mat frame);

private:
    cv::Point2f* OriginalPoints;
};

#endif //OPENFACE_FACEMASK_HPP
