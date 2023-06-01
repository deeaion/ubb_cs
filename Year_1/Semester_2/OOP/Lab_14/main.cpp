#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QFormLayout>
#include <QListWidget>
#include <vector>
#include <string>
#include "APPGUI.h"
#include "validator/ValidatorSubject.h"
using namespace std;
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    FileRepositorySubjects repo{"../subjects.txt"};
    ValidatorSubject val;
    ContractRepo contract;
    SubjectsService serv{repo,contract,val};

    APPGUI gui(serv,contract);
    gui.show();
    return QApplication::exec();
}
//    QWidget w{};
//
//    QHBoxLayout* lymain=new QHBoxLayout;
//    w.setLayout(lymain);
//    auto lybtns=new QVBoxLayout;
//    lybtns->addWidget(new QPushButton("B1"));
//    lybtns->addWidget(new QPushButton("B1"));
//    lybtns->addWidget(new QPushButton("B1"));
//
//    lymain->addWidget(new QLabel{"HY"});
//    lymain->addWidget(new QPushButton{"I am a button"});
//    lymain->addWidget(new QLineEdit{});
//    lymain->addLayout(lybtns);
//    auto form=new QFormLayout;
//    form->addRow("Nume",new QLineEdit);
//    form->addRow("Prenume",new QLineEdit);
//    lymain->addLayout(form);
//    auto lst=new QListWidget;
//    lst->addItem("item1");
//    vector<string> allProduct={"prod1","prod2","prod3"};
//    for(const auto&pr:allProduct)
//    {
//        lst->addItem(QString::fromStdString(pr)) ;
//    }
//    lst->addItem(new QListWidgetItem{"item 2"});
//    lymain->addWidget(lst);
//    w.show();