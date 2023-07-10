//
// Created by Deea on 6/19/2023.
//

#include "Ui.h"

void Ui::init() {
    QHBoxLayout* main=new QHBoxLayout;
    setLayout(main);
    myT=new MyTable{ctr.getAll()};
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setModel(myT);
    main->addWidget(table);
    QVBoxLayout* dr=new QVBoxLayout;
    main->addLayout(dr);
    dr->addWidget(imbatranire);
    dr->addWidget(intinerire);
    dr->addWidget(sterge);
    dr->addWidget(undo);
    dr->addWidget(redo);
    resize(1000,800);


}

void Ui::connectBut() {
    QObject::connect(sterge,&QPushButton::clicked,[&](){
       auto sel=table->selectionModel()->selectedRows();
       if(sel.empty())
           QMessageBox::warning(this,"!","SELECTION EMPTY");
       else
       {
           vector<Student> toDelete;
           for(auto i:sel)
           {
               QModelIndex &index=i;
               auto st=myT->getStudent(i);
               cout<<st.getFacultate();
               toDelete.push_back(st);
           }
           ctr.stergereMultipla(toDelete);
           loadTable();
       }

    });
    QObject::connect(imbatranire,&QPushButton::pressed,[&](){
       ctr.updateAll(1);
       loadTable();

    });
    QObject::connect(undo,&QPushButton::pressed,[&](){
       try
       {
           ctr.UndoAct();

       }
       catch (RepoExceptie &e)
       {
           QMessageBox::warning(this,"!",QString::fromStdString(e.getMes()));
       }
        loadTable();

    });
    QObject::connect(redo,&QPushButton::pressed,[&](){
        try
        {
            ctr.RedoAct();

        }
        catch (RepoExceptie &e)
        {
            QMessageBox::warning(this,"!",QString::fromStdString(e.getMes()));
        }
        loadTable();

    });
    QObject::connect(intinerire,&QPushButton::pressed,[&](){
        ctr.updateAll(-1);
        loadTable();

    });
}

void Ui::loadTable() {
    myT->setStudenti(ctr.getAll());
}