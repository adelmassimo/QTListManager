#include "qmodel.h"
#include <QTime>
#include <QBrush>
#include <iostream>



//QLM::QLM(QObject *parent):QAbstractListModel(parent){}

QLM::QLM(){
m_row=0;
}

int QLM::rowCount(const QModelIndex &parent) const{
    return m_row;
}

QVariant QLM::Name(const QModelIndex &index, int role) const{

    if (role == Qt::DisplayRole){
        return m_data[index.row()].Name;

        //return m_data.at(row).getName();
            }

   return QVariant();
}

QVariant QLM::data(const QModelIndex &index, int role) const{

    if (role == Qt::DisplayRole){
        QString a = m_data[index.row()].Name;
        a.append("\t[");
        a.append(m_data[index.row()].Type);
        a.append("]");

        return a;
            }

   return QVariant();
}

QVariant QLM::Type(const QModelIndex &index, int role) const{

    if (role == Qt::DisplayRole){
        return m_data[index.row()].Type;
            }

   return QVariant();
}


bool QLM::SyncList(Lists *L){
    m_row=0;
    for (int i = 0; i < L->getSize(); i++){
        m_data[i].Name = L->getName(i);
        m_data[i].Type = L->getType(i);
        m_data[i].id = L->getId(i);
        m_row++;}

    //aggiorno
    //if (!L->getSize() ) return false;
    QModelIndex topLeft = createIndex(0,0);
    //emit a signal to make the view reread identified data
    emit dataChanged(topLeft, topLeft);

    return true;
}

Qt::ItemFlags QLM::flags(const QModelIndex & /*index*/) const
{
    return Qt::ItemIsSelectable |  Qt::ItemIsEditable | Qt::ItemIsEnabled ;
}




bool QLM::SyncActs(Lists *L, int rowL){

    for (int i = 0; i < 1; i++){
        m_data[i].Name = L->getActName(rowL, i);
        m_data[i].Type = "a";
        m_data[i].id = 0;
        m_row++;}

    //aggiorno
    if (m_row < 0 ) return false;
    QModelIndex topLeft = createIndex(0,0);
    //emit a signal to make the view reread identified data
    emit dataChanged(topLeft, topLeft);

    return true;
}
