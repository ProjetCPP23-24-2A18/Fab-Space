/********************************************************************************
** Form generated from reading UI file 'passwordresetdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORDRESETDIALOG_H
#define UI_PASSWORDRESETDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PasswordResetDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *usernameLineEdit;
    QLabel *label_2;
    QLineEdit *securityAnswerLineEdit;
    QLabel *label_3;
    QLineEdit *newPasswordLineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *resetButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *PasswordResetDialog)
    {
        if (PasswordResetDialog->objectName().isEmpty())
            PasswordResetDialog->setObjectName(QStringLiteral("PasswordResetDialog"));
        PasswordResetDialog->resize(400, 200);
        verticalLayout = new QVBoxLayout(PasswordResetDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(PasswordResetDialog);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        usernameLineEdit = new QLineEdit(PasswordResetDialog);
        usernameLineEdit->setObjectName(QStringLiteral("usernameLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, usernameLineEdit);

        label_2 = new QLabel(PasswordResetDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        securityAnswerLineEdit = new QLineEdit(PasswordResetDialog);
        securityAnswerLineEdit->setObjectName(QStringLiteral("securityAnswerLineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, securityAnswerLineEdit);

        label_3 = new QLabel(PasswordResetDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        newPasswordLineEdit = new QLineEdit(PasswordResetDialog);
        newPasswordLineEdit->setObjectName(QStringLiteral("newPasswordLineEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, newPasswordLineEdit);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        resetButton = new QPushButton(PasswordResetDialog);
        resetButton->setObjectName(QStringLiteral("resetButton"));

        horizontalLayout->addWidget(resetButton);

        cancelButton = new QPushButton(PasswordResetDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(PasswordResetDialog);

        QMetaObject::connectSlotsByName(PasswordResetDialog);
    } // setupUi

    void retranslateUi(QDialog *PasswordResetDialog)
    {
        PasswordResetDialog->setWindowTitle(QApplication::translate("PasswordResetDialog", "Password Reset", Q_NULLPTR));
        label->setText(QApplication::translate("PasswordResetDialog", "Username:", Q_NULLPTR));
        label_2->setText(QApplication::translate("PasswordResetDialog", "Security Answer:", Q_NULLPTR));
        label_3->setText(QApplication::translate("PasswordResetDialog", "New Password:", Q_NULLPTR));
        resetButton->setText(QApplication::translate("PasswordResetDialog", "Reset Password", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("PasswordResetDialog", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PasswordResetDialog: public Ui_PasswordResetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORDRESETDIALOG_H
