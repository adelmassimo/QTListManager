#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <QString>
#include <QDate>
#include <QFont>
#include <vector>

class Activity
{
public:
    Activity():done(false){}
    QString getDoneName(){return textDone;}
    QString getName(){return text;}
    QString getNote(){return note;}
    bool getDone(){return done;}
    void setNote(QString newNote){note = newNote;}
    void setName( QString newtext) { text = newtext; textDone="[DONE]\t\t"; textDone.append(text);}
    void setExpiry(QDate Expiry) { expiry = Expiry; }
    QDate getExp(){return expiry;}


    void setDoneName(QString txt){ textDone = txt;}

    void setDone(){
        if (done == true)
            done = false;
        else
            done = true;
    }




private:

     bool done;
     QString textDone;
     QString text;
     QString note;
     QDate expiry;
     std::vector<QString> Comments;


};

#endif // ACTIVITY_H
