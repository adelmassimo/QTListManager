#ifndef QMODEL_H
#define QMODEL_H

#include <QAbstractListModel>
#include <QString>
#include <vector>
#include <iostream>
#include <QTimer>
#include "model.h"
#include "list.h"





 struct typeL{
    int id;
    QString Type;
    QString Name;
};

class QLM : public QAbstractListModel
{
    Q_OBJECT
public:
    QLM();
    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    QVariant Name(const QModelIndex &index, int role = Qt::DisplayRole) const; //return Name list
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const; //lo vuole per forza! è quello che stampa
    QVariant Type(const QModelIndex &index, int role = Qt::DisplayRole) const; //return Type list
    bool SyncList(Lists *L =0 );
    bool DeleteList(const QModelIndex & index, int role = Qt::EditRole);
    Qt::ItemFlags flags(const QModelIndex & index) const ;
    QTimer *timer;


    bool SyncActs(Lists *L, int rowL);
private:
    int m_row;
    //std::vector<List> m_data; //array di soggetti List
    typeL m_data[100];
};

#endif // QMODEL_H
