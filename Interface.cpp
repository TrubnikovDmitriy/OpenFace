#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
#include <QPushButton>
#include <opencv2/videoio.hpp>
#include "Interface.hpp"
#include <iostream>

Interface::Interface(int width, int height): QWidget(nullptr) {

    QVBoxLayout* vert_layout = new QVBoxLayout(this);
    QHBoxLayout* horz_layout = new QHBoxLayout(this);

    QPushButton* first_button = new QPushButton("1");
    QPushButton* second_button = new QPushButton("2");
    QPushButton* third_button = new QPushButton("3");
    QLabel* camera = new QLabel;

    horz_layout->addWidget(first_button);
    horz_layout->addWidget(second_button);
    horz_layout->addWidget(third_button);


    vert_layout->addWidget(camera, 5);
    vert_layout->addLayout(horz_layout);

    this->setLayout(vert_layout);

    this->resize(width, height + 100);
    camera->resize(width, height);
//    this->show();

}

void Interface::show_image(cv::Mat &frame) {

    QLabel lbl;

    QImage image(frame.data, frame.cols, frame.rows, (int) frame.step, QImage::Format_RGB888);
    camera->setPixmap(QPixmap::fromImage(image));
    lbl.setPixmap(QPixmap::fromImage(image));
//    lbl.show();
}