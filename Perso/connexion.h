#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlDatabase>
class connexion
{
 public:
    connexion();
    bool creatconnect();
    void closeConnect();
};

#endif // CONNECTION_H
