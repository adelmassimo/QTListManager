#ifndef LIST_H
#define LIST_H

#include <QString>
#include <QDataStream>
#include <vector>
#include "activity.h"



class List
{
public:
    List();
    List(int Id, QString Name, QString Type): id(Id), name(Name), type(Type){}
    int getId();
    void setId(int newId);

    QString getName();
    void setName(QString newName);

    QString getType();
    void setType(QString newType);

    QString getActName(int row){return allActs.at(row).getName();}
    void setActName(int row, QString newName){ allActs.at(row).setName(newName);}

    void setExpiryAct(int row, QDate expiry){ allActs.at(row).setExpiry(expiry);}
    QDate getExpiry(int row){ return allActs.at(row).getExp();}

    QString getNoteAct(int row){return allActs.at(row).getNote();}
    void setActNote(int row, QString newNote){ allActs.at(row).setNote(newNote);}

    QString getDoneName(int rowA){ return allActs.at(rowA).getDoneName();}

    void addAct(QString name);
    bool getDone(int rowA){return allActs.at(rowA).getDone();}
    void doneAct(int rowA);
    void setDone(int rowA){allActs.at(rowA).setDone();}
    int nActs;




private:
    int id;
    QString name;
    QString type;
    std::vector<Activity> allActs;
};
#endif // LIST_H
