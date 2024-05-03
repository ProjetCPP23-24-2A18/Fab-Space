#include "arduinotemp.h"
#include "ui_arduinotemp.h"
#include <QSqlQuery>
#include <QSqlError>

arduinotemp::arduinotemp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::arduinotemp)
{
    ui->setupUi(this);
    int ret = A.connect_arduino();
    switch(ret) {
        case 0:
            qDebug() << "Arduino is available and connected to:" << A.get_arduino_port_name();
            break;
        case 1:
            qDebug() << "Arduino is available but not connected to:" << A.get_arduino_port_name();
            break;
        case -1:
            qDebug() << "Arduino is not available";
            break;
    }
    QObject::connect(A.get_serial(), SIGNAL(readyRead()), this, SLOT(update_label()));
}

void arduinotemp::update_label()
{
    data = A.read_from_arduino();
    if(data == "0") {
        ui->label_etat->setText("Normal temperature");
        updateTemperatureInDatabase("444", "Normal"); // Update temperature in database
    } else if (data == "1") {
        ui->label_etat->setText("High temperature");
        updateTemperatureInDatabase("444", "High"); // Update temperature in database
    } else if (data == "2") {
        ui->label_etat->setText("Low temperature");
        updateTemperatureInDatabase("444", "Low"); // Update temperature in database
    }
}

void arduinotemp::updateTemperatureInDatabase(const QString &reference, const QString &temperature)
{
    QSqlDatabase db = QSqlDatabase::database(); // Retrieve the existing database connection

    if (db.isOpen()) {
        QSqlQuery query(db);
        QString sqlQuery = QString("UPDATE espace SET temperature='%1' WHERE reference='%2'")
                .arg(temperature)
                .arg(reference);
        if (!query.exec(sqlQuery)) {
            qDebug() << "Failed to update temperature in database:" << query.lastError().text();
        } else {
            qDebug() << "Temperature updated in database for reference" << reference;
        }
    } else {
        qDebug() << "Database connection is not open";
    }
}

void arduinotemp::on_ondht11_clicked()
{
    A.write_to_arduino("1");
}

void arduinotemp::on_offdht11_clicked()
{
    A.write_to_arduino("0");
}

arduinotemp::~arduinotemp()
{
    delete ui;
}
