// dashboard.h
#ifndef DASHBOARDPAGE_H
#define DASHBOARDPAGE_H

#include <QWidget>

namespace Ui {
class dashboardPage;
}

class dashboardPage : public QWidget
{
    Q_OBJECT
public:
    explicit dashboardPage(QWidget *parent = nullptr);
    void initialize();

signals:
    void logoutRequested();

private:
    Ui::dashboardPage *ui;
};

#endif // DASHBOARDPAGE_H
