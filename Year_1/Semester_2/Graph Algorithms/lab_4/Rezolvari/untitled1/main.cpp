#include <QApplication>
#include <QPushButton>
#include "GUI.h"
int main(int argc, char *argv[]) {
    QApplication a(argc,argv);
    GUI gui;
    gui.show();
    return QApplication::exec();
}
