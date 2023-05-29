//
// Created by Deea on 5/6/2023.
//

#include "APPGUI.h"
void APPGUI::initgui() {
    //main layout
    //setting style :)
    this->setWindowTitle("Subjects App");
    QPalette pallete=QPalette();
    pallete.setColor(QPalette::Window,"#1d092b");
    QFont font("Caviar Dreams",12);
    this->setAutoFillBackground(true);
    this->setPalette(pallete);
    this->setFont(font);
    //main layout orientation!
    auto* lymain=new QHBoxLayout;
    setLayout(lymain);

    /**LIST LAYOUT*/
    auto* left_layout=new QVBoxLayout;
    lymain->addLayout(left_layout,9);
    //now i am gonna populate it
    //Adding the label for the table
    left_layout->addWidget(new QLabel{"Table"});
    table_main->resizeColumnsToContents();
    left_layout->addWidget(table_main);
    left_layout->addWidget(undo);
    left_layout->addWidget(open_contract);
    //lymain->stretch(30);
    /**
     * RIGHT LAYOUT
     */
    //right layout -> buttons and operations. Will have 3 other layouts
    QVBoxLayout* right_layout=new QVBoxLayout;
    //lymain->stretch(30);
    lymain->addLayout(right_layout,20);
    //operations
    QFormLayout* data_layout=new QFormLayout;
    right_layout->addLayout(data_layout);
    data_layout->addRow(new QLabel{"SUBJECT:"},txtSubject);
    data_layout->addRow(new QLabel{"HOURS:"},txtHours);
    data_layout->addRow(new QLabel{"TYPE:"},txtType);
    data_layout->addRow(new QLabel{"TEACHER:"},txtTeacher);
    QHBoxLayout* actions=new QHBoxLayout;
    right_layout->addLayout(actions);
    actions->addWidget(add);
    actions->addWidget(modify);
    actions->addWidget(del);

    QVBoxLayout* sflayer=new QVBoxLayout;
    right_layout->addLayout(sflayer);
    sflayer->addWidget(new QLabel{"SORT TYPE"});
    sflayer->addWidget(sort_name);
    sflayer->addWidget(sort_hours);
    sflayer->addWidget(sort_teacher);
    sflayer->addWidget(new QLabel{"FILTER"});
    QHBoxLayout* filterlayer=new QHBoxLayout;
    right_layout->addLayout(type);
    right_layout->addLayout(filterlayer);
    filterlayer->addWidget(filter_hours);
    filterlayer->addWidget(filter_teacher);
    right_layout->addWidget(txtfilter);
    left_layout->addWidget(load);
    right_layout->addWidget(exit);
    //loadTable(service.getAll());


//
//
//    lst->addItem(new QListWidgetItem{"item 2"});
//    lymain->addWidget(lst);
}

void APPGUI::ui_generatetypebuttons() {
    set<string> types_from_service=service.number_of_types();

    for(const auto& t:types_from_service)
    {   auto it=find_if(this->buttons_types.begin(),
                           buttons_types.end(),
                           [t](const pair<QPushButton*,string>& but )
                           {
                               if(but.second==t)
                                   return true;
                               else
                                   return false;
                           });

        if(it!=this->buttons_types.end())
        {
            continue;
        }
        else {
            std::cout << t << "\n";


            QPushButton *button = new QPushButton{QString::fromStdString(t)};
            buttons_types.push_back(std::make_pair(button, t));
            type->addWidget(button);

            QObject::connect(button, &QPushButton::clicked, [this,t]() {
                map<string, vector<Subject>> m = service.creatingmap();
                int nr = m[t].size();
                QString mes = "Number is:";
                mes += QString::number(nr);
                QMessageBox::information(nullptr, "Info", mes);
            });

        }        }
        vector<string> toremove;
        for(const auto& pair:buttons_types)
        {
            if(std::find(types_from_service.begin(),types_from_service.end(),pair.second)==types_from_service.end())
            {
                toremove.push_back(pair.second);
                std::cout<<pair.second<<" HERE";
            }
        }

        for(const auto& type_to_remove:toremove)
        {
            auto it=find_if(this->buttons_types.begin(),
                            buttons_types.end(),
                            [type_to_remove](const pair<QPushButton*,string>& but )
                            {
                                if(but.second==type_to_remove)
                                    return true;
                                else
                                    return false;
                            });
            int poz= (int)std::distance(this->buttons_types.begin(),it);
           delete this->buttons_types[poz].first;
           this->buttons_types.erase(it);
        }

    }


void APPGUI::contractgui() {
    //second layout for uh School Contract
    contract->setWindowTitle("Set Contract");
    QPalette second_pal=QPalette();
    second_pal.setColor(QPalette::Window,"#092b2b");
    QFont font2("Comic Sans",12);
    contract->setPalette(second_pal);
    contract->setFont(font2);
    QHBoxLayout* lysecond=new QHBoxLayout;
    contract->setLayout(lysecond);
    QVBoxLayout* l_lay=new QVBoxLayout;
    lysecond->addLayout(l_lay);
    l_lay->addWidget(new QLabel{"CONTRACT"});
    l_lay->addWidget(empty_contract);
    QFormLayout* l_form=new QFormLayout;
    l_lay->addLayout(l_form);
    l_form->addRow(new QLabel{"Name:"},txtContractName);
    l_form->addRow(new QLabel{"Teacher:"},txtContractTeacher);
    l_lay->addWidget(add_contract);
    l_lay->addWidget(new QLabel{"GENERATE"});
    QFormLayout* gen_layout=new QFormLayout;
    l_lay->addLayout(gen_layout);
    gen_layout->addRow(new QLabel{"How many:"},txtContractNumber);
    l_lay->addWidget(generate_contract);
    l_lay->addWidget(new QLabel{"Export"});
    QFormLayout* export_layout=new QFormLayout;
    l_lay->addLayout(export_layout);
    export_layout->addRow(new QLabel{"FILE:"},txtContractFile);
    l_lay->addWidget(export_contract);
    QVBoxLayout* r_layout=new QVBoxLayout;
    lysecond->addLayout(r_layout);
    r_layout->addWidget(contract_list);
    r_layout->addWidget(exit_contract);
    //contract->show();

}
void APPGUI::loadTable(const vector<Subject> &subject) {
    this->table_main->clearContents();
    this->table_main->setColumnCount(5);
   // this->table_main->setRowCount(subject.size()+1);
    this->table_main->setRowCount(subject.size()+1);
    int line_nr=0;
    table_main->setItem(line_nr,0,new QTableWidgetItem("NR"));
    table_main->setItem(line_nr,1,new QTableWidgetItem("NAME"));
    table_main->setItem(line_nr,2,new QTableWidgetItem("HOURS"));
    table_main->setItem(line_nr,3,new QTableWidgetItem("TEACHER"));
    table_main->setItem(line_nr,4,new QTableWidgetItem("TYPE"));
    line_nr++;
    for(const auto& Subject:subject)
    {
        table_main->setItem(line_nr,0,new QTableWidgetItem(QString::number(line_nr)));
        table_main->setItem(line_nr,1,new QTableWidgetItem(QString::fromStdString(Subject.get_name())));
        table_main->setItem(line_nr,2,new QTableWidgetItem(QString::number(Subject.get_hours())));
        table_main->setItem(line_nr,3,new QTableWidgetItem(QString::fromStdString(Subject.get_teacher())));
        table_main->setItem(line_nr,4,new QTableWidgetItem(QString::fromStdString(Subject.get_type())));
//        if(Subject.get_name()=="2")
//        {   for(int i=0;i<table_main->columnCount();i++) {
//                QTableWidgetItem *change = table_main->item(line_nr, i);
//                change->setBackground(Qt::red);
//            }
//        }
        line_nr++;
    }
    ui_generatetypebuttons();


}

void APPGUI::ui_add() {
    string name=txtSubject->text().toStdString();
    string teacher=txtTeacher->text().toStdString();
    string type=txtType->text().toStdString();
    string hours=txtHours->text().toStdString();
    qDebug()<<name<<teacher;
    int h;
    try {
        h= stoi(hours);
    }
    catch(std::invalid_argument& mes)
    {
        QMessageBox::warning(this,"WARNING","INVALID DATA");
        return;
    }
    try
    {
        service.addSubject(name,h,teacher,type);
    }
    catch(RepositoryException& mes)
    {
        QMessageBox::warning(this,"WARNING",QString::fromStdString(mes.getMessage()));
    }
    catch(ValidatorException& mes)
    {
        QMessageBox::warning(this,"WARNING",QString::fromStdString(mes.getMessage()));
    }
    loadTable(service.getAll());

}
void APPGUI::ui_delete() {
    string name=txtSubject->text().toStdString();
    string teacher=txtTeacher->text().toStdString();
    qDebug()<<name<<teacher;
    try
    {
        service.deleteSubject(name,teacher);
    }
    catch(RepositoryException& mes)
    {
        QMessageBox::warning(this,"WARNING",QString::fromStdString(mes.getMessage()));
    }
    catch(ValidatorException& mes)
    {
        QMessageBox::warning(this,"WARNING",QString::fromStdString(mes.getMessage()));
    }
    loadTable(service.getAll());

}
void APPGUI::ui_modify() {
    string name=txtSubject->text().toStdString();
    string teacher=txtTeacher->text().toStdString();
    string type=txtType->text().toStdString();
    string hours=txtHours->text().toStdString();
    qDebug()<<name<<teacher;
    int h;
    try {
        h= stoi(hours);
    }
    catch(std::invalid_argument& mes)
    {
        QMessageBox::warning(this,"WARNING","INVALID DATA");
        return;
    }
    try
    {
        service.updateSubject(name,teacher,h,type);
    }
    catch(RepositoryException& mes)
    {
        QMessageBox::warning(this,"WARNING",QString::fromStdString(mes.getMessage()));
    }
    catch(ValidatorException& mes)
    {
        QMessageBox::warning(this,"WARNING",QString::fromStdString(mes.getMessage()));
    }
    loadTable(service.getAll());
}
void APPGUI::ui_filter_h(){
    string h=txtfilter->text().toStdString();
    int hours;
    try
    {
        hours=stoi(h);
    }
    catch (std::invalid_argument &mes)
    {
        QMessageBox::warning(nullptr,"!","INVALID INPUT");
    }
    vector<Subject> sbj=service.filterByHours(hours);
    for(const auto& s:sbj)
    {
        qDebug()<<s.to_string_print();
    }
    loadTable(sbj);
}
void APPGUI::ui_filter_t(){
    string teacher=txtfilter->text().toStdString();
    qDebug()<<teacher;
    vector<Subject> sbj=service.filterByTeacher(teacher);
    for(const auto& s:sbj)
    {
        qDebug()<<s.to_string_print();
    }
    loadTable(sbj);
}
void APPGUI::ui_sort_n() {
    vector<Subject> s=service.sortByName();
    loadTable(s);
}
void APPGUI::loadList(const vector<Subject> &subject) {
    contract_list->clear();
    for(const auto& s:subject)
    {   //QListWidgetItem* it=new QListWidgetItem()
        contract_list->addItem(QString::fromStdString(s.l_sbj()));
    }
}
void APPGUI::ui_addContract() {
    string name=txtContractName->text().toStdString();
    string teacher=txtContractTeacher->text().toStdString();
    auto found=service.filterBySubjectName(name);
    if(found.empty())
    {
        QMessageBox::warning(nullptr,"1","SUBJECT: UNFOUND");
        return;
    }
    if(found.size()==1)
    {try
    {
        service.add_to_contract(name,found[0].get_teacher(),found);
    }
catch(ContractException &m)
{
    QMessageBox::warning(nullptr,"!",QString::fromStdString(m.getMessage()));
    return;
}
catch(RepositoryException &m)
{
    QMessageBox::warning(nullptr,"!",QString::fromStdString(m.getMessage()));
    return;
}
catch(ValidatorException &m)
{
    QMessageBox::warning(nullptr,"!",QString::fromStdString(m.getMessage()));
    return;
}}
    else
    {
        if(teacher!="")
        {
            try
            {
                service.add_to_contract(name,teacher,found);
            }
            catch(ContractException &m)
            {
                QMessageBox::warning(nullptr,"!",QString::fromStdString(m.getMessage()));
                return;
            }
            catch(RepositoryException &m)
            {
                QMessageBox::warning(nullptr,"!",QString::fromStdString(m.getMessage()));
                return;
            }
            catch(ValidatorException &m)
            {
                QMessageBox::warning(nullptr,"!",QString::fromStdString(m.getMessage()));
                return;
            }
        }
        else
        {
            QMessageBox::warning(nullptr,"!","You have to provide something in the teacher field!");
        }
    }
    loadList(service.getAllContract());
}
void APPGUI::connectSignalSlots() {
        /**GUI*/
        //exit
        QObject::connect(exit,&QPushButton::clicked,[&](){
        this->close();
        contract->close();
        QMessageBox::information(nullptr,"!","Closing app");
    });
        QObject::connect(add,&QPushButton::clicked,this,&APPGUI::ui_add);
        QObject::connect(del,&QPushButton::clicked,this,&APPGUI::ui_delete);
        QObject::connect(modify,&QPushButton::clicked,this,&APPGUI::ui_modify);
        QObject::connect(filter_teacher,&QPushButton::clicked,this,&APPGUI::ui_filter_t);
        QObject::connect(filter_hours,&QPushButton::clicked,this,&APPGUI::ui_filter_h);
        QObject::connect(load,&QPushButton::clicked,[&](){
            this->loadTable(service.getAll());
        });
        QObject::connect(sort_name,&QRadioButton::toggled,this,&APPGUI::ui_sort_n);
    QObject::connect(sort_teacher,&QRadioButton::toggled,[&](){

        loadTable(service.sortByTeacherandType());
    });
    QObject::connect(sort_hours,&QRadioButton::toggled,[&](){

        loadTable(service.sortByHours());
    });
    QObject::connect(undo,&QPushButton::clicked,[&](){
        try{
        service.Undo();}
        catch(RepositoryException& mes)
        {
            QMessageBox::warning(nullptr,"!",QString::fromStdString(mes.getMessage()));
        }
    });
    QObject::connect(open_contract,&QPushButton::clicked,[&](){
        contract->show();
    });
    /**CONTRACT WINDOW*/
    QObject::connect(exit_contract,&QPushButton::clicked,[&](){
        contract->close();
    });
    QObject::connect(empty_contract,&QPushButton::clicked,[&](){
        service.emptyContract();
        loadList(service.getAllContract());
    });
    QObject::connect(generate_contract,&QPushButton::clicked,[&](){
        string n=txtContractNumber->text().toStdString();
        int nr;
        try
        {
            nr=stoi(n);
        }
        catch(std::invalid_argument &m)
        {
            QMessageBox::warning(nullptr,"!","INVALID ARGUMENT");
        }
        service.generateContract(nr);
        loadList(service.getAllContract());
    });
    QObject::connect(add_contract,&QPushButton::clicked,this,&APPGUI::ui_addContract);
    QObject::connect(export_contract,&QPushButton::clicked,[&](){
        string file=txtContractFile->text().toStdString();
        service.exportContract(file);
    });
    QObject::connect(table_main,&QTableWidget::itemSelectionChanged,[&](){
        auto sel=table_main->selectionModel();

            txtSubject->setText(sel->selectedRows(1).value(0).data().toString());
            txtTeacher->setText(sel->selectedRows(3).value(0).data().toString());
            txtHours->setText(sel->selectedRows(2).value(0).data().toString());
            txtType->setText(sel->selectedRows(4).value(0).data().toString());
    });

}
