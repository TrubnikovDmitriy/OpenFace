#ifndef OPENFACE_INTERFACE_HPP
#define OPENFACE_INTERFACE_HPP

#include <QtCore/QObject>
#include <QtWidgets>
#include <opencv2/core/mat.hpp>
#include "Button.hpp"


class Interface: public QWidget {
Q_OBJECT

public:
    Interface();
    QSignalMapper* signal_map;

private:
    std::vector<Button> mask_buttons;
    QVBoxLayout* vert_layout;
    QHBoxLayout* horz_layout;

    QLabel* camera;
    QImage image;

protected:
    void closeEvent(QCloseEvent* event);

public slots:
    void show_image(cv::Mat &frame);

signals:
    void close();
};

#endif //OPENFACE_INTERFACE_HPP
