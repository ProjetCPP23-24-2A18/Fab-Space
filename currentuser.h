#ifndef CURRENTUSER_H
#define CURRENTUSER_H

#include <QString>

class CurrentUser {
public:
    CurrentUser(const QString &username, const QString &role)
        : m_username(username), m_role(role) {}

    QString username() const { return m_username; }
    QString role() const { return m_role; }

private:
    QString m_username;
    QString m_role;
};

#endif // CURRENTUSER_H
