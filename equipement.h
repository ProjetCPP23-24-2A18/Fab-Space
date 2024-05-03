#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H

#include <QString> // Inclure le fichier d'en-tête nécessaire pour utiliser QString
#include <QSqlQuery>
#include <QSqlQueryModel>
class Equipement {
    int id;         // Identifiant de l'équipement
    QString nom;    // Nom de l'équipement
    int quantite;   // Quantité disponible de l'équipement
    float prix;    // Prix de l'équipement
    float prixLoc; // Prix de location de l'équipement

public:

    // Constructeur par défaut
    Equipement();

    // Constructeur avec paramètres pour initialiser les attributs

    Equipement(int, QString, int, float, float);


    // Accesseurs en lecture
    int getId() const;
    QString getNom() const;
    float getPrix() const;
    int getQuantite() const;
    float getPrixLoc() const;

    // Accesseurs en écriture
    void setId(int id);
    void setNom(const QString& nom);
    void setPrix(float prix);
    void setQuantite(int quantite);
    void setPrixLoc(float prixLoc);

    bool Ajouter();
    bool Modifier(int);
    QSqlQueryModel * Afficher();
    bool Supprimer(int);
    int login(QString email , QString mdp);


private:

};

#endif // EQUIPEMENT_H

