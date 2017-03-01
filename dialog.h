#ifndef DIALOG_H
#define DIALOG_H

#include "controller.h"
#include "model.h"
#include <QDialog>
#include <QLineEdit>
#include <QListView>
#include <QTextEdit>
#include <QCheckBox>
#include <QFont>
#include <QCalendarWidget>

namespace Ui {
class Dialog;
}
class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(Controller *C, QWidget *parent = 0, std::vector<QString> *actExp = 0);
    void CallModify(int currentRow);
    void CallModifyAct(int currentRow);
    ~Dialog();

private:

    int CurrentRowList;
    int CurrentRowAct;
    Ui::Dialog *ui;
    Controller *Cont;
    //finestra modify List
    QWidget *ModWg;
    QPushButton *save;
    QPushButton *del;
    QLineEdit *name;
    QListView *type;
    QPushButton *addTy;
    QGridLayout *Grid;
    //fine
    //finestra modify Act
    QWidget *ModActWg;
    QPushButton *saveAct;
    QTextEdit *note;
    QCheckBox *done;
    QGridLayout *GridAct;
    //finestra new type
    QWidget *ModNeTy;
    QPushButton *saveTy;
    QTextEdit *NewTy;
    QCalendarWidget *expiry; //scadenza attività
    QGridLayout *GridTy;
    //window alert
    QWidget *ModAlert;
    QGridLayout *GridAlert;
    QLabel *title;
    QLabel *alert;





public slots:
    void SignalAddList(){Cont->CallAddList();}

    void SignalModifyList(const QModelIndex &index){
       std::cout<< index.row()<< std::endl;
       CallModify(index.row());
    }

    void SignalModifyAct(const QModelIndex &index){
        int rowAct = index.row();
        CallModifyAct(rowAct);
    }

    void SignalNewType();
    void SignalAddType();

    void SignalAddAct();
    void SignalSaveList();
    void SignalDelList();
    void SignalSaveAct();
    void changeActs( const QModelIndex &index){CurrentRowList=index.row(); Cont->ViewActs->SyncActs( Cont->model->getL(), index.row());}
    void SignalDelAct(const QModelIndex &index){Cont->CallDoneAct(index.row());}

    void ViewAlert(std::vector<QString> *actExp);


};

#endif // DIALOG_H
