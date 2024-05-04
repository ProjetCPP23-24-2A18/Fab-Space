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
    QPushButton *onlm35;
    QPushButton *offlm35;
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
        onlm35 = new QPushButton(arduinotemp);
        onlm35->setObjectName(QStringLiteral("onlm35"));
        onlm35->setGeometry(QRect(170, 160, 211, 51));
        onlm35->setStyleSheet(QLatin1String("QPushButton {\n"
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
        offlm35 = new QPushButton(arduinotemp);
        offlm35->setObjectName(QStringLiteral("offlm35"));
        offlm35->setGeometry(QRect(170, 230, 211, 51));
        offlm35->setStyleSheet(QLatin1String("QPushButton {\n"
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
        onlm35->setText(QApplication::translate("arduinotemp", "ON", Q_NULLPTR));
        offlm35->setText(QApplication::translate("arduinotemp", "OFF", Q_NULLPTR));
        label_etat->setText(QApplication::translate("arduinotemp", "<html><head/><body><p><br/></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class arduinotemp: public Ui_arduinotemp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARDUINOTEMP_H
