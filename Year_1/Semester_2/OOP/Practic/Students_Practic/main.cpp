#include <QApplication>
#include <QPushButton>
#include "Teste.h"
#include "Repo.h"
#include "Service.h"
#include "Ui.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Teste teste;
    teste.TestAll();
    Repository repo{"../stud"};
    Service ctr{repo};
    Ui ui{ctr};
    ui.show();
    //return 0;
    return QApplication::exec();
}
