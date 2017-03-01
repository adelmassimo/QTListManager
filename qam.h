#ifndef QAM_H
#define QAM_H

#include <QAbstractListModel>
#include <QString>
#include <vector>
#include <iostream>
#include <QTimer>
#include "qmodel.h"
#include "model.h"
#include "list.h"


struct typeA{
    int id;
    QString Type;
    QString Name;
};

class QAM : public QLM
{
    Q_OBJECT
public:
    QAM(){m_row=0;}
    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    QVariant Name(const QModelIndex &index, int role = Qt::DisplayRole) const; //return Name list
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const; //lo vuole per forza! è quello che stampa
    int getListId(){return listId;}

    QTimer *timer;


    bool SyncActs(Lists *L, int rowL);

private:
    int listId;
    int m_row;
    //std::vector<List> m_data; //array di oggetti List
    typeA m_data[100];
};
#endif // QAM_H
