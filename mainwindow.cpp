#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QMessageBox>
#include <QtDebug>
#include <QPrinter>
#include <QPainter>
#include <QFileDialog>
#include <QSortFilterProxyModel>
#include <QtSql/QSqlError>
#include <QtSql/QSqlError>
#include "passwordresetdialog.h"
#include "stats_page.h"
#include "equipement.h"

#include <QVBoxLayout>
#include <QtCharts>
#include <QPainter>
#include <QtCharts/QLineSeries>
#include <QtCharts/QPieSlice>
#include <QChartView>
#include <QDesktopServices>
#include <QPdfWriter>
#include <QWidget>
//pour le statique
#include <QPixmap>
#include <QBarSeries>
#include <QBarSet>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include"smtp.h"
#include <smtp.h>
#include "personnel.h"
#include "ImageDelegate.h"
#include <QDebug>
#include <QMessageBox>
#include <QMainWindow>
#include <QSqlTableModel>
#include <QIntValidator>
#include <QPainter>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QUrl>


#include <QSqlRecord>

#include <QPdfWriter>
#include <QPrinter>
#include <QPrintDialog>
#include <QFileDialog>
#include <QPainter>

#include <QTextDocument>
#include <QTextStream>
#include <QStringListModel>
#include <QPixmap>
#include "qrcode.h"


#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>

#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtWidgets/QVBoxLayout>

#include <QtCharts/QBarSeries>

#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtWidgets/QVBoxLayout>

#include <QtCharts/QBarSeries>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QUrlQuery>
#include <QJsonObject>
#include <QJsonDocument>
#include <QNetworkReply>

#include <QFileDialog>
#include <QPixmap>

#include "espace.h"
#include <QMessageBox>
#include <iostream>
#include <QIntValidator>
#include <QModelIndex>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QtWidgets>
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QSqlQuery>
#include <QPixmap>
#include <QSettings>
#include <QtCharts/QPieSlice>
#include <qrcode.h>
#include <fstream>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtSvg/QSvgRenderer>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>


#include "arduinotemp.h"
#include "arduino.h"


using qrcodegen::QrCode;
using qrcodegen::QrSegment;
using namespace qrcodegen;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_currentUser("username", "role")
{
    ui->setupUi(this);
    //menu conneection
    connect(ui->gestio_cl, &QPushButton::clicked, this, &MainWindow::on_gestio_CLientB_clicked);
    connect(ui->login, &QPushButton::clicked, this, &MainWindow::onLoginButtonClicked);
    connect(ui->gestio_eq, &QPushButton::clicked, this, &MainWindow::on_gestio_eqB_clicked);
    connect(ui->gestio_emp, &QPushButton::clicked, this, &MainWindow::on_gestio_employee);

    // Connect the login button clicked() signal to a slot

    // Connect the button signal to the slot in MainWindow constructor
  // connect(ui->gestio_CLientB, &QPushButton::clicked, this, &MainWindow::on_gestio_CLientB_clicked);
    connect(ui->cancel_3, &QPushButton::clicked, this, &MainWindow::on_Back_gestion_clicked2);
    connect(ui->Back_gestion_p, &QPushButton::clicked, this, &MainWindow::on_Back_gestion_clicked);
    connect(ui->AjoutButton, &QPushButton::clicked, this, &MainWindow::on_AjoutButton_clicked);
    connect(ui->BackAjout ,&QPushButton::clicked, this, &MainWindow::on_BackAjout_clicked);
    connect(ui->BackModifir ,&QPushButton::clicked, this, &MainWindow::on_BackModifir_clicked);
    connect(ui->ModifierButton ,&QPushButton::clicked, this, &MainWindow::on_ModifierButton_clicked);
    connect(ui->BUTTONAJOUTENRE, &QPushButton::clicked, this, &MainWindow::on_BUTTONAJOUTENRE_clicked);
  //  connect(ui->pushButton_216, &QPushButton::clicked, this, &MainWindow::on_pushButton_216_clicked);
   // connect(ui->BackModifir_15, &QPushButton::clicked, this, &MainWindow::on_BackModifir_15_clicked);
    connect(ui->Supprimer_Button, &QPushButton::clicked, this, &MainWindow::on_Supprimer_Button_clicked);
     connect(ui->chercher, &QPushButton::clicked, this, &MainWindow::clicked_rech);
    //connect(ui->pushButton_17, &QPushButton::clicked, this, &MainWindow::on_rechercherButton_clicked);
    //connect(ui->pushButton_23, &QPushButton::clicked, this, &MainWindow::on_exportToPdfButton_clicked);

    connect(ui->tableView->horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(onHeaderClicked(int)));
       //*****************************espace
    // Create a calendar widget
    QCalendarWidget *calendarWidget = new QCalendarWidget();
    calendarWidget->setStyleSheet("background-color: white;");

    // Connect the activated signal of the calendar widget to the showReferenceOnHover function
     connect(calendarWidget, &QCalendarWidget::activated, this, &MainWindow::showReferenceOnHover);




    clientModel = new QSqlTableModel(this);
    clientModel->setTable("client");
    clientModel->select();
    clientModel->setHeaderData(0, Qt::Horizontal, "cin");
    ui->tableView->setModel(Ctemp.afficher());

    connect(ui->mailing, SIGNAL(clicked()), this, SLOT(on_mailing_clicked()));

    connect(ui->pdf_cl, &QPushButton::clicked, this, &MainWindow::on_pdf_cl_clicked);
    connect(ui->stat_cl, &QPushButton::clicked, this, &MainWindow::on_stat_cl_clicked);
     connect(ui->pushButton_19, &QPushButton::clicked, this, &MainWindow::on_historyButton_clicked);


     //emplyee **************
     personnelsModel = new QSqlTableModel(this);
         personnelsModel->setTable("PERSONNEL");
         personnelsModel->select();
         ui->tableView->setModel(personnelsModel);
         ui->tableView->setItemDelegateForColumn(11, new ImageDelegate(this));  // Assuming column 11 has
             ui->tableView->resizeColumnsToContents();
 connect(ui->confirm_3, &QPushButton::clicked, this, &MainWindow::on_confirm_clicked);
//connect(ui->pushButton_14_p_2, &QPushButton::clicked, this, &MainWindow::on_pushButton_14_clicked);
 connect(ui->pushButton_17_p, &QPushButton::clicked, this, &MainWindow::on_pushButton_17_clicked);
 connect(ui->printButton_p, &QPushButton::clicked, this, &MainWindow::on_printButton_clicked);
 connect(ui->filterButton_p, &QPushButton::clicked, this, &MainWindow::on_filterButton_clicked);
 connect(ui->uploadImageButton_3, &QPushButton::clicked, this, &MainWindow::on_uploadImageButton_clicked);
connect(ui->AjoutButton_p, &QPushButton::clicked, this, &MainWindow::on_AjoutBtton_clicked);
connect(ui->searchButton_2_p, &QPushButton::clicked, this, &MainWindow::on_searchButton_clicked);
connect(ui->generateQRButton_2, &QPushButton::clicked, this, &MainWindow::on_generateQRButton_clicked);
 connect(ui->pdfExcelButton_p, &QPushButton::clicked, this, &MainWindow::on_pdfExcelButton_clicked);
 connect(ui->statAge_p, &QPushButton::clicked, this, &MainWindow::on_statAge_clicked);
 connect(ui->stat, &QPushButton::clicked, this, &MainWindow::on_stat_clicked);

 // ************



 // eq ***************************

 connect(ui->Back_gestioneq, &QPushButton::clicked, this, &MainWindow::on_Back_gestion_clicked);
 connect(ui->AjoutButtoneq, &QPushButton::clicked, this, &MainWindow::on_AjoutBttoneq_clicked_eq);
 connect(ui->BackAjouteq ,&QPushButton::clicked, this, &MainWindow::on_BackModifir_clicked_eq);
 connect(ui->BackModifireq ,&QPushButton::clicked, this, &MainWindow::on_BackModifir_clicked_eq);
 connect(ui->ModifierButtoneq ,&QPushButton::clicked, this, &MainWindow::on_ModifierButtoneq_clicked);
 connect(ui->BUTTONAJOUTENREeq, &QPushButton::clicked, this, &MainWindow::on_BUTTONAJOUTENRE_clicked_eq);
 connect(ui->pushButton_216eq, &QPushButton::clicked, this, &MainWindow::on_pushButton_216_clicked_eq);
 connect(ui->BackModifir_16, &QPushButton::clicked, this, &MainWindow::on_BackModifir_clicked_eq);
 connect(ui->Supprimer_Buttoneq, &QPushButton::clicked, this, &MainWindow::on_Supprimer_Button_clicked_eq);
 connect(ui->pushButtoneq, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked_eq);
 connect(ui->pushButton_20eq, &QPushButton::clicked, this, &MainWindow::on_pushButton_20_clicked_eq);
 connect(ui->rechercherButtoneq, &QPushButton::clicked, this, &MainWindow::on_rechercherButton_clicked_eq);
 connect(ui->pushButton_19eq, &QPushButton::clicked, this, &MainWindow::on_exportToPdfButton_clicked_eq);
 connect(ui->login, &QPushButton::clicked, this, &MainWindow::on_loginButton_clicked_eq);
 //connect(ui->gestio_eqB, &QPushButton::clicked, this, &MainWindow::verifierQuantiteEquipements_eq);
 //connect(ui->modifier_Buttoneq, &QPushButton::clicked, this, &MainWindow::verifierQuantiteEquipements_eq);
 connect(ui->oublie, &QPushButton::clicked, this, &MainWindow::on_forgotPasswordButton_clicked_eq);
 //connect(ui->stat, &QPushButton::clicked, this, &MainWindow::on_StatsButton_clicked);
 connect(ui->stateq, &QPushButton::clicked, this, &MainWindow::on_stat_cl_clicked_eq);
 connect(ui->gestio_emp, &QPushButton::clicked, this, &MainWindow::on_employeeManagementButton_clicked);





 ui->tableView->setModel(EQtemp.Afficher());


 //*************************************
}

MainWindow::~MainWindow()
{
    delete ui;
}


#include <random>

// Function to generate a random integer within a specified range
int MainWindow::generateRandomInt(int min, int max) {
    // Use a random device to seed the random number engine
    std::random_device rd;
    // Use the random device to generate a random seed for the random number engine
    std::mt19937 gen(rd());
    // Create a uniform distribution for the range [min, max]
    std::uniform_int_distribution<int> distribution(min, max);
    // Generate a random number within the specified range
    return distribution(gen);
}


void MainWindow::recordHistory(const QString &action, int clientId) {
    // Generate a random number for uniqueness
    int randomNumber =  generateRandomInt(1, 1000000);

    // Get the current timestamp
    qint64 timestamp = QDateTime::currentDateTime().toMSecsSinceEpoch();

    // Combine timestamp and random number to create a unique ID
    int id = timestamp + randomNumber;

    // Prepare the INSERT query
    QString insertQuery = "INSERT INTO client_history (id, timestamp, client_id, action_description) "
                          "VALUES (:id, CURRENT_TIMESTAMP, (SELECT cin FROM client WHERE cin = :clientId), :action)";

    // Bind values to placeholders
    QSqlQuery query;
    query.prepare(insertQuery);
    query.bindValue(":id", id);
    query.bindValue(":clientId", clientId);
    query.bindValue(":action", action);

    // Execute the INSERT query
    if (query.exec()) {
        qDebug() << "Record inserted successfully.";
    } else {
        qDebug() << "Error inserting record:" << query.lastError().text();
    }
}



void MainWindow::onLoginButtonClicked()
{
    // Move to the next page in the stacked widget (Page 2)
    ui->stackedWidget->setCurrentIndex(0);
    ui->tableView->setModel(Ctemp.afficher());

}

void MainWindow::on_gestio_CLientB_clicked()
{
    // Move to the next page in the stacked widget (Page Gestion)
    ui->stackedWidget->setCurrentIndex(1);
    ui->tableView->setModel(Ctemp.afficher());

}
void MainWindow::on_gestio_eqB_clicked()
{
    // Move to the next page in the stacked widget (Page Gestion)
     // Setting the current index to 1 for the second index

    ui->stackedWidget->setCurrentIndex(9);
    ui->tableView->setModel(EQtemp.Afficher());

}
void MainWindow::on_gestio_employee()
{
    // Move to the next page in the stacked widget (Page Gestion)
    ui->stackedWidget->setCurrentIndex(6);

    ui->tableView->setModel(Ctemp.afficher());

}
void MainWindow::on_Back_gestion_clicked()
{
    // Move to the previous page in the stacked widget (Page 2)
    ui->stackedWidget->setCurrentIndex(5);

}
void MainWindow::on_Back_gestion_clicked2()
{
    // Move to the previous page in the stacked widget (Page 2)
    ui->stackedWidget->setCurrentIndex(6);

}

void MainWindow::on_AjoutBtton_clicked()
{
    // Move to the next page in the stacked widget (Ajout page)
    ui->stackedWidget->setCurrentIndex(4);
    ui->tableView->setModel(Ctemp.afficher());

}


void MainWindow::on_BackAjout_clicked()
{
    // Move to the previous page in the stacked widget (Page Gestion)
    ui->stackedWidget->setCurrentIndex(1);
    ui->tableView->setModel(Ctemp.afficher());

}

void MainWindow::on_BackModifir_clicked()
{
    // Move to the previous page in the stacked widget (Page Gestion)
    ui->stackedWidget->setCurrentIndex(1);
    ui->tableView->setModel(Ctemp.afficher());

}

void MainWindow::on_ModifierButton_clicked()
{
    // Move to the previous page in the stacked widget (Page Gestion)
    ui->stackedWidget->setCurrentIndex(3);
    ui->tableView->setModel(Ctemp.afficher());

}




void MainWindow::on_BUTTONAJOUTENRE_clicked() {
    // Retrieve client data from input fields
    QString prenom = ui->Prenom_A->text();
    QString nom = ui->Nom_A->text();
    int cin = ui->Cin_A->text().toInt();
    QString adresse = ui->Adresse_A->text();
    int nbe_projet = ui->Nbe_Projet_A->text().toInt();



    // Create a Client object with the retrieved data
    Client client(prenom, nom, cin, adresse, nbe_projet);

    // Add the client to the database
    if (client.ajouter()) {
         recordHistory("addedd", cin);
        // Update the table view if the client is added successfully
        ui->tableView->setModel(Ctemp.afficher());
        QMessageBox::information(this, "Success", "Client added successfully.");
    }/// else {
       /// QMessageBox::critical(this, "Error", "Failed to add client to the database.");
   /// }
}






void MainWindow::on_Supprimer_Button_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}
/*
void MainWindow::on_pushButton_216_clicked()
{
        QMessageBox msgBox;

        // Retrieve the client ID from the QLineEdit widget
        int cin = ui->Cin_Supprime->text().toInt();
        bool test = Ctemp.supprimer(cin);

        if(test)
        {
            recordHistory("deleted", cin);
            ui->tableView->setModel(Ctemp.afficher());
            msgBox.setText("Suppression réussie pour le CIN : " + QString::number(cin));
        }
        else
        {
            msgBox.setText("Échec de suppression pour le CIN : " + QString::number(cin) + ". Vérifiez les erreurs.");

            // Retrieve the error message from the QSqlQuery object

        }

        msgBox.exec();



}
*/
void MainWindow::on_BackModifir_15_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_modifier_Button_clicked()
{
    int cin = ui->cin_u->text().toInt();
    QString nom = ui->nom_u->text();
    QString prenom = ui->prenom_U->text();
    QString adresse = ui->adresse_u->text();
    int nbe_projet = ui->nbe_u->text().toInt();

    Client c(prenom, nom, cin, adresse, nbe_projet);
    bool test = c.modifier();

    QMessageBox msgBox;

    if (test) {
        recordHistory("modified", cin);
        msgBox.setText("Modification avec succes.");
        ui->tableView->setModel(c.afficher());
    } else {
        msgBox.setText("Echec de Modification. Veuillez consulter la console pour plus de détails.");
    }

    msgBox.exec();
}


void MainWindow::onHeaderClicked(int logicalIndex) {
    if (ui->tableView) {

        QSqlQueryModel *existingModel = qobject_cast<QSqlQueryModel*>(ui->tableView->model());

        if (existingModel) {

            QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(this);
            proxyModel->setSourceModel(existingModel);
            ui->tableView->setModel(proxyModel);
            ui->tableView->setSortingEnabled(true);
            QString sortAttribute = existingModel->headerData(logicalIndex, Qt::Horizontal).toString();
            proxyModel->sort(logicalIndex, Qt::AscendingOrder);
        } else {
            qDebug() << "Existing model is not of type QSqlQueryModel.";
        }
    } else {
        qDebug() << "QTableView (tableView_3) not found.";
    }
}

void MainWindow::on_pdf_cl_clicked()
{
    QString filePath = "C:/yessine/facturation.pdf";

    QPdfWriter pdf(filePath);
    pdf.setPageSize(QPageSize(QPageSize::A4));

    if (pdf.resolution() <= 0) {
        QMessageBox::critical(this, "Error", "Unable to create PDF file.");
        return;
    }

    QPainter painter(&pdf);

    if (!painter.isActive()) {
        QMessageBox::critical(this, "Error", "Unable to create QPainter.");
        return;
    }

    int i = 400; // Adjust the starting y-coordinate

    // Set fonts
    QFont titleFont("Bodoni MT", 18, QFont::Bold);
    QFont headerFont("Arial", 10, QFont::Bold);
    QFont normalFont("Arial", 10);

    // Draw title
    painter.setFont(titleFont);
    painter.drawText(200, i, "CLIENTS LIST");
    i += 200; // Adjust vertical spacing

    // Draw table headers
    painter.setFont(headerFont);
    painter.drawText(100, i, "Nom");
    painter.drawText(1500, i, "Prenom");
    painter.drawText(3000, i, "Adresse");
    painter.drawText(4500, i, "CIN");
    painter.drawText(6000, i, "Nombre de Projets");
    i += 200; // Adjust vertical spacing

    // Fetch data from the database and draw onto PDF
    QSqlQuery query("SELECT * FROM client");
    while (query.next()) {
        painter.setFont(normalFont);
        painter.drawText(100, i, query.value("nom").toString());
        painter.drawText(1500, i, query.value("prenom").toString());
        painter.drawText(3000, i, query.value("adresse").toString());
        painter.drawText(4500, i, query.value("cin").toString());
        painter.drawText(6000, i, query.value("nbe_projet").toString());
        i += 200; // Adjust vertical spacing
    }

    // Draw header
    painter.setFont(headerFont);
    painter.drawText(200, 200, "FAB SPACE");

    // Draw image
    QImage image("path/to/image.png");
    if (!image.isNull()) {
        painter.drawImage(200, 700, image);
    } else {
        qDebug() << "Failed to load image.";
    }

    // Adjust PDF page size to fit the table height
    pdf.setPageSize(QPageSize(QPageSize::A4));
    pdf.setPageMargins(QMarginsF(10, 10, 10, 10));

    painter.end();

    // Ask user if they want to open the generated PDF
    int response = QMessageBox::question(this, "PDF Generated", "Open the PDF?", QMessageBox::Yes | QMessageBox::No);
    if (response == QMessageBox::Yes) {
        QDesktopServices::openUrl(QUrl::fromLocalFile(filePath));
    }

}


void MainWindow::on_stat_cl_clicked()
{
    // Fetch data from the database
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT nom, nbe_projet FROM client");

    // Create a bar series and populate it with data
    QtCharts::QBarSeries *series = new QtCharts::QBarSeries();
    for (int i = 0; i < model->rowCount(); ++i) {
        QString clientName = model->data(model->index(i, 0)).toString();
        int numProjects = model->data(model->index(i, 1)).toInt();

        QtCharts::QBarSet *set = new QtCharts::QBarSet(clientName);
        *set << numProjects;
        series->append(set);
    }

    // Create a bar chart and add the series
    QtCharts::QChart *chart = new QtCharts::QChart();
    chart->addSeries(series);
    chart->setTitle("Statistics on Number of Projects per Client");
    chart->setAnimationOptions(QtCharts::QChart::AllAnimations);

    // Create and configure the axes
    QtCharts::QBarCategoryAxis *axisX = new QtCharts::QBarCategoryAxis();
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QtCharts::QValueAxis *axisY = new QtCharts::QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);

    // Create a chart view to display the chart
    QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Set up a new window to display the chart
    QDialog *chartDialog = new QDialog(this);
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(chartView);
    chartDialog->setLayout(layout);

    // Show the chart window
    chartDialog->exec();
}
void MainWindow::clicked_rech()
{
    QString searchValue = QInputDialog::getText(this, "Search", "Enter the cin to search for:");

    // Check if the search value is empty
    if (searchValue.isEmpty()) {
        QMessageBox::information(this, "Information", "Please enter a cin.");
        return;
    }

    // Search for the cin in the table
    QSqlQuery query;
    query.prepare("SELECT * FROM client WHERE cin = :cin");
    query.bindValue(":cin", searchValue);

    if (query.exec() && query.next()) {
        // Cin exists, display it
        QMessageBox::information(this, "Result", "CIN: " + searchValue + " exists.");
    } else {
        // Cin does not exist
        QMessageBox::warning(this, "Result", "Invalid CIN: " + searchValue);
    }
}

#include <QtGlobal> // Include for qrand()
//#include "smtpclient.h"
#include "mimepart.h"
#include "mimeattachment.h"
#include "emailaddress.h"
#include "mimetext.h"
#include <QDateTime>
#include <QApplication>
/*void MainWindow::on_mailing_clicked()
{
    // Get recipient's email address
    QString recipientEmail = QInputDialog::getText(this, "Recipient Email", "Enter the recipient's email address:");

    // Check if recipient's email address is empty
    if (recipientEmail.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Recipient's email address cannot be empty.");
        return;
    }

    // Create the SMTP client
    SmtpClient smtp("smtp-relay.brevo.com", 587, SmtpClient::TcpConnection);

    // Set the sender's email address and password
    smtp.setUser("mrabetomar31@gmail.com");
    smtp.setPassword("Iz2Mq1vpJhNR90jS");

    // Create the email message
    MimeMessage message;
    message.setSender(new EmailAddress("mrabetomar31@gmail.com", "omar"));
    message.addRecipient(new EmailAddress(recipientEmail, "Recipient"));
    message.setSubject("Confirmation Email");
    message.addPart(new MimeText("Thank you for registering. Your registration is confirmed."));

    // Send the email
    if (!smtp.connectToHost()) {
        QMessageBox::critical(this, "SMTP Error", "Failed to connect to SMTP server.");
        return;
    }

    if (!smtp.login()) {
        QMessageBox::critical(this, "SMTP Error", "Failed to login to SMTP server.");
        return;
    }

    if (!smtp.sendMail(message)) {
        QMessageBox::critical(this, "SMTP Error", "Failed to send the confirmation email.");
        return;
    }

    smtp.quit();
}*/
void MainWindow::on_historyButton_clicked()
{


    // Execute the INSERT query
    QSqlQuery query;


    // Display the existing history records
    query.exec("SELECT timestamp, client_id, action_description FROM client_history");

    // Prepare the warning message
    QString warningMessage = "History Records:\n\n";

    // Append history records to the message
    while (query.next()) {
        QDateTime timestamp = query.value(0).toDateTime();
        int clientId = query.value(1).toInt();
        QString actionDescription = query.value(2).toString();

        warningMessage += "Timestamp: " + timestamp.toString() + "\n";
        warningMessage += "Client ID: " + QString::number(clientId) + "\n";
        warningMessage += "Action Description: " + actionDescription + "\n\n";
    }

    // Display the warning message
    QMessageBox::warning(this, "History Records", warningMessage);
}


// employee *****************************************************************************************



void MainWindow::on_confirm_clicked()
{
    // Collect data from UI
    QString id = ui->lineEdit_id_3->text();
    QString name = ui->lineEdit_name_3->text();
    QString lastName = ui->lineEdit_lastName_3->text();
    QDate dateOfBirth = ui->dateEdit_dateOfBirth_3->date();
    QDate dateEmb = ui->dateEdit_dateEmb_3->date();
    QString address = ui->lineEdit_address_3->text();
    QString phone = ui->lineEdit_phone_3->text();
    QString email = ui->lineEdit_email_3->text();
    QString function = ui->lineEdit_function_3->text();
    QString UserName = ui->lineEdit_UserName_3->text();
    QString password = ui->lineEdit_password_3->text();
    bool ok;
    if (!id.toInt(&ok) || !ok) {
        QMessageBox::critical(this, "Invalid Input", "ID must contain only Numbers.");
        return;
    }

    if (isCreatingPerso) {
        QSqlQuery checkIdQuery;
        checkIdQuery.prepare("SELECT COUNT(*) FROM personnel WHERE ID = ?");
        checkIdQuery.addBindValue(id);
        if (checkIdQuery.exec()) {
            if (checkIdQuery.next() && checkIdQuery.value(0).toInt() > 0) {
                QMessageBox::critical(this, "Invalid Input", "ID is already exist.");
                return;
            }
        } else {
            QMessageBox::critical(this, "Database Error", "Failed to check ID uniqueness: " + checkIdQuery.lastError().text());
            return;
        }
    }

    if (name.isEmpty() || name.toInt(&ok), ok) {
           QMessageBox::critical(this, "Invalid Input", "Name must contain only letters.");
           return;
       }

    QRegExp lastNameRegExp("^[A-Za-z]+$");
    if (!lastNameRegExp.exactMatch(lastName)) {
        QMessageBox::critical(this, "Invalid Input", "Last name must contain only letters.");
        return;
    }

    if (address.isEmpty()) {
        QMessageBox::critical(this, "Invalid Input", "Address cannot be empty.");
        return;
    }

    QRegExp phoneRegExp("^\\d{8}$");
    if (!phoneRegExp.exactMatch(phone)) {
        QMessageBox::critical(this, "Invalid Input", "Phone number must be exactly 8 Number.");
        return;
    }
    if (isCreatingPerso) {
        QSqlQuery checkQuery;
        checkQuery.prepare("SELECT COUNT(*) FROM personnel WHERE PHONE = ?");
        checkQuery.addBindValue(phone);
        if (checkQuery.exec()) {
            if (checkQuery.next() && checkQuery.value(0).toInt() > 0) {
                QMessageBox::critical(this, "Invalid Input", "Phone number is already exists.");
                return;
            }
        } else {
            QMessageBox::critical(this, "Database Error", "Failed to check phone number uniqueness: " + checkQuery.lastError().text());
            return;
        }
    }

    QRegExp emailRegExp("^[\\w-\\.]+@[\\w-]+\\.[\\w-]{2,4}$");
    if (!emailRegExp.exactMatch(email)) {
        QMessageBox::critical(this, "Invalid Input", "Email must be in the format example@something.com");
        return;
    }



    if (isCreatingPerso) {
        QSqlQuery checkEmailQuery;
        checkEmailQuery.prepare("SELECT COUNT(*) FROM personnel WHERE EMAIL = ?");
        checkEmailQuery.addBindValue(email);
        if (checkEmailQuery.exec()) {
            if (checkEmailQuery.next() && checkEmailQuery.value(0).toInt() > 0) {
                QMessageBox::critical(this, "Invalid Input", "Email is already exists.");
                return;
            }
        } else {
            QMessageBox::critical(this, "Database Error", "Failed to check email uniqueness: " + checkEmailQuery.lastError().text());
            return;
        }
    }

    if (function.isEmpty()) {
        QMessageBox::critical(this, "Invalid Input", "Function cannot be empty.");
        return;
    }

    if (UserName.isEmpty()) {
        QMessageBox::critical(this, "Invalid Input", "User Name cannot be empty.");
        return;
    }

    if (password.length() < 8) {
            QMessageBox::critical(this, "Invalid Input", "Password must be at least 8 characters long.");
            return;
        }

        // Check if the first character is a capital letter
        if (password.isEmpty() || !password[0].isUpper()) {
            QMessageBox::critical(this, "Invalid Input", "The first character of the password must be a capital letter.");
            return;
        }






    // Create a Member object (assuming you have a constructor set up to take all these arguments)
    Personnel newPersonnel(id, name, lastName, dateOfBirth,dateEmb, address, phone, email, function, UserName, password, imagePath);

    // Insert into database
    QSqlQuery query;
    query.prepare("INSERT INTO personnel (ID, NAME, LAST_NAME, DATE_OF_BIRTH,DATE_EMB, ADDRESS, PHONE, EMAIL, FUNCTION, USER_NAME, PASSWORD, IMAGE_PATH) "
                  "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
    query.addBindValue(newPersonnel.getId());
    query.addBindValue(newPersonnel.getName());
    query.addBindValue(newPersonnel.getLastName());
    query.addBindValue(newPersonnel.getDateOfBirth());
     query.addBindValue(newPersonnel.getDateEmb());
    query.addBindValue(newPersonnel.getAddress());
    query.addBindValue(newPersonnel.getPhone());
    query.addBindValue(newPersonnel.getEmail());
    query.addBindValue(newPersonnel.getFunction());
    query.addBindValue(newPersonnel.getUserName());
    query.addBindValue(newPersonnel.getPassword());
    query.addBindValue(memberImagePath);

    if (query.exec()) {
            QMessageBox::information(this, "Success", "Personnel added successfully!");
            personnelsModel->select(); // Refresh the model to include the new Personnel

            // Clear the form after adding the member
            ui->lineEdit_id_3->clear();
            ui->lineEdit_name_3->clear();
            ui->lineEdit_lastName_3->clear();
            ui->dateEdit_dateOfBirth_3->setDate(QDate(2000, 1, 1)); // Set the date to January 1, 2000
            ui->dateEdit_dateEmb_3->setDate(QDate(2000, 1, 1)); // Set the date to January 1, 2000
            ui->lineEdit_address_3->clear();
            ui->lineEdit_phone_3->clear();
            ui->lineEdit_email_3->clear();
            ui->lineEdit_function_3->clear();
            ui->lineEdit_UserName_3->clear();
            ui->lineEdit_password_3->clear();
            ui->imageLabel_2->clear();
            memberImagePath.clear();
             ui->stackedWidget->setCurrentIndex(2); // Switch back to the member list page
        } else {

        query.prepare("UPDATE personnel SET ID = ?, NAME = ?, LAST_NAME = ?, DATE_OF_BIRTH = ?, DATE_EMB = ?, ADDRESS = ?, PHONE = ?, EMAIL = ?, FUNCTION = ?, USER_NAME = ?, PASSWORD = ?, IMAGE_PATH = ? WHERE ID = ?");
        query.addBindValue(id);
        query.addBindValue(name);
        query.addBindValue(lastName);
        query.addBindValue(dateOfBirth);
        query.addBindValue(dateEmb);
        query.addBindValue(address);
        query.addBindValue(phone);
        query.addBindValue(email);
        query.addBindValue(function);
        query.addBindValue(UserName);
        query.addBindValue(password);
        query.addBindValue(memberImagePath);
        query.addBindValue(selectedPersonnelId);

        if (query.exec()) {
            QMessageBox::information(this, "Success", "Personnels updated successfully!");
            personnelsModel->select(); // Refresh the model to include the updated member
            ui->lineEdit_id_3->clear();
            ui->lineEdit_name_3->clear();
            ui->lineEdit_lastName_3->clear();
            ui->dateEdit_dateOfBirth_3->setDate(QDate(2000, 1, 1)); // Set the date to January 1, 2000
            ui->dateEdit_dateEmb_3->setDate(QDate(2000, 1, 1)); // Set the date to January 1, 2000
            ui->lineEdit_address_3->clear();
            ui->lineEdit_phone_3->clear();
            ui->lineEdit_email_3->clear();
            ui->lineEdit_function_3->clear();
            ui->lineEdit_UserName_3->clear();
            ui->lineEdit_password_3->clear();
            ui->imageLabel_2->clear();
            memberImagePath.clear();

           ui->stackedWidget->setCurrentIndex(6); // Switch back to the member list page


        }
    }
}

void MainWindow::on_cancel_clicked()
{
    // Clear all the input fields
    ui->lineEdit_id_3->clear();
    ui->lineEdit_name_3->clear();
    ui->lineEdit_lastName_3->clear();
    ui->dateEdit_dateOfBirth_3->setDate(QDate(2000, 1, 1)); // Set the date to January 1, 2000
    ui->dateEdit_dateEmb_3->setDate(QDate(2000, 1, 1)); // Set the date to January 1, 2000
    ui->lineEdit_address_3->clear();
    ui->lineEdit_phone_3->clear();
    ui->lineEdit_email_3->clear();
    ui->lineEdit_function_3->clear();
    ui->lineEdit_UserName_3->clear();
    ui->lineEdit_password_3->clear();
    ui->imageLabel_2->clear();
    memberImagePath.clear();
      //  ui->stackedWidget->setCurrentIndex(2);
        ui->lineEdit_id_3->setReadOnly(false);
        // Add any other fields you might have in your form
}

    void MainWindow::on_pushButton_14_p_2_clicked() {
        isCreatingPerso = false;

        // Check if any row is selected
        QModelIndexList selectedRows = ui->tableView_p->selectionModel()->selectedRows();
        if (!selectedRows.isEmpty()) {
            int row = selectedRows.first().row();

            // Retrieve personnel ID
            selectedPersonnelId = personnelsModel->data(personnelsModel->index(row, 0)).toString(); // Assuming ID is in the first column

            // Populate the form with selected personnel's details
            ui->lineEdit_id_3->setText(selectedPersonnelId);
            ui->lineEdit_name_3->setText(personnelsModel->data(personnelsModel->index(row, 1)).toString());
            ui->lineEdit_lastName_3->setText(personnelsModel->data(personnelsModel->index(row, 2)).toString());
            ui->dateEdit_dateOfBirth_3->setDate(personnelsModel->data(personnelsModel->index(row, 3)).toDate());
            ui->dateEdit_dateEmb_3->setDate(personnelsModel->data(personnelsModel->index(row, 4)).toDate());
            ui->lineEdit_address_3->setText(personnelsModel->data(personnelsModel->index(row, 5)).toString());
            ui->lineEdit_phone_3->setText(personnelsModel->data(personnelsModel->index(row, 6)).toString());
            ui->lineEdit_email_3->setText(personnelsModel->data(personnelsModel->index(row, 7)).toString());
            ui->lineEdit_function_3->setText(personnelsModel->data(personnelsModel->index(row, 8)).toString());
            ui->lineEdit_UserName_3->setText(personnelsModel->data(personnelsModel->index(row, 9)).toString());
            ui->lineEdit_password_3->setText(personnelsModel->data(personnelsModel->index(row, 10)).toString());

            // Load and display image
            QString imagePath = personnelsModel->data(personnelsModel->index(row, 11)).toString(); // Assuming 11 is the image path column
            QPixmap image(imagePath);
            if (!image.isNull()) {
                ui->imageLabel_2->setPixmap(image.scaled(ui->imageLabel_2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
            } else {
                qDebug() << "Image at path" << imagePath << "could not be loaded.";
                ui->imageLabel_2->setText("No image available");
            }

            // Set read-only property and update stacked widget
            ui->lineEdit_id_3->setReadOnly(true);
            ui->stackedWidget->setCurrentIndex(6);
        } else {
            // Inform user about no selection
            QMessageBox::information(this, "No Selection", "Please select a member to modify.");
        }
    }

void MainWindow::on_pushButton_17_clicked()
{
    QModelIndexList selectedRows = ui->tableView_p->selectionModel()->selectedRows();
        if (!selectedRows.isEmpty()) {
            int row = selectedRows.first().row();
            QString personnelId = personnelsModel->data(personnelsModel->index(row, 0)).toString();

            // Ask for confirmation before deleting
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, "Delete Personnel", "Are you sure you want to delete this personnel?",
                                          QMessageBox::Yes | QMessageBox::No);
            if (reply == QMessageBox::Yes) {
                // Delete the member from the database
                QSqlQuery query;
                query.prepare("DELETE FROM personnel WHERE ID = ?");
                query.addBindValue(personnelId);
                if (query.exec()) {
                    QMessageBox::information(this, "Success", "personnel deleted successfully!");
                    personnelsModel->select(); // Refresh the model
                } else {
                    QMessageBox::information(this, "Error", "Failed to delete personnel: " + query.lastError().text());
                }
            }
        } else {
            QMessageBox::information(this, "No Selection", "Please select a personnel to delete.");
        }
}

void MainWindow::on_pushButton_14_p_clicked()
{
    personnelsModel = new QSqlTableModel(this);
    personnelsModel->setTable("PERSONNEL");
    personnelsModel->select();

    // Assuming you have a QTableView with objectName set to "tableView"
    ui->tableView_p->setModel(personnelsModel);
    ui->tableView_p->resizeColumnsToContents(); // Optional, for better column sizing
    // Check if the model is empty
    if (personnelsModel->rowCount() == 0) {
        qDebug() << "The model is empty or not properly set up.";
        qDebug() << "Error:" << personnelsModel->lastError().text();
    }

    personnelsModel->select();
    ui->stackedWidget->setCurrentIndex(6); // Switch to the page with the member list
}






void MainWindow::on_AjoutButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_searchButton_clicked()
{
    QString searchQuery = ui->searchLineEdit_2->text().trimmed();
    if (!searchQuery.isEmpty())
    {
        QString selectQuery = "ID = '" + searchQuery + "'";
        personnelsModel->setFilter(selectQuery);
        personnelsModel->select();
        if (personnelsModel->rowCount() == 0)
        {
            QMessageBox::information(this, "Not Found", "No personnel found with the provided ID.");
            selectedPersonnelId.clear();
        } else {
            selectedPersonnelId = searchQuery;
            ui->labelMessage->setText("Personnel with ID " + searchQuery + " found. Ready to add card.");
               }
     } else {
             QMessageBox::warning(this, "Input Error", "Please enter an ID to search.");
             selectedPersonnelId.clear();
            }
}



void MainWindow::on_pdfExcelButton_clicked()
{
    QMessageBox msgBox;
        msgBox.setText("Choose the format to export:");
        QPushButton *pdfButton = msgBox.addButton(tr("PDF"), QMessageBox::ActionRole);
        QPushButton *excelButton = msgBox.addButton(tr("Excel"), QMessageBox::ActionRole);

        msgBox.exec();

        if (msgBox.clickedButton() == pdfButton) {
            exportToPDF();
        } else if (msgBox.clickedButton() == excelButton) {
            exportToExcel();
        }
}

void MainWindow::exportToPDF() {
    QString fileName = QFileDialog::getSaveFileName(this, tr("Export PDF"), QString(), "*.pdf");
    if (fileName.isEmpty()) {
        return; // User canceled save
    }

    // Assuming you want to print the QTableView
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);

    QPainter painter(&printer);

    // Here we scale the output to fit on a single page. You might need to adjust this
    double scaleX = printer.pageRect().width() / double(ui->tableView_p->width());
    double scaleY = printer.pageRect().height() / double(ui->tableView_p->height());
    double scale = qMin(scaleX, scaleY);
    painter.scale(scale, scale);

    ui->tableView_p->render(&painter);
}
void MainWindow::exportToExcel() {
    QString fileName = QFileDialog::getSaveFileName(this, tr("Export Excel"), QString(), "*.csv");
    if (fileName.isEmpty()) {
        return; // User canceled save
    }

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Cannot create file");
        return;
    }

    QTextStream stream(&file);
    const int columnCount = personnelsModel->columnCount();
    const int rowCount = personnelsModel->rowCount();

    // Write headers
    for (int i = 0; i < columnCount; ++i) {
        stream << '"' << personnelsModel->headerData(i, Qt::Horizontal).toString() << '"';
        if (i < columnCount - 1) {
            stream << ",";
        } else {
            stream << "\n";
        }
    }

    // Write data
    for (int i = 0; i < rowCount; ++i) {
        for (int j = 0; j < columnCount; ++j) {
            stream << '"' << personnelsModel->data(personnelsModel->index(i, j)).toString().replace("\"", "\"\"") << '"';
            if (j < columnCount - 1) {
                stream << ",";
            } else {
                stream << "\n";
            }
        }
    }

    file.close();
}


void MainWindow::on_printButton_clicked()
{
    QPrinter printer(QPrinter::HighResolution);
    printer.setPageSize(QPrinter::A4);
    printer.setOrientation(QPrinter::Landscape);
    printer.setFullPage(false);

    QPrintDialog printDialog(&printer, this);
    if (printDialog.exec() == QDialog::Accepted) {
        QPainter painter(&printer);

        QRect printArea = printer.pageRect();

        // Get the size of the content you want to print
        QSize tableViewSize = ui->tableView_p->sizeHint();

        // Scale the content to fit within the print area
        double xscale = printArea.width() / double(tableViewSize.width());
        double yscale = printArea.height() / double(tableViewSize.height());
        double scale = qMin(xscale, yscale);

        // Translate the painter to start drawing from the top left of the print area
        painter.translate(printArea.topLeft());

        // Apply the scale
        painter.scale(scale, scale);

        // Render the table view onto the painter
        ui->tableView_p->render(&painter);
    }
}

void MainWindow::on_filterButton_clicked()
{
    int index = ui->sortComboBox_p->currentIndex();

    // Clear any existing filters or sorting
    personnelsModel->setFilter("");
    personnelsModel->setSort(0, Qt::AscendingOrder); // Reset to the default sort

    switch (index) {
        case 0:
        break;
        case 1: // Sort by increasing Creation Date
            personnelsModel->setSort(3, Qt::AscendingOrder);
            break;
        case 2: // Sort by descending Creation Date
            personnelsModel->setSort(3, Qt::DescendingOrder);
            break;
        case 3: // Sort in ascending alphabetical order
             personnelsModel->setSort(1, Qt::AscendingOrder);
             break;
        case 4: // Sort in descending alphabetical order
             personnelsModel->setSort(1, Qt::DescendingOrder);
             break;

        default:
            // Handle any other cases or errors
            break;
    }
    ui->sortComboBox_p->setCurrentIndex(0);
    personnelsModel->select(); // Apply the sort/filter
}



void MainWindow::on_generateQRButton_clicked()
{
    int tabeq=ui->tableView_p->currentIndex().row();
       QVariant idd=ui->tableView_p->model()->data(ui->tableView_p->model()->index(tabeq,0));
       QString id=idd.toString();
      // QString code=idd.toSTring();
       QSqlQuery qry;
       qry.prepare("select * from personnel where ID=:code");
       qry.bindValue(":code",id);
       qry.exec();

        QString NAME,LAST_NAME,DATE_OF_BIRTH,PHONE;//attributs

      while(qry.next()){

          id=qry.value(0).toString();
           NAME=qry.value(1).toString();
            LAST_NAME=qry.value(2).toInt();
           DATE_OF_BIRTH=qry.value(3).toInt();
           PHONE=qry.value(4).toInt();
       }
       id=QString(id);
              id="CODE:\t" +id+ "NAME\t:" +NAME+ "LAST_NAME:\t" +LAST_NAME+ "DATE_OF_BIRTH:\t" +DATE_OF_BIRTH+ "PHONE:\t" +PHONE+ "PHONE:\t" +PHONE ;
       QrCode qr = QrCode::encodeText(id.toUtf8().constData(), QrCode::Ecc::HIGH);

       // Read the black & white pixels
       QImage im(qr.getSize(),qr.getSize(), QImage::Format_RGB888);
       for (int y = 0; y < qr.getSize(); y++) {
           for (int x = 0; x < qr.getSize(); x++) {
               int color = qr.getModule(x, y);  // 0 for white, 1 for black

               // You need to modify this part
               if(color==0)
                   im.setPixel(x, y,qRgb(254, 254, 254));
               else
                   im.setPixel(x, y,qRgb(0, 0, 0));
           }
       }
       im=im.scaled(200,200);
      ui->qrcode_p->setPixmap(QPixmap::fromImage(im));
}


void MainWindow::on_uploadImageButton_clicked() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Choose Image"), "", tr("Images (*.png *.jpg *.jpeg *.bmp *.gif)"));
        if (!fileName.isEmpty()) {
            QPixmap pixmap(fileName);
            ui->imageLabel_2->setPixmap(pixmap.scaled(ui->imageLabel_2->size(), Qt::KeepAspectRatio));
            memberImagePath = fileName;

        if (!isCreatingPerso) {
            QSqlQuery query;
            query.prepare("UPDATE PERSONNEL SET IMAGE_PATH = ? WHERE ID = ?");
            query.addBindValue(memberImagePath);
            query.addBindValue(selectedPersonnelId);
            if (!query.exec()) {
                qDebug() << "Error updating personnel's image path:" << query.lastError();
            } else {
                // Refresh your model to update the view
                personnelsModel->select();
            }
        }
    }
}


void MainWindow::displaySelectedMemberImage(int Id) {

    QSqlQuery query;
    query.prepare("SELECT IMAGE_PATH FROM PERSONNEL WHERE ID = ?");
    query.addBindValue(Id);
    if(query.exec() && query.next()) {
        QString imagePath = query.value(0).toString();
        QPixmap image(imagePath);
        ui->imageLabel_2->setPixmap(image.scaled(ui->imageLabel_2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
}

// Call this method when the member selection changes, e.g., when a row in your table is clicked
void MainWindow::on_tableView_selectionChanged(const QItemSelection &selected, const QItemSelection &/*deselected*/)  {
    // Assuming you have only one selection at a time
    const QModelIndexList indexes = selected.indexes();
    if (indexes.size() > 0) {
        int memberId = indexes.at(0).data().toInt();
        displaySelectedMemberImage(memberId);
    }
}


void MainWindow::on_statAge_clicked()
{
    clearChart();
    clearChartmember();
    // Ensure the model is initially displaying all members
    personnelsModel->setTable("PERSONNEL");
    personnelsModel->select();

    // Get current date for age calculation
    QDate currentDate = QDate::currentDate();

    // Initialize counters for each age group
    int under18 = 0;
    int group18_30 = 0;
    int group31_45 = 0;
    int group46_60 = 0;
    int above60 = 0;

    for (int row = 0; row < personnelsModel->rowCount(); ++row) {
        QDate dob = personnelsModel->record(row).value("DATE_OF_BIRTH").toDate();
        int age = currentDate.year() - dob.year(); // Calculate age
        if (dob > currentDate.addYears(-age)) age--; // Adjust if the birthday hasn't occurred yet this year

        // Increment the appropriate age group counter
        if (age < 18) {
            under18++;
        } else if (age >= 18 && age <= 30) {
            group18_30++;
        } else if (age >= 31 && age <= 45) {
            group31_45++;
        } else if (age >= 46 && age <= 60) {
            group46_60++;
        } else if (age > 60) {
            above60++;
        }
    }

    // Prepare the statistical data for the list view
    QStringList ageStats;
    ageStats << QString("Under 18: %1").arg(under18);
    ageStats << QString("18-30: %1").arg(group18_30);
    ageStats << QString("31-45: %1").arg(group31_45);
    ageStats << QString("46-60: %1").arg(group46_60);
    ageStats << QString("60+: %1").arg(above60);

    // Assuming you have a QStringListModel* named statsModel that's already connected to your list view
    QStringListModel* ageStatsModel = new QStringListModel(this);
    ageStatsModel->setStringList(ageStats);

    // Assuming ui->listView is your QListView for displaying the stats
    ui->listView_p->setModel(ageStatsModel);

    // Optionally, you may want to resize the columns to fit the content
    ui->listView_p->setResizeMode(QListView::Adjust);

    QBarSet *set = new QBarSet("Age Groups");
        *set << under18 << group18_30 << group31_45 << group46_60 << above60;

        // Create a bar series and add the bar set
        QBarSeries *series = new QBarSeries();
        series->append(set);

        // Create a chart and add the series to it
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Age Distribution");
        chart->setAnimationOptions(QChart::SeriesAnimations);

        // Create the axis and set the labels
        QStringList categories;
        categories << "Under 18" << "18-30" << "31-45" << "46-60" << "60+";
        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(categories);
        chart->createDefaultAxes();
        chart->setAxisX(axisX, series);

        // Make the chart legend visible
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);

        // Create a chart view with the chart
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        // Add the chart view to the placeholder widget's layout
        QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(ui->placeholderWidget_2->layout());
        if (!layout) {
            layout = new QVBoxLayout();
            ui->placeholderWidget_2->setLayout(layout);

        }
        layout->addWidget(chartView);

        // Set the string list to the model and then set the model to the list view
        ui->listView_p->setModel(ageStatsModel);



}

void MainWindow::clearChart()
{
    QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(ui->chartFrame_2->layout());
    if (layout) {
        QLayoutItem *child;
        while ((child = layout->takeAt(0)) != nullptr) {
            if (child->widget()) {
                delete child->widget(); // This will delete the chart view
            }
            delete child;
        }
    }
}


void MainWindow::clearChartmember()
{
    // Assuming 'placeholderWidget' is a QWidget or QFrame in your UI where the stats are displayed
    if (ui->placeholderWidget_2->layout() != nullptr) {
        // Remove and delete all widgets from the layout
        QLayoutItem *child;
        while ((child = ui->placeholderWidget_2->layout()->takeAt(0)) != nullptr) {
            delete child->widget(); // This will delete the chart view
            delete child;           // This will delete the layout item
        }
    }

    // Optionally, remove the layout itself
    delete ui->placeholderWidget_2->layout();
    ui->placeholderWidget_2->setLayout(new QVBoxLayout()); // Set a new clean layout
}

void MainWindow::on_stat_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

// **********************************************************************************





// eq *************************************************************
void MainWindow::onLoginButtonClicked_eq()
{
    // Move to the next page in the stacked widget (Page 2)
    ui->stackedWidget->setCurrentIndex(1);
    ui->tableView->setModel(EQtemp.Afficher());

}
/*
void MainWindow::on_gestio_eqB_clicked_eq()
{
    // Move to the next page in the stacked widget (Page Gestion)
    ui->stackedWidget->setCurrentIndex(8);
    ui->tableView->setModel(EQtemp.Afficher());

}*/

void MainWindow::on_Back_gestion_clicked_eq()
{
    // Move to the previous page in the stacked widget (Page 2)
    ui->stackedWidget->setCurrentIndex(5);

}

void MainWindow::on_AjoutBttoneq_clicked_eq()
{
    // Move to the next page in the stacked widget (Ajout page)
    ui->stackedWidget->setCurrentIndex(10);
    ui->tableView->setModel(EQtemp.Afficher());

}


void MainWindow::on_BackAjout_clicked_eq()
{
    // Move to the previous page in the stacked widget (Page Gestion)
    ui->stackedWidget->setCurrentIndex(5);
    ui->tableView->setModel(EQtemp.Afficher());

}

void MainWindow::on_BackModifir_clicked_eq()
{
    // Move to the previous page in the stacked widget (Page Gestion)
    ui->stackedWidget->setCurrentIndex(9);
    ui->tableView->setModel(EQtemp.Afficher());

}

void MainWindow::on_ModifierButtoneq_clicked()
{
    // Move to the previous page in the stacked widget (Page Gestion)
    ui->stackedWidget->setCurrentIndex(11);
    ui->tableView->setModel(EQtemp.Afficher());

}




void MainWindow::on_BUTTONAJOUTENRE_clicked_eq() {
    // Récupérer les données de l'équipement à partir des champs de saisie
    QString idString = ui->id_u_3->text();
    QString nom = ui->nom_u_2->text();
    QString quantiteString = ui->quantite_u->text();
    QString prixString = ui->prix_u->text();
    QString prixLocString = ui->prixLoc_u->text();

    // Vérifier si les champs sont vides
    if (idString.isEmpty() || nom.isEmpty() || quantiteString.isEmpty() || prixString.isEmpty() || prixLocString.isEmpty()) {
        QMessageBox::critical(this, "Erreur", "Veuillez remplir tous les champs.");
        return;
    }

    // Vérifier si les valeurs saisies sont valides
    bool conversionOk = false;
    int id = idString.toInt(&conversionOk);
    if (!conversionOk || id <= 0) {
        QMessageBox::critical(this, "Erreur", "ID invalide. Veuillez saisir un nombre entier positif.");
        return;
    }

    int quantite = quantiteString.toInt(&conversionOk);
    if (!conversionOk || quantite <= 0) {
        QMessageBox::critical(this, "Erreur", "Quantité invalide. Veuillez saisir un nombre entier positif.");
        return;
    }

    double prix = prixString.toDouble(&conversionOk);
    if (!conversionOk || prix <= 0) {
        QMessageBox::critical(this, "Erreur", "Prix invalide. Veuillez saisir un nombre décimal positif.");
        return;
    }

    double prixLoc = prixLocString.toDouble(&conversionOk);
    if (!conversionOk || prixLoc <= 0) {
        QMessageBox::critical(this, "Erreur", "Prix de location invalide. Veuillez saisir un nombre décimal positif.");
        return;
    }

    // Créer une instance de la classe Equipement avec les données récupérées
    Equipement equipement(id, nom, quantite, prix, prixLoc);

    // Ajouter l'équipement à la base de données
    bool test = equipement.Ajouter();
    if (test) {
        // Mettre à jour la vue du tableau si l'ajout de l'équipement est réussi
        ui->tableView->setModel(EQtemp.Afficher());
        QMessageBox::information(this, "Succès", "Équipement ajouté avec succès.");
    } /*else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout de l'équipement à la base de données.");
    }*/
}


void MainWindow::on_Supprimer_Button_clicked_eq()
{
    ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::on_pushButton_216_clicked_eq()
{
        QMessageBox msgBox;

        // Récupérer l'identifiant de l'équipement depuis le widget QLineEdit
        int id = ui->id_u_2->text().toInt();
        bool test = EQtemp.Supprimer(id);

        if(test)
        {
            ui->tableView->setModel(EQtemp.Afficher());
            msgBox.setText("Suppression réussie pour l'ID : " + QString::number(id));
        }
        else
        {
            msgBox.setText("Échec de suppression pour l'ID : " + QString::number(id) + ". Vérifiez les erreurs.");

            // Récupérer le message d'erreur à partir de l'objet QSqlQuery

        }

        msgBox.exec();
}


void MainWindow::on_BackModifir_15_clicked_eq()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_modifier_Button_clicked_eq()
{
    int id = ui->id_u->text().toInt();
    QString nom = ui->nom_u_3->text();
    int quantite = ui->quantite_u_2->text().toInt();
    double prix = ui->prix_u_2->text().toDouble();
    double prixLoc = ui->prixLoc_u_2->text().toDouble();

    // Vérifier que le champ "nom" n'est pas vide
        if (nom.isEmpty()) {
            QMessageBox::critical(this, "Erreur", "Le champ 'Nom' ne peut pas être vide.");
            return; // Sortir de la fonction si le champ est vide
        }

        /* Vérifier que la quantité est positive et non nulle
        if (quantite <= 0) {
            QMessageBox::critical(this, "Erreur", "La quantité doit être supérieure à zéro.");
            return; // Sortir de la fonction si la quantité est invalide
        }*/

        // Vérifier que le prix est positif et non nul
        if (prix <= 0) {
            QMessageBox::critical(this, "Erreur", "Le prix doit être supérieur à zéro.");
            return; // Sortir de la fonction si le prix est invalide
        }

        // Vérifier que le prix de location est positif et non nul
        if (prixLoc <= 0) {
            QMessageBox::critical(this, "Erreur", "Le prix de location doit être supérieur à zéro.");
            return; // Sortir de la fonction si le prix de location est invalide
        }

    Equipement e(id,nom,quantite,prix,prixLoc);
    bool test = e.Modifier(id);

    QMessageBox msgBox;

    if (test) {
        msgBox.setText("Modification avec succès.");
        ui->tableView->setModel(e.Afficher());
    } else {
        msgBox.setText("Échec de la modification. Veuillez consulter la console pour plus de détails.");
    }

    msgBox.exec();
}

void MainWindow::on_pushButton_20_clicked_eq() {
    // Récupérer le critère de tri à partir de la ligne de saisie
    QString critereTri = ui->trie->text();

    // Vérifier si le critère de tri est valide
    if (!critereTri.isEmpty()) {
        // Trier les équipements en fonction du critère spécifié
        QSqlQueryModel* model = new QSqlQueryModel();
        QString query = "SELECT ID_EQ, NOM_EQ, QUANTITE_EQ, PRIX_EQ, PRIXLOC_EQ FROM EQUIPEMENT ORDER BY " + critereTri;
        model->setQuery(query);

        // Mettre à jour la vue du tableau avec les équipements triés
        ui->tableView_2->setModel(model);
    } else {
        QMessageBox::warning(this, "Critère de tri vide", "Veuillez spécifier un critère de tri.");
    }
}
void MainWindow::on_pushButton_clicked_eq() {
    // Afficher les équipements depuis la base de données
    ui->tableView_2->setModel(EQtemp.Afficher());
}
void MainWindow::on_rechercherButton_clicked_eq() {
    // Récupérer le texte saisi dans le champ de recherche
    QString rechercheTexte = ui->recherche->text().trimmed(); // Trim pour enlever les espaces inutiles

    // Construire la requête SQL en filtraaant les résultats selon les critères que vous définissez
    QString queryString = QString("SELECT ID_EQ, NOM_EQ, QUANTITE_EQ, PRIX_EQ, PRIXLOC_EQ FROM EQUIPEMENT WHERE ID_EQ LIKE '%%1%' OR NOM_EQ LIKE '%%1%' OR QUANTITE_EQ LIKE '%%1%' OR PRIX_EQ LIKE '%%1%' OR PRIXLOC_EQ LIKE '%%1%'").arg(rechercheTexte);

    // Exécuter la requête SQL
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(queryString);

    // Définir les en-têtes
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Quantité"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prix location"));

    // Mettre à jour la vue du tableau avec les résultats filtrés
    ui->tableView_2->setModel(model);
}

#include <QPrinter>
#include <QPainter>
#include <QTextDocument>
#include <QTextCursor>

void MainWindow::drawModel_eq(QPainter& painter, QSqlQueryModel* model) {
    QTextDocument doc;
    QSizeF pageSize(model->columnCount() * 200, model->rowCount() * 60); // Ajustez les valeurs selon vos besoins
    doc.setPageSize(pageSize);
    QString html = "<html><body><h1>FAB SPACE</h1><h3>Listes des equipements</h3><table border='1'>";

    // Header
    html += "<tr>";
    for (int col = 0; col < model->columnCount(); ++col) {
        html += QString("<th>%1</th>").arg(model->headerData(col, Qt::Horizontal).toString());
    }
    html += "</tr>";

    // Data
    for (int row = 0; row < model->rowCount(); ++row) {
        html += "<tr>";
        for (int col = 0; col < model->columnCount(); ++col) {
            QString data = model->data(model->index(row, col)).toString();
            html += QString("<td>%1</td>").arg(data);
        }
        html += "</tr>";
    }

    html += "</table></body></html>";
    doc.setHtml(html);
    doc.drawContents(&painter);
}
void MainWindow::exportToPDF_eq(const QString& filePath, QSqlQueryModel* model) {
    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filePath);

    QPainter painter;
    painter.begin(&printer);

    drawModel_eq(painter, model);

    painter.end();
}
void MainWindow::on_exportToPdfButton_clicked_eq() {
    QString filePath = QFileDialog::getSaveFileName(this, tr("Save PDF"), "", "PDF Files (*.pdf)");
    if (!filePath.isEmpty()) {
        QSqlQueryModel *queryModel = qobject_cast<QSqlQueryModel*>(ui->tableView_2->model());
        if (queryModel) {
            exportToPDF_eq(filePath, queryModel);
            QMessageBox::information(this, tr("Export PDF"), tr("PDF exported successfully."));
        } else {
            QMessageBox::warning(this, tr("Export PDF"), tr("Unable to export PDF: Invalid model type."));
        }
    }
}
/*void MainWindow::verifierQuantiteEquipements_eq() {
    // Requête pour récupérer tous les équipements disponibles
    QSqlQuery query("SELECT NOM_EQ FROM EQUIPEMENT WHERE QUANTITE_EQ = 0");

    QStringList equipementsEpuises; // Liste pour stocker les noms des équipements épuisés

    // Vérification de chaque équipement
    while (query.next()) {
        QString nomEquipement = query.value(0).toString();
        equipementsEpuises.append(nomEquipement);
    }

    // Vérification s'il y a des équipements épuisés
    if (!equipementsEpuises.isEmpty()) {
        // Construction du message de notification
        QString messageNotification = "Les équipements suivants sont épuisés :\n";
        messageNotification += equipementsEpuises.join(", ");

        // Envoyer la notification (par exemple, afficher dans une boîte de dialogue)
        QMessageBox::information(this, "Notification - Équipements épuisés", messageNotification);
    }
}*/
void MainWindow::on_loginButton_clicked_eq()
{
    // Récupérer le nom d'utilisateur et le mot de passe saisis par l'utilisateur
    QString username = ui->Username->text();
    QString password = ui->Password->text();

    // Vérifier les informations d'identification dans la base de données
    QSqlQuery query;
    query.prepare("SELECT * FROM LOGIN WHERE USERNAME = :USERNAME AND PASSWORD = :PASSWORD");
    query.bindValue(":USERNAME", username);
    query.bindValue(":PASSWORD", password);

    if (query.exec() && query.next()) {
        // L'utilisateur est authentifié avec succès
        QMessageBox::information(this, "Connexion réussie", "Vous êtes maintenant connecté.");
        // Rediriger vers la page principale de l'application ou effectuer d'autres actions nécessaires
        ui->stackedWidget->setCurrentWidget(ui->menu);
    } else {
        // L'authentification a échoué
        QMessageBox::warning(this, "Échec de la connexion", "Nom d'utilisateur ou mot de passe incorrect.");
    }
}
void MainWindow::on_forgotPasswordButton_clicked_eq()
{
    // Ouvrir la fenêtre de réinitialisation de mot de passe
    PasswordResetDialog resetDialog;
    resetDialog.exec();
}
void MainWindow::on_StatsButton_clicked_eq()
{
    // Créer une instance de la page de statistiques
    StatsPage *statsPage = new StatsPage(this);

    // Afficher la page deistiques
    statsPage->show();
}
void MainWindow::on_stat_cl_clicked_eq()
{
    // Fetch data from the database
    QSqlQueryModel *quantityModel = new QSqlQueryModel();
    quantityModel->setQuery("SELECT NOM_EQ, QUANTITE_EQ FROM EQUIPEMENT");

    // Create a bar series for quantity statistics and populate it with data
    QtCharts::QBarSeries *quantitySeries = new QtCharts::QBarSeries();
    for (int i = 0; i < quantityModel->rowCount(); ++i) {
        QString equipementName = quantityModel->data(quantityModel->index(i, 0)).toString();
        int quantity = quantityModel->data(quantityModel->index(i, 1)).toInt();

        QtCharts::QBarSet *set = new QtCharts::QBarSet(equipementName);
        *set << quantity;
        quantitySeries->append(set);
    }

    // Create a bar chart for quantity statistics
    QtCharts::QChart *quantityChart = new QtCharts::QChart();
    quantityChart->addSeries(quantitySeries);
    quantityChart->setTitle("Statistique en quantité des équipements");
    quantityChart->setAnimationOptions(QtCharts::QChart::AllAnimations);

    // Create and configure the axes for quantity statistics
    QtCharts::QBarCategoryAxis *quantityAxisX = new QtCharts::QBarCategoryAxis();
    quantityChart->addAxis(quantityAxisX, Qt::AlignBottom);
    quantitySeries->attachAxis(quantityAxisX);

    QtCharts::QValueAxis *quantityAxisY = new QtCharts::QValueAxis();
    quantityChart->addAxis(quantityAxisY, Qt::AlignLeft);

    // Fetch data for price statistics
    QSqlQueryModel *priceModel = new QSqlQueryModel();
    priceModel->setQuery("SELECT NOM_EQ, PRIX_EQ FROM EQUIPEMENT");

    // Create a pie series for price statistics and populate it with data
    QtCharts::QPieSeries *priceSeries = new QtCharts::QPieSeries();
    for (int i = 0; i < priceModel->rowCount(); ++i) {
        QString equipementName = priceModel->data(priceModel->index(i, 0)).toString();
        double price = priceModel->data(priceModel->index(i, 1)).toDouble();

        QtCharts::QPieSlice *slice = new QtCharts::QPieSlice(equipementName, price);
        priceSeries->append(slice);
    }

    // Create a pie chart for price statistics
    QtCharts::QChart *priceChart = new QtCharts::QChart();
    priceChart->addSeries(priceSeries);
    priceChart->setTitle("Statistique en prix des équipements");
    priceChart->setAnimationOptions(QtCharts::QChart::AllAnimations);

    // Create a chart view to display the charts
    QtCharts::QChartView *quantityChartView = new QtCharts::QChartView(quantityChart);
    quantityChartView->setRenderHint(QPainter::Antialiasing);

    QtCharts::QChartView *priceChartView = new QtCharts::QChartView(priceChart);
    priceChartView->setRenderHint(QPainter::Antialiasing);

    // Set up a new window to display the charts
    QDialog *chartDialog = new QDialog(this);
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(quantityChartView);
    layout->addWidget(priceChartView);
    chartDialog->setLayout(layout);

    // Show the chart window
    chartDialog->exec();
}
// ESPACEEEEEEEEE   ***************************************************************************************************************

void MainWindow::on_ajouter_clicked()
{
    QStringList typesValides = {"conference", "labo", "formation"};
    QStringList etatsValides = {"0", "1"};

    QString type = ui->type_1->text();
    int quantite = ui->quantite->text().toInt();
    int etat = ui->etat->text().toInt();
    QString reference = ui->reference->text();

    // Get the selected date from the dateEdit widget
    QDate disponibilite = ui->dateEdit_1->date();

    //controle de saisie reference
    if (reference.length() < 5 || !reference.contains(QRegularExpression("[a-zA-Z]")) || !reference.contains(QRegularExpression("\\d"))) {
        QMessageBox::warning(this, "Erreur", "La référence doit contenir au moins 5 caractères avec des lettres et des chiffres.");
        return;
    }

    //controle de saisie type
    if (!typesValides.contains(type)) {
        QMessageBox::warning(this, "Erreur", "Le type doit être 'conference', 'labo', 'formation'.");
        return;
    }

    //controle de saisie etat
    if (!etatsValides.contains(QString::number(etat))) {
        QMessageBox::warning(this, "Erreur", "L'état doit être 0 ou 1 ");
        return;
    }

    espace E(reference, quantite, type, etat, disponibilite); // Pass the selected date
    bool test = E.ajouter(reference);

    if (test) {
        ui->affichage->setModel(E1.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("espace ajouté.\nCliquez sur OK pour quitter"), QMessageBox::Ok);
        ui->reference->clear();
        ui->quantite->clear();
        ui->type_1->clear();
        ui->etat->clear();
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Erreur lors de l'ajout de l'équipement.\nCliquez sur OK pour quitter"), QMessageBox::Ok);
    }


    QString message = "Nouveau espace ajouté: " + reference + " avec type: " + type ;
    SMS sms;
    QString to = "+21625243360";
    sms.sendSms(to, message);


}


void MainWindow::on_supprimer_clicked()
{
    QModelIndex index = ui->affichage->currentIndex();
    QString reference2 = index.sibling(index.row(), 0).data().toString();
    espace E2 ;
    E2.setReference(ui->ref_supp_1->text()) ;
    bool test=E2.supprimer(E2.getReference()) ;
    if(test)
{
         ui->ref_supp_1->clear();
         ui->affichage->setModel(E2.afficher()) ;
        QMessageBox::information(nullptr, QObject::tr("OK"),
                 QObject::tr("espace supprime .\n""clique Ok pour quiter"),QMessageBox::Ok);
        ui->reference->clear() ;

        ui->quantite->clear() ;
        ui->type_1->clear() ;
        ui->etat->clear() ;
}
    else
        QMessageBox::critical(nullptr, QObject::tr("LE"),
                 QObject::tr("NOOOOOOON.\n""clique Ok pour quiter"),QMessageBox::Ok);
    bool test2=E2.supprimer(reference2) ;
    if(test2)
{

     ui->affichage->setModel(E2.afficher()) ;
     ui->reference->clear() ;

     ui->quantite->clear() ;
     ui->type_1->clear() ;
     ui->etat->clear() ;

}
    else
        QMessageBox::critical(nullptr, QObject::tr("LE"),
                 QObject::tr("NOOOOON 2.\n""clique Ok pour quiter"),QMessageBox::Ok);
}

void MainWindow::on_modifier_clicked()
{
    QStringList typesValides = {"conference", "labo", "formation"};
    QStringList etatsValides = {"0", "1"};
    QString reference = ui->reference->text();
    QString type = ui->type_1->text();
    int quantite = ui->quantite->text().toInt();
    int etat = ui->etat->text().toInt();

    // Get the selected date from the dateEdit widget
    QDate disponibilite = ui->dateEdit_1->date();

    //controle de saisie reference
    if (reference.length() < 5 || !reference.contains(QRegularExpression("[a-zA-Z]")) || !reference.contains(QRegularExpression("\\d"))) {
        QMessageBox::warning(this, "Erreur", "La référence doit contenir au moins 5 caractères avec des lettres et des chiffres.");
        return;
    }

    //controle de saisie type
    if (!typesValides.contains(type)) {
        QMessageBox::warning(this, "Erreur", "Le type doit être 'conference', 'labo', 'formation'.");
        return;
    }

    //controle de saisie etat
    if (!etatsValides.contains(QString::number(etat))) {
        QMessageBox::warning(this, "Erreur", "L'état doit être 0, 1 .");
        return;
    }

    espace E(reference, quantite, type, etat, disponibilite); // Pass the selected date
    bool test = E.modifier(reference);

    if (test) {
        ui->affichage->setModel(E.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("espace Modifie .\n""clique Ok pour quitter"), QMessageBox::Ok);
        ui->reference->clear();
        ui->type_1  ->clear();
        ui->etat->clear();
    } else {
        QMessageBox::critical(nullptr, QObject::tr("LE"),
                              QObject::tr("NOOOOOOOOOOON 3 .\n""clique Ok pour quitter"), QMessageBox::Ok);
    }
}


void MainWindow::on_affichage_clicked(const QModelIndex &index)
{
    QString  ref = index.sibling(index.row(), 0).data().toString();
            ui->reference->setText(ref);
}

void MainWindow::on_affichage_doubleClicked(const QModelIndex &index)
{
    QAbstractItemModel *model = ui->affichage->model();

    QString reference = model->data(model->index(index.row(), 0)).toString();
    QString type = model->data(model->index(index.row(), 2)).toString();
    int quantite = model->data(model->index(index.row(), 1)).toInt();
    int etat = model->data(model->index(index.row(), 3)).toInt();
    QDate disponibilite = model->data(model->index(index.row(), 4)).toDate(); // Assuming disponibilite is stored as string in the format "yyyy-MM-dd"


    ui->reference->setText(reference);
    ui->type_1->setText(type);
    ui->quantite->setText(QString::number(quantite));
    ui->etat->setText(QString::number(etat));

    // Update the dateEdit widget with the relevant date
    ui->dateEdit_1->setDate(disponibilite);
}



void MainWindow::on_pdf_clicked()
{
        espace E ;
       E.create_PDF() ;
}



void MainWindow::on_qrcode_clicked()
{


    if(ui->affichage->currentIndex().row() == -1)
    {
        QMessageBox::information(nullptr, QObject::tr("QrCode"),
                                 QObject::tr("Veuillez choisir un espace du tableau.\n"
                                             "Cliquez sur OK pour quitter."), QMessageBox::Ok);
    }
    else
    {
        int quantite = ui->affichage->model()->data(ui->affichage->model()->index(ui->affichage->currentIndex().row(),1)).toInt();
        QString qrContent = QString("la quantité est %1").arg(quantite);
        const QrCode qr = QrCode::encodeText(qrContent.toStdString().c_str(), QrCode::Ecc::LOW);
        std::ofstream myfile;
        myfile.open("qrcode.svg");

        myfile << qr.toSvgString(1);
        myfile.close();
        QSvgRenderer svgRenderer(QString("qrcode.svg"));
        QPixmap pix(QSize(90, 90));
        QPainter pixPainter(&pix);
        svgRenderer.render(&pixPainter);
        ui->label_72->setPixmap(pix);

    }
}



void MainWindow::on_search_clicked()//rech statique
{
    QString reference = ui->rech->text();
        espace E;
        E.recherche(ui->affichage, reference);
}

void MainWindow::on_filtrer_clicked()
{
    // Play notification sound
    espace E;
    ui->affichage->setModel(E.triReference());
        QMessageBox::information(nullptr, QObject::tr("OK"),QObject::tr("Tri avec id effectue.\n" "Click Cancel to exit."), QMessageBox::Cancel);

}



void MainWindow::on_rech_textChanged(const QString &arg1)//rech dynamique
{

        // Obtenez le texte de votre QLineEdit
        QString searchText = arg1;

        // Préparez la requête SQL pour rechercher des correspondances partielles dans votre base de données
        QString queryString = "SELECT * FROM ESPACE WHERE reference LIKE :searchText";

        // Préparez la requête
        QSqlQuery query;
        query.prepare(queryString);
        query.bindValue(":searchText", "%" + searchText + "%");

        // Exécutez la requête
        if (!query.exec()) {
            qDebug() << "Erreur de recherche:" << query.lastError().text();
            return;
        }

        // Créez un modèle pour stocker les résultats de la requête
        QSqlQueryModel *model = new QSqlQueryModel();

        // Chargez les résultats de la requête dans le modèle
        model->setQuery(query);

        // Affichez le modèle dans votre vue (QTableView)
        ui->affichage->setModel(model);



}




void MainWindow::on_stat_1_clicked()
{
    // Clear the layout of label_73 if it's occupied
    if (ui->label_73->layout()) {
        QLayoutItem *child;
        while ((child = ui->label_73->layout()->takeAt(0)) != nullptr) {
            delete child->widget(); // Delete any widgets in the layout
            delete child; // Delete the layout item
        }
    }

    // Create a new QPieSeries for statistics
    QPieSeries *series = new QPieSeries();

    // Create a QMap to store type names and their corresponding slices
    QMap<QString, QPieSlice*> sliceMap;

    // Calculate total count of all elements in the database
    QSqlQuery totalCountQuery("SELECT COUNT(*) AS total FROM ESPACE");
    totalCountQuery.next();
    int total = totalCountQuery.value("total").toInt();

    // Query for specific types
    QSqlQuery query("SELECT COUNT(*) AS count, type FROM ESPACE WHERE type IN ('labo', 'conference', 'formation') GROUP BY type");
    while (query.next()) {
        int count = query.value("count").toInt();
        QString type = query.value("type").toString();
        qreal percentage = (count * 100.0) / total;

        // Create a slice for each type
        QPieSlice *slice = series->append(type, percentage);
        sliceMap[type] = slice;

        // Make the slice clickable
        connect(slice, &QPieSlice::clicked, this, [=]() {
            // Adjust the size of the clicked slice
            slice->setExploded(true);
            slice->setExplodeDistanceFactor(0.2); // Adjust this value to increase/decrease the size of the slice
        });
    }

    // Create a QChart to display the statistics
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition par type");
    chart->setAnimationOptions(QChart::AllAnimations);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);

    // Create a QChartView to display the chart
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(100, 100);

    // Set the chartView as the contents of label_73
    ui->label_73->setLayout(new QVBoxLayout());
    ui->label_73->layout()->addWidget(chartView);
}


void MainWindow::on_showAvailability_1_clicked()
{
    qDebug() << "on_showAvailability_clicked() called"; // Debug output to indicate function call

    // Clear the layout of label_73 if it's occupied
    if (ui->label_73->layout()) {
        QLayoutItem *child;
        while ((child = ui->label_73->layout()->takeAt(0)) != nullptr) {
            delete child->widget(); // Delete any widgets in the layout
            delete child; // Delete the layout item
        }
    }



    // Create a calendar widget
    QCalendarWidget *calendarWidget = new QCalendarWidget();

    calendarWidget->setStyleSheet("background-color: white;");


    // Query the database to fetch availability data
    QSqlQuery query("SELECT disponibilite, etat FROM ESPACE");

    // Iterate through the query results and highlight the calendar accordingly
    while (query.next()) {
        QDate date = query.value(0).toDate();
        int etat = query.value(1).toInt();

        // Debug output to verify fetched data
        qDebug() << "Date:" << date << ", Etat:" << etat;

        // Create a QTextCharFormat object for styling
        QTextCharFormat format;

        // Set the background color of the calendar widget based on availability
        if (etat == 1) {
            // Unavailable (red)
            format.setBackground(Qt::red);
        } else {
            // Available (green)
            format.setBackground(Qt::green);
        }

        // Set the text format for the date
        calendarWidget->setDateTextFormat(date, format);
    }

    // Set the calendar widget as the contents of label_73
    ui->label_73->setLayout(new QVBoxLayout());
    ui->label_73->layout()->addWidget(calendarWidget);
}

void MainWindow::showReferenceOnHover(const QDate &date)
{
    qDebug() << "showReferenceOnHover called for date:" << date;

    QSqlQuery query;
    query.prepare("SELECT * FROM ESPACE WHERE disponibilite = :date");
    query.bindValue(":date", date);

    if (query.exec() && query.next()) {
        qDebug() << "Espace found for date:" << date;
        QString reference = query.value("reference").toString();
        int quantite = query.value("quantite").toInt();
        QString type = query.value("type").toString();
        int etat = query.value("etat").toInt();

        QMessageBox::information(this, "Espace Info",
                                 "Reference: " + reference + "\n" +
                                 "Quantite: " + QString::number(quantite) + "\n" +
                                 "type: " + type + "\n" +
                                 "Etat: " + QString::number(etat) + "\n" +
                                 "Disponibilite: " + date.toString("yyyy-MM-dd"));
    } else {
        qDebug() << "No espace found for date:" << date;
        QMessageBox::information(this, "No Espace", "There is no espace available on " + date.toString("yyyy-MM-dd"));
    }
}



void MainWindow::on_logout_1_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}

void MainWindow::on_gestio_space_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);

}

/*//////////////////////////////////////////////////////////////////////////CONTRAT*/
void MainWindow::on_lineEditFilter_textChanged(const QString &text)
{

    QSqlQueryModel *filteredModel = new QSqlQueryModel();

    filteredModel->setQuery(QString("SELECT * FROM REGLE WHERE ID_REGLE LIKE '%%1%'").arg(text));

    filteredModel->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    filteredModel->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
    filteredModel->setHeaderData(2, Qt::Horizontal, QObject::tr("time debut"));
    filteredModel->setHeaderData(3, Qt::Horizontal, QObject::tr("time fin"));



    ui->tableView_c->setModel(filteredModel);
}
void MainWindow::on_pushButton_c_clicked()
{
    int id=ui->id->text().toInt();
    QString type = ui->comboBox->currentText();
    QString desc=ui->desc->text();
    QString con=ui->con->text();

    QString idString = QString::number(id);

    REGLE e(id,type,desc,con);

    bool test=e.ajouter();




    if(test){

        ui->tableView_c->setModel(etmp.afficher());

        QMessageBox::information(nullptr, QObject::tr("CONGRATULATION"),QObject::tr("addition made \n""click cancel to exit"),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("ID EXISTE"),QObject::tr("addition not made\n""click cancel to exit"),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_2_clicked()//suprimer
{
    int id=ui->idmod_2->text().toInt();
    REGLE r;
    bool test=etmp.supprimer(id);
    if(test){

        ui->tableView_c->setModel(etmp.afficher());
        QMessageBox::information(nullptr,QObject::tr("CONGRATULATION"),QObject::tr("deletion done \n""click cancel to exit,"),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("ID NOT FOUND"),QObject::tr("ID NOT FOUND,\n""click cancel to exit"),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_3_clicked()//modifier
{
    int id=ui->idmod->text().toInt();

    QString d=ui->nvdesc->text();
    QString co=ui->nvcon->text();
    QString t=ui->comboBox_2->currentText();

    REGLE e;
    e.setid(id);

    e.setdesc(d);
    e.setcon(co);
    e.settype(t);


    bool test=e.modifier(id, t, d, co);

    if(test){

        ui->tableView_c->setModel(etmp.afficher());

        QMessageBox::information(nullptr, QObject::tr("CONGRATULATION"),QObject::tr("modification made \n""click cancel to exit"),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("ID NOT FOUND"),QObject::tr("modification non effectuee\n""click cancel to exit"),QMessageBox::Cancel);

}


void MainWindow::on_pushButton_4_clicked()
{
    ui->tableView_c->setModel(etmp.sortid());
}




void MainWindow::on_pushButton_6_clicked()
{
     ui->tableView_c->setModel(etmp.sorttype());
}






void MainWindow::on_pushButton_7_clicked()
{
    QPdfWriter pdf("C:/Users/houss/Downloads/houssem (1)/cruuuuuuuuuuuuud/liste.pdf");

   QPainter painter(&pdf);
   int i = 4100;


          QColor dateColor(0x4a5bcf);
          painter.setPen(dateColor);

          painter.setFont(QFont("Montserrat SemiBold", 11));
          QDate cd = QDate::currentDate();
          painter.drawText(7700,250,cd.toString("Ariana, El Ghazela"));
          painter.drawText(8100,500,cd.toString("dd/MM/yyyy"));

          QColor titleColor(0x341763);
          painter.setPen(titleColor);
          painter.setFont(QFont("Montserrat SemiBold", 20));

          painter.drawText(2900,2400,"CONTRAT");

          painter.setPen(Qt::black);
          painter.setFont(QFont("Time New Roman", 15));
          painter.drawRect(100,100,9400,2500);
          painter.drawRect(100,3300,9400,500);

          painter.setFont(QFont("Montserrat SemiBold", 8));

          painter.drawText(200,3600,"ID");
          painter.drawText(700,3600,"TYPE");
          painter.drawText(2000,3600,"TIME DEBUT");
          painter.drawText(4700,3600,"TIME FIN");

          painter.setFont(QFont("Montserrat", 9));


          painter.drawRect(100,3300,9400,9000);

          QSqlQuery query;
          query.prepare("select * from REGLE");
          query.exec();
          int y=4300;
          while (query.next())
          {
              painter.drawLine(100,y,9490,y);
              y+=500;
              painter.drawText(200,i,query.value(0).toString());
              painter.drawText(500,i,query.value(1).toString());
              painter.drawText(2000,i,query.value(2).toString());
              painter.drawText(4700,i,query.value(3).toString());
              painter.drawText(7500,i,query.value(4).toString());
              painter.drawText(8500,i,query.value(5).toString());


             i = i + 500;
          }

          int reponse = QMessageBox::question(this, "Génerer PDF", "PDF Enregistré.\nVous voulez l'affichez ?", QMessageBox::Yes |  QMessageBox::No);
          if (reponse == QMessageBox::Yes)
          {
              QDesktopServices::openUrl( QUrl ::fromLocalFile("C:/Users/houss/Downloads/houssem (1)/cruuuuuuuuuuuuud/liste.pdf"));
              painter.end();
          }
          else
          {
              painter.end();
          }

}

void MainWindow::setupChart() {
    QPieSeries *series = new QPieSeries();
    int adhesionCount = etmp.countadhesion("adhesion");
    int locationCount = etmp.countlocation ("location");
    int serviceCount  = etmp.countservice ("service");

    if (adhesionCount != -1)
        series->append("adhésion", adhesionCount);
    if (locationCount != -1)
        series->append("location", locationCount);
    if (serviceCount != -1)
        series->append("service", serviceCount);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("TYPE_CONTRAT Statistics");

    QChart::AnimationOptions anim = QChart::AllAnimations;
    chart->setAnimationOptions(anim);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(ui->frameChart);
    chartView->resize(ui->frameChart->size());
    chart->legend()->setAlignment(Qt::AlignRight);
    chart->legend()->setFont(QFont("Arial", 8));

    for (QPieSlice *slice : series->slices()) {
        connect(slice, &QPieSlice::clicked, this, &MainWindow::handleSliceClick);
    }
}


void MainWindow::handleSliceClick() {
    QPieSlice *clickedSlice = qobject_cast<QPieSlice*>(sender());

    if (clickedSlice) {
           QPieSeries *series = clickedSlice->series();


           for (QPieSlice *slice : series->slices()) {
               if (slice != clickedSlice) {
                   slice->setExploded(false);
                   slice->setLabelVisible(false);
               }
           }


           clickedSlice->setExploded(!clickedSlice->isExploded());

           clickedSlice->setLabelVisible(true);

       }
}





void MainWindow::browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );



}


void MainWindow::on_exitBtn_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}

void MainWindow::on_gestio_contrat_clicked()
{
    ui->stackedWidget->setCurrentIndex(14);

}
void MainWindow::on_arduino_clicked()
{
    // Create an instance of arduinotemp dialog
        arduinotemp *arduinoTempDialog = new arduinotemp(this);

        // Hide the current MainWindow
        this->hide();

        // Show the arduinotemp dialog
        arduinoTempDialog->show();
}














/*////////////////////////////arduino ref*/
//void MainWindow::on_tableView2_selectionChanged(const QItemSelection &selected, const QItemSelection &/*deselected*/)
/*{
    const QModelIndexList indexes = selected.indexes();
    if (indexes.size() > 0)
    {
        int personnelId = indexes.at(0).data().toInt();
        displaySelectedMemberImage(personnelId);
    }
}*/



void MainWindow::onCardScanned(const QString &dataFromArduino)
{
    QString cardID = parseCardID(dataFromArduino);
    if (cardID.isEmpty())
    {
        return;
    }
    QSqlDatabase::database().transaction();
    QSqlQuery checkCardQuery;
    checkCardQuery.prepare("SELECT ID FROM personnel WHERE CARD_ID = :cardID AND ID !=:personnelId ");
    checkCardQuery.bindValue(":cardID", cardID);
    checkCardQuery.bindValue(":personnelId", selectedPersonnelId);
    if (!checkCardQuery.exec())
    {
        QSqlDatabase::database().rollback();
        QMessageBox::critical(this, "Database Error", "Could not query the database: " + checkCardQuery.lastError().text());
        return;
    }


    if (checkCardQuery.next())
    {
        QSqlDatabase::database().rollback();
        QMessageBox::warning(this, "Card Error", "This card is already assigned to another personnel.");
        return;
    }
    QSqlQuery updateMemberQuery;
    updateMemberQuery.prepare("UPDATE personnel SET CARD_ID = :cardID WHERE ID = :personnelId");
    updateMemberQuery.bindValue(":cardID", cardID);
    updateMemberQuery.bindValue(":personnelId", selectedPersonnelId);
    if (!updateMemberQuery.exec())
    {
        QSqlDatabase::database().rollback();
        QMessageBox::critical(this, "Database Error", "Could not save the card to the database: " + updateMemberQuery.lastError().text());
        return;
    }


    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM CARD_LOGS WHERE CARD_ID = :cardID");
    checkQuery.bindValue(":cardID", cardID);
    if (!checkQuery.exec())
    {
        QSqlDatabase::database().rollback();
        QMessageBox::critical(this, "Database Error", "Error checking for existing card logs: " + checkQuery.lastError().text());
        return;
    }
    int count = 0;
    if (checkQuery.next())
    {
        count = checkQuery.value(0).toInt();
    }
    QSqlQuery query;
    if (count == 0)
    {
        query.prepare("INSERT INTO CARD_LOGS (CARD_ID, LAST_ACCESS, ACCESS_TIME, ACCESS_STATUS) " "VALUES (:cardID, CURRENT_TIMESTAMP, CURRENT_TIMESTAMP, 'Access granted.')");
    } else {
               query.prepare("UPDATE CARD_LOGS SET LAST_ACCESS = CURRENT_TIMESTAMP, " "ACCESS_TIME = CURRENT_TIMESTAMP, ACCESS_STATUS = 'Access granted.' " "WHERE CARD_ID = :cardID");
           }
    query.bindValue(":cardID", cardID);
     if (!query.exec())
     {
           QSqlDatabase::database().rollback();
           QMessageBox::critical(this, "Database Error", "Could not update the CARD_LOGS table: " + query.lastError().text());
           return;
     }
     QSqlDatabase::database().commit();
     QMessageBox::information(this, "Success", "Access logged for card ID: " + cardID);
     bool cardExists = checkIfCardExists(cardID);
     updateStatusLabelColor(cardExists,cardID);
 }
QString MainWindow::parseCardID(const QString &dataFromArduino)
{
    QRegularExpression regex("Card ID: (\\w+)");
    QRegularExpressionMatch match = regex.match(dataFromArduino);
    if (match.hasMatch())
    {
        return match.captured(1);
    }
    return QString();
}



void MainWindow::on_refreche_2_clicked()
{
    cardLogsModel = new QSqlTableModel(this);
    cardLogsModel->setTable("CARD_LOGS");
    cardLogsModel->select();
    ui->tableView_3->setModel(cardLogsModel);
    if (cardLogsModel->rowCount() == 0)
    {
        qDebug() << "The model is empty or not properly set up.";
        qDebug() << "Error:" << cardLogsModel->lastError().text();
    }
    cardLogsModel->select();
    ui->stackedWidget->setCurrentIndex(15);
}

void MainWindow::updateStatusLabelColor(bool cardExists, const QString& cardID)
{
    if (cardExists)
    {
        QByteArray data = "1";
        arduino->write_to_arduino(data);
        ui->accessStatusLabel2VERT->setStyleSheet("QLabel { background-color: green; }");
        ui->accessStatusLabelRED->setStyleSheet("");

        // Fetch personnel information from the database
        QSqlQuery query;
        query.prepare("SELECT ID, NAME, FUNCTION FROM personnel WHERE CARD_ID = :cardID");
        query.bindValue(":cardID", cardID);
        if (query.exec() && query.next())
        {
            int personnelId = query.value(0).toInt();
            QString name = query.value(1).toString();
            QString function = query.value(2).toString();

            // Construct message
            QString message = "Personnel ID: " + QString::number(personnelId) + "\n";
            message += "Name: " + name + "\n";
            message += "Function: " + function;

            // Show message box with personnel information
            QMessageBox::information(this, "Personnel Information", message);
        }
        else
        {
            ui->labelMessage->setText("Failed to fetch personnel information.");
        }
    }
    else
    {
        QByteArray data = "0";
        arduino->write_to_arduino(data);

        ui->accessStatusLabelRED->setStyleSheet("QLabel { background-color: red; }");
        ui->accessStatusLabel2VERT->setStyleSheet("");

        ui->labelMessage->setText(""); // Clear the message if card does not exist
    }
}


bool MainWindow::checkIfCardExists(const QString& cardID)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM PERSONNEL WHERE CARD_ID = :cardID");
    query.bindValue(":cardID", cardID);
    if (query.exec() && query.next())
    {
        int count = query.value(0).toInt();
        return count > 0;
    } else {
               qDebug() << "Error checking if card exists in MEMBERS table:" << query.lastError().text();
               return false;
           }
}


/*void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(14);
}*/

void MainWindow::on_refreche_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}



void MainWindow::activateBuzzer(int numTimes) {
    // Turn on the buzzer
    qDebug() << "Buzzer on" << numTimes << "time(s)";

    // Start the timer with a duration of 1 second (1000 milliseconds) for each activation
    buzzerTimer->start(numTimes * 200);

    // If you want to activate the buzzer only once, you can stop the timer after the first activation
    if (numTimes == 1) {
        connect(buzzerTimer, &QTimer::timeout, [=]() {
            buzzerTimer->stop();
        });
    } else if (numTimes == 2) {
            // Connect the timeout signal of the timer to a slot that turns off the buzzer after the second activation
            connect(buzzerTimer, &QTimer::timeout, [=]() {
                // Turn off the buzzer
                qDebug() << "Buzzer off";
                // Stop the timer
                buzzerTimer->stop();
            });
        }
    }



void MainWindow::on_addMemberButton_2_clicked()
{
    QString searchQuery = ui->searchLineEdit_2->text().trimmed();
    if (!searchQuery.isEmpty())
    {
        QMessageBox::warning(this, "No personnel Selected", "Please search and find a member to add a card to.");
    } else {
        ui->labelMessage_2->setText("No personnel Selected "" Please search and find a member to add a card to..");
           }
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);

}

QString MainWindow::fetchUserRoleFromDatabase(const QString& username) {
    // Remplacer cette logique par la récupération du rôle de l'utilisateur depuis la base de données
    // Vous pouvez utiliser une requête SQL pour cela
    // Par exemple :
    // QSqlQuery query;
    // query.prepare("SELECT role FROM users WHERE username = :username AND password = :password");
    // query.bindValue(":username", username);
    // query.bindValue(":password", password);
    // if (query.exec() && query.next()) {
    //     return query.value(0).toString();
    // } else {
    //     return ""; // Rôle non trouvé
    // }
    // Ici, je simule le rôle de l'utilisateur en fonction du nom d'utilisateur
    if (username == "ADMIN") {
        return "Admin";
    } else {
        return "Employe";
    }
}
void MainWindow::on_employeeManagementButton_clicked() {
    // Récupérer le nom d'utilisateur et le mot de passe de l'utilisateur
    QString username = ui->Username->text();

    // Récupérer le rôle de l'utilisateur à partir de la base de données
    QString userRole = fetchUserRoleFromDatabase(username);

    // Vérifier le rôle de l'utilisateur
    if (userRole == "Employe") {
        // Afficher un message d'interdiction
        QMessageBox::warning(this, "Accès refusé", "Vous n'avez pas les autorisations nécessaires pour accéder à cette fonctionnalité.");
    } else {
        // Autoriser l'accès à la gestion des employés pour les autres rôles
        // Insérez ici le code pour afficher la fenêtre de gestion des employés
    }
}
