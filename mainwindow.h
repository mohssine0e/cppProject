#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QStackedWidget>

namespace Ui {
class MainWindow;
}

class LoginPage;
class DashboardPage;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    LoginPage *loginPage;
    DashboardPage *dashboardPage;
};
#endif // MAINWINDOW_H
