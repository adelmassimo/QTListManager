#include "lists.h"
#include "list.h"
#include "activity.h"

#include <iostream>
Lists::Lists()
{id=0;}

void Lists::addList(QString name, QString type)
{

    List *App;
    App = new List;
    //setto l'oggetto

    App->setName(name);
    App->setType(type);
    App->setId(id);
    allList.push_back(*App);
    id++;


}


void Lists::delList(int currentRow){

    allList.erase(allList.begin()+currentRow);
}


void Lists::doneAct(int rowL, int rowA){
     allList.at(rowL).doneAct(rowA);
}

void Lists::addAct(int rowL, QString text){

    allList.at(rowL).addAct(text);
}

void Lists::setName(int row, QString newName){
    allList.at(row).setName(newName);
}

void Lists::setType(int row, QString newType){
    allList.at(row).setType(newType);
}

void Lists::SaveAct(int rowL, int rowA, QString newNote, bool completed, QDate expiry){
    allList.at(rowL).setActNote(rowA, newNote );
    allList.at(rowL).setExpiryAct(rowA, expiry);
    if(completed != allList.at(rowL).getDone(rowA))
        doneAct(rowL,rowA);

}
