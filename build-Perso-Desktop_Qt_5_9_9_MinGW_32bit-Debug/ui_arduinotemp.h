/********************************************************************************
** Form generated from reading UI file 'arduinotemp.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARDUINOTEMP_H
#define UI_ARDUINOTEMP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_arduinotemp
{
public:
    QLabel *label_14;
    QPushButton *ondht11;
    QPushButton *offdht11;
    QLabel *label_etat;

    void setupUi(QDialog *arduinotemp)
    {
        if (arduinotemp->objectName().isEmpty())
            arduinotemp->setObjectName(QStringLiteral("arduinotemp"));
        arduinotemp->resize(578, 400);
        arduinotemp->setStyleSheet(QLatin1String("background-color:#E8D7C6;\n"
"\n"
""));
        label_14 = new QLabel(arduinotemp);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(20, 30, 531, 61));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_14->setFont(font);
        label_14->setStyleSheet(QLatin1String("/* Style for the label */\n"
"background-color: rgb(232, 215, 198);\n"
"QLabel {\n"
"    font-size: 40px; /* Font size */\n"
"    font-weight: bold; /* Bold font */\n"
"    color: #ffffff; /* White text color */\n"
"    text-transform: uppercase; /* Uppercase text */\n"
"    letter-spacing: 2px; /* Letter spacing */\n"
"    padding: 10px 20px; /* Padding */\n"
" \n"
"    border-radius: 30px; /* Rounded corners */\n"
"    box-shadow: 0px 4px 6px rgba(0, 0, 0, 0.1); /* Shadow */\n"
"    transition: background-color 0.3s ease; /* Smooth transition */\n"
"}\n"
"\n"
"\n"
""));
        ondht11 = new QPushButton(arduinotemp);
        ondht11->setObjectName(QStringLiteral("ondht11"));
        ondht11->setGeometry(QRect(170, 160, 211, 51));
        ondht11->setStyleSheet(QLatin1String("QPushButton {\n"
"    font-size: 12pt; /* Larger font size */\n"
"    border: 2px solid #000000; /* Black border */\n"
"    border-radius: 15px; /* Rounded corners */\n"
"    padding: 10px 20px; /* Padding */\n"
"    color: #8B4513; /* White text */\n"
"    background-color: #FFF5E1; /* Gold background */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #A48569; /* Lighter gold on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #A48569; /* Slightly darker gold when pressed */\n"
"}"));
        offdht11 = new QPushButton(arduinotemp);
        offdht11->setObjectName(QStringLiteral("offdht11"));
        offdht11->setGeometry(QRect(170, 230, 211, 51));
        offdht11->setStyleSheet(QLatin1String("QPushButton {\n"
"    font-size: 12pt; /* Larger font size */\n"
"    border: 2px solid #000000; /* Black border */\n"
"    border-radius: 15px; /* Rounded corners */\n"
"    padding: 10px 20px; /* Padding */\n"
"    color: #8B4513; /* White text */\n"
"    background-color: #FFF5E1; /* Gold background */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #A48569; /* Lighter gold on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #A48569; /* Slightly darker gold when pressed */\n"
"}"));
        label_etat = new QLabel(arduinotemp);
        label_etat->setObjectName(QStringLiteral("label_etat"));
        label_etat->setGeometry(QRect(10, 310, 421, 61));
        label_etat->setFont(font);
        label_etat->setStyleSheet(QLatin1String("/* Style for the label */\n"
"background-color: rgb(232, 215, 198);\n"
"QLabel {\n"
"    font-size: 40px; /* Font size */\n"
"    font-weight: bold; /* Bold font */\n"
"    color: #ffffff; /* White text color */\n"
"    text-transform: uppercase; /* Uppercase text */\n"
"    letter-spacing: 2px; /* Letter spacing */\n"
"    padding: 10px 20px; /* Padding */\n"
" \n"
"    border-radius: 30px; /* Rounded corners */\n"
"    box-shadow: 0px 4px 6px rgba(0, 0, 0, 0.1); /* Shadow */\n"
"    transition: background-color 0.3s ease; /* Smooth transition */\n"
"}\n"
"\n"
"\n"
""));

        retranslateUi(arduinotemp);

        QMetaObject::connectSlotsByName(arduinotemp);
    } // setupUi

    void retranslateUi(QDialog *arduinotemp)
    {
        arduinotemp->setWindowTitle(QApplication::translate("arduinotemp", "Dialog", Q_NULLPTR));
        label_14->setText(QApplication::translate("arduinotemp", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; color:#a48569;\">Capteur temperature</span></p></body></html>", Q_NULLPTR));
        ondht11->setText(QApplication::translate("arduinotemp", "ON", Q_NULLPTR));
        offdht11->setText(QApplication::translate("arduinotemp", "OFF", Q_NULLPTR));
        label_etat->setText(QApplication::translate("arduinotemp", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:400; color:#000000;\">Etat:</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class arduinotemp: public Ui_arduinotemp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARDUINOTEMP_H
