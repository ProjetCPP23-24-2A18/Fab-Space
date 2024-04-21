#ifndef PERSONNELLIST_H
#define PERSONNELLIST_H
#include <QSqlTableModel>
#include <QMainWindow>
#include <QDir>
#include <QImage>
#include <QCoreApplication>
#include <QStringListModel>
#include <QItemSelectionModel>


QT_BEGIN_NAMESPACE
namespace Ui { class personnellist; }
QT_END_NAMESPACE

class personnellist : public QMainWindow
{
    Q_OBJECT

public:
    personnellist(QWidget *parent = nullptr);
    ~personnellist();

private slots:




    void on_confirm_clicked();

    void on_cancel_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_clicked();

    void on_pushButton_10_clicked();

    void on_Back_gestion_clicked();

    void on_AjoutButton_clicked();

    void on_searchButton_clicked();

    void on_pdfExcelButton_clicked();

    void exportToPDF();

    void exportToExcel();

    void on_printButton_clicked();

    void on_filterButton_clicked();



    void on_generateQRButton_clicked();

    void on_uploadImageButton_clicked();
    void displaySelectedMemberImage(int memberId);
    void on_tableView_selectionChanged(const QItemSelection &selected, const QItemSelection &deselected);

    void on_statAge_clicked();
    void clearChart();
    void clearChartmember();
    void on_stat_clicked();

private:
    Ui::personnellist *ui;
    QSqlTableModel *personnelsModel; // This is the model for your QTableView
    QString selectedPersonnelId;
    QString imagePath;
    QString memberImagePath;
    bool isCreatingPerso;

};
#endif // PERSONNELLIST_H
