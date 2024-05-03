#ifndef ESPACE_H
#define ESPACE_H

#include <QString>
#include <QSqlQueryModel>
#include <QTableView>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDate> // Include QDate for handling DATE type

class espace
{
public:
    espace();
    espace(QString reference, int quantite, QString type, int etat, const QDate &disponibilite); // Add DISPONIBILITE to constructor parameters
    QString getReference() const; // Update getter methods to const
    int getQuantite() const;
    QString getType() const;
    int getEtat() const;
    QDate getDisponibilite() const; // Add getter for DISPONIBILITE

    void setReference(const QString &reference);
    void setQuantite(int quantite);
    void setType(const QString &type);
    void setEtat(int etat);
    void setDisponibilite(const QDate &disponibilite); // Add setter for DISPONIBILITE

    bool ajouter(const QString &reference);
    QSqlQueryModel *afficher();
    bool supprimer(const QString &reference);
    bool modifier(const QString &reference);
    void create_PDF();
    QSqlQueryModel *rechercherD(const QString &reference);
    QSqlQueryModel *rechercherR(const QString &reference);
    QSqlQueryModel *triA();
    QSqlQueryModel *triReference();
    void recherche(QTableView *table, const QString x);
    void clearTable(QTableView *table);

private:
    int quantite, etat;
    QString reference, type;
    QDate disponibilite; // Add DISPONIBILITE attribute
};

#endif // ESPACE_H
