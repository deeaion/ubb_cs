//
// Created by Deea on 5/14/2023.
//

#include "GUI.h"
void GUI::init() {
    mainLayout=new QHBoxLayout;
    this->setLayout(mainLayout);
    auto l_s=new QVBoxLayout;

    mainLayout->addWidget(procesoare);
    mainLayout->addWidget(placi);
    mainLayout->addLayout(l_s);
    l_s->addWidget(nume);
    l_s->addWidget(soclu);
    l_s->addWidget(pret);
    l_s->addWidget(add);
    l_s->addWidget(filtrare);
    l_s->addWidget(price);


}