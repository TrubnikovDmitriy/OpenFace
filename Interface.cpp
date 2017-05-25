#include <vector>
#include <opencv2/videoio.hpp>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
#include "Interface.hpp"
#include "Utils.hpp"


Interface::Interface(): QWidget(nullptr) {

    signal_map = new QSignalMapper(this);
    camera = new QLabel;
    vert_layout = new QVBoxLayout(this);
    horz_layout = new QHBoxLayout();

    for (int i = 0; i < MASK_NUMBER; ++i) {

        mask_buttons.push_back(Button("../masks/glass_" + QString::number(i) + ".png"));
        horz_layout->addWidget(mask_buttons[i].button);

        QObject::connect(mask_buttons[i].button, SIGNAL(clicked()), signal_map, SLOT(map()));
        signal_map->setMapping(mask_buttons[i].button, i);
    }

    this->resize(MIN_WINDOW_SIZE);

    vert_layout->addWidget(camera);
    vert_layout->addLayout(horz_layout);
    this->setLayout(vert_layout);
}

void Interface::show_image(cv::Mat &frame) {

    image = QImage(frame.data, frame.cols, frame.rows, (int)frame.step, QImage::Format_RGB888);
    camera->setPixmap(QPixmap::fromImage(image));
}
void Interface::closeEvent(QCloseEvent *event) {

    emit close();
    event->accept();
}