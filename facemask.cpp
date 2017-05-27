#include "facemask.hpp"
#include "Utils.hpp"


FaceMask::FaceMask(std::string name):
        original_object(cv::imread(name)) {

    if (original_object.cols == 0 || original_object.rows == 0)
        throw MyException(name);
}


Glasses::Glasses(): FaceMask("../masks/glass_0.png") {

    OriginalPoints = new cv::Point2f[3];
    OriginalPoints[0] = cv::Point2f(620, 520);
    OriginalPoints[1] = cv::Point2f(1350, 520);
    OriginalPoints[2] = cv::Point2f(620, 570);
}
Glasses::~Glasses() {

    delete[] OriginalPoints;
}
void Glasses::SetMask(std::vector<cv::Point> &points, cv::Mat frame) {

    if ((points[1].x > points[0].x && points[2].x > points[0].x) ||
        (points[1].x < points[0].x && points[2].x < points[0].x) )
        return; // Чтобы очки не съезжали на один глаз.

    mask = cv::Mat::zeros(frame.size(),
                          original_object.type());
    mask.copyTo(transform_object);

    float length = OriginalPoints[1].x - OriginalPoints[0].x;
    float width = OriginalPoints[2].y - OriginalPoints[1].y;

    float dx = abs(points[1].x - points[2].x);
    float dy = points[2].y - points[1].y;
    float new_length = (float)sqrt(dx*dx + dy*dy);
    float new_width = new_length / length * width;
    float sin = dy / new_length;
    float cos = dx / new_length;

    cv::Point down_point;
    if (points[1].x < points[2].x) {
        down_point.x = points[1].x - int(new_width * sin);
        down_point.y = points[1].y + abs((int)(new_width * cos));
    }
    else {
        down_point.x = points[1].x + int(new_width * sin);
        down_point.y = points[1].y + abs((int)(new_width * cos));
    }

    cv::Point2f TransformPoints[3] = {
            points[1],
            points[2],
            down_point
    };

    cv::Mat affine = getAffineTransform(OriginalPoints, TransformPoints);
    warpAffine(original_object, transform_object, affine, transform_object.size(),
               cv::INTER_AREA, cv::BORDER_CONSTANT, cv::Scalar(255,255,255));

    threshold(transform_object, mask, MIN_THRESEHOLD,
              MAX_THRESEHOLD, CV_THRESH_BINARY_INV);
    transform_object.copyTo(frame, mask);
}

Glasses_Red::Glasses_Red():
        FaceMask("../masks/glass_1.png"),
        black_original(cv::imread("../masks/glass_0.png")) {

    OriginalPoints = new cv::Point2f[3];
    OriginalPoints[0] = cv::Point2f(620, 520);
    OriginalPoints[1] = cv::Point2f(1350, 520);
    OriginalPoints[2] = cv::Point2f(620, 570);
}
Glasses_Red::~Glasses_Red() {

    delete[] OriginalPoints;
}
void Glasses_Red::SetMask(std::vector<cv::Point> &points, cv::Mat frame) {

    if ((points[1].x > points[0].x && points[2].x > points[0].x) ||
        (points[1].x < points[0].x && points[2].x < points[0].x) )
        return; // Чтобы очки не съезжали на один глаз.

    mask = cv::Mat::zeros(frame.size(),
                          original_object.type());
    mask.copyTo(transform_object);

    float length = OriginalPoints[1].x - OriginalPoints[0].x;
    float width = OriginalPoints[2].y - OriginalPoints[1].y;

    float dx = abs(points[1].x - points[2].x);
    float dy = points[2].y - points[1].y;
    float new_length = (float)sqrt(dx*dx + dy*dy);
    float new_width = new_length / length * width;
    float sin = dy / new_length;
    float cos = dx / new_length;

    cv::Point down_point;
    if (points[1].x < points[2].x) {
        down_point.x = points[1].x - int(new_width * sin);
        down_point.y = points[1].y + abs((int)(new_width * cos));
    }
    else {
        down_point.x = points[1].x + int(new_width * sin);
        down_point.y = points[1].y + abs((int)(new_width * cos));
    }

    cv::Point2f TransformPoints[3] = {
            points[1],
            points[2],
            down_point
    };

    cv::Mat affine = getAffineTransform(OriginalPoints, TransformPoints);
    warpAffine(black_original, transform_object, affine, transform_object.size(),
               cv::INTER_AREA, cv::BORDER_CONSTANT, cv::Scalar(255,255,255));
    threshold(transform_object, mask, MIN_THRESEHOLD,
              MAX_THRESEHOLD, CV_THRESH_BINARY_INV);

    warpAffine(original_object, transform_object, affine, transform_object.size(),
               cv::INTER_AREA, cv::BORDER_CONSTANT, cv::Scalar(255,255,255));
    transform_object.copyTo(frame, mask);
}

Glasses_Blue::Glasses_Blue():
        FaceMask("../masks/glass_2.png"),
        black_original(cv::imread("../masks/glass_0.png")) {

    OriginalPoints = new cv::Point2f[3];
    OriginalPoints[0] = cv::Point2f(620, 520);
    OriginalPoints[1] = cv::Point2f(1350, 520);
    OriginalPoints[2] = cv::Point2f(620, 570);
}
Glasses_Blue::~Glasses_Blue() {

    delete[] OriginalPoints;
}
void Glasses_Blue::SetMask(std::vector<cv::Point> &points, cv::Mat frame) {

    if ((points[1].x > points[0].x && points[2].x > points[0].x) ||
        (points[1].x < points[0].x && points[2].x < points[0].x) )
        return; // Чтобы очки не съезжали на один глаз.

    mask = cv::Mat::zeros(frame.size(), original_object.type());
    mask.copyTo(transform_object);

    float length = OriginalPoints[1].x - OriginalPoints[0].x;
    float width = OriginalPoints[2].y - OriginalPoints[1].y;

    float dx = abs(points[1].x - points[2].x);
    float dy = points[2].y - points[1].y;
    float new_length = (float)sqrt(dx*dx + dy*dy);
    float new_width = new_length / length * width;
    float sin = dy / new_length;
    float cos = dx / new_length;

    cv::Point down_point;
    if (points[1].x < points[2].x) {
        down_point.x = points[1].x - int(new_width * sin);
        down_point.y = points[1].y + abs((int)(new_width * cos));
    }
    else {
        down_point.x = points[1].x + int(new_width * sin);
        down_point.y = points[1].y + abs((int)(new_width * cos));
    }

    cv::Point2f TransformPoints[3] = {
            points[1],
            points[2],
            down_point
    };

    cv::Mat affine = getAffineTransform(OriginalPoints, TransformPoints);
    warpAffine(black_original, transform_object, affine, transform_object.size(),
               cv::INTER_AREA, cv::BORDER_CONSTANT, cv::Scalar(255,255,255));
    threshold(transform_object, mask, MIN_THRESEHOLD,
              MAX_THRESEHOLD, CV_THRESH_BINARY_INV);

    warpAffine(original_object, transform_object, affine, transform_object.size(),
               cv::INTER_AREA, cv::BORDER_CONSTANT, cv::Scalar(255,255,255));
    transform_object.copyTo(frame, mask);
}
