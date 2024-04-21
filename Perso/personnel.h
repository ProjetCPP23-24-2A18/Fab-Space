#ifndef PERSONNEL_H
#define PERSONNEL_H
#include <QString>
#include <QDate>


class Personnel
{
private:
    QString id;
    QString name;
    QString lastName;
    QDate dateOfBirth;
    QDate dateEmb;
    QString address;
    QString phone;
    QString email;
    QString function;
    QString UserName;
    QString password;
     QString imagePath;

public:
    Personnel();
    Personnel(const QString &id, const QString &name, const QString &lastName, const QDate &dob,const QDate &de,
           const QString &address, const QString &phone, const QString &email,
           const QString &function,const QString &UserName,const QString &password, const QString &imagePath);

    QString getId() const { return id; }
    QString getName() const { return name; }
    QString getLastName() const { return lastName; }
    QDate getDateOfBirth() const { return dateOfBirth; }
    QDate getDateEmb() const { return dateEmb; }
    QString getAddress() const { return address; }
    QString getPhone() const { return phone; }
    QString getEmail() const { return email; }
    QString getFunction() const { return function; }
    QString getUserName() const { return UserName; }
    QString getPassword() const { return password; }
    void    setImagePath(const QString &path) { imagePath = path; };
    QString getImagePath() const { return imagePath; }

};

#endif // PERSONNEL_H
