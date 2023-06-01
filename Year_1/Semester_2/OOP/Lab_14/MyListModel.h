//
// Created by Deea on 5/30/2023.
//

#ifndef LAB_14_MYLISTMODEL_H
#define LAB_14_MYLISTMODEL_H
#include <QAbstractListModel>
#include <vector>
#include "service/SubjectsService.h"
#include <sstream>
class MyListModel: public QAbstractListModel{
vector<Subject> subjects;
public:
    MyListModel(const std::vector<Subject> &sbjs) : subjects(sbjs){};
    int rowCount(const QModelIndex &parent=QModelIndex()) const override{
        return subjects.size();
    };
    QVariant data(const QModelIndex &index,int role=Qt::DisplayRole) const override{
        if(role==Qt::DisplayRole)
        {   std::stringstream stream;
            stream<<subjects[index.row()];

            string sp=stream.str();
            //std::cout<<sp;
            return QString::fromStdString(sp);
        }
        if(role==Qt::UserRole)
        {
            auto ut=subjects[index.row()].to_string_print();
            return QString::fromStdString(ut);
        }
        return QVariant{};
    };

};


#endif //LAB_14_MYLISTMODEL_H
