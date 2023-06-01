//
// Created by Deea on 5/30/2023.
//

#ifndef LAB_14_MYTABLEMODEL_H
#define LAB_14_MYTABLEMODEL_H
#include <QAbstractTableModel>
#include "domain/Subject.h"
#include <vector>
using std::vector;
#include <QAbstractItemView>
#include <iostream>
class MyTableModel: public QAbstractTableModel{
std::vector<Subject> subjects;
public:
    MyTableModel(const vector<Subject>& sbjs): subjects(sbjs){
    };
    int rowCount(const QModelIndex & parent = QModelIndex()) const override{
        return subjects.size();
    }
    int columnCount(const QModelIndex & parent = QModelIndex()) const override{
        return 4;
    }
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const override {
        if(role==Qt::DisplayRole)
        {
            Subject sbj=subjects[index.row()];
            if(index.column()==0)
            {
                return QString::fromStdString(sbj.get_name());
            }
            if(index.column()==1)
            {
                return QString::fromStdString(std::to_string(sbj.get_hours()));
            }
            if(index.column()==2)
            {
                return QString::fromStdString(sbj.get_teacher());
            }
            if(index.column()==3)
            {
                return QString::fromStdString(sbj.get_type());
            }
        }
        return QVariant{};

    }
    QVariant headerData(int section, Qt::Orientation orientation, int role) const
    {
        if(orientation == Qt::Horizontal)
        {
            if(role == Qt::DisplayRole)
                switch(section)
                {
                    case 0: return "Name";            break;
                    case 1: return "Hours";   break;
                    case 2: return "Teacher";       break;
                    case 3: return "Type";   break;
                    default:
                        return QString("Column %1").arg(section + 1);
                        break;
                }
        }
        else if(orientation == Qt::Vertical)
        {
            if(role == Qt::DisplayRole)
                return section+1;
        }

        return QVariant();
    }
    Subject getsbj(const QModelIndex &index)
    {
        return subjects[index.row()];
    }
    void setMasini(const vector<Subject>& subject) {
        this->subjects = subject;
        QModelIndex topLeft = createIndex(0, 0);
        QModelIndex bottomRight = createIndex(rowCount(), columnCount());
        emit dataChanged(topLeft, bottomRight);//notify ca la observer
        emit layoutChanged();
    }

};


#endif //LAB_14_MYTABLEMODEL_H
