#include "stats_page.h"
#include "ui_stats_page.h"
#include <QtSql>

StatsPage::StatsPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StatsPage)
{
    ui->setupUi(this);

    // Appeler la méthode pour afficher les statistiques
    displayEquipmentStatistics();
    connect(ui->closeButton, &QPushButton::clicked, this, &StatsPage::close);
}

StatsPage::~StatsPage()
{
    delete ui;
}

void StatsPage::displayEquipmentStatistics()
{
    QSqlQuery query;

    // Nombre total d'équipements
    query.exec("SELECT COUNT(*) FROM EQUIPEMENT");
    query.next();
    int totalEquipment = query.value(0).toInt();

    // Quantité totale d'équipements
    query.exec("SELECT SUM(QUANTITE_EQ) FROM EQUIPEMENT");
    query.next();
    int totalQuantity = query.value(0).toInt();

    // Somme totale des équipements
    query.exec("SELECT SUM(PRIX_EQ) FROM EQUIPEMENT");
    query.next();
    double totalSum = query.value(0).toDouble();

    // Équipement le plus cher
    query.exec("SELECT NOM_EQ FROM EQUIPEMENT ORDER BY PRIX_EQ DESC");
    query.next();
    QString mostExpensive = query.value(0).toString();

    // Équipement le plus disponible
    query.exec("SELECT NOM_EQ FROM EQUIPEMENT ORDER BY QUANTITE_EQ DESC ");
    query.next();
    QString mostAvailable = query.value(0).toString();

    // Équipement le moins disponible
    query.exec("SELECT NOM_EQ FROM EQUIPEMENT ORDER BY QUANTITE_EQ ASC ");
    query.next();
    QString leastAvailable = query.value(0).toString();

    // Affichage des statistiques
    QString statsText = "Statistiques sur les équipements :\n";
    statsText += "Nombre total d'équipements : " + QString::number(totalEquipment) + "\n";
    statsText += "Quantité totale d'équipements : " + QString::number(totalQuantity) + "\n";
    statsText += "Somme totale des équipements : " + QString::number(totalSum) + "\n";
    statsText += "Équipement le plus cher : " + mostExpensive + "\n";
    statsText += "Équipement le plus disponible : " + mostAvailable + "\n";
    statsText += "Équipement le moins disponible : " + leastAvailable + "\n";

    ui->statsLabel->setText(statsText);
}
