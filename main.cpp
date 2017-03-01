#include "dialog.h"
#include <QApplication>
#include "lists.h"
#include "model.h"
#include "qmodel.h"
#include <iostream>
#include "controller.h"
#include "qam.h"
#include "qtm.h"
#include <QFile>
#include <QDataStream>
#include <QTextStream>
#include <string>

int serialize_read_list(QFile *list, Model *M, Controller *C, std::vector<QString> *vec); //leggo i dati serializzati
void serialize_write_list(QFile *list, Model *M, Controller *C); //serializzo gli oggetti correnti

void serialize_read_type(QFile *types, Model *M, Controller *C);
void serialize_write_type(QFile *types, Model *M, Controller *C);


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile list("lists.dat");
    QFile types("types.dat");
    Model M;
    std::vector<QString> ActExpiried;


    QLM ViewL;
    QAM ViewA;
    QTM ViewT;
    Controller C(&M, &ViewL, &ViewA, &ViewT);

    serialize_read_type(&types, &M, &C);
    serialize_read_list(&list, &M, &C, &ActExpiried);




    // eseguo

    Dialog w(&C,0,&ActExpiried);

    w.show();
    if(ActExpiried.size() > 0) w.ViewAlert(&ActExpiried);
    a.exec();

    serialize_write_list(&list, &M, &C);
    serialize_write_type(&types, &M, &C);
    std::cout << ActExpiried.size() << std::endl;
    return 0;

}


int serialize_read_list(QFile *list, Model *M, Controller *C, std::vector<QString> *vec ){
    QDataStream out(list);
    if(list->exists()){
        list->open(QIODevice::ReadOnly); //apro in sola lettura

        int numL, numA;  QString nameList, typeList, Act, noteAct; bool doneA;
        QDate expiry, currentDate;
        currentDate = QDate::currentDate();
        out >> numL; //numero delle liste
        for(int i=0; i<numL; i++){
            //prendo tuti i dati delle liste
            out >> nameList;
            out >> typeList;
            M->addList(nameList,typeList);

            out >> numA; //numero attività
            for(int j=0; j < numA; j++){
                //prendo tutti i dati delle attività
                out >> Act;
                out >> noteAct;
                out >> doneA;
                out >> expiry;
                if(expiry == currentDate && doneA == 0){
                    QString tmp = Act;
                    tmp.append("  ["); tmp.append(nameList); tmp.append("]");
                    vec->push_back(tmp);

                }//3RD for




                M->addAct(i,Act);
                M->SaveAct(i,j,noteAct,0,expiry);

                if (doneA == true) M->setDone(i,j);
            } //2Th for

        } //1st for

        list->close();
        return vec->size();
    } //if

    else{ //se non ci sono dati serializzati imposto dati di default

        //Liste di default

        C->CallAddList("Viaggi da Fare", "Travel");
        C->CallAddList("Lista della Spesa", "List");
        C->CallAddList("Privato", "Private");
        C->CallAddList("Lavoro", "Work");
/*
        //Attività di default
        C->CallAddAct(1, "Pane, 1/2 Kg");
        C->CallAddAct(1, "1Lt di Latte");
        C->CallAddAct(1, "3 Uova");

        C->CallAddAct(3, "Implementare la serializzaizone (Maledetta)");
        C->CallAddAct(3, "Staccare il Controller dal model");

        C->CallAddAct(2, "Ricordati di passare da Anna");
        C->CallAddAct(2, "STUDIA!!");

        C->CallAddAct(0, "Islanda");
        C->CallAddAct(0, "Messico");
        C->CallAddAct(0, "Cile");*/
        return 0;
    } //else

} //function

void serialize_write_list(QFile *list, Model *M, Controller *C){
    QDataStream out(list);
    list->open(QIODevice::WriteOnly); //apro in sola scrittura

    out << M->getSize(); //numero Liste
    for(int i=0; i<M->getSize(); i++){
    //setto il nome e il tipo
    out << M->getName(i);
    out << M->getType(i);

    out << M->getnActs(i); //attività
   for(int j=0; j < M->getnActs(i);j++){
       //setto i dati delle attività
       out << M->getActName(i,j);
       out << M->getNoteAct(i,j);
       out << M->getDone(i,j);
       out << M->Getexp(i,j);

   }
}

list->close();

}


void serialize_read_type(QFile *types, Model *M, Controller *C){
    QDataStream out(types);

    if(types->exists()){
        types->open(QIODevice::ReadOnly); //apro in sola lettura

        int NumTy;//numero dei type
        QString NameTy;
        out >> NumTy;

        for(int i = 0; i <= NumTy; i++){
            out >> NameTy;
            M->addT(NameTy);
        }


        types->close(); //chiudo

    }
    else{ //se non ci sono tipi serializzati imposto dati di default
        C->CallAddType("Private");
        C->CallAddType("Travel");
        C->CallAddType("Film");
        C->CallAddType("Work");
        C->CallAddType("Family");
    }
} //function

void serialize_write_type(QFile *types, Model *M, Controller *C){
    QDataStream out(types);
    types->open(QIODevice::WriteOnly); //apro in sola scrittura

    out << M->getNT();


    for(int i = 0; i <= M->getNT(); i++)
        out << M->getT(i);



    types->close();
} //function














