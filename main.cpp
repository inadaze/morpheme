#include <iostream>
#include <QApplication>
#include "window.h"

int main(int argc, char **argv)
{
    if(argc < 2) {
        QApplication app (argc, argv);

        Window window;
        window.show();

        return app.exec();
    }
    std::cerr << "Using command line interface " << std::endl;
    return 0;
}
