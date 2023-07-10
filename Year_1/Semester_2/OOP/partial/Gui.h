//
// Created by Deea on 5/23/2023.
//

#ifndef PARTIAL_IONANDREEA_GUI_H
#define PARTIAL_IONANDREEA_GUI_H
#include <QWidget>
#include <QSlider>
#include <QComboBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QListWidget>
#include <QLabel>
#include <QFormLayout>
#include <QPushButton>
#include <QMessageBox>
#include "Controler.h"

class Gui:public QWidget {
    //referinta la Contorler
    Controler &ctr;
    //componente
    QListWidget *list=new QListWidget;
    //fields
    QLineEdit* loc=new QLineEdit;
    QLineEdit* date=new QLineEdit;
    QLineEdit* intens=new QLineEdit;
    QLineEdit* adanc=new QLineEdit;
    QPushButton* inreg=new QPushButton{"&Inregistrare"};
    //filter
    QSlider* slider=new QSlider{Qt::Horizontal};
    QLabel* v_slider=new QLabel;
    QComboBox* locatie=new QComboBox;
    //functions
    void init();
    void loadList(const vector<Cutremur> &cutremure);
    void loadLocatii();
    void connectButtons();
public:
    //constructor
    Gui(Controler &c): ctr(c){
      init();
        loadList(ctr.get_cutremure());
        connectButtons();
        loadLocatii();
    };

};


#endif //PARTIAL_IONANDREEA_GUI_H
