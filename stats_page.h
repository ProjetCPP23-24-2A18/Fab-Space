#ifndef STATS_PAGE_H
#define STATS_PAGE_H

#include <QWidget>

namespace Ui {
class StatsPage;
}

class StatsPage : public QWidget
{
    Q_OBJECT

public:
    explicit StatsPage(QWidget *parent = nullptr);
    ~StatsPage();

private:
    Ui::StatsPage *ui;

    // Méthode pour afficher les statistiques sur les équipements
    void displayEquipmentStatistics();
};

#endif // STATS_PAGE_H
