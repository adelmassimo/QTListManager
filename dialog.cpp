#include "dialog.h"
#include "ui_dialog.h"
#include <iostream>
#include "qmodel.h"
#include "QDate"


Dialog::Dialog(Controller *C, QWidget *parent, std::vector<QString> *actExp) :
    QDialog(parent),
    ui(new Ui::Dialog),
    Cont(C)


{
    ui->setupUi(this);
    CurrentRowList = -1;
    //Window List
    ModWg  = new QWidget();
    save = new QPushButton();
    name  = new QLineEdit();
    type  = new QListView();
    Grid = new QGridLayout();
    del = new QPushButton();
    addTy = new QPushButton();


    //Window Activity
    ModActWg = new QWidget();
    saveAct = new QPushButton();
    note = new QTextEdit();
    GridAct = new QGridLayout();
    done = new QCheckBox();
    expiry = new QCalendarWidget();

    //Window New Type
    ModNeTy = new QWidget();
    saveTy = new QPushButton();
    NewTy = new QTextEdit();
    GridTy = new QGridLayout();

    //window alert
    ModAlert = new QWidget();
    GridAlert = new QGridLayout();
    alert = new QLabel();
    title = new QLabel();







    //se ci sono attività scadute notifico l'avviso







    ui->lineEdit->setFocus();
    ui->lineEdit->setPlaceholderText(" Insert your activities here...");


    note->setPlaceholderText("Insert your notes... ");

    Cont->View->SyncList(Cont->model->getL());
    Cont->ViewTypes->syncT(Cont->model);

    //connessioni
    QObject::connect(ui->addList, SIGNAL(clicked()), this, SLOT(SignalAddList()) ); //addlist
    QObject::connect(ui->listView, SIGNAL(clicked(QModelIndex)), this, SLOT(changeActs(QModelIndex))); //chnge act
    QObject::connect(ui->listView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(SignalModifyList(QModelIndex))); //lista selezionata
    QObject::connect(ui->actView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(SignalModifyAct(QModelIndex)));
    QObject::connect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(SignalAddAct()));
    //window list
    QObject::connect(del, SIGNAL(clicked()), this, SLOT(SignalDelList()));
    QObject::connect(save, SIGNAL(clicked()), this , SLOT(SignalSaveList()));
    QObject::connect(name, SIGNAL(returnPressed()), this, SLOT(SignalSaveList()));
    //window Act
    QObject::connect(saveAct, SIGNAL(clicked()), this, SLOT(SignalSaveAct()));
    //window Type
    QObject::connect(addTy, SIGNAL(clicked()), this, SLOT(SignalNewType()));
    QObject::connect(saveTy, SIGNAL(clicked()), this, SLOT(SignalAddType()));

    ui->listView->setModel(Cont->View);
    ui->actView->setModel(Cont->ViewActs);

    type->setModel(Cont->ViewTypes);

}


void Dialog::CallModify(int currentRow){
    //creo la finestra e setto i parametri
    CurrentRowList = currentRow;

    //setto i valori dei widgets
    save->setText("Save");
    del->setText("Delete");
    del->setStyleSheet("color: red");
    save->setStyleSheet("color:green");

    //css
    del->setFixedHeight(40);
    save->setFixedHeight(40);
    type->setEditTriggers(type->NoEditTriggers);
    ui->listView->setEditTriggers(type->NoEditTriggers);
    ui->actView->setEditTriggers(type->NoEditTriggers);
    addTy->setFixedWidth(20);
    addTy->setText("+");
    addTy->setStyleSheet("color:green;");
    addTy->setFixedHeight(20);

    name->setPlaceholderText(Cont->model->getName(currentRow));
    //type->setPlaceholderText(Cont->model->getType(currentRow));
    save->setFocus();

    ModWg->show();
    ModWg->setFixedHeight(280);
    ModWg->setFixedWidth(250);
    ModWg->setWindowTitle("List option");
    Grid->addWidget(del, 0, 0);
    Grid->addWidget(name, 1, 0);
    Grid->addWidget(type, 2, 0);
    Grid->addWidget(save, 3, 0);
    Grid->addWidget(addTy, 2, 1);
   // altezza righe
    Grid->setRowStretch(0,2);
    Grid->setRowStretch(1,1);
    Grid->setRowStretch(2,8);
    Grid->setRowStretch(3,2);

    Grid->setColumnStretch(0,5);
    Grid->setColumnStretch(1,1);

    ModWg->setLayout(Grid);

}

void Dialog::CallModifyAct(int currentRow){
    CurrentRowAct = currentRow;
    //ModActWg->setWindowTitle(Cont->L->getActName(CurrentRowList,currentRow));
    ModActWg->setWindowTitle("Activity Option");

    //setto i valori dei wigedts
    saveAct->setText("Save");
    saveAct->setStyleSheet("color:green");
    saveAct->setFocus();
    done->setText("Completed");
    done->setChecked(Cont->model->getDone(CurrentRowList, currentRow));
    saveAct->setFixedHeight(40);
    //fine

    ModActWg->show();
    ModActWg->setFixedHeight(400);
    ModActWg->setFixedWidth(400);

    //layout
    GridAct->addWidget(done, 0, 0);
    GridAct->addWidget(note, 1,0);
    GridAct->addWidget(expiry, 2, 0);
    GridAct->addWidget(saveAct, 3, 0);


    Grid->setRowStretch(0,1);
    Grid->setRowStretch(1,1);
    Grid->setRowStretch(1,2);


    int rowl = ui->listView->currentIndex().row();
    if(rowl == -1) rowl = 0; //se non è selezionato è = -1 e non va bene
    //prendo i dati (se sono settati)
    QString Note = Cont->model->getNoteAct(rowl, currentRow);
    if(Note.isEmpty())
        note->setText("");
    else
        note->setText(Note);

    ModActWg->setLayout(GridAct);
}





void Dialog::SignalNewType(){
    ModNeTy->setWindowTitle("New Type");

    //setto i valori dei widgets
    saveTy->setText("Save");
    saveTy->setStyleSheet("color:green");
    saveTy->setFocus();
    saveAct->setFixedHeight(40);
    NewTy->setPlaceholderText("Enter new type...");
    //fine

    ModNeTy->show();
    ModNeTy->setFixedHeight(200);
    ModNeTy->setFixedWidth(200);

    //layout
    GridTy->addWidget(NewTy, 0, 0);
    GridTy->addWidget(saveTy, 1,0);



    ModNeTy->setLayout(GridTy);
}

void Dialog::SignalAddType(){
    Cont->CallAddType(NewTy->toPlainText());
    ModNeTy->close();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::SignalAddAct(){
    QModelIndex currentList = ui->listView->currentIndex();
    int currentRowList = currentList.row();
    if(currentRowList != -1){    if (Cont->model->getSize() > 0){
    QString ActText = ui->lineEdit->text();
    ui->lineEdit->clear();
    if(ActText != 0)
    Cont->CallAddAct(currentRowList, ActText);}
}}


void Dialog::SignalSaveList(){
    QModelIndex currentList = ui->listView->currentIndex();
    int currentRowList = currentList.row();
    if(currentRowList == -1) currentRowList = 0; //se non è selezionata nessuna lista l'index è -1, e non va bene
    if(name->text() !=0 && type->currentIndex().row() >= 0 )
    Cont->CallSaveList(currentRowList,name->text(), Cont->model->getT(type->currentIndex().row()));
    else if (name->text() == 0 && type->currentIndex().row() >=0)
    Cont->CallSaveList(currentRowList,Cont->model->getName(currentRowList), Cont->model->getT(type->currentIndex().row()));
    else if (name->text() == 0 && type->currentIndex().row() <0)
    Cont->CallSaveList(currentRowList,Cont->model->getName(currentRowList), Cont->model->getType(currentRowList));
    else if (name->text() != 0 && type->currentIndex().row() <0)
    Cont->CallSaveList(currentRowList,name->text(), Cont->model->getType(currentRowList));

    type->reset();
    name->clear();//ci si possono risparmiare i clear tanto si chiude.
    //type->clear();
    ModWg->close();

}



void Dialog::SignalDelList(){
    QModelIndex getRow = ui->listView->currentIndex();
    int row = getRow.row();
    if(row == -1) row=0;
    Cont->CallDelList(row);
    name->clear();//ci si possono risparmiare i clear tanto si chiude.
    //type->clear();
    ModWg->close();

    if(CurrentRowList == Cont->model->getSize())
        CurrentRowList --;
    Cont->ViewActs->SyncActs(Cont->model->getL(),CurrentRowList);
   }

void Dialog::SignalSaveAct(){
    //prendo gli indici correnti
    QModelIndex indexrow = ui->listView->currentIndex();
    int rowl = indexrow.row();
    QModelIndex indexact = ui->actView->currentIndex();
    int rowa = indexact.row();

    if(rowa == -1) rowa = 0;
    if(rowl == -1) rowl = 0;
    Cont->CallSaveAct(rowl, rowa, note->toPlainText(), done->checkState(), expiry->selectedDate());
    Cont->ViewActs->SyncActs(Cont->model->getL(), rowl);
    ModActWg->close();
}

void Dialog::ViewAlert(std::vector<QString> *actExp){

    QString title="Le seguenti attività scadono oggi:\n";
    for(int i=0; i<actExp->size();i++){
         title.append("\n-");
         title.append(actExp->at(i));

    }
    ModAlert->setWindowTitle("Occhio..");
    ModAlert->show();
    ModAlert->setFixedHeight(200);
    ModAlert->setFixedWidth(200);

    this->title->setText(title);
    GridAlert->addWidget(this->title, 0, 0);
    GridAlert->addWidget(alert, 1, 0);

    ModAlert->setLayout(GridAlert);



}
