//
// Created by Deea on 5/14/2023.
//

#ifndef UNTITLED1_GUI_H
#define UNTITLED1_GUI_H
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QListWidget>
#include <QPushButton>
#include <QLineEdit>
class GUI:public QWidget {
private:

    QHBoxLayout* mainLayout;
    QPushButton* add=new QPushButton{"&Adauga"};
    QPushButton* price=new QPushButton{"&Price"};
    QPushButton* filtrare=new QPushButton{"&Procesor"};
    QPushButton* load=new QPushButton{"&Load Procesoare"};
    QPushButton* load_2=new QPushButton{"&Load Placi"};
    QListWidget* procesoare=new QListWidget;
    QListWidget* placi=new QListWidget;
    QLineEdit* nume=new QLineEdit;
    QLineEdit* soclu=new QLineEdit;
    QLineEdit* pret=new QLineEdit;
    void init();
    //void conect();


public:
    GUI()
    {
        init();
        //conect();
    }
};


#endif //UNTITLED1_GUI_H
