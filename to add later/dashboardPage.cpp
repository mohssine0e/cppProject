#include "dashboardPage.h"
#include "ui_mainwindow.h"

dashboardPage::dashboardPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dashboardPage)
{
    ui->setupUi(this);
    setWindowTitle("Application Dashboard");
    // Add your dashboard initialization here
}

dashboardPage::~dashboardPage()
{
    delete ui;
}
