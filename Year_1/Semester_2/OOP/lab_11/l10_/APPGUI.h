//
// Created by Deea on 5/6/2023.
//

#ifndef L10__APPGUI_H
#define L10__APPGUI_H
#include <QMessageBox>
#include <QWidget>
#include <QVBoxLayout>
#include<QLayoutItem>
#include <QHBoxLayout>
using std::pair;
#include <QPushButton>
#include <QLineEdit>
#include <QFormLayout>
#include <QLabel>
#include <QDebug>
#include <QListWidget>
#include <QTableWidget>
#include "service/SubjectsService.h"
#include <QRadioButton>
#include <QHeaderView>
#include <QSplitter>
class APPGUI:public QWidget {
public:
    APPGUI(SubjectsService&  ser):service{ser} {
        initgui();
        //for the beginning i wil show it always!
        contractgui();
        loadTable(ser.getAll());
        //initiateTable();
        //loadTable(service.getAll());
        connectSignalSlots();
    }

private:
    SubjectsService& service;
    QWidget* contract=new QWidget;
    QTableWidget* table_main=new QTableWidget;
    QListWidget* contract_list=new QListWidget;
    /** BUTTONS MAIN
     */
    QPushButton* undo=new QPushButton{"&UNDO"};
    QPushButton* add=new QPushButton{"&ADD"};
    QPushButton* del=new QPushButton{"&DELETE"};
    QPushButton* modify=new QPushButton{"&MODIFY"};
    QPushButton* open_contract=new QPushButton{"&OPEN CONTRACT"};
    QRadioButton* sort_name=new QRadioButton{"&Name"};
    QRadioButton* sort_hours=new QRadioButton{"&Hours"};
    QRadioButton* sort_teacher=new QRadioButton{"&Teacher"};
    QPushButton* filter_hours=new QPushButton{"&HOURS"};
    QPushButton* filter_teacher=new QPushButton{"&TEACHER"};
    QLineEdit* txtfilter=new QLineEdit;
    QPushButton* exit=new QPushButton{"&EXIT"};
    QPushButton* load=new QPushButton{"&LOAD"};
    QHBoxLayout* type=new QHBoxLayout;
    vector<pair<QPushButton*,string>> buttons_types;
    //vector<string> ty_added;

    //CONTRACT BUTTON
    QPushButton* add_contract=new QPushButton{"&ADD TO CONTRACT"};
    QPushButton* empty_contract=new QPushButton{"&EMPTY CONTRACT"};
    QPushButton* generate_contract=new QPushButton{"&Generate CONTRACT"};
    QPushButton* export_contract=new QPushButton{"&EXPORT TO CONTRACT"};
    QPushButton* exit_contract=new QPushButton{"&EXIT"};



    /**FORM LAYOUT*/
    QLineEdit* txtSubject=new QLineEdit;
    QLineEdit* txtHours=new QLineEdit;
    QLineEdit* txtType=new QLineEdit;
    QLineEdit* txtTeacher=new QLineEdit;
    /*
     * Contract
     */
    QLineEdit* txtContractName=new QLineEdit;
    QLineEdit* txtContractTeacher=new QLineEdit;
    QLineEdit* txtContractNumber=new QLineEdit;
    QLineEdit* txtContractFile=new QLineEdit;
    void loadList(const vector<Subject> &subject);
    void loadTable(const vector<Subject> &subject);
    void contractgui();
    void connectSignalSlots();
   // void initiateTable();

    void initgui();

    void ui_add();
    void ui_delete();
    void ui_modify();
    void ui_filter_h();
    void ui_filter_t();
    void ui_sort_n();
    void ui_addContract();
    void ui_generatetypebuttons();
    void ui_cout_map(const map<string,vector<Subject>> mapFiltered,const string &type);

};
#endif //L10__APPGUI_H
