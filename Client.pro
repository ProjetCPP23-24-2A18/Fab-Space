QT+= sql

QT       += core gui sql
QT       +=charts
QT       +=widgets printsupport
QT       +=xml

QT += multimedia multimediawidgets
QT       += core gui serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

QT += svg

QT += network
LIBS += -LC:/SmtpClient/build

# Link against the SMTP library
LIBS += -LC:/SmtpClient/build \
        -llibSmtpClient
# Specify your header files
HEADERS += \
    C:/SmtpClient/src/SmtpClient.h \
    # Add other header files here if needed
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS \
    ImageDelegate.h \
    equipement.h \
    espace.h \
    passwordresetdialog.h \
    personnel.h \
    qrcode.h \
    regle.h \
    sms.h \
    stats_page.h

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ImageDelegate.cpp \
    client.cpp \
    connexion.cpp \
    equipement.cpp \
    espace.cpp \
    main.cpp \
    mainwindow.cpp \
    passwordresetdialog.cpp \
    personnel.cpp \
    qrcode.cpp \
    regle.cpp \
    sms.cpp \
    stats_page.cpp

HEADERS += \
    client.h \
    connexion.h \
    mainwindow.h

FORMS += \
    mainwindow.ui \
    passwordresetdialog.ui \
    stats_page.ui
INCLUDEPATH += C:/SmtpClient/src
DEPENDPATH += C:/SmtpClient/src
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target