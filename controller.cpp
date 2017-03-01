#include "controller.h"

Controller::Controller(Model *M, QLM *V, QAM *V2, QTM *V3)

{
    View = V;
    ViewActs = V2;
    ViewTypes = V3;
    model=M;

}

void Controller::CallAddList(QString Name, QString Type){
    //aggiungo i dati
    model->addList(Name, Type);
    //aggiorno la lista
    View->SyncList(model->getL());
}

void Controller::CallAddAct(int rowList, QString ActText){
    model->addAct(rowList, ActText);
    ViewActs->SyncActs(model->getL(), rowList);

  }
void Controller::CallDoneAct(int rowA){
    model->doneAct(ViewActs->getListId(), rowA);
    ViewActs->SyncActs(model->getL(), ViewActs->getListId());

}
void Controller::CallSaveList(int currentRow, QString ListName, QString ListType){
    model->setName(currentRow, ListName);
    model->setType(currentRow, ListType);
    View->SyncList( model->getL());
}

void Controller::CallDelList(int currentRow){
    model->delList(currentRow);
    View->SyncList(model->getL());
}

void Controller::CallSaveAct(int currentRowL, int currentRowA, QString note, bool completed, QDate expiry){
    model->SaveAct(currentRowL, currentRowA, note, completed, expiry);
   // QDebug << expiry;
}

void Controller::CallAddType(QString NewTy){
    model->addT(NewTy);
    ViewTypes->syncT(model);
}
