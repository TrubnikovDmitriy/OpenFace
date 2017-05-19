#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
#include <QPushButton>
#include <opencv2/videoio.hpp>
#include "Interface.hpp"

Interface::Interface(int width, int height): QWidget(nullptr) {

    vert_layout = new QVBoxLayout(this);
    horz_layout = new QHBoxLayout(this);

    first_button = new QPushButton("1");
    second_button = new QPushButton("2");
    third_button = new QPushButton("3");
    camera = new QLabel;

    horz_layout->addWidget(first_button);
    horz_layout->addWidget(second_button);
    horz_layout->addWidget(third_button);


    vert_layout->addWidget(camera, 5);
    vert_layout->addLayout(horz_layout);

    this->setLayout(vert_layout);

    this->resize(width, height + 100);
    camera->resize(width, height);
    this->show();

}

void Interface::show_image(cv::Mat &frame) {

    image = QImage(frame.data, frame.cols, frame.rows, (int)frame.step, QImage::Format_RGB888);
    camera->setPixmap(QPixmap::fromImage(image));
}