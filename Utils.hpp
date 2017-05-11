//
// Created by dmitriy on 10.05.17.
//

#ifndef OPENFACE_UTILS_HPP
#define OPENFACE_UTILS_HPP

#include <opencv2/core/types.hpp>
#include <iostream>

class myException {
public:
    myException(std::string name = "file!"):
            error("Can't load ") { error += name; }

    void ShowError() { std::cout << error << std::endl; }

private:
    std::string error;
};

#endif //OPENFACE_UTILS_HPP
