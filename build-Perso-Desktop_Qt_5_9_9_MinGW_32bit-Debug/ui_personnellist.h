/********************************************************************************
** Form generated from reading UI file 'personnellist.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSONNELLIST_H
#define UI_PERSONNELLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_personnellist
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label_3;
    QPushButton *pushButton_10;
    QLabel *label_14;
    QLabel *label;
    QLabel *label_5;
    QLabel *label_2;
    QLabel *label_24;
    QLineEdit *Prenom_2;
    QLineEdit *Prenom;
    QLabel *label_4;
    QWidget *page_2;
    QLabel *label_17;
    QPushButton *pushButton_voyage;
    QPushButton *pushButton_hot;
    QLabel *label_11;
    QLabel *label_16;
    QLabel *label_40;
    QPushButton *pushButton;
    QPushButton *pushButton_comp;
    QPushButton *pushButton_perso;
    QWidget *page_3;
    QLabel *label_13;
    QPushButton *printButton;
    QPushButton *Back_gestion;
    QPushButton *pushButton_17;
    QLabel *label_41;
    QPushButton *pushButtonsdd;
    QTableView *tableView;
    QPushButton *pushButton_14;
    QPushButton *pushButton_13;
    QPushButton *AjoutButton;
    QPushButton *filterButton;
    QPushButton *pdfExcelButton;
    QPushButton *pushButton_20;
    QPushButton *searchButton;
    QLineEdit *searchLineEdit;
    QComboBox *sortComboBox;
    QPushButton *generateQRButton;
    QLabel *qrcode;
    QPushButton *stat;
    QWidget *page_4;
    QLabel *label_42;
    QPushButton *pushButton_15;
    QPushButton *cancel;
    QLabel *label_21;
    QLabel *label_18;
    QLineEdit *lineEdit_UserName;
    QPushButton *pushButton_16;
    QPushButton *confirm;
    QLineEdit *lineEdit_lastName;
    QLabel *label_20;
    QLabel *label_22;
    QLineEdit *lineEdit_function;
    QLabel *label_23;
    QLabel *label_19;
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_id;
    QDateEdit *dateEdit_dateOfBirth;
    QLabel *label_25;
    QDateEdit *dateEdit_dateEmb;
    QLabel *label_26;
    QLabel *label_27;
    QLineEdit *lineEdit_address;
    QLineEdit *lineEdit_phone;
    QLabel *label_28;
    QLineEdit *lineEdit_email;
    QLabel *label_29;
    QLabel *label_30;
    QLineEdit *lineEdit_password;
    QPushButton *uploadImageButton;
    QLabel *imageLabel;
    QWidget *page_5;
    QListView *listView;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *setLayout;
    QWidget *placeholderWidget;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout;
    QFrame *chartFrame;
    QPushButton *statAge;
    QLabel *label_39;
    QLabel *label_43;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *personnellist)
    {
        if (personnellist->objectName().isEmpty())
            personnellist->setObjectName(QStringLiteral("personnellist"));
        personnellist->resize(1485, 805);
        centralwidget = new QWidget(personnellist);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(70, 10, 1381, 881));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        label_3 = new QLabel(page);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 0, 1331, 831));
        label_3->setStyleSheet(QStringLiteral("background-color: rgba(246,247,252,255);"));
        pushButton_10 = new QPushButton(page);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(910, 470, 351, 51));
        pushButton_10->setStyleSheet(QLatin1String("QPushButton {\n"
"    font-size: 12pt; /* Larger font size */\n"
"    border: 2px solid #000000; /* Black border */\n"
"    border-radius: 15px; /* Rounded corners */\n"
"    padding: 10px 20px; /* Padding */\n"
"    color: #ffffff; /* White text */\n"
"    background-color: #f4d69a; /* Gold background */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #e0b75e; /* Lighter gold on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #d0a04c; /* Slightly darker gold when pressed */\n"
"}"));
        label_14 = new QLabel(page);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(980, 170, 271, 81));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_14->setFont(font);
        label_14->setStyleSheet(QLatin1String("/* Style for the label */\n"
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
        label = new QLabel(page);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(1140, 330, 41, 31));
        label->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/projet_emp/Downloads/1144760.png")));
        label->setScaledContents(true);
        label_5 = new QLabel(page);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(1150, 400, 41, 31));
        label_5->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/projet_emp/Downloads/t\303\251l\303\251chargement (1).png")));
        label_5->setScaledContents(true);
        label_2 = new QLabel(page);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 10, 751, 731));
        label_2->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/projet_emp/Downloads/article-fablab-1 (1).jpg")));
        label_2->setScaledContents(true);
        label_24 = new QLabel(page);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(1110, -40, 291, 241));
        label_24->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/projet_emp/Downloads/422871135_3753649611547138_2993912555110327539_n-removebg-preview.png")));
        label_24->setScaledContents(true);
        Prenom_2 = new QLineEdit(page);
        Prenom_2->setObjectName(QStringLiteral("Prenom_2"));
        Prenom_2->setGeometry(QRect(940, 390, 298, 51));
        Prenom_2->setStyleSheet(QString::fromUtf8("font-size: 16px; /* Taille de la police */\n"
"    font-weight: bold; /* Police en gras */\n"
"    color: #8B4513; /* Couleur marron */\n"
"    background-color: #FFF5E1; /* Couleur de fond beige */\n"
"    padding: 10px; /* Remplissage int\303\251rieur */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    border: 2px solid #8B4513; /* Bordure marron */\n"
"    text-align: center; /* Alignement centr\303\251 du texte */\n"
"    max-width: 200px; /* Largeur maximale */\n"
"    margin: 0 auto; /* Centrage horizontal */\n"
"    box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.2); /* Ombre port\303\251e *"));
        Prenom = new QLineEdit(page);
        Prenom->setObjectName(QStringLiteral("Prenom"));
        Prenom->setGeometry(QRect(940, 320, 291, 51));
        Prenom->setStyleSheet(QString::fromUtf8("font-size: 16px; /* Taille de la police */\n"
"    font-weight: bold; /* Police en gras */\n"
"    color: #8B4513; /* Couleur marron */\n"
"    background-color: #FFF5E1; /* Couleur de fond beige */\n"
"    padding: 10px; /* Remplissage int\303\251rieur */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    border: 2px solid #8B4513; /* Bordure marron */\n"
"    text-align: center; /* Alignement centr\303\251 du texte */\n"
"    max-width: 200px; /* Largeur maximale */\n"
"    margin: 0 auto; /* Centrage horizontal */\n"
"    box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.2); /* Ombre port\303\251e *"));
        label_4 = new QLabel(page);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(820, 10, 501, 731));
        label_4->setStyleSheet(QLatin1String("background-color:#4b514f;\n"
""));
        stackedWidget->addWidget(page);
        label_3->raise();
        label_2->raise();
        label_4->raise();
        pushButton_10->raise();
        label_14->raise();
        label->raise();
        label_5->raise();
        label_24->raise();
        Prenom_2->raise();
        Prenom->raise();
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        label_17 = new QLabel(page_2);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(69, 174, 291, 71));
        QFont font1;
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        label_17->setFont(font1);
        label_17->setStyleSheet(QLatin1String("#label_17 {\n"
"    font-size: 36px; /* Adjust font size as needed */\n"
"    font-weight: bold; /* Make the text bold */\n"
"    color: #8b4513; /* Saddle brown color */\n"
"    text-shadow: 2px 2px 4px rgba(0, 0, 0, 0.3); /* Add a subtle shadow effect */\n"
"}\n"
""));
        pushButton_voyage = new QPushButton(page_2);
        pushButton_voyage->setObjectName(QStringLiteral("pushButton_voyage"));
        pushButton_voyage->setGeometry(QRect(280, 620, 729, 53));
        pushButton_voyage->setStyleSheet(QLatin1String("QPushButton {\n"
"    font-size: 12pt; /* Larger font size */\n"
"    border: 2px solid #000000; /* Black border */\n"
"    border-radius: 15px; /* Rounded corners */\n"
"    padding: 12px 24px; /* Increased padding for better spacing */\n"
"    color: #ffffff; /* White text */\n"
"    background-color: #be996f; /* Gold background */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #8b5f3d; /* Darker gold on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #9e4b0f; /* Darker gold when pressed */\n"
"}\n"
""));
        pushButton_hot = new QPushButton(page_2);
        pushButton_hot->setObjectName(QStringLiteral("pushButton_hot"));
        pushButton_hot->setGeometry(QRect(280, 486, 729, 53));
        pushButton_hot->setStyleSheet(QLatin1String("QPushButton {\n"
"    font-size: 12pt; /* Larger font size */\n"
"    border: 2px solid #000000; /* Black border */\n"
"    border-radius: 15px; /* Rounded corners */\n"
"    padding: 12px 24px; /* Increased padding for better spacing */\n"
"    color: #ffffff; /* White text */\n"
"    background-color: #be996f; /* Gold background */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #8b5f3d; /* Darker gold on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #9e4b0f; /* Darker gold when pressed */\n"
"}\n"
""));
        label_11 = new QLabel(page_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(149, 284, 281, 41));
        QFont font2;
        font2.setBold(true);
        font2.setItalic(true);
        font2.setUnderline(true);
        font2.setWeight(75);
        label_11->setFont(font2);
        label_11->setStyleSheet(QLatin1String("#label_11 {\n"
"    font-size: 18px; /* Adjust font size as needed */\n"
"    font-weight: bold; /* Make the text bold */\n"
"    color: #cd853f; /* Peru color */\n"
"    text-align: center; /* Center align the text */\n"
"    text-decoration: underline; /* Add underline */\n"
"}\n"
""));
        label_16 = new QLabel(page_2);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(-1, 4, 1301, 881));
        label_16->setStyleSheet(QStringLiteral("background-color: #fede97;"));
        label_16->setPixmap(QPixmap(QString::fromUtf8(":/Downloads/pic1.png")));
        label_40 = new QLabel(page_2);
        label_40->setObjectName(QStringLiteral("label_40"));
        label_40->setGeometry(QRect(1059, 64, 291, 241));
        label_40->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/projet_emp/Downloads/422871135_3753649611547138_2993912555110327539_n-removebg-preview.png")));
        label_40->setScaledContents(true);
        pushButton = new QPushButton(page_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(280, 553, 729, 53));
        pushButton->setStyleSheet(QLatin1String("QPushButton {\n"
"    font-size: 12pt; /* Larger font size */\n"
"    border: 2px solid #000000; /* Black border */\n"
"    border-radius: 15px; /* Rounded corners */\n"
"    padding: 12px 24px; /* Increased padding for better spacing */\n"
"    color: #ffffff; /* White text */\n"
"    background-color: #be996f; /* Gold background */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #8b5f3d; /* Darker gold on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #9e4b0f; /* Darker gold when pressed */\n"
"}\n"
""));
        pushButton_comp = new QPushButton(page_2);
        pushButton_comp->setObjectName(QStringLiteral("pushButton_comp"));
        pushButton_comp->setGeometry(QRect(280, 352, 729, 53));
        pushButton_comp->setStyleSheet(QLatin1String("QPushButton {\n"
"    font-size: 12pt; /* Larger font size */\n"
"    border: 2px solid #000000; /* Black border */\n"
"    border-radius: 15px; /* Rounded corners */\n"
"    padding: 12px 24px; /* Increased padding for better spacing */\n"
"    color: #ffffff; /* White text */\n"
"    background-color: #be996f; /* Gold background */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #8b5f3d; /* Darker gold on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #9e4b0f; /* Darker gold when pressed */\n"
"}\n"
""));
        pushButton_perso = new QPushButton(page_2);
        pushButton_perso->setObjectName(QStringLiteral("pushButton_perso"));
        pushButton_perso->setGeometry(QRect(280, 419, 729, 53));
        pushButton_perso->setStyleSheet(QLatin1String("QPushButton {\n"
"    font-size: 12pt; /* Larger font size */\n"
"    border: 2px solid #000000; /* Black border */\n"
"    border-radius: 15px; /* Rounded corners */\n"
"    padding: 12px 24px; /* Increased padding for better spacing */\n"
"    color: #ffffff; /* White text */\n"
"    background-color: #be996f; /* Gold background */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #8b5f3d; /* Darker gold on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #9e4b0f; /* Darker gold when pressed */\n"
"}\n"
""));
        stackedWidget->addWidget(page_2);
        label_16->raise();
        label_17->raise();
        pushButton_voyage->raise();
        pushButton_hot->raise();
        label_11->raise();
        label_40->raise();
        pushButton->raise();
        pushButton_comp->raise();
        pushButton_perso->raise();
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        label_13 = new QLabel(page_3);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(-20, 20, 1331, 801));
        label_13->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/projet_emp/Downloads/fablab-1020x512.jpg")));
        label_13->setScaledContents(true);
        printButton = new QPushButton(page_3);
        printButton->setObjectName(QStringLiteral("printButton"));
        printButton->setGeometry(QRect(790, 630, 221, 51));
        printButton->setStyleSheet(QLatin1String("QPushButton {\n"
"    font-size: 12pt; /* Larger font size */\n"
"    border: 2px solid #000000; /* Black border */\n"
"    border-radius: 15px; /* Rounded corners */\n"
"    padding: 12px 24px; /* Increased padding for better spacing */\n"
"    color: #ffffff; /* White text */\n"
"    background-color: #f4d69a; /* Gold background */\n"
"}\n"
"\n"
"\n"
""));
        Back_gestion = new QPushButton(page_3);
        Back_gestion->setObjectName(QStringLiteral("Back_gestion"));
        Back_gestion->setGeometry(QRect(430, 640, 271, 51));
        Back_gestion->setStyleSheet(QLatin1String("QPushButton {\n"
"    font-size: 12pt; /* Larger font size */\n"
"    border: 2px solid #000000; /* Black border */\n"
"    border-radius: 15px; /* Rounded corners */\n"
"    padding: 12px 24px; /* Increased padding for better spacing */\n"
"    color: #ffffff; /* White text */\n"
"    background-color: #8b5f3d; /* Gold background */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #9e4b0f; /* Darker gold on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #9e4b0f; /* Darker gold when pressed */\n"
"}\n"
""));
        pushButton_17 = new QPushButton(page_3);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));
        pushButton_17->setGeometry(QRect(1030, 280, 261, 51));
        pushButton_17->setStyleSheet(QLatin1String("QPushButton {\n"
"    font-size: 12pt; /* Larger font size */\n"
"    border: 2px solid #000000; /* Black border */\n"
"    border-radius: 15px; /* Rounded corners */\n"
"    padding: 12px 24px; /* Increased padding for better spacing */\n"
"    color: #ffffff; /* White text */\n"
"    background-color: #be996f; /* Gold background */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #8b5f3d; /* Darker gold on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #9e4b0f; /* Darker gold when pressed */\n"
"}\n"
""));
        label_41 = new QLabel(page_3);
        label_41->setObjectName(QStringLiteral("label_41"));
        label_41->setGeometry(QRect(1090, -60, 271, 201));
        label_41->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/projet_emp/Downloads/422871135_3753649611547138_2993912555110327539_n-removebg-preview.png")));
        label_41->setScaledContents(true);
        pushButtonsdd = new QPushButton(page_3);
        pushButtonsdd->setObjectName(QStringLiteral("pushButtonsdd"));
        pushButtonsdd->setGeometry(QRect(330, 200, 461, 51));
        pushButtonsdd->setStyleSheet(QLatin1String("QPushButton {\n"
"    font-size: 12pt; /* Larger font size */\n"
"    border: 2px solid #000000; /* Black border */\n"
"    border-radius: 15px; /* Rounded corners */\n"
"    padding: 10px 20px; /* Padding */\n"
"    color: #ffffff; /* White text */\n"
"    background-color: #f4d69a; /* Gold background */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #e0b75e; /* Lighter gold on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #d0a04c; /* Slightly darker gold when pressed */\n"
"}\n"
""));
        tableView = new QTableView(page_3);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(190, 250, 761, 371));
        tableView->setStyleSheet(QLatin1String("QTableView {\n"
"    background-color: #f4d69a; /* Light brown background color */\n"
"    border: 2px solid #996515; /* Dark brown border with 2px width */\n"
"    border-radius: 15px; /* Border radius of 15px for rounded corners */\n"
"}\n"
"\n"
"QTableView::item {\n"
"    color: #3a3a3a; /* Dark gray text color */\n"
"    font-family: Arial, sans-serif; /* Font family */\n"
"    font-size: 14px; /* Font size */\n"
"}\n"
"\n"
"QTableView::item:selected {\n"
"    background-color: #e0b86e; /* Lighter brown background color for selected items */\n"
"}\n"
"\n"
"QTableView::item:focus {\n"
"    background-color: #996515; /* Dark brown background color for focused items */\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    border: 1px solid #996515; /* Dark brown border for vertical scrollbar */\n"
"    background: #f4d69a; /* Light brown background color for vertical scrollbar */\n"
"    width: 20px; /* Width of the vertical scrollbar */\n"
"    margin: 0px 0px 0px 0px; /* Margin */\n"
"}\n"
"\n"
"QScrollBar::handle:v"
                        "ertical {\n"
"    background: #996515; /* Dark brown handle color for vertical scrollbar */\n"
"    min-height: 20px; /* Minimum height of the handle */\n"
"    border-radius: 10px; /* Border radius of the handle */\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:hover {\n"
"    background: #6b472e; /* Darker brown handle color for vertical scrollbar on hover */\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical {\n"
"    border: 1px solid #996515; /* Dark brown border for vertical scrollbar add line */\n"
"    background: #f4d69a; /* Light brown background color for vertical scrollbar add line */\n"
"    height: 20px; /* Height of the add line */\n"
"    subcontrol-position: bottom; /* Position at the bottom */\n"
"    subcontrol-origin: margin; /* Origin from the margin */\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical {\n"
"    border: 1px solid #996515; /* Dark brown border for vertical scrollbar sub line */\n"
"    background: #f4d69a; /* Light brown background color for vertical scrollbar sub line */\n"
"    height: "
                        "20px; /* Height of the sub line */\n"
"    subcontrol-position: top; /* Position at the top */\n"
"    subcontrol-origin: margin; /* Origin from the margin */\n"
"}\n"
"\n"
"QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical {\n"
"    border: 1px solid #996515; /* Dark brown border for vertical scrollbar arrows */\n"
"    width: 10px; /* Width of the arrows */\n"
"    height: 10px; /* Height of the arrows */\n"
"    background: #f4d69a; /* Light brown background color for arrows */\n"
"}\n"
"\n"
"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {\n"
"    background: none; /* No background for page */\n"
"}"));
        pushButton_14 = new QPushButton(page_3);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setGeometry(QRect(1030, 220, 261, 51));
        pushButton_14->setStyleSheet(QLatin1String("QPushButton {\n"
"    font-size: 12pt; /* Larger font size */\n"
"    border: 2px solid #000000; /* Black border */\n"
"    border-radius: 15px; /* Rounded corners */\n"
"    padding: 12px 24px; /* Increased padding for better spacing */\n"
"    color: #ffffff; /* White text */\n"
"    background-color: #be996f; /* Gold background */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #8b5f3d; /* Darker gold on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #9e4b0f; /* Darker gold when pressed */\n"
"}\n"
""));
        pushButton_13 = new QPushButton(page_3);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(1020, 210, 281, 511));
        pushButton_13->setStyleSheet(QLatin1String("QPushButton {\n"
"    font-size: 12pt; /* Larger font size */\n"
"    border: 2px solid #000000; /* Black border */\n"
"    border-radius: 15px; /* Rounded corners */\n"
"    padding: 12px 24px; /* Increased padding for better spacing */\n"
"    color: #ffffff; /* White text */\n"
"    background-color: #f4d69a; /* Gold background */\n"
"}\n"
"\n"
""));
        AjoutButton = new QPushButton(page_3);
        AjoutButton->setObjectName(QStringLiteral("AjoutButton"));
        AjoutButton->setGeometry(QRect(1030, 340, 261, 51));
        AjoutButton->setStyleSheet(QLatin1String("QPushButton {\n"
"    font-size: 12pt; /* Larger font size */\n"
"    border: 2px solid #000000; /* Black border */\n"
"    border-radius: 15px; /* Rounded corners */\n"
"    padding: 12px 24px; /* Increased padding for better spacing */\n"
"    color: #ffffff; /* White text */\n"
"    background-color: #be996f; /* Gold background */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #8b5f3d; /* Darker gold on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #9e4b0f; /* Darker gold when pressed */\n"
"}\n"
""));
        filterButton = new QPushButton(page_3);
        filterButton->setObjectName(QStringLiteral("filterButton"));
        filterButton->setGeometry(QRect(60, 130, 141, 61));
        filterButton->setStyleSheet(QLatin1String("QPushButton {\n"
"    font-size: 12pt; /* Larger font size */\n"
"    border: 2px solid #000000; /* Black border */\n"
"    border-radius: 15px; /* Rounded corners */\n"
"    padding: 12px 24px; /* Increased padding for better spacing */\n"
"    color: #ffffff; /* White text */\n"
"    background-color: #f4d69a; /* Gold background */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #e0b75e; /* Lighter gold on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #d0a04c; /* Slightly darker gold when pressed */\n"
"}\n"
""));
        pdfExcelButton = new QPushButton(page_3);
        pdfExcelButton->setObjectName(QStringLiteral("pdfExcelButton"));
        pdfExcelButton->setGeometry(QRect(1140, 400, 131, 51));
        pdfExcelButton->setStyleSheet(QLatin1String("QPushButton {\n"
"    font-size: 12pt; /* Larger font size */\n"
"    border: 2px solid #000000; /* Black border */\n"
"    border-radius: 15px; /* Rounded corners */\n"
"    padding: 12px 24px; /* Increased padding for better spacing */\n"
"    color: #ffffff; /* White text */\n"
"    background-color: #f4d69a; /* Gold background */\n"
"}\n"
"\n"
"\n"
""));
        pushButton_20 = new QPushButton(page_3);
        pushButton_20->setObjectName(QStringLiteral("pushButton_20"));
        pushButton_20->setGeometry(QRect(890, 210, 51, 31));
        pushButton_20->setStyleSheet(QLatin1String("QPushButton {\n"
"    font-size: 12pt; /* Larger font size */\n"
"    border: 2px solid #000000; /* Black border */\n"
"    border-radius: 15px; /* Rounded corners */\n"
"    padding: 12px 24px; /* Increased padding for better spacing */\n"
"    color: #ffffff; /* White text */\n"
"    background-color: #f4d69a; /* Gold background */\n"
"}\n"
"\n"
"\n"
""));
        searchButton = new QPushButton(page_3);
        searchButton->setObjectName(QStringLiteral("searchButton"));
        searchButton->setGeometry(QRect(60, 630, 141, 61));
        searchButton->setStyleSheet(QLatin1String("QPushButton {\n"
"    font-size: 12pt; /* Larger font size */\n"
"    border: 2px solid #000000; /* Black border */\n"
"    border-radius: 15px; /* Rounded corners */\n"
"    padding: 12px 24px; /* Increased padding for better spacing */\n"
"    color: #ffffff; /* White text */\n"
"    background-color: #f4d69a; /* Gold background */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #e0b75e; /* Lighter gold on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #d0a04c; /* Slightly darker gold when pressed */\n"
"}\n"
""));
        searchLineEdit = new QLineEdit(page_3);
        searchLineEdit->setObjectName(QStringLiteral("searchLineEdit"));
        searchLineEdit->setGeometry(QRect(220, 640, 151, 41));
        searchLineEdit->setStyleSheet(QLatin1String(" font-size: 12pt; /* Larger font size */\n"
"    border: 2px solid #000000; /* Black border */\n"
"    border-radius: 15px; /* Rounded corners */\n"
"    padding: 12px 24px; /* Increased padding for better spacing */\n"
"    color: #ffffff; /* White text */\n"
"    background-color: #f4d69a; /* Gold background */"));
        sortComboBox = new QComboBox(page_3);
        sortComboBox->setObjectName(QStringLiteral("sortComboBox"));
        sortComboBox->setGeometry(QRect(220, 140, 231, 41));
        sortComboBox->setStyleSheet(QLatin1String("\n"
"QComboBox\n"
" {\n"
"    font-size: 12pt; /* Larger font size */\n"
"    border: 2px solid #000000; /* Black border */\n"
"    border-radius: 15px; /* Rounded corners */\n"
"    padding: 12px 24px; /* Increased padding for better spacing */\n"
"    color: #ffffff; /* White text */\n"
"    background-color: #f4d69a; /* Gold background */\n"
"}"));
        generateQRButton = new QPushButton(page_3);
        generateQRButton->setObjectName(QStringLiteral("generateQRButton"));
        generateQRButton->setGeometry(QRect(1030, 400, 91, 51));
        generateQRButton->setStyleSheet(QLatin1String("QPushButton {\n"
"    font-size: 12pt; /* Larger font size */\n"
"    border: 2px solid #000000; /* Black border */\n"
"    border-radius: 15px; /* Rounded corners */\n"
"    padding: 12px 24px; /* Increased padding for better spacing */\n"
"    color: #ffffff; /* White text */\n"
"    background-color: #f4d69a; /* Gold background */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #e0b75e; /* Lighter gold on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #d0a04c; /* Slightly darker gold when pressed */\n"
"}\n"
""));
        qrcode = new QLabel(page_3);
        qrcode->setObjectName(QStringLiteral("qrcode"));
        qrcode->setGeometry(QRect(1030, 460, 261, 251));
        stat = new QPushButton(page_3);
        stat->setObjectName(QStringLiteral("stat"));
        stat->setGeometry(QRect(30, 430, 141, 61));
        stat->setStyleSheet(QLatin1String("QPushButton {\n"
"    font-size: 12pt; /* Larger font size */\n"
"    border: 2px solid #000000; /* Black border */\n"
"    border-radius: 15px; /* Rounded corners */\n"
"    padding: 12px 24px; /* Increased padding for better spacing */\n"
"    color: #ffffff; /* White text */\n"
"    background-color: #f4d69a; /* Gold background */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #e0b75e; /* Lighter gold on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #d0a04c; /* Slightly darker gold when pressed */\n"
"}\n"
""));
        stackedWidget->addWidget(page_3);
        pushButton_13->raise();
        label_13->raise();
        printButton->raise();
        Back_gestion->raise();
        pushButton_17->raise();
        label_41->raise();
        pushButtonsdd->raise();
        tableView->raise();
        pushButton_14->raise();
        AjoutButton->raise();
        filterButton->raise();
        pdfExcelButton->raise();
        pushButton_20->raise();
        searchButton->raise();
        searchLineEdit->raise();
        sortComboBox->raise();
        generateQRButton->raise();
        qrcode->raise();
        stat->raise();
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        label_42 = new QLabel(page_4);
        label_42->setObjectName(QStringLiteral("label_42"));
        label_42->setGeometry(QRect(840, 130, 291, 241));
        label_42->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/projet_emp/Downloads/422871135_3753649611547138_2993912555110327539_n-removebg-preview.png")));
        label_42->setScaledContents(true);
        pushButton_15 = new QPushButton(page_4);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        pushButton_15->setGeometry(QRect(110, 30, 1101, 631));
        pushButton_15->setStyleSheet(QLatin1String("QPushButton {\n"
"    font-size: 12pt; /* Larger font size */\n"
"    border: 2px solid #000000; /* Black border */\n"
"    border-radius: 15px; /* Rounded corners */\n"
"    padding: 12px 24px; /* Increased padding for better spacing */\n"
"    color: #ffffff; /* White text */\n"
"    background-color: #f4d69a; /* Gold background */\n"
"}\n"
"\n"
""));
        cancel = new QPushButton(page_4);
        cancel->setObjectName(QStringLiteral("cancel"));
        cancel->setGeometry(QRect(490, 650, 271, 51));
        cancel->setStyleSheet(QLatin1String("QPushButton {\n"
"    font-size: 12pt; /* Larger font size */\n"
"    border: 2px solid #000000; /* Black border */\n"
"    border-radius: 15px; /* Rounded corners */\n"
"    padding: 10px 20px; /* Padding */\n"
"    color: #ffffff; /* White text */\n"
"    background-color: #f4d69a; /* Gold background */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #e0b75e; /* Lighter gold on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #d0a04c; /* Slightly darker gold when pressed */\n"
"}"));
        label_21 = new QLabel(page_4);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(200, 130, 271, 51));
        label_21->setStyleSheet(QLatin1String("/* Style pour la label */\n"
"QLabel {\n"
"    font-size: 12pt; /* Taille de la police */\n"
"   \n"
"	color: rgb(9, 9, 9);\n"
"}\n"
""));
        label_18 = new QLabel(page_4);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(180, 270, 271, 51));
        label_18->setStyleSheet(QLatin1String("/* Style pour la label */\n"
"QLabel {\n"
"    font-size: 12pt; /* Taille de la police */\n"
" /* Couleur marron */\n"
"	color: rgb(13, 13, 13);\n"
"}\n"
""));
        lineEdit_UserName = new QLineEdit(page_4);
        lineEdit_UserName->setObjectName(QStringLiteral("lineEdit_UserName"));
        lineEdit_UserName->setGeometry(QRect(900, 390, 281, 51));
        lineEdit_UserName->setStyleSheet(QString::fromUtf8("font-size: 16px; /* Taille de la police */\n"
"    font-weight: bold; /* Police en gras */\n"
"    color: #8B4513; /* Couleur marron */\n"
"    background-color: #FFF5E1; /* Couleur de fond beige */\n"
"    padding: 10px; /* Remplissage int\303\251rieur */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    border: 2px solid #8B4513; /* Bordure marron */\n"
"    text-align: center; /* Alignement centr\303\251 du texte */\n"
"    max-width: 200px; /* Largeur maximale */\n"
"    margin: 0 auto; /* Centrage horizontal */\n"
"    box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.2); /* Ombre port\303\251e *"));
        pushButton_16 = new QPushButton(page_4);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        pushButton_16->setGeometry(QRect(520, 20, 261, 51));
        pushButton_16->setStyleSheet(QLatin1String("QPushButton {\n"
"    font-size: 12pt; /* Larger font size */\n"
"    border: 2px solid #000000; /* Black border */\n"
"    border-radius: 15px; /* Rounded corners */\n"
"    padding: 12px 24px; /* Increased padding for better spacing */\n"
"    color: #ffffff; /* White text */\n"
"    background-color: #be996f; /* Gold background */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #8b5f3d; /* Darker gold on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #9e4b0f; /* Darker gold when pressed */\n"
"}\n"
""));
        confirm = new QPushButton(page_4);
        confirm->setObjectName(QStringLiteral("confirm"));
        confirm->setGeometry(QRect(770, 650, 271, 51));
        confirm->setStyleSheet(QLatin1String("QPushButton {\n"
"    font-size: 12pt; /* Larger font size */\n"
"    border: 2px solid #000000; /* Black border */\n"
"    border-radius: 15px; /* Rounded corners */\n"
"    padding: 10px 20px; /* Padding */\n"
"    color: #ffffff; /* White text */\n"
"    background-color: #be996f; /* Gold background */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #8b5f3d; /* Darker gold on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #9e4b0f; /* Darker gold when pressed */\n"
"}"));
        lineEdit_lastName = new QLineEdit(page_4);
        lineEdit_lastName->setObjectName(QStringLiteral("lineEdit_lastName"));
        lineEdit_lastName->setGeometry(QRect(420, 260, 281, 51));
        lineEdit_lastName->setStyleSheet(QString::fromUtf8("font-size: 16px; /* Taille de la police */\n"
"    font-weight: bold; /* Police en gras */\n"
"    color: #8B4513; /* Couleur marron */\n"
"    background-color: #FFF5E1; /* Couleur de fond beige */\n"
"    padding: 10px; /* Remplissage int\303\251rieur */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    border: 2px solid #8B4513; /* Bordure marron */\n"
"    text-align: center; /* Alignement centr\303\251 du texte */\n"
"    max-width: 200px; /* Largeur maximale */\n"
"    margin: 0 auto; /* Centrage horizontal */\n"
"    box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.2); /* Ombre port\303\251e *"));
        label_20 = new QLabel(page_4);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(690, 290, 271, 51));
        label_20->setStyleSheet(QLatin1String("/* Style pour la label */\n"
"QLabel {\n"
"    font-size: 12pt; /* Taille de la police */\n"
"    \n"
"	color: rgb(15, 15, 15);\n"
"}\n"
""));
        label_22 = new QLabel(page_4);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(700, 390, 61, 51));
        label_22->setStyleSheet(QLatin1String("/* Style pour la label */\n"
"QLabel {\n"
"    font-size: 12pt; /* Taille de la police */\n"
"    \n"
"	color: rgb(15, 15, 15);\n"
"}\n"
""));
        lineEdit_function = new QLineEdit(page_4);
        lineEdit_function->setObjectName(QStringLiteral("lineEdit_function"));
        lineEdit_function->setGeometry(QRect(900, 290, 281, 51));
        lineEdit_function->setStyleSheet(QString::fromUtf8("font-size: 16px; /* Taille de la police */\n"
"    font-weight: bold; /* Police en gras */\n"
"    color: #8B4513; /* Couleur marron */\n"
"    background-color: #FFF5E1; /* Couleur de fond beige */\n"
"    padding: 10px; /* Remplissage int\303\251rieur */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    border: 2px solid #8B4513; /* Bordure marron */\n"
"    text-align: center; /* Alignement centr\303\251 du texte */\n"
"    max-width: 200px; /* Largeur maximale */\n"
"    margin: 0 auto; /* Centrage horizontal */\n"
"    box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.2); /* Ombre port\303\251e *"));
        label_23 = new QLabel(page_4);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(150, 80, 1281, 811));
        label_23->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/projet_emp/Downloads/fablab-1020x512.jpg")));
        label_23->setScaledContents(true);
        label_19 = new QLabel(page_4);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(190, 200, 271, 51));
        label_19->setStyleSheet(QLatin1String("/* Style pour la label */\n"
"QLabel {\n"
"    font-size: 12pt; /* Taille de la police */\n"
"   \n"
"	color: rgb(8, 8, 8);\n"
"}\n"
""));
        lineEdit_name = new QLineEdit(page_4);
        lineEdit_name->setObjectName(QStringLiteral("lineEdit_name"));
        lineEdit_name->setGeometry(QRect(420, 200, 281, 51));
        lineEdit_name->setStyleSheet(QString::fromUtf8("font-size: 16px; /* Taille de la police */\n"
"    font-weight: bold; /* Police en gras */\n"
"    color: #8B4513; /* Couleur marron */\n"
"    background-color: #FFF5E1; /* Couleur de fond beige */\n"
"    padding: 10px; /* Remplissage int\303\251rieur */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    border: 2px solid #8B4513; /* Bordure marron */\n"
"    text-align: center; /* Alignement centr\303\251 du texte */\n"
"    max-width: 200px; /* Largeur maximale */\n"
"    margin: 0 auto; /* Centrage horizontal */\n"
"    box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.2); /* Ombre port\303\251e *"));
        lineEdit_id = new QLineEdit(page_4);
        lineEdit_id->setObjectName(QStringLiteral("lineEdit_id"));
        lineEdit_id->setGeometry(QRect(420, 140, 281, 51));
        lineEdit_id->setStyleSheet(QString::fromUtf8("font-size: 16px; /* Taille de la police */\n"
"    font-weight: bold; /* Police en gras */\n"
"    color: #8B4513; /* Couleur marron */\n"
"    background-color: #FFF5E1; /* Couleur de fond beige */\n"
"    padding: 10px; /* Remplissage int\303\251rieur */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    border: 2px solid #8B4513; /* Bordure marron */\n"
"    text-align: center; /* Alignement centr\303\251 du texte */\n"
"    max-width: 200px; /* Largeur maximale */\n"
"    margin: 0 auto; /* Centrage horizontal */\n"
"    box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.2); /* Ombre port\303\251e *"));
        dateEdit_dateOfBirth = new QDateEdit(page_4);
        dateEdit_dateOfBirth->setObjectName(QStringLiteral("dateEdit_dateOfBirth"));
        dateEdit_dateOfBirth->setGeometry(QRect(420, 340, 281, 51));
        dateEdit_dateOfBirth->setStyleSheet(QString::fromUtf8("font-size: 16px; /* Taille de la police */\n"
"    font-weight: bold; /* Police en gras */\n"
"    color: #8B4513; /* Couleur marron */\n"
"    background-color: #FFF5E1; /* Couleur de fond beige */\n"
"    padding: 10px; /* Remplissage int\303\251rieur */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    border: 2px solid #8B4513; /* Bordure marron */\n"
"    text-align: center; /* Alignement centr\303\251 du texte */\n"
"    max-width: 200px; /* Largeur maximale */\n"
"    margin: 0 auto; /* Centrage horizontal */\n"
"    box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.2); /* Ombre port\303\251e *"));
        label_25 = new QLabel(page_4);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(160, 350, 271, 51));
        label_25->setStyleSheet(QLatin1String("/* Style pour la label */\n"
"QLabel {\n"
"    font-size: 12pt; /* Taille de la police */\n"
" /* Couleur marron */\n"
"	color: rgb(13, 13, 13);\n"
"}\n"
""));
        dateEdit_dateEmb = new QDateEdit(page_4);
        dateEdit_dateEmb->setObjectName(QStringLiteral("dateEdit_dateEmb"));
        dateEdit_dateEmb->setGeometry(QRect(420, 440, 281, 51));
        dateEdit_dateEmb->setStyleSheet(QString::fromUtf8("font-size: 16px; /* Taille de la police */\n"
"    font-weight: bold; /* Police en gras */\n"
"    color: #8B4513; /* Couleur marron */\n"
"    background-color: #FFF5E1; /* Couleur de fond beige */\n"
"    padding: 10px; /* Remplissage int\303\251rieur */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    border: 2px solid #8B4513; /* Bordure marron */\n"
"    text-align: center; /* Alignement centr\303\251 du texte */\n"
"    max-width: 200px; /* Largeur maximale */\n"
"    margin: 0 auto; /* Centrage horizontal */\n"
"    box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.2); /* Ombre port\303\251e *"));
        label_26 = new QLabel(page_4);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(140, 440, 271, 51));
        label_26->setStyleSheet(QLatin1String("/* Style pour la label */\n"
"QLabel {\n"
"    font-size: 12pt; /* Taille de la police */\n"
" /* Couleur marron */\n"
"	color: rgb(13, 13, 13);\n"
"}\n"
""));
        label_27 = new QLabel(page_4);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(140, 540, 271, 51));
        label_27->setStyleSheet(QLatin1String("/* Style pour la label */\n"
"QLabel {\n"
"    font-size: 12pt; /* Taille de la police */\n"
" /* Couleur marron */\n"
"	color: rgb(13, 13, 13);\n"
"}\n"
""));
        lineEdit_address = new QLineEdit(page_4);
        lineEdit_address->setObjectName(QStringLiteral("lineEdit_address"));
        lineEdit_address->setGeometry(QRect(420, 540, 281, 51));
        lineEdit_address->setStyleSheet(QString::fromUtf8("font-size: 16px; /* Taille de la police */\n"
"    font-weight: bold; /* Police en gras */\n"
"    color: #8B4513; /* Couleur marron */\n"
"    background-color: #FFF5E1; /* Couleur de fond beige */\n"
"    padding: 10px; /* Remplissage int\303\251rieur */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    border: 2px solid #8B4513; /* Bordure marron */\n"
"    text-align: center; /* Alignement centr\303\251 du texte */\n"
"    max-width: 200px; /* Largeur maximale */\n"
"    margin: 0 auto; /* Centrage horizontal */\n"
"    box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.2); /* Ombre port\303\251e *"));
        lineEdit_phone = new QLineEdit(page_4);
        lineEdit_phone->setObjectName(QStringLiteral("lineEdit_phone"));
        lineEdit_phone->setGeometry(QRect(900, 140, 281, 51));
        lineEdit_phone->setStyleSheet(QString::fromUtf8("font-size: 16px; /* Taille de la police */\n"
"    font-weight: bold; /* Police en gras */\n"
"    color: #8B4513; /* Couleur marron */\n"
"    background-color: #FFF5E1; /* Couleur de fond beige */\n"
"    padding: 10px; /* Remplissage int\303\251rieur */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    border: 2px solid #8B4513; /* Bordure marron */\n"
"    text-align: center; /* Alignement centr\303\251 du texte */\n"
"    max-width: 200px; /* Largeur maximale */\n"
"    margin: 0 auto; /* Centrage horizontal */\n"
"    box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.2); /* Ombre port\303\251e *"));
        label_28 = new QLabel(page_4);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(700, 140, 271, 51));
        label_28->setStyleSheet(QLatin1String("/* Style pour la label */\n"
"QLabel {\n"
"    font-size: 12pt; /* Taille de la police */\n"
" /* Couleur marron */\n"
"	color: rgb(13, 13, 13);\n"
"}\n"
""));
        lineEdit_email = new QLineEdit(page_4);
        lineEdit_email->setObjectName(QStringLiteral("lineEdit_email"));
        lineEdit_email->setGeometry(QRect(900, 210, 281, 51));
        lineEdit_email->setStyleSheet(QString::fromUtf8("font-size: 16px; /* Taille de la police */\n"
"    font-weight: bold; /* Police en gras */\n"
"    color: #8B4513; /* Couleur marron */\n"
"    background-color: #FFF5E1; /* Couleur de fond beige */\n"
"    padding: 10px; /* Remplissage int\303\251rieur */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    border: 2px solid #8B4513; /* Bordure marron */\n"
"    text-align: center; /* Alignement centr\303\251 du texte */\n"
"    max-width: 200px; /* Largeur maximale */\n"
"    margin: 0 auto; /* Centrage horizontal */\n"
"    box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.2); /* Ombre port\303\251e *"));
        label_29 = new QLabel(page_4);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(700, 210, 271, 51));
        label_29->setStyleSheet(QLatin1String("/* Style pour la label */\n"
"QLabel {\n"
"    font-size: 12pt; /* Taille de la police */\n"
" /* Couleur marron */\n"
"	color: rgb(13, 13, 13);\n"
"}\n"
""));
        label_30 = new QLabel(page_4);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(700, 480, 271, 51));
        label_30->setStyleSheet(QLatin1String("/* Style pour la label */\n"
"QLabel {\n"
"    font-size: 12pt; /* Taille de la police */\n"
"    \n"
"	color: rgb(15, 15, 15);\n"
"}\n"
""));
        lineEdit_password = new QLineEdit(page_4);
        lineEdit_password->setObjectName(QStringLiteral("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(900, 480, 281, 51));
        lineEdit_password->setStyleSheet(QString::fromUtf8("font-size: 16px; /* Taille de la police */\n"
"    font-weight: bold; /* Police en gras */\n"
"    color: #8B4513; /* Couleur marron */\n"
"    background-color: #FFF5E1; /* Couleur de fond beige */\n"
"    padding: 10px; /* Remplissage int\303\251rieur */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    border: 2px solid #8B4513; /* Bordure marron */\n"
"    text-align: center; /* Alignement centr\303\251 du texte */\n"
"    max-width: 200px; /* Largeur maximale */\n"
"    margin: 0 auto; /* Centrage horizontal */\n"
"    box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.2); /* Ombre port\303\251e *"));
        uploadImageButton = new QPushButton(page_4);
        uploadImageButton->setObjectName(QStringLiteral("uploadImageButton"));
        uploadImageButton->setGeometry(QRect(720, 570, 211, 41));
        uploadImageButton->setStyleSheet(QLatin1String("QPushButton {\n"
"    font-size: 12pt; /* Larger font size */\n"
"    border: 2px solid #000000; /* Black border */\n"
"    border-radius: 15px; /* Rounded corners */\n"
"    padding: 10px 20px; /* Padding */\n"
"    color: #ffffff; /* White text */\n"
"    background-color: #f4d69a; /* Gold background */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #e0b75e; /* Lighter gold on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #d0a04c; /* Slightly darker gold when pressed */\n"
"}"));
        imageLabel = new QLabel(page_4);
        imageLabel->setObjectName(QStringLiteral("imageLabel"));
        imageLabel->setGeometry(QRect(940, 540, 191, 91));
        imageLabel->setStyleSheet(QString::fromUtf8("font-size: 16px; /* Taille de la police */\n"
"    font-weight: bold; /* Police en gras */\n"
"    color: #8B4513; /* Couleur marron */\n"
"    background-color: #FFF5E1; /* Couleur de fond beige */\n"
"    padding: 10px; /* Remplissage int\303\251rieur */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    border: 2px solid #8B4513; /* Bordure marron */\n"
"    text-align: center; /* Alignement centr\303\251 du texte */\n"
"    max-width: 200px; /* Largeur maximale */\n"
"    margin: 0 auto; /* Centrage horizontal */\n"
"    box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.2); /* Ombre port\303\251e *"));
        stackedWidget->addWidget(page_4);
        label_23->raise();
        label_42->raise();
        pushButton_15->raise();
        cancel->raise();
        label_21->raise();
        label_18->raise();
        pushButton_16->raise();
        confirm->raise();
        lineEdit_lastName->raise();
        label_20->raise();
        label_22->raise();
        lineEdit_function->raise();
        label_19->raise();
        lineEdit_name->raise();
        lineEdit_id->raise();
        dateEdit_dateOfBirth->raise();
        label_25->raise();
        dateEdit_dateEmb->raise();
        label_26->raise();
        label_27->raise();
        lineEdit_address->raise();
        lineEdit_phone->raise();
        label_28->raise();
        lineEdit_email->raise();
        label_29->raise();
        label_30->raise();
        lineEdit_password->raise();
        lineEdit_UserName->raise();
        uploadImageButton->raise();
        imageLabel->raise();
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        listView = new QListView(page_5);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(230, 140, 811, 511));
        listView->setStyleSheet(QStringLiteral(""));
        horizontalLayoutWidget = new QWidget(page_5);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(240, 260, 791, 381));
        setLayout = new QHBoxLayout(horizontalLayoutWidget);
        setLayout->setObjectName(QStringLiteral("setLayout"));
        setLayout->setContentsMargins(0, 0, 0, 0);
        placeholderWidget = new QWidget(horizontalLayoutWidget);
        placeholderWidget->setObjectName(QStringLiteral("placeholderWidget"));

        setLayout->addWidget(placeholderWidget);

        horizontalLayoutWidget_2 = new QWidget(page_5);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(240, 260, 791, 381));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        chartFrame = new QFrame(horizontalLayoutWidget_2);
        chartFrame->setObjectName(QStringLiteral("chartFrame"));
        chartFrame->setStyleSheet(QLatin1String("QTableView {\n"
"    background-color: #f4d69a; /* Light brown background color */\n"
"    border: 2px solid #996515; /* Dark brown border with 2px width */\n"
"    border-radius: 15px; /* Border radius of 15px for rounded corners */\n"
"}\n"
"\n"
"QTableView::item {\n"
"    color: #3a3a3a; /* Dark gray text color */\n"
"    font-family: Arial, sans-serif; /* Font family */\n"
"    font-size: 14px; /* Font size */\n"
"}\n"
"\n"
"QTableView::item:selected {\n"
"    background-color: #e0b86e; /* Lighter brown background color for selected items */\n"
"}\n"
"\n"
"QTableView::item:focus {\n"
"    background-color: #996515; /* Dark brown background color for focused items */\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    border: 1px solid #996515; /* Dark brown border for vertical scrollbar */\n"
"    background: #f4d69a; /* Light brown background color for vertical scrollbar */\n"
"    width: 20px; /* Width of the vertical scrollbar */\n"
"    margin: 0px 0px 0px 0px; /* Margin */\n"
"}\n"
"\n"
"QScrollBar::handle:v"
                        "ertical {\n"
"    background: #996515; /* Dark brown handle color for vertical scrollbar */\n"
"    min-height: 20px; /* Minimum height of the handle */\n"
"    border-radius: 10px; /* Border radius of the handle */\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:hover {\n"
"    background: #6b472e; /* Darker brown handle color for vertical scrollbar on hover */\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical {\n"
"    border: 1px solid #996515; /* Dark brown border for vertical scrollbar add line */\n"
"    background: #f4d69a; /* Light brown background color for vertical scrollbar add line */\n"
"    height: 20px; /* Height of the add line */\n"
"    subcontrol-position: bottom; /* Position at the bottom */\n"
"    subcontrol-origin: margin; /* Origin from the margin */\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical {\n"
"    border: 1px solid #996515; /* Dark brown border for vertical scrollbar sub line */\n"
"    background: #f4d69a; /* Light brown background color for vertical scrollbar sub line */\n"
"    height: "
                        "20px; /* Height of the sub line */\n"
"    subcontrol-position: top; /* Position at the top */\n"
"    subcontrol-origin: margin; /* Origin from the margin */\n"
"}\n"
"\n"
"QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical {\n"
"    border: 1px solid #996515; /* Dark brown border for vertical scrollbar arrows */\n"
"    width: 10px; /* Width of the arrows */\n"
"    height: 10px; /* Height of the arrows */\n"
"    background: #f4d69a; /* Light brown background color for arrows */\n"
"}\n"
"\n"
"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {\n"
"    background: none; /* No background for page */\n"
"}"));
        chartFrame->setFrameShape(QFrame::StyledPanel);
        chartFrame->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(chartFrame);

        statAge = new QPushButton(page_5);
        statAge->setObjectName(QStringLiteral("statAge"));
        statAge->setGeometry(QRect(530, 80, 191, 51));
        statAge->setStyleSheet(QLatin1String("QPushButton {\n"
"    font-size: 12pt; /* Larger font size */\n"
"    border: 2px solid #000000; /* Black border */\n"
"    border-radius: 15px; /* Rounded corners */\n"
"    padding: 12px 24px; /* Increased padding for better spacing */\n"
"    color: #ffffff; /* White text */\n"
"    background-color: #be996f; /* Gold background */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #8b5f3d; /* Darker gold on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #9e4b0f; /* Darker gold when pressed */\n"
"}\n"
""));
        statAge->setIconSize(QSize(33, 33));
        statAge->setAutoRepeat(false);
        statAge->setAutoExclusive(false);
        statAge->setFlat(false);
        label_39 = new QLabel(page_5);
        label_39->setObjectName(QStringLiteral("label_39"));
        label_39->setGeometry(QRect(220, 30, 821, 41));
        label_39->setStyleSheet(QLatin1String("QLabel{\n"
"    color: rgb(31, 32, 33);\n"
"    font-weight: bold; /* Add this line to set the font weight to bold */\n"
"}\n"
"\n"
""));
        label_43 = new QLabel(page_5);
        label_43->setObjectName(QStringLiteral("label_43"));
        label_43->setGeometry(QRect(180, 20, 1041, 661));
        label_43->setStyleSheet(QLatin1String("QPushButton {\n"
"    font-size: 12pt; /* Larger font size */\n"
"    border: 2px solid #000000; /* Black border */\n"
"    border-radius: 15px; /* Rounded corners */\n"
"    padding: 12px 24px; /* Increased padding for better spacing */\n"
"    color: #ffffff; /* White text */\n"
"    background-color: #f4d69a; /* Gold background */\n"
"}\n"
"\n"
""));
        stackedWidget->addWidget(page_5);
        label_43->raise();
        listView->raise();
        horizontalLayoutWidget->raise();
        horizontalLayoutWidget_2->raise();
        statAge->raise();
        label_39->raise();
        personnellist->setCentralWidget(centralwidget);
        menubar = new QMenuBar(personnellist);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1485, 22));
        personnellist->setMenuBar(menubar);
        statusbar = new QStatusBar(personnellist);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        personnellist->setStatusBar(statusbar);

        retranslateUi(personnellist);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(personnellist);
    } // setupUi

    void retranslateUi(QMainWindow *personnellist)
    {
        personnellist->setWindowTitle(QApplication::translate("personnellist", "personnellist", Q_NULLPTR));
        label_3->setText(QString());
        pushButton_10->setText(QApplication::translate("personnellist", "Login Now", Q_NULLPTR));
        label_14->setText(QApplication::translate("personnellist", "login", Q_NULLPTR));
        label->setText(QString());
        label_5->setText(QString());
        label_2->setText(QString());
        label_24->setText(QString());
        Prenom_2->setPlaceholderText(QApplication::translate("personnellist", "Mot de passe", Q_NULLPTR));
        Prenom->setPlaceholderText(QApplication::translate("personnellist", "Nom d'utilisateur", Q_NULLPTR));
        label_4->setText(QString());
        label_17->setText(QApplication::translate("personnellist", "BIENVENUE ", Q_NULLPTR));
        pushButton_voyage->setText(QApplication::translate("personnellist", "GESTION CONTRATS", Q_NULLPTR));
        pushButton_hot->setText(QApplication::translate("personnellist", "GESTION ESPACE", Q_NULLPTR));
        label_11->setText(QApplication::translate("personnellist", "Ou souhaitez-vous dirigez ?", Q_NULLPTR));
        label_16->setText(QString());
        label_40->setText(QString());
        pushButton->setText(QApplication::translate("personnellist", "GESTION EMPLOYEE", Q_NULLPTR));
        pushButton_comp->setText(QApplication::translate("personnellist", "GESTION EQUIPEMENTS", Q_NULLPTR));
        pushButton_perso->setText(QApplication::translate("personnellist", "GESTION CLIENT", Q_NULLPTR));
        label_13->setText(QString());
        printButton->setText(QApplication::translate("personnellist", "Print", Q_NULLPTR));
        Back_gestion->setText(QApplication::translate("personnellist", "Back", Q_NULLPTR));
        pushButton_17->setText(QApplication::translate("personnellist", "Supprimer", Q_NULLPTR));
        label_41->setText(QString());
        pushButtonsdd->setText(QApplication::translate("personnellist", "List des employees", Q_NULLPTR));
        pushButton_14->setText(QApplication::translate("personnellist", "Modifier", Q_NULLPTR));
        pushButton_13->setText(QString());
        AjoutButton->setText(QApplication::translate("personnellist", "Ajouter", Q_NULLPTR));
        filterButton->setText(QApplication::translate("personnellist", "Trie par", Q_NULLPTR));
        pdfExcelButton->setText(QApplication::translate("personnellist", "PDF/EXCEL", Q_NULLPTR));
        pushButton_20->setText(QApplication::translate("personnellist", "ref", Q_NULLPTR));
        searchButton->setText(QApplication::translate("personnellist", "Chercher", Q_NULLPTR));
        sortComboBox->clear();
        sortComboBox->insertItems(0, QStringList()
         << QApplication::translate("personnellist", "Default", Q_NULLPTR)
         << QApplication::translate("personnellist", "Sort by increasing Creation Date", Q_NULLPTR)
         << QApplication::translate("personnellist", "Sort by descending Creation Date", Q_NULLPTR)
         << QApplication::translate("personnellist", "Sort from 'A' to 'Z'", Q_NULLPTR)
         << QApplication::translate("personnellist", "Sort from 'Z' to 'A'", Q_NULLPTR)
        );
        generateQRButton->setText(QApplication::translate("personnellist", "QR", Q_NULLPTR));
        qrcode->setText(QApplication::translate("personnellist", "                             QR", Q_NULLPTR));
        stat->setText(QApplication::translate("personnellist", "STAT", Q_NULLPTR));
        label_42->setText(QString());
        pushButton_15->setText(QString());
        cancel->setText(QApplication::translate("personnellist", "Back", Q_NULLPTR));
        label_21->setText(QApplication::translate("personnellist", "ID:", Q_NULLPTR));
        label_18->setText(QApplication::translate("personnellist", "Prenom :", Q_NULLPTR));
        lineEdit_UserName->setPlaceholderText(QApplication::translate("personnellist", "salaire", Q_NULLPTR));
        pushButton_16->setText(QApplication::translate("personnellist", "EMPLOYEE FORM", Q_NULLPTR));
        confirm->setText(QApplication::translate("personnellist", "Enregistrer", Q_NULLPTR));
        lineEdit_lastName->setPlaceholderText(QApplication::translate("personnellist", "Prenom", Q_NULLPTR));
        label_20->setText(QApplication::translate("personnellist", "fonction", Q_NULLPTR));
        label_22->setText(QApplication::translate("personnellist", "Salaire", Q_NULLPTR));
        lineEdit_function->setPlaceholderText(QApplication::translate("personnellist", "fonction", Q_NULLPTR));
        label_23->setText(QString());
        label_19->setText(QApplication::translate("personnellist", "Nom :", Q_NULLPTR));
        lineEdit_name->setPlaceholderText(QApplication::translate("personnellist", "Nom", Q_NULLPTR));
        lineEdit_id->setPlaceholderText(QApplication::translate("personnellist", "id", Q_NULLPTR));
        label_25->setText(QApplication::translate("personnellist", "Date de Naisance :", Q_NULLPTR));
        label_26->setText(QApplication::translate("personnellist", "Date de Emboche :", Q_NULLPTR));
        label_27->setText(QApplication::translate("personnellist", "adress :", Q_NULLPTR));
        lineEdit_address->setText(QString());
        lineEdit_address->setPlaceholderText(QApplication::translate("personnellist", "adresse", Q_NULLPTR));
        lineEdit_phone->setText(QString());
        lineEdit_phone->setPlaceholderText(QApplication::translate("personnellist", "Phone", Q_NULLPTR));
        label_28->setText(QApplication::translate("personnellist", "phone", Q_NULLPTR));
        lineEdit_email->setPlaceholderText(QApplication::translate("personnellist", "E-mail", Q_NULLPTR));
        label_29->setText(QApplication::translate("personnellist", "email", Q_NULLPTR));
        label_30->setText(QApplication::translate("personnellist", "password", Q_NULLPTR));
        lineEdit_password->setText(QString());
        lineEdit_password->setPlaceholderText(QApplication::translate("personnellist", "password", Q_NULLPTR));
        uploadImageButton->setText(QApplication::translate("personnellist", "upload Image", Q_NULLPTR));
        imageLabel->setText(QString());
        statAge->setText(QApplication::translate("personnellist", "STAT BY AGE", Q_NULLPTR));
        label_39->setText(QApplication::translate("personnellist", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">STATISTICS</span></p></body></html>", Q_NULLPTR));
        label_43->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class personnellist: public Ui_personnellist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONNELLIST_H
