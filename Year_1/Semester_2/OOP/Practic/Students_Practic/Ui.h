//
// Created by Deea on 6/19/2023.
//

#ifndef IONANDREEAMARINA_UI_H
#define IONANDREEAMARINA_UI_H
#include <QWidget>
#include <QTableView>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include "Service.h"
#include "MyTable.h"
#include <QMessageBox>
class Ui :public QWidget{
    //tabel
    QTableView* table=new QTableView;
    MyTable* myT;
    //butoane
    QPushButton* intinerire=new QPushButton{"intinerire"};
    QPushButton* imbatranire=new QPushButton{"imbatranire"};
    QPushButton* sterge=new QPushButton{"sterge"};
    QPushButton* undo=new QPushButton{"undo"};
    QPushButton* redo=new QPushButton{"redo"};
    //referinta la service
    Service &ctr;
    //functii
    void init();
    void connectBut();
    void loadTable();
public:
    Ui(Service &c):ctr(c){
        init();
        connectBut();
        loadTable();
    }


};


#endif //IONANDREEAMARINA_UI_H
