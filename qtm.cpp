#include "qtm.h"

QTM::QTM()
{m_row=0;}

int QTM::rowCount(const QModelIndex &parent) const{
    return m_row;
}

QVariant QTM::data(const QModelIndex &index, int role) const{

    if (role == Qt::DisplayRole){
        //return m_data.at(index.row()).getName();
        return m_data[index.row()];
            }

   return QVariant();
}
