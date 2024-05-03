#include "personnel.h"
#include "connexion.h"
#include "personnel.h"
#include "mainwindow.h"




Personnel::Personnel()
    : id(""), name(""), lastName(""), dateOfBirth(QDate::currentDate()),
      dateEmb(QDate::currentDate()), address(""), phone(""),
      email(""), function(""), UserName(""), password(""),
      imagePath("")  // Initialize imagePath in your constructor
{
}

Personnel::Personnel(const QString &id, const QString &name, const QString &lastName, const QDate &dob,const QDate &de,
               const QString &address, const QString &phone, const QString &email,
               const QString &function,const QString &UserName,const QString &password, const QString &imagePath)
    : id(id), name(name), lastName(lastName), dateOfBirth(dob),dateEmb(de), address(address),
      phone(phone), email(email), function(function), UserName(UserName), password(password), imagePath(imagePath) // Initializer list includes imagePath
{
}

// The getters have been implemented inline in the header file.
