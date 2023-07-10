//
// Created by Deea on 5/23/2023.
//

#include "Gui.h"

void Gui::init() {
    QHBoxLayout* main=new QHBoxLayout;
    setLayout(main);
    main->addWidget(list);
    QVBoxLayout* dr=new QVBoxLayout;
    main->addLayout(dr);

    QFormLayout* form=new QFormLayout;
    dr->addLayout(form);
    form->addRow(new QLabel{"Loc:"},loc);
    form->addRow(new QLabel{"Data:"},date);
    form->addRow(new QLabel{"Intensitate"},intens);
    form->addRow(new QLabel{"Adancime"},adanc);
    form->addRow(inreg);
    dr->addWidget(new QLabel{"Filters"});
    dr->addWidget(locatie);
    dr->addWidget(slider);
    dr->addWidget(v_slider);
    slider->setRange(0,10);
}

void Gui::loadList(const vector<Cutremur> &cutremure) {
    list->clear();
    for(const auto& cut:cutremure)
    {
        QListWidgetItem* to_add=new QListWidgetItem{QString::fromStdString(cut.print())};
        if(cut.get_intensitate()<3)
        {
            to_add->setBackground(Qt::gray);
        }
        if(cut.get_intensitate()>=3 &&cut.get_intensitate()<4)
        {
            to_add->setBackground(Qt::green);
        }
        if(cut.get_intensitate()>=4 &&cut.get_intensitate()<5)
        {
            to_add->setBackground(Qt::yellow);
        }
        if(cut.get_intensitate()>=5 &&cut.get_intensitate()<6)
        {
            to_add->setBackground(Qt::darkYellow);
        }
        if(cut.get_intensitate()>=6 &&cut.get_intensitate()<7)
        {
            to_add->setBackground(Qt::cyan);
        }
        if(cut.get_intensitate()>=7)
        {
            to_add->setBackground(Qt::red);
        }
        list->addItem(to_add);
    }

}

void Gui::loadLocatii() {
    locatie->clear();
    locatie->addItem("None");
    for(const auto& l:ctr.get_locatii())
    {
        locatie->addItem(QString::fromStdString(l));
    }
}
void Gui::connectButtons() {
    QObject::connect(inreg,&QPushButton::clicked,[&](){
       string locat=loc->text().toStdString();
       string date=loc->text().toStdString();
       int intensitate=intens->text().toInt();
        int ad=adanc->text().toInt();
        try {
            ctr.store_Cut(locat,date,intensitate,ad);

        }
        catch (ValidException &m)
        {
            QMessageBox::warning(this,"!",QString::fromStdString(m.get_message()));
        }
        loadLocatii();
        loadList(ctr.get_cutremure());

    });
    QObject::connect(slider,&QSlider::sliderReleased,[&](){
        int val=slider->value();
        cout<<val<<" ";

        string loc=locatie->itemText(locatie->currentIndex()).toStdString();
        cout<<loc;
        v_slider->setText(QString::fromStdString(to_string(val)));
        loadList(ctr.filter_loc_int(loc,val));
    });
    QObject::connect(locatie,&QComboBox::currentIndexChanged,[&](){
        int val=slider->value();

        cout<<val<<" ";
        string loc=locatie->itemText(locatie->currentIndex()).toStdString();
        cout<<loc;
        loadList(ctr.filter_loc_int(loc,val));
    });


}