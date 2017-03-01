#include "qam.h"
#include <QTime>
#include <QBrush>
#include <iostream>

int QAM::rowCount(const QModelIndex &parent) const{
    return m_row;
}

QVariant QAM::Name(const QModelIndex &index, int role) const{

    if (role == Qt::DisplayRole){
        return m_data[index.row()].Name;

        //return m_data.at(row).getName();
            }

   return QVariant();
}


QVariant QAM::data(const QModelIndex &index, int role) const{

    if (role == Qt::DisplayRole){
        //return m_data.at(index.row()).getName();
        return m_data[index.row()].Name;
            }

   return QVariant();
}


bool QAM::SyncActs(Lists *L, int rowL){
        listId=rowL;
        m_row=0;
        if (listId >= 0 ){

        for (int i = 0; i < L->getnActs(rowL); i++){
        if(L->getDone(rowL,i) == true)
        m_data[i].Name = L->getDoneName(rowL, i);
        else
        m_data[i].Name = L->getActName(rowL, i);
        m_data[i].Type = "a";
        m_data[i].id = 0;
        m_row++;}
        }

    //aggiorno

    QModelIndex topLeft = createIndex(0,0);
    //emit a signal to make the view reread identified data
    emit dataChanged(topLeft, topLeft);

    return true;
}
