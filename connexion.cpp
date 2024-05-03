#include "connexion.h"
#include <QDebug>
#include <QSqlError> // Include QSqlError header for error handling

connexion::connexion()
{

}

bool connexion::creatconnect()
{
    bool test = false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("test-bd");
    db.setUserName("yassin");
    db.setPassword("yassin");

    if (db.open()) {
        test = true;
    } else {
        // Print error message to identify the reason for connection failure
        QSqlError err = db.lastError();
        qDebug() << "Database error:" << err.text(); // Print the error message
    }

    return test;
}
