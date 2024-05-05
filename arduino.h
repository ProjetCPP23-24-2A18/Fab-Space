#ifndef ARDUINO_H
#define ARDUINO_H

#include <QObject> // Include QObject header to use Q_OBJECT macro
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>

class Arduino : public QObject // Inherit from QObject
{
    Q_OBJECT // Add the Q_OBJECT macro

public:
    Arduino();
    void initPort(const QString &portName);
    int connect_arduino();
    int close_arduino();
    int write_to_arduino(QByteArray);
    QByteArray read_from_arduino();
    QSerialPort* getserial();
    QString getarduino_port_name();

private:
    void processTheCardData(const QByteArray &data);
    QSerialPort *serial;
    static const quint16 arduino_uno_vendor_id;
    static const quint16 arduino_uno_producy_id;
    QString arduino_port_name;
    bool arduino_is_available;
    QByteArray data;

signals:
    void cardScanned(const QString &cardID);

private slots:
    void onReadyRead();
};

#endif // ARDUINO_H


