// THESE INCLUDES MUST BE IN THIS EXACT ORDER
#include "LoginPage.h"
#include "ui_LoginPage.h"  // Generated header MUST come after LoginPage.h
#include <QMessageBox>

LoginPage::LoginPage(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::LoginPage)  // Allocation now happens after ui_LoginPage.h is included
{
    ui->setupUi(this);
}

LoginPage::~LoginPage()
{
    delete ui;
}

// ... rest of your implementation ...
