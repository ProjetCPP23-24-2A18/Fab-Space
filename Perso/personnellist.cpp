#include "ui_personnellist.h"
#include "personnellist.h"
#include "connection.h"
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

using namespace qrcodegen;


personnellist::personnellist(QWidget *parent)
    : QMainWindow(parent)
    , ui (new Ui::personnellist)
{
    ui->setupUi(this);
    personnelsModel = new QSqlTableModel(this);
        personnelsModel->setTable("PERSONNEL");
        personnelsModel->select();
        ui->tableView->setModel(personnelsModel);
        ui->tableView->setItemDelegateForColumn(11, new ImageDelegate(this));  // Assuming column 11 has
            ui->tableView->resizeColumnsToContents();

        connect(ui->confirm, &QPushButton::clicked, this, &personnellist::on_confirm_clicked);

    connect(ui->cancel, &QPushButton::clicked, this, &personnellist::on_cancel_clicked);

    connect(ui->pushButton_14, &QPushButton::clicked, this, &personnellist::on_pushButton_14_clicked);

    connect(ui->pushButton_17, &QPushButton::clicked, this, &personnellist::on_pushButton_17_clicked);

    connect(ui->printButton, &QPushButton::clicked, this, &personnellist::on_printButton_clicked);

    connect(ui->filterButton, &QPushButton::clicked, this, &personnellist::on_filterButton_clicked);

    connect(ui->uploadImageButton, &QPushButton::clicked, this, &personnellist::on_uploadImageButton_clicked);
}

personnellist::~personnellist()
{
    delete ui;

}

void personnellist::on_pushButton_clicked()
{
    isCreatingPerso = true;
    ui->stackedWidget->setCurrentIndex(2);
}






void personnellist::on_confirm_clicked()
{
    // Collect data from UI
    QString id = ui->lineEdit_id->text();
    QString name = ui->lineEdit_name->text();
    QString lastName = ui->lineEdit_lastName->text();
    QDate dateOfBirth = ui->dateEdit_dateOfBirth->date();
    QDate dateEmb = ui->dateEdit_dateEmb->date();
    QString address = ui->lineEdit_address->text();
    QString phone = ui->lineEdit_phone->text();
    QString email = ui->lineEdit_email->text();
    QString function = ui->lineEdit_function->text();
    QString UserName = ui->lineEdit_UserName->text();
    QString password = ui->lineEdit_password->text();
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
            ui->lineEdit_id->clear();
            ui->lineEdit_name->clear();
            ui->lineEdit_lastName->clear();
            ui->dateEdit_dateOfBirth->setDate(QDate(2000, 1, 1)); // Set the date to January 1, 2000
            ui->dateEdit_dateEmb->setDate(QDate(2000, 1, 1)); // Set the date to January 1, 2000
            ui->lineEdit_address->clear();
            ui->lineEdit_phone->clear();
            ui->lineEdit_email->clear();
            ui->lineEdit_function->clear();
            ui->lineEdit_UserName->clear();
            ui->lineEdit_password->clear();
            ui->imageLabel->clear();
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
            ui->lineEdit_id->clear();
            ui->lineEdit_name->clear();
            ui->lineEdit_lastName->clear();
            ui->dateEdit_dateOfBirth->setDate(QDate(2000, 1, 1)); // Set the date to January 1, 2000
            ui->dateEdit_dateEmb->setDate(QDate(2000, 1, 1)); // Set the date to January 1, 2000
            ui->lineEdit_address->clear();
            ui->lineEdit_phone->clear();
            ui->lineEdit_email->clear();
            ui->lineEdit_function->clear();
            ui->lineEdit_UserName->clear();
            ui->lineEdit_password->clear();
            ui->imageLabel->clear();
            memberImagePath.clear();

            ui->stackedWidget->setCurrentIndex(2); // Switch back to the member list page


        }
    }
}

void personnellist::on_cancel_clicked()
{
    // Clear all the input fields
    ui->lineEdit_id->clear();
    ui->lineEdit_name->clear();
    ui->lineEdit_lastName->clear();
    ui->dateEdit_dateOfBirth->setDate(QDate(2000, 1, 1)); // Set the date to January 1, 2000
    ui->dateEdit_dateEmb->setDate(QDate(2000, 1, 1)); // Set the date to January 1, 2000
    ui->lineEdit_address->clear();
    ui->lineEdit_phone->clear();
    ui->lineEdit_email->clear();
    ui->lineEdit_function->clear();
    ui->lineEdit_UserName->clear();
    ui->lineEdit_password->clear();
    ui->imageLabel->clear();
    memberImagePath.clear();
        ui->stackedWidget->setCurrentIndex(2);
        ui->lineEdit_id->setReadOnly(false);
        // Add any other fields you might have in your form
}

void personnellist::on_pushButton_14_clicked()
{
    isCreatingPerso = false;
    QModelIndexList selectedRows = ui->tableView->selectionModel()->selectedRows();
        if (!selectedRows.isEmpty()) {
            int row = selectedRows.first().row();
            selectedPersonnelId = personnelsModel->data(personnelsModel->index(row, 0)).toString(); // Assuming ID is in the first column

            // Populate the form with the selected personnels details
            ui->lineEdit_id->setText(selectedPersonnelId);
            ui->lineEdit_name->setText(personnelsModel->data(personnelsModel->index(row, 1)).toString());
            ui->lineEdit_lastName->setText(personnelsModel->data(personnelsModel->index(row, 2)).toString());
            ui->dateEdit_dateOfBirth->setDate(personnelsModel->data(personnelsModel->index(row, 3)).toDate());
            ui->dateEdit_dateEmb->setDate(personnelsModel->data(personnelsModel->index(row, 4)).toDate());
            ui->lineEdit_address->setText(personnelsModel->data(personnelsModel->index(row, 5)).toString());
            ui->lineEdit_phone->setText(personnelsModel->data(personnelsModel->index(row, 6)).toString());
            ui->lineEdit_email->setText(personnelsModel->data(personnelsModel->index(row, 7)).toString());
            ui->lineEdit_function->setText(personnelsModel->data(personnelsModel->index(row, 8)).toString());
            ui->lineEdit_UserName->setText(personnelsModel->data(personnelsModel->index(row, 9)).toString());
            ui->lineEdit_password->setText(personnelsModel->data(personnelsModel->index(row, 10)).toString());

            QString imagePath = personnelsModel->data(personnelsModel->index(row, 11)).toString(); // Assuming 11 is the image path column
                    QPixmap image(imagePath);
                    if (!image.isNull()) {
                        ui->imageLabel->setPixmap(image.scaled(ui->imageLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
                    } else {
                        qDebug() << "Image at path" << imagePath << "could not be loaded.";
                        ui->imageLabel->setText("No image available");
                    }

                    ui->lineEdit_id->setReadOnly(true);
                    ui->stackedWidget->setCurrentIndex(2);
                } else {

        QMessageBox::information(this, "No Selection", "Please select a member to modify.");
                }
}

void personnellist::on_pushButton_17_clicked()
{
    QModelIndexList selectedRows = ui->tableView->selectionModel()->selectedRows();
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

void personnellist::on_pushButton_20_clicked()
{
    personnelsModel = new QSqlTableModel(this);
    personnelsModel->setTable("PERSONNEL");
    personnelsModel->select();

    // Assuming you have a QTableView with objectName set to "tableView"
    ui->tableView->setModel(personnelsModel);
    ui->tableView->resizeColumnsToContents(); // Optional, for better column sizing
    // Check if the model is empty
    if (personnelsModel->rowCount() == 0) {
        qDebug() << "The model is empty or not properly set up.";
        qDebug() << "Error:" << personnelsModel->lastError().text();
    }

    personnelsModel->select();
    ui->stackedWidget->setCurrentIndex(2); // Switch to the page with the member list
}



void personnellist::on_pushButton_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void personnellist::on_Back_gestion_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void personnellist::on_AjoutButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void personnellist::on_searchButton_clicked()
{
    personnelsModel->setTable("PERSONNEL");
        personnelsModel->select();

        QString searchQuery = ui->searchLineEdit->text().toLower(); // Convert search query to lowercase

           QString selectQuery = "LOWER(NAME) LIKE '%" + searchQuery + "%' OR LOWER(LAST_NAME) LIKE '%" + searchQuery + "%' OR ID LIKE '%" + searchQuery + "%'";
           personnelsModel->setFilter(selectQuery);
        personnelsModel->select();

        ui->searchLineEdit->clear(); // Clear search line
        ui->tableView->resizeColumnsToContents();
}



void personnellist::on_pdfExcelButton_clicked()
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

void personnellist::exportToPDF() {
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
    double scaleX = printer.pageRect().width() / double(ui->tableView->width());
    double scaleY = printer.pageRect().height() / double(ui->tableView->height());
    double scale = qMin(scaleX, scaleY);
    painter.scale(scale, scale);

    ui->tableView->render(&painter);
}
void personnellist::exportToExcel() {
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


void personnellist::on_printButton_clicked()
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
        QSize tableViewSize = ui->tableView->sizeHint();

        // Scale the content to fit within the print area
        double xscale = printArea.width() / double(tableViewSize.width());
        double yscale = printArea.height() / double(tableViewSize.height());
        double scale = qMin(xscale, yscale);

        // Translate the painter to start drawing from the top left of the print area
        painter.translate(printArea.topLeft());

        // Apply the scale
        painter.scale(scale, scale);

        // Render the table view onto the painter
        ui->tableView->render(&painter);
    }
}

void personnellist::on_filterButton_clicked()
{
    int index = ui->sortComboBox->currentIndex();

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
    ui->sortComboBox->setCurrentIndex(0);
    personnelsModel->select(); // Apply the sort/filter
}



void personnellist::on_generateQRButton_clicked()
{
    int tabeq=ui->tableView->currentIndex().row();
       QVariant idd=ui->tableView->model()->data(ui->tableView->model()->index(tabeq,0));
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
      ui->qrcode->setPixmap(QPixmap::fromImage(im));
}


void personnellist::on_uploadImageButton_clicked() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Choose Image"), "", tr("Images (*.png *.jpg *.jpeg *.bmp *.gif)"));
        if (!fileName.isEmpty()) {
            QPixmap pixmap(fileName);
            ui->imageLabel->setPixmap(pixmap.scaled(ui->imageLabel->size(), Qt::KeepAspectRatio));
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


void personnellist::displaySelectedMemberImage(int Id) {

    QSqlQuery query;
    query.prepare("SELECT IMAGE_PATH FROM PERSONNEL WHERE ID = ?");
    query.addBindValue(Id);
    if(query.exec() && query.next()) {
        QString imagePath = query.value(0).toString();
        QPixmap image(imagePath);
        ui->imageLabel->setPixmap(image.scaled(ui->imageLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
}

// Call this method when the member selection changes, e.g., when a row in your table is clicked
void personnellist::on_tableView_selectionChanged(const QItemSelection &selected, const QItemSelection &/*deselected*/)  {
    // Assuming you have only one selection at a time
    const QModelIndexList indexes = selected.indexes();
    if (indexes.size() > 0) {
        int memberId = indexes.at(0).data().toInt();
        displaySelectedMemberImage(memberId);
    }
}


void personnellist::on_statAge_clicked()
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
    ui->listView->setModel(ageStatsModel);

    // Optionally, you may want to resize the columns to fit the content
    ui->listView->setResizeMode(QListView::Adjust);

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
        QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(ui->placeholderWidget->layout());
        if (!layout) {
            layout = new QVBoxLayout();
            ui->placeholderWidget->setLayout(layout);

        }
        layout->addWidget(chartView);

        // Set the string list to the model and then set the model to the list view
        ui->listView->setModel(ageStatsModel);



}

void personnellist::clearChart()
{
    QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(ui->chartFrame->layout());
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


void personnellist::clearChartmember()
{
    // Assuming 'placeholderWidget' is a QWidget or QFrame in your UI where the stats are displayed
    if (ui->placeholderWidget->layout() != nullptr) {
        // Remove and delete all widgets from the layout
        QLayoutItem *child;
        while ((child = ui->placeholderWidget->layout()->takeAt(0)) != nullptr) {
            delete child->widget(); // This will delete the chart view
            delete child;           // This will delete the layout item
        }
    }

    // Optionally, remove the layout itself
    delete ui->placeholderWidget->layout();
    ui->placeholderWidget->setLayout(new QVBoxLayout()); // Set a new clean layout
}

void personnellist::on_stat_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}
