#include <QApplication>
#include <QPushButton>
#include "Controler.h"
#include "Domain.h"
#include "Repo.h"
#include "Gui.h"
#include "Teste.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Repo repo{"../cutremure.txt"};
    Validator val;
    Controler ctr{repo,val};
    Teste test;
    test.testAll();
    Gui gui(ctr);
    gui.show();
    return QApplication::exec();
}
