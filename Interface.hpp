#ifndef OPENFACE_INTERFACE_HPP
#define OPENFACE_INTERFACE_HPP

#include <QtCore/QObject>
#include <opencv2/core/mat.hpp>
#include <QtWidgets/QDialog>
#include <QtWidgets>


class Interface: public QWidget {
Q_OBJECT

public:
    Interface(int width, int height);

private:
    QVBoxLayout* vert_layout;
    QHBoxLayout* horz_layout;

    QPushButton* first_button;
    QPushButton* second_button;
    QPushButton* third_button;
    QLabel* camera;
    QImage image;

public slots:
    void show_image(cv::Mat &frame);
};

#endif //OPENFACE_INTERFACE_HPP
