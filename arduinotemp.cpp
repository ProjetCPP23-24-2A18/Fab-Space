#include "arduinotemp.h"
#include "ui_arduinotemp.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QTimer>

arduinotemp::arduinotemp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::arduinotemp)
{
    ui->setupUi(this);
    int ret = A.connect_arduino(); // lancer la connexion à Arduino
    switch(ret){
    case(0):
        qDebug()<< "Arduino is available and connected to: "<< A.getarduino_port_name();
        break;
    case(1):
        qDebug() << "Arduino is available but not connected to: " << A.getarduino_port_name();
        break;
    case(-1):
        qDebug() << "Arduino is not available";
        break;
    }

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &arduinotemp::update_label);
    timer->start(1000); // Mettre à jour label_etat toutes les 1000 millisecondes (1 seconde)

    QTimer *ventilationTimer = new QTimer(this);
    connect(ventilationTimer, &QTimer::timeout, this, &arduinotemp::control_ventilation_based_on_database);
   // Vérifier et contrôler la ventilation toutes les 1000 millisecondes (1 minute)
}

arduinotemp::~arduinotemp()
{
    delete ui;
}

void arduinotemp::on_onlm35_clicked()
{
    A.write_to_arduino("1");
}

void arduinotemp::on_offlm35_clicked()
{
    A.write_to_arduino("0");
}

void arduinotemp::update_label()
{
    // Lire les données depuis Arduino
    QByteArray data = A.read_from_arduino();

    // Convertir QByteArray en QString en utilisant différentes méthodes
    QString receivedData;
    if (!data.isEmpty()) {
        receivedData = QString::fromUtf8(data); // Supposant que les données sont réellement encodées en UTF-8
    }

    // Afficher les données reçues dans la console
    qDebug() << "Received data from Arduino:" << receivedData;

    // Analyser la valeur de température à partir des données reçues
    bool ok;
    float temperature = receivedData.toFloat(&ok);
    if (!ok) {
        qDebug() << "Failed to parse temperature value from the received data.";
        return;
    }

    // Mettre à jour label_etat avec les données reçues
    ui->label_etat->setText(receivedData);

    // Mettre à jour l'attribut de la base de données 'temperature' en fonction de la valeur de température
    QSqlQuery query;
    QString temp = QString::number(temperature);
    query.prepare("UPDATE ESPACE SET TEMPERATURE = :temperature WHERE REFERENCE = 'h5555'");
    query.bindValue(":temperature", temp); // Lier la température directement à la requête
    if (!query.exec()) {
        qDebug() << "Failed to update database:" << query.lastError().text();
    }
}

void arduinotemp::control_ventilation_based_on_database()
{
    // Sélectionner la dernière température enregistrée dans la base de données
    QSqlQuery query;
    query.prepare("SELECT TEMPERATURE FROM ESPACE WHERE REFERENCE = 'h5555'");
    if (!query.exec()) {
        qDebug() << "Failed to fetch temperature from database:" << query.lastError().text();
        return;
    }

    if (query.next()) {
        // Récupérer la température depuis la base de données
        float temperature = query.value(0).toFloat();

        // Contrôler la ventilation en fonction de la température récupérée
        if (temperature > 35.0) {
            A.write_to_arduino("2"); // Activer la ventilation en envoyant "2" à Arduino
        } else {
            A.write_to_arduino("3"); // Désactiver la ventilation en envoyant "3" à Arduino
        }
    } else {
        qDebug() << "No temperature data found in the database.";
    }
}
