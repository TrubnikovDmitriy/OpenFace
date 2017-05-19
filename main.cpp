#include <iostream>

#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>

#include <opencv2/imgproc.hpp>
#include <QApplication>

#include <QtWidgets>
#include "OpenFace.hpp"
#include "Utils.hpp"
#include "Interface.hpp"


int main(int argc, char* argv[]) {

    QApplication q(argc, argv);
    OpenFace* project = new OpenFace;

    try {
        while ( true ) {
            project->NextStep();
            int c = cv::waitKey(33);
            if( c == 27 ) {
                break; // escape
            }
            if (c == 'q') {
                project->ChangeMask(0);
            }
            if (c == 'w') {
                project->ChangeMask(1);
            }
            if (c == 'e') {
                project->ChangeMask(2);
            }
        }

    }
    catch(MyException except) {
        except.ShowError();
        return EXIT_FAILURE;
    }


    delete project;
    return q.exec();
}