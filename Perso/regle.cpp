#include "regle.h"
#include<QDebug>
#include <QSqlError>

REGLE::REGLE()
{

}

REGLE::REGLE(int id, QString type, QString desc, QString con)
{
    this->id = id;
    this->type = type;
    this->desc = desc;
    this->con = con;

}

bool REGLE::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(id);

    if (res.length() > 8 || !res.toInt()) {
        qDebug() << "L'ID n'est pas un nombre valide ou a plus de 8 caractères. L'ajout a échoué.";
        return false;
    }

    // Check if the type length exceeds the maximum allowed length (20 characters)
    if (type.length() > 30) {
        qDebug() << "La longueur du type dépasse la longueur maximale autorisée. L'ajout a échoué.";
        return false;
    }

    // Truncate the type if needed
    QString truncatedType = type.left(30);

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT ID_REGLE FROM REGLE WHERE ID_REGLE = :id");
    checkQuery.bindValue(":id", res);
    checkQuery.exec();

    if (checkQuery.next()) {
        qDebug() << "L'ID existe déjà. L'ajout a échoué.";
        return false;
    } else {
        query.prepare("INSERT INTO REGLE(ID_REGLE, TYPE_REGLE, DESCRIPTION, CONDITIONS) VALUES(:id, :type, :desc, :con)");
        query.bindValue(":id", res); // Bind the ID as a string
        query.bindValue(":type", truncatedType); // Bind the truncated type
        query.bindValue(":desc", desc);
        query.bindValue(":con", con);

        return query.exec();
    }
}



bool REGLE::supprimer(int id)
{
    QSqlQuery query;
    QString res = QString::number(id);

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT ID_REGLE FROM REGLE WHERE ID_REGLE = :id");
    checkQuery.bindValue(":id",res);
    checkQuery.exec();

    if (checkQuery.next()) {
        query.prepare("DELETE FROM REGLE WHERE ID_REGLE = :id");
        query.bindValue(":id", res);
        return query.exec();
    }
    else
    {
        qDebug() << "ID not found in the database";
        return false;
    }
}

QSqlQueryModel * REGLE::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM REGLE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("time debut"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("time fin"));

    return model;
}

bool REGLE::modifier(int id, const QString &type, const QString &desc, const QString &con)
{
    QSqlQuery query;
    QString res = QString::number(id);
    QSqlQuery checkQuery;

    checkQuery.prepare("SELECT ID_REGLE FROM REGLE WHERE ID_REGLE = :ID_REGLE");
    checkQuery.bindValue(":ID_REGLE", res);
    checkQuery.exec();

    if (checkQuery.next()) {

        QString updateQuery = "UPDATE REGLE SET";


        if (type != "") {
            updateQuery += " TYPE_REGLE = :type,";
        }
        if (desc != "") {
            updateQuery += " DESCRIPTION = :desc,";
        }
        if (con != "") {
            updateQuery += " CONDITIONS = :con,";
        }


        updateQuery.chop(1);


        updateQuery += " WHERE ID_REGLE = :id";

        query.prepare(updateQuery);
        query.bindValue(":id", res);
        if (type != "") {
            query.bindValue(":type", type);
        }
        if (desc != "") {
            query.bindValue(":desc", desc);
        }
        if (con != "") {
            query.bindValue(":con", con);
        }


        return query.exec();
    } else {
        qDebug() << "ID not found in the database. Modification failed.";
        return false;
    }
}


QSqlQueryModel *REGLE:: sortid()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from REGLE order by ID_REGLE asc ;");
    return model;
}

QSqlQueryModel *REGLE:: sorttype()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from REGLE order by TYPE_REGLE asc ;");
    return model;
}



int REGLE::countadhesion(QString type) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) AS etat_count FROM REGLE WHERE TYPE_REGLE LIKE :type");
    query.bindValue(":type", "%" + type + "%");

    if (query.exec() && query.next()) {
        int count = query.value("etat_count").toInt();
        qDebug() << "adhesion Count:" << count; // Debug output
        return count;
    } else {
        QSqlError error = query.lastError();
        qDebug() << "Error executing adhesion query:" << error.text(); // Debug output
        return -1;
    }
}

int REGLE::countlocation(QString type) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) AS etat_count FROM REGLE WHERE TYPE_REGLE LIKE :type");
    query.bindValue(":type", "%" + type + "%");

    if (query.exec() && query.next()) {
        int count = query.value("etat_count").toInt();
        qDebug() << "Location Count:" << count; // Debug output
        return count;
    } else {
        QSqlError error = query.lastError();
        qDebug() << "Error executing location query:" << error.text(); // Debug output
        return -1;
    }
}

int REGLE::countservice(QString type) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) AS etat_count FROM REGLE WHERE TYPE_REGLE LIKE :type");
    query.bindValue(":type", "%" + type + "%");

    if (query.exec() && query.next()) {
        int count = query.value("etat_count").toInt();
        qDebug() << "Service Count:" << count; // Debug output
        return count;
    } else {
        QSqlError error = query.lastError();
        qDebug() << "Error executing service query:" << error.text(); // Debug output
        return -1;
    }
}

