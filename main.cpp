#include <iostream>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <QApplication>
#include "OpenFace.hpp"
#include "Utils.hpp"


int main(int argc, char* argv[]) {

    QApplication q(argc, argv);
    OpenFace* project = new OpenFace();
    try {
        while (project->NextStep()) {
            q.processEvents();
            cv::waitKey(33);
        }
    }
    catch(MyException except) {
        except.ShowError();
        delete project;
        return EXIT_FAILURE;
    }

    delete project;
    return 0;
}
// Обернуть в умные указатели
