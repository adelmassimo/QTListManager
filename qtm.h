#ifndef QTM_H
#define QTM_H

#include <QAbstractListModel>
#include <QString>
#include <vector>
#include <iostream>
#include <QTimer>
#include "qmodel.h"
#include "model.h"
#include "list.h"


class QTM : public QLM
{
    Q_OBJECT
public:
    QTM();
    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    QVariant Name(const QModelIndex &index, int role = Qt::DisplayRole) const; //return Name list
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const; //lo vuole per forza! è quello che stampa
    int getListId(){return listId;}

    QTimer *timer;


    bool syncT(Model *M){
        m_row=0;
        for(int i=0; i <= M->getNT(); i++){
            m_data[i] = M->getT(i);
            m_row ++;
        }
        //aggiorno
        if (m_row < 0 ) return false;
        QModelIndex topLeft = createIndex(0,0);
        //emit a signal to make the view reread identified data
        emit dataChanged(topLeft, topLeft);

        return true;
    }

private:
    int listId;
    int m_row;
    QString m_data[100];
};

#endif // QTM_H
