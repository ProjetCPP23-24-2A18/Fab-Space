/********************************************************************************
** Form generated from reading UI file 'stats_page.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATS_PAGE_H
#define UI_STATS_PAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StatsPage
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *statsLabel;
    QPushButton *closeButton;

    void setupUi(QWidget *StatsPage)
    {
        if (StatsPage->objectName().isEmpty())
            StatsPage->setObjectName(QStringLiteral("StatsPage"));
        StatsPage->resize(717, 465);
        StatsPage->setStyleSheet(QStringLiteral("background-color: white;"));
        verticalLayout = new QVBoxLayout(StatsPage);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        statsLabel = new QLabel(StatsPage);
        statsLabel->setObjectName(QStringLiteral("statsLabel"));
        statsLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout->addWidget(statsLabel);

        closeButton = new QPushButton(StatsPage);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setStyleSheet(QStringLiteral("background-color: red;"));

        verticalLayout->addWidget(closeButton);


        retranslateUi(StatsPage);

        QMetaObject::connectSlotsByName(StatsPage);
    } // setupUi

    void retranslateUi(QWidget *StatsPage)
    {
        StatsPage->setWindowTitle(QApplication::translate("StatsPage", "Statistics", Q_NULLPTR));
        statsLabel->setText(QApplication::translate("StatsPage", "Statistics will be displayed here.", Q_NULLPTR));
        closeButton->setText(QApplication::translate("StatsPage", "Close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class StatsPage: public Ui_StatsPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATS_PAGE_H
