// dashboardpage.cpp
#include "dashboardPage.h"

DashboardPage::DashboardPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DashboardPage)
{
    ui->setupUi(this);


    // connect(this, &DashboardPage::logoutRequested, this, [this]() {
    //     const QString errorStyle = "color: red; font-size: 13px;";
    // }

}


DashboardPage::~DashboardPage() {
    delete ui;
}

void DashboardPage::on_logoutButton_clicked() {
    emit logoutRequested();
}
