#include "Button.hpp"
#include "Utils.hpp"


Button::Button(const QString &load_str) {

    button = new QPushButton(QIcon(load_str), "");
    button->setIconSize(ICON_SIZE);
    button->setMinimumSize(BUTTON_SIZE);
}
