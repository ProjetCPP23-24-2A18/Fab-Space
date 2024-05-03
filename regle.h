#ifndef REGLE_H
#define REGLE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QDebug>



class REGLE
{
    QString type,desc,con;
    int id;

public:
    REGLE();
    REGLE(int,QString,QString,QString);

    QString gettype(){return type;}
    QString getdesc(){return desc;}
    int getid(){return id;}
    QString getcon(){return con;}




    void settype(QString n){type=n;}
    void setdesc(QString a){desc=a;}
    void setid(int id){this->id=id;}
    void setcon(QString a2){con=a2;}



    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * sorttype();
    QSqlQueryModel * sortid();
    bool supprimer(int);
    bool modifier(int id, const QString &type, const QString &desc, const QString &con);
    int countadhesion(QString);
    int countlocation (QString);
    int countservice (QString);


};

#endif //
