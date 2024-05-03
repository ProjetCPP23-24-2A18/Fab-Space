#include "smtp.h"

Smtp::Smtp(const QString &user, const QString &pass, const QString &host, int port, int timeout)
{
    socket = new QSslSocket(this);

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(errorReceived(QAbstractSocket::SocketError)));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));

    this->user = user;
    this->pass = pass;
    this->host = host;
    this->port = port;
    this->timeout = timeout;

    socket->setProtocol(QSsl::TlsV1_2); // Set SSL version explicitly

    qDebug() << "SSL support: " << QSslSocket::supportsSsl();

    if (!QSslSocket::supportsSsl()) {
        // Handle the case where SSL support is not available
        qDebug() << "SSL is not supported!";
        return;
    }

    socket->connectToHostEncrypted(host, port);
    if (!socket->waitForConnected(timeout)) {
        qDebug() << "Connection error: " << socket->errorString();
        return;
    }
}

void Smtp::sendMail(const QString &from, const QString &to, const QString &subject, const QString &body, QStringList files)
{
    if (!socket->isOpen()) {
        qDebug() << "Connection is not open.";
        return;
    }

    message = "To: " + to + "\r\n";
    message.append("From: " + from + "\r\n");
    message.append("Subject: " + subject + "\r\n");
    message.append("MIME-Version: 1.0\r\n");
    message.append("Content-Type: multipart/mixed; boundary=frontier\r\n\r\n");
    message.append("--frontier\r\n");
    message.append("Content-Type: text/plain\r\n\r\n");
    message.append(body + "\r\n\r\n");

    for (const QString &filePath : files) {
        QFile file(filePath);
        if (file.exists() && file.open(QIODevice::ReadOnly)) {
            QByteArray bytes = file.readAll();
            message.append("--frontier\r\n");
            message.append("Content-Type: application/octet-stream\r\n");
            message.append("Content-Disposition: attachment; filename=" + QFileInfo(file.fileName()).fileName() + "\r\n");
            message.append("Content-Transfer-Encoding: base64\r\n\r\n");
            message.append(bytes.toBase64() + "\r\n");
        }
    }

    message.append("--frontier--\r\n");

    if (socket->isOpen()) {
        *t << "MAIL FROM:<" << from << ">\r\n";
        t->flush();
        *t << "RCPT TO:<" << to << ">\r\n";
        t->flush();
        *t << "DATA\r\n";
        t->flush();
        *t << message << "\r\n.\r\n";
        t->flush();
    } else {
        qDebug() << "Connection is not open.";
    }
}

void Smtp::readyRead()
{
    QString responseLine;
    do {
        responseLine = socket->readLine();
        response += responseLine;
    } while (socket->canReadLine() && responseLine[3] != ' ');

    responseLine.truncate(3);
    qDebug() << "Server response code: " << responseLine;
    qDebug() << "Server response: " << response;

    // Handle SMTP response codes and process accordingly
    // Implement your logic here
}

void Smtp::connected()
{
    qDebug() << "Connected to SMTP server.";
    // Implement any initialization or authentication steps here
}

void Smtp::errorReceived(QAbstractSocket::SocketError socketError)
{
    qDebug() << "Socket error: " << socketError;
    // Implement error handling or logging here
}

void Smtp::disconnected()
{
    qDebug() << "Disconnected from SMTP server.";
    // Implement any cleanup or finalization steps here
}
void Smtp::stateChanged(QAbstractSocket::SocketState socketState)
{
    qDebug() << "Socket state changed: " << socketState;
    // Add your implementation logic here
}
Smtp::~Smtp()
{
    delete t; // Delete QTextStream object
    delete socket; // Delete QSslSocket object
}
