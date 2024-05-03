
#include "client.h"
#include "QString"
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>

Client::Client()
{
    nom = "Nom "; // Initialise avec une valeur par défaut
    prenom = "Prenom"; // Initialise avec une valeur par défaut
    cin = 6; // Initialise à zéro (ou une valeur appropriée) selon votre logique
    adresse = "Adresse"; // Initialise avec une valeur par défaut
    nbe_projet = 0; // Initialise à zéro (ou une valeur appropriée) selon votre logique
}
void Client::setprenom(QString n){prenom=n;}
void Client::setnom(QString n){nom=n;}

void Client::setcin(int n) {

        cin = n;
}
void Client::setadresse( QString n) {
        adresse = n;

}
void Client ::setnbe_projet(int n){nbe_projet=n;}
QString Client::get_prenom(){return prenom;}
QString Client::get_nom(){return nom;}
int Client::get_cin(){return cin;}
QString Client::get_adresse(){return adresse;}
int Client::get_nbe_projet(){return nbe_projet;}




Client::Client(QString prenom,QString nom,int cin,QString adresse,int nbe_projet)
{
    this->prenom=prenom;

    this->nom=nom;
    this->cin=cin;

    this->adresse=adresse;
    this->nbe_projet=nbe_projet;
}

bool Client::ajouter() {
    bool test = false;
    QSqlQuery query;
    QString cin_string = QString::number(cin);
    QString nbe_projet_string = QString::number(nbe_projet);

    QString queryString = "INSERT INTO CLIENT (PRENOM, NOM, CIN, ADRESSE, NBE_PROJET) "
                          "VALUES (:PRENOM, :NOM, :CIN, :ADRESSE, :NBE_PROJET)";

    query.prepare(queryString);
    query.bindValue(":PRENOM", prenom);
    query.bindValue(":NOM", nom);
    query.bindValue(":CIN", cin_string);
    query.bindValue(":ADRESSE", adresse);
    query.bindValue(":NBE_PROJET", nbe_projet_string);

    qDebug() << "Executing query:" << queryString;
    qDebug() << "Bound values:";
    qDebug() << "PRENOM:" << prenom;
    qDebug() << "NOM:" << nom;
    qDebug() << "CIN:" << cin_string;
    qDebug() << "ADRESSE:" << adresse;
    qDebug() << "NBE_PROJET:" << nbe_projet_string;

    if (query.exec()) {
        test = true;
        qDebug() << "Client added successfully.";
    } else {
        qDebug() << "Error inserting client:" << query.lastError().text();
    }

    return test;
}





bool Client::supprimer(int cin)
{
     QSqlQuery query;
    query.prepare("delete from CLIENT where CIN=:CIN");
    query.bindValue(":CIN", cin);



    return  query.exec();
}



QSqlQueryModel* Client::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT*  FROM CLIENT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("PRENOM"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE-EMAIL"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("NOMBRE DE PROJETS"));





    return model;
}

bool Client::modifier()
{
    QSqlQuery query;

    query.prepare("UPDATE CLIENT SET NOM = :nom, PRENOM = :prenom, ADRESSE = :adresse, NBE_PROJET = :nbe_projet WHERE CIN = :cin");
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":cin", cin);
    query.bindValue(":adresse", adresse);
    query.bindValue(":nbe_projet", nbe_projet);

    if (query.exec()) {
        return true;
    } else {
        qDebug() << "Error executing SQL query:" << query.lastError().text();
        return false;
    }
}

QSqlQueryModel* Client::rechercher(QString a)
{
    QSqlQueryModel * query=new QSqlQueryModel();
    query->setQuery("select * from CLIENT where (NOM like '%"+a+"%' or PRENOM like '%"+a+"%' ) ");
    return    query;
}

int Client::login(QString email, QString mdp)
{
int row_count = 0;
QSqlQuery query;
query.prepare("SELECT * FROM CADMIN where NOM=? and MOTDEPASSE=? ");
query.addBindValue(email);
    query.addBindValue(mdp);
 query.exec();
 while(query.next())
 {
     row_count++;
 }
qDebug() << "Number of Rows: " << row_count;
return row_count;
}
