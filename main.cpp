#include "mainwindow.h"
#include "connexion.h"
#include <QMessageBox>
#include <QApplication>
#include <QMessageBox>
#include <QtGlobal> // Include for qrand()
//#include "smtpclient.h"
#include "mimepart.h"
#include "mimeattachment.h"
#include "emailaddress.h"
#include "mimetext.h"
#include <QDateTime>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connexion c;
    bool test=c.creatconnect();
    MainWindow w;
    if(test)
    {w.show();
        QMessageBox::critical(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);




    return a.exec();
}

