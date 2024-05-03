#ifndef ARDUINOTEMP_H
#define ARDUINOTEMP_H

#include "arduino.h"

#include <QDialog>

namespace Ui {
class arduinotemp;
}

class arduinotemp : public QDialog
{
    Q_OBJECT

public:
    explicit arduinotemp(QWidget *parent = nullptr);
    ~arduinotemp();

private:
    Ui::arduinotemp *ui;
    QByteArray data; // variable contenant les données reçues
    Arduino A; // objet temporaire
private slots:
    void update_label();
    void on_ondht11_clicked();
    void on_offdht11_clicked();
   void updateTemperatureInDatabase(const QString &reference, const QString &temperature);
};

#endif // ARDUINOTEMP_H
