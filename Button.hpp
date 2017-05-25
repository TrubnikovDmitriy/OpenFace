#ifndef OPENFACE_BUTTON_HPP
#define OPENFACE_BUTTON_HPP

#include <QtWidgets/QPushButton>
#include <QtCore/QSignalMapper>

class Button {
public:
    Button(const QString &load_str);
    QPushButton* button;
};

#endif //OPENFACE_BUTTON_HPP
