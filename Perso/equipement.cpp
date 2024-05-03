#include "equipement.h"
#include "QString"
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
Equipement::Equipement()
{

    id=0;         // Identifiant de l'équipement
     nom="";    // Nom de l'équipement
    quantite=0;   // Quantité disponible de l'équipement
     prix=0;    // Prix de l'équipement
    prixLoc=0;

}

Equipement::Equipement(int id, QString nom, int quantite, float prix, float prixLoc)
{
    this->id=id;
    this->nom =nom;
    this->quantite = quantite;
    this->prix =prix;
    this->prixLoc =prixLoc;
}
// Accesseur en lecture pour l'identifiant
int Equipement::getId() const {
    return id;
}

// Accesseur en lecture pour le nom
QString Equipement::getNom() const {
    return nom;
}

// Accesseur en lecture pour le prix
float Equipement::getPrix() const {
    return prix;
}

// Accesseur en lecture pour la quantité
int Equipement::getQuantite() const {
    return quantite;
}

// Accesseur en lecture pour le prix de location
float Equipement::getPrixLoc() const {
    return prixLoc;
}

// Accesseur en écriture pour l'identifiant
void Equipement::setId(int id) {
    this->id = id;
}

// Accesseur en écriture pour le nom
void Equipement::setNom(const QString& nom) {
    this->nom = nom;
}

// Accesseur en écriture pour le prix
void Equipement::setPrix(float prix) {
    this->prix = prix;
}

// Accesseur en écriture pour la quantité
void Equipement::setQuantite(int quantite) {
    this->quantite = quantite;
}

// Accesseur en écriture pour le prix de location
void Equipement::setPrixLoc(float prixLoc) {
    this->prixLoc = prixLoc;
}

bool Equipement::Ajouter()
{
    bool test = false;
    QSqlQuery query;
    QString res= QString::number(id);
    QString res1= QString::number(quantite);
    QString res2= QString::number(prix);
    QString res3= QString::number(prixLoc);
    QString queryString = ("INSERT INTO EQUIPEMENT (ID_EQ,NOM_EQ,QUANTITE_EQ,PRIX_EQ,PRIXLOC_EQ) VALUES (:ID_EQ,:NOM_EQ,:QUANTITE_EQ,:PRIX_EQ,:PRIXLOC_EQ)");

    query.prepare(queryString);
    query.bindValue(":ID_EQ",res);
    query.bindValue(":NOM_EQ",nom);
    query.bindValue(":QUANTITE_EQ",res1);
    query.bindValue(":PRIX_EQ",res2);
    query.bindValue(":PRIXLOC_EQ",res3);

    qDebug() << "Executing query:" << queryString;
    qDebug() << "Bound values:";
    qDebug() << "ID_EQ:" << id;
    qDebug() << "NOM_EQ:" << nom;
    qDebug() << "QUANTITE_EQ:" << quantite;
    qDebug() << "PRIX_EQ:" << prix;
    qDebug() << "PRIXLOC_EQ:" << prixLoc;

    if (query.exec()) {
        test = true;
        qDebug() << "Equipement ajouté avec succès.";
    } else {
        qDebug() << "Erreur lors de l'ajout de l'équipement :" << query.lastError().text();
    }

    return test;
}

bool Equipement::Supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM EQUIPEMENT WHERE ID_EQ = :id");
    query.bindValue(":id", id);

    return query.exec();
}



QSqlQueryModel* Equipement::Afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT ID_EQ, NOM_EQ, QUANTITE_EQ, PRIX_EQ, PRIXLOC_EQ FROM EQUIPEMENT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Quantité"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prix location"));
    return model;
}


bool Equipement::Modifier(int id)
{
    QSqlQuery query;
    QString r= QString::number(id);
    QString r1= QString::number(quantite);
    QString r2= QString::number(prix);
    QString r3= QString::number(prixLoc);
    query.prepare("UPDATE EQUIPEMENT SET NOM_EQ = :NOM_EQ, QUANTITE_EQ = :QUANTITE_EQ, "
                  "PRIX_EQ = :PRIX_EQ, PRIXLOC_EQ = :PRIXLOC_EQ WHERE ID_EQ = :ID_EQ");
    query.bindValue(":NOM_EQ", nom);
    query.bindValue(":QUANTITE_EQ", r1);
    query.bindValue(":PRIX_EQ", r2);
    query.bindValue(":PRIXLOC_EQ", r3);
    query.bindValue(":ID_EQ", r);

    return query.exec();
}

