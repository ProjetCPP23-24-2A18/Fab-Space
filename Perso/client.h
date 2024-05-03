#ifndef CLIENT_H
#define CLIENT_H
#include "QString"
#include <QSqlQuery>
#include <QSqlQueryModel>


class Client
{

private:
    QString nom,prenom,adresse  ;
    int cin;
    int nbe_projet;
public:

    Client();
    Client(QString,QString,int,QString,int);

    void setcin(int n);
    void setnom(QString n);
    void setprenom(QString n);
    void setadresse( QString n);
    void setnbe_projet(int n);
    int get_cin();
    QString get_nom();
    QString get_prenom();
    QString get_adresse();
    int get_nbe_projet();

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier();
    int login(QString email , QString mdp);
    QSqlQueryModel* rechercher(QString);






};

#endif // CLIENT_H
