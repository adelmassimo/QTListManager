#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QBrush>
#include <iostream>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

#include "qam.h"
#include "qmodel.h"
#include "qtm.h"
#include "list.h"
#include "model.h"


class Controller
{
public:
    Controller(Model *M, QLM *V, QAM *V2, QTM *V3); //V=ViewList V2=ActivityView
    QLM *View;
    QAM *ViewActs;
    QTM *ViewTypes;
    Model *model;
    void CallAddList(QString Name = "New List", QString Type = "Private");
    void CallAddAct(int currentList, QString ActText);
    void CallSaveList(int currentRow, QString ListName, QString ListType);
    void CallDoneAct(int rowA);
    void CallDelList(int currentRow);
    void CallSaveAct(int currentRowL, int currentRowA, QString note, bool completed, QDate expiry);
    void CallAddT(QString T){
        model->addT(T);
        ViewTypes->syncT(model);
    }
    void CallAddType(QString NewTy);
};
#endif // CONTROLLER_H
