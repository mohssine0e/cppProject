// mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginPage.h"
#include "dashboardPage.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialize pages
    loginPage = new LoginPage(this);
    dashboardPage = new DashboardPage(this);

    // Add pages to stacked widget
    ui->stackedWidget->addWidget(loginPage);
    ui->stackedWidget->addWidget(dashboardPage);

    // Start with login page
    ui->stackedWidget->setCurrentWidget(loginPage);

    // Connect signals
    connect(loginPage, &LoginPage::loginSuccess, this, [this]() {
        ui->stackedWidget->setCurrentWidget(dashboardPage);
    });

    connect(dashboardPage, &DashboardPage::logoutRequested, this, [this]() {
        ui->stackedWidget->setCurrentWidget(loginPage);
    });
}

MainWindow::~MainWindow() {
    delete ui;
}
