#ifndef LISTS_H
#define LISTS_H

#include "list.h"
#include <vector>
#include <iostream>


class Lists
{
public:
    //costruttore
    Lists();
    // metod on Lists
    int getSize(){return allList.size();}

    void setName(int row, QString newName);
    QString getName(int row){ return allList.at(row).getName();}

    void setType(int row, QString newType);
    QString getType(int row){ return allList.at(row).getType();}

    void addList(QString name, QString type);
    void delList(int currentRow);

    int getId(int row){return allList.at(row).getId();}


    // metods on Activitys
    void setDone(int rowL,int rowA){ allList.at(rowL).setDone(rowA);}
    bool getDone(int rowL, int rowA){ return allList.at(rowL).getDone(rowA);}
    int getnActs(int row){return allList.at(row).nActs;}
    void doneAct(int rowL, int rowA);
    void addAct(int rowL, QString text);
    QString getActName(int rowL,int rowA){return allList.at(rowL).getActName(rowA);}
    QString getNoteAct(int rowL, int rowA){return allList.at(rowL).getNoteAct(rowA);}
    void SaveAct(int rowL, int rowA, QString newNote, bool completed, QDate expiry);
    QDate getExpiry(int rowL, int rowA){ return allList.at(rowL).getExpiry(rowA);}
    QString getDoneName(int rowL, int rowA){return allList.at(rowL).getDoneName(rowA);}


private:
    int id;
    std::vector<List> allList; //array di oggetti List

};
#endif // LISTS_H
