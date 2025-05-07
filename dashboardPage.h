// dashboardpage.h
#include <QWidget>
#include "ui_dashboardPage.h"


namespace Ui {
class DashboardPage;
}
class DashboardPage : public QWidget {
    Q_OBJECT

public:
    explicit DashboardPage(QWidget *parent = nullptr);
    ~DashboardPage();

signals:
    void logoutRequested();

private slots:
    void on_logoutButton_clicked();

private:
    Ui::DashboardPage *ui;
};
