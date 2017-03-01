#include "list.h"

List::List()
{
    nActs=0;

}

int List::getId(){
    return id;
}

void List::setId(int newId){
    id=newId;
}

QString List::getName(){
    return name;
}

void List::setName(QString newName){
    name=newName;
}

QString List::getType(){
    return type;
}

void List::setType(QString newType){
    type=newType;
}


void List::addAct(QString name)
{
    //int size = allActs.size();
    Activity *App;
    App = new Activity;
    //setto l'oggetto
    App->setName(name);
    allActs.push_back(*App);
    nActs++;


}

void List::doneAct(int rowA)
{

    allActs.at(rowA).setDoneName(allActs.at(rowA).getDoneName());
    allActs.at(rowA).setDone();
}
