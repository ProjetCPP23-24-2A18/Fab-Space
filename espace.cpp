#include "espace.h"
#include "QSqlQuery"
#include "QtDebug"
#include "QObject"
#include <iostream>
#include <QFileDialog>
#include <QPrinter>
#include <QTextDocument>
#include <QSqlRecord>
#include <QCoreApplication>
#include <QtWidgets/QApplication>
#include <QtNetwork/QSslSocket>
#include <QtNetwork/QSslError>
#include <QtNetwork/QSslConfiguration>
#include <QtNetwork/QHostAddress>
#include <QTableView>
#include <QPainter>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

using namespace std;

espace::espace()
{
    reference = "";
    quantite = 0;
    type = "";
    etat = 0;
}

espace::espace(QString reference, int quantite, QString type, int etat, const QDate &disponibilite)
{
    this->reference = reference;
    this->quantite = quantite;
    this->type = type;
    this->etat = etat;
    this->disponibilite = disponibilite;
}
QString espace::getReference() const {
    return reference;
}

void espace::setReference(const QString &reference)
{
    this->reference = reference;
}

void espace::setQuantite(int quantite)
{
    this->quantite = quantite;
}

void espace::setType(const QString &type)
{
    this->type = type;
}

void espace::setEtat(int etat)
{
    this->etat = etat;
}

void espace::setDisponibilite(const QDate &disponibilite)
{
    this->disponibilite = disponibilite;
}

bool espace::ajouter(const QString &reference)
{

    QSqlQuery query;
    //QString reference_string=QString::number(reference) ;
    QString quantite_string = QString::number(quantite);
    QString etat_string = QString::number(etat);

    if (reference == "")
    {
        query.prepare("INSERT INTO espace(QUANTITE, TYPE, ETAT, DISPONIBILITE)"
                      "VALUES ( :quantite ,:type, :etat, :disponibilite)");
    }
    else
    {
        query.prepare("INSERT INTO espace(REFERENCE, QUANTITE, TYPE, ETAT, DISPONIBILITE) "
                      "VALUES (:reference, :quantite, :type, :etat, :disponibilite)");
        query.bindValue(":reference", reference);
    }

    query.bindValue(":quantite", quantite);
    query.bindValue(":type", type);
    query.bindValue(":etat", etat);
    query.bindValue(":disponibilite", disponibilite);
    return query.exec();
}

QSqlQueryModel *espace::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT* FROM espace");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("reference :"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("quantite :"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type :"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("etat :"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("disponibilite :"));

    return model;
}

bool espace::supprimer(const QString &reference)
{

    QSqlQuery query;
    query.prepare("Delete from espace where REFERENCE=:reference");
    query.bindValue(":reference", reference);

    return query.exec();
}

bool espace::modifier(const QString &reference)
{
    QSqlQuery query;
    QString quantite_string = QString::number(quantite);
    QString etat_string = QString::number(etat);
    query.prepare("UPDATE espace SET REFERENCE = :reference, QUANTITE = :quantite, TYPE = :type, ETAT = :etat, DISPONIBILITE = :disponibilite WHERE REFERENCE = :ref");
    query.bindValue(":reference", reference);
    query.bindValue(":quantite", quantite_string);
    query.bindValue(":type", type);
    query.bindValue(":etat", etat_string);
    query.bindValue(":disponibilite", disponibilite);
    query.bindValue(":ref", reference); // bind the reference again for WHERE clause

    if (!query.exec()) {
        qDebug() << "Error executing update query:" << query.lastError().text();
        return false;
    }

    return true;
}
void espace::clearTable(QTableView *table)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->clear();
    table->setModel(model);
}

void espace::create_PDF()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget *)0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty())
    {
        fileName.append(".pdf");
    }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);

    QTextDocument doc;

    // Date
    QDateTime dateTime = QDateTime::currentDateTime();
    QString currentDate = dateTime.toString("dd/MM/yyyy");

    // Tableau
    QSqlQuery q;
    q.prepare("SELECT * FROM espace");
    q.exec();
    QString pdf = "<div style='border: 2px solid black; padding: 10px; text-align: center;'>";
    pdf += "<p style='position: absolute; top: 40px; left: 0px; font-family: \"Times New Roman\", Times, serif;'>Date: " + currentDate + "</p>";
    pdf += "<h1 style='font-family: \"Times New Roman\", Times, serif; color: #ADD8E6;'>Liste des salles</h1>";
    pdf += "<table style='border-collapse: collapse; width: 100%; background-color: #E0FFFF;'>";
    pdf += "<thead><tr style='background-color: #0074D9; color: white;'>";
    pdf += "<th style='padding: 10px; border: 1px solid #ddd;'>Référence</th>";
    pdf += "<th style='padding: 10px; border: 1px solid #ddd;'>Quantité</th>";
    pdf += "<th style='padding: 10px; border: 1px solid #ddd;'>Type</th>";
    pdf += "<th style='padding: 10px; border: 1px solid #ddd;'>État</th>";
    pdf += "<th style='padding: 10px; border: 1px solid #ddd;'>Disponibilité</th>";
    pdf += "</tr></thead><tbody>";

    while (q.next())
    {
        QString idColor = (q.value(2).toDouble() == 100) ? "red" : "";
        pdf += "<tr>";
        pdf += "<td style='padding: 10px; border: 1px solid #ddd;'>" + q.value(0).toString() + "</td>";
        pdf += "<td style='padding: 10px; border: 1px solid #ddd;'>" + q.value(1).toString() + "</td>";
        pdf += "<td style='padding: 10px; border: 1px solid #ddd;'>" + q.value(2).toString() + "</td>";
        pdf += "<td style='padding: 10px; border: 1px solid #ddd;'>" + q.value(3).toString() + "</td>";
        pdf += "<td style='padding: 10px; border: 1px solid #ddd;'>" + q.value(4).toDate().toString("dd/MM/yyyy") + "</td>";
        pdf += "<td style='padding: 10px; border: 1px solid #ddd; color: " + idColor + "'>" + q.value(7).toString() + "</td>";
        pdf += "</tr>";
    }

    pdf += "</tbody></table></div>";
    doc.setHtml(pdf);
    doc.setPageSize(printer.pageRect().size());
    doc.print(&printer);
}

void espace::recherche(QTableView *table, QString x)
{

    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery;
    query->prepare("select * from espace WHERE reference=:reference");
    query->bindValue(":reference", x);

    if (x.isEmpty())
    {
        query->prepare("select * from espace;");
    }
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();
}

QSqlQueryModel *espace::triReference()
{
    QSqlQueryModel *model = new QSqlQueryModel();

    model->setQuery("select * from ESPACE order by reference ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("reference :"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantite :"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("type :"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("etat :"));
    return model;
}


