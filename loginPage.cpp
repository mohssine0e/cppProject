// loginpage.cpp
#include "loginPage.h"
#include "registerDialog.h"
#include "ui_loginPage.h"  // THIS IS CRUCIAL - contains full class definition
#include <QMessageBox>

LoginPage::LoginPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginPage)
{
    ui->setupUi(this);

    // Connect the validation error handler
    connect(this, &LoginPage::loginFailed, this, [this](ValidationError error, QString message) {
        const QString errorStyle = "color: red; font-size: 13px;";

        ui->errEmail->clear();
        ui->errPss->clear();

        switch (error) {

        case ValidationError::Email:

            ui->errEmail->setStyleSheet(errorStyle);
            ui->errEmail->setText(message);
            break;
            return;

        case ValidationError::Password:

            ui->errPss->setStyleSheet(errorStyle);
            ui->errPss->setText(message);
            break;
            return;



        default:
            QMessageBox::warning(this, "Incomplete Form", "something else");
            return;

        }
    });
}

LoginPage::~LoginPage() {
    delete ui;
}

void LoginPage::clearForm(){
    ui->emailInput->clear();
    ui->passwordInput->clear();


}
void LoginPage::on_loginButton_clicked() {
    QString username = ui->emailInput->text();
    QString password = ui->passwordInput->text();

    if(!validateForm()){
        return;
    }

    // Replace with actual authentication logic
    if (username == "admin" && password == "password") {
        emit loginSuccess();
    } else {
        emit loginFailed( ValidationError::Password, "Invalid credentials");
        QMessageBox::warning(this, "Error", "Invalid credentials");
    }
}



bool LoginPage::validateForm() {
    const QString email = ui->emailInput->text().trimmed();
    const QString password = ui->passwordInput->text().trimmed();



    if (email.isEmpty()){
        emit loginFailed(ValidationError::Email, "email is required");
        return false;
    }
    if (password.isEmpty()){
        emit loginFailed(ValidationError::Password, "password is required");
        return false;
    }


    // emit registrationSuccess();
    return true;
}


//regiser link logic

void LoginPage::on_registerLink_linkActivated(){
    // database& db = getDatabase();

    //create a registration form
    RegisterDialog form(this);

    // Show the form and wait for response
    if(form.exec()==QDialog::Accepted){//if the fields are filled properly

        QString firstName=form.getFName();//to use later
        QString lastName=form.getLName();// to use later

        QString email=form.getEmail().trimmed();
        QString password=form.getPassword();

        // sqlite db


        // Register the user
        // bool success = db.addUser(firstName, lastName, email, password);

        // if (success) {


        //     // Auto-fill login form
        //     ui->emailInput->setText(email);
        //     ui->passwordInput->setText(form.getPassword());
        //     ui->passwordInput->setFocus();

        //     QMessageBox::information(this, "Success", "Registration successful!");
        //     return;
        // } else {
        //     QMessageBox::critical(this, "Error", "Registration failed. Please try again.");
        //     return;
        // }

    }
}



