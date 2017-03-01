#ifndef MODEL_H
#define MODEL_H

#include"lists.h"
#include "QAbstractListModel"

class Model
{

public:
    Model();
    Lists* getL(){return &L;}
    QString getT(int index){return AllTypes.at(index);}
    void addT(QString t){nT++; AllTypes.push_back(t);}
    int getNT(){return nT;}



    // metod on Lists
        int getSize(){return L.getSize();}
        void setName(int row, QString newName){L.setName(row, newName);}
        QString getName(int row){ return L.getName(row);}
        void setType(int row, QString newType){L.setType(row, newType);}
        QString getType(int row){ return L.getType(row);}
        void addList(QString name, QString type){L.addList(name,type);}
        void delList(int currentRow){L.delList(currentRow);}
        int getId(int row){return L.getId(row);}


     // metods on Activitys
        void setDone(int rowL,int rowA){ L.setDone(rowL,rowA);}
        bool getDone(int rowL, int rowA){ return L.getDone(rowL,rowA);}
        int getnActs(int row){return L.getnActs(row);}
        void doneAct(int rowL, int rowA){L.doneAct(rowL,rowA);}
        void addAct(int rowL, QString text){L.addAct(rowL, text);}
        QString getActName(int rowL,int rowA){return L.getActName(rowL,rowA);}
        QString getNoteAct(int rowL, int rowA){return L.getNoteAct(rowL, rowA);}
        void SaveAct(int rowL, int rowA, QString newNote, bool completed, QDate expiry){L.SaveAct(rowL,rowA,newNote,completed, expiry);}
        QDate Getexp(int rowL, int rowA){ return L.getExpiry(rowL, rowA);}
private:
    Lists L;
    //QString types[20];
    std::vector<QString> AllTypes; //array che contiene i tipi di lista
    int nT;
};

#endif // MODEL_H
