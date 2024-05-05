    #ifndef MAINWINDOW_H
    #define MAINWINDOW_H
#include "personnel.h"
    #include <QMainWindow>
    #include <QStackedWidget>
    #include <QPushButton>
    #include "client.h"
#include <QSqlTableModel>
#include <QComboBox>
#include <QWidgetList>
#include "equipement.h"

#include <QSqlTableModel>
#include <QMainWindow>
#include <QDir>
#include <QImage>
#include <QCoreApplication>
#include <QStringListModel>
#include <QItemSelectionModel>
#include "espace.h"
#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "sms.h"
#include "regle.h"
#include "arduino.h"


    QT_BEGIN_NAMESPACE
    namespace Ui { class MainWindow; }
    QT_END_NAMESPACE

    class MainWindow : public QMainWindow
    {
        Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();
        void setupChart();
        QString parseCardID(const QString &dataFromArduino);






    private slots:
        void onLoginButtonClicked();
        void on_gestio_CLientB_clicked();
        void on_Back_gestion_clicked();
        void on_AjoutBtton_clicked();

        void on_BackAjout_clicked();


        void on_BackModifir_clicked();

        void on_ModifierButton_clicked();



        void on_BUTTONAJOUTENRE_clicked();

        void on_Supprimer_Button_clicked();



        void on_BackModifir_15_clicked();
        void on_modifier_Button_clicked();


int generateRandomInt(int min, int max);




        // Fonction pour exporter la liste d'équipements vers un fichier PDF

                // Fonction utilitaire pour dessiner le contenu du modèle sur une page PDF



                void on_pdf_cl_clicked();
                void on_stat_cl_clicked();
                 void onHeaderClicked(int logicalIndex);
                 void clicked_rech();
                 void on_mailing_clicked();
                 void on_historyButton_clicked();
void recordHistory(const QString &action, int clientId);

// employee****************************
void on_gestio_employee();
void on_confirm_clicked();
void on_cancel_clicked();
void on_pushButton_14_p_2_clicked();
void on_pushButton_17_clicked();
void on_pushButton_10_clicked();
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
void on_Back_gestion_clicked2();
//*********************************

// eq ****************
void onLoginButtonClicked_eq();
void on_Back_gestion_clicked_eq();
void on_AjoutBttoneq_clicked_eq();

void on_BackAjout_clicked_eq();


void on_BackModifir_clicked_eq();

void on_ModifierButtoneq_clicked();



void on_BUTTONAJOUTENRE_clicked_eq();

void on_Supprimer_Button_clicked_eq();

void on_pushButton_216_clicked_eq();

void on_BackModifir_15_clicked_eq();
void on_modifier_Button_clicked_eq();

void on_pushButton_clicked_eq();
void on_pushButton_20_clicked_eq();
void on_rechercherButton_clicked_eq();
// Fonction pour exporter la liste d'équipements vers un fichier PDF
void exportToPDF_eq(const QString& filePath, QSqlQueryModel* model);

// Fonction utilitaire pour dessiner le contenu du modèle sur une page PDF
void drawModel_eq(QPainter& painter, QSqlQueryModel* model);
void on_exportToPdfButton_clicked_eq();
void on_loginButton_clicked_eq();
void on_forgotPasswordButton_clicked_eq();
void on_StatsButton_clicked_eq();
void on_stat_cl_clicked_eq();
void on_gestio_eqB_clicked();
void on_pushButton_14_p_clicked();

//espace*********************************************/////////////////////////////
void on_ajouter_clicked();
void on_supprimer_clicked();
void on_modifier_clicked();
void on_affichage_clicked(const QModelIndex &index);
void on_affichage_doubleClicked(const QModelIndex &index);
void on_pdf_clicked();
void on_qrcode_clicked();
void on_search_clicked();
void on_filtrer_clicked();
void on_rech_textChanged(const QString &arg1);
void on_stat_1_clicked();
void on_showAvailability_1_clicked();
void showReferenceOnHover(const QDate &date);// Declare the slot for showing availability










// *******************
void on_logout_1_clicked();

void on_gestio_space_clicked();


// Contrats
void on_pushButton_c_clicked();
void on_pushButton_2_clicked();
void on_pushButton_3_clicked();
void on_pushButton_4_clicked();
void on_pushButton_6_clicked();
void on_pushButton_7_clicked();
void on_lineEditFilter_textChanged(const QString &text);
void handleSliceClick();

void browse();

void on_exitBtn_3_clicked();

void on_gestio_contrat_clicked();

void on_arduino_clicked();
/*arduino ref
 */
void updateStatusLabelColor(bool cardExists, const QString& cardID);
void on_refreche_2_clicked();
//void on_pushButton_2_clicked();
void on_refreche_3_clicked();
void activateBuzzer(int numTimes);
void on_addMemberButton_clicked();
/*

*/  void onCardScanned(const QString &dataFromArduino) ;
void on_addMemberButton_2_clicked();

void on_pushButton_9_clicked();

    private:

        Ui::MainWindow *ui;
        Client Ctemp;
        QSqlTableModel *clientModel;
        // employee
        QSqlTableModel *personnelsModel; // This is the model for your QTableView
        QString selectedPersonnelId;
        QString imagePath;
        QString memberImagePath;
        bool isCreatingPerso;
        Personnel ptemp;
        // ***********

        // eq
        Equipement EQtemp;
        QString critereTri;
        //espace
        espace E1;
        QByteArray data;
        QString ref;
        QSqlDatabase db;
        SMS sms;// Declare QSqlDatabase object for database connection
        //********
        //contrat
        REGLE etmp;
        QStringList files;
        //arduino ref

        QSqlTableModel *cardLogsModel;
        Arduino *arduino;
        bool checkIfCardExists(const QString& cardID);
        QTimer *buzzerTimer;



    };
    #endif // MAINWINDOW_H
