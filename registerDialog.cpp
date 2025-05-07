#include "registerDialog.h"
#include "mainwindow.h"
#include "qfile.h"
#include "QRegularExpression"//class that provides pattern matching using regular expressions (regex)
#include "ui_registerDialog.h"
#include "QMessageBox"


// #include "DatabaseManager.h"



// Create the email checker once when program starts
const QRegularExpression RegisterDialog::emailRegex(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");

// Create the name checker
const QRegularExpression RegisterDialog::nameRegex("^[a-zA-Z]{2,30}$");







RegisterDialog::RegisterDialog(QWidget *parent): QDialog(parent), ui(new Ui::RegisterDialog){
    ui->setupUi(this);

    setWindowTitle("Register");

    //the style
    // In constructor
    setStyleSheet(R"(


        QDialog {
            background-color: black;
            font-family: 'Segoe UI', Arial;
        }

        QLineEdit {
            padding-left:8px;
            border: 1px solid #ddd;
            border-radius: 8px;
            padding: 8px;
            font-size: 14px;
            min-width: 200px;
        }

        QLineEdit:focus {
            border-color: #4a90e2;
        }

        QLabel[error="true"] {
            color: #e74c3c;
            font-size: 13px;
        }

        QPushButton {
            background-color: #4a90e2;
            color: white;
            border: none;
            border-radius: 4px;
            padding: 8px 16px;
            font-weight: 500;
        }

        QPushButton:hover {
            background-color: #3a7bc8;
        }

        QRadioButton {
            spacing: 5px;
        }
    )");

    // Set focus policy for better UX
    ui->FNameInput->setFocus();



    // Update password strength indicator
    connect(ui->passwordInput, &QLineEdit::textChanged, [this](const QString &text) {
        int strength = 0;

        // Length check
        if (text.length() >= 8) strength++;
        if (text.length() >= 12) strength++;
        // Complexity checks
        if (text.contains(QRegularExpression("[A-Z]"))) strength++;
        if (text.contains(QRegularExpression("[0-9]"))) strength++;
        if (text.contains(QRegularExpression("[^A-Za-z0-9]"))) strength++;

        QString color, message;
        switch(strength) {
        case 0: case 1:
            color = "red"; message = "Weak"; break;
        case 2:
            color = "orange"; message = "Fair"; break;
        case 3:
            color = "#FFCC00"; message = "Good"; break;
        case 4:
            color = "#99CC00"; message = "Strong"; break;
        default:
            color = "green"; message = "Excellent"; break;
        }

        ui->errPss->setText(QString("<span style='color:%1;'>%2</span>")
                                .arg(color).arg(message));
    });



    // Update password match indicator
    connect(ui->password2Input, &QLineEdit::textChanged, [this](const QString &text){
        if (text!=ui->passwordInput->text()){
            ui->errPss2->setText(QString("<span style='color:red;'>%1</span>")
                                    .arg("password not match"));

        }else ui->errPss2->clear();

    });




    // Connect the validation error handler
    connect(this, &RegisterDialog::registrationFailed, this, [this](ValidationError error, QString message) {
        const QString errorStyle = "color: red; font-size: 13px;";
        ui->errFN->clear();
        ui->errLN->clear();
        ui->errEmail->clear();
        ui->errPss->clear();
        ui->errPss2->clear();

        switch (error) {
        case ValidationError::FirstName:

            ui->errFN->setStyleSheet(errorStyle);
            ui->errFN->setText(message);
            break;
            return;
        case ValidationError::LastName:

            ui->errLN->setStyleSheet(errorStyle);
            ui->errLN->setText(message);
            break;
            return;

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

        case ValidationError::PasswordMatch:

            ui->errPss2->setStyleSheet(errorStyle);
            ui->errPss2->setText(message);
            break;
            return;

        // case ValidationError::Role:

        //     ui->errRole->setStyleSheet(errorStyle);
        //     ui->errRole->setText(message);
        //     break;
        //     return;

        default:
            QMessageBox::warning(this, "Incomplete Form", "Please fill all  fields");
            return;

        }
    });
}



RegisterDialog::~RegisterDialog(){
    delete ui;
}

//getters
QString RegisterDialog::getEmail()const{
    return ui->emailInput->text().trimmed();//trimmed to remove extra spaces
}

QString RegisterDialog::getFName()const{
    return ui->FNameInput->text().trimmed();//trimmed to remove extra spaces
}

QString RegisterDialog::getLName()const{
    return ui->LNameInput->text().trimmed();//trimmed to remove extra spaces
}

QString RegisterDialog::getPassword()const{
    return ui->passwordInput->text().trimmed();//trimmed to remove extra spaces
}



//


// Update validateForm()
bool RegisterDialog::validateForm() {
    const QString firstName = ui->FNameInput->text().trimmed();
    const QString lastName = ui->LNameInput->text().trimmed();
    const QString email = ui->emailInput->text().trimmed();
    const QString password = ui->passwordInput->text().trimmed();
    const QString password2 = ui->password2Input->text().trimmed();
    // const bool is_student=ui->isStudent->isChecked();
    // const bool is_teacher=ui->isTeacher->isChecked();


    if (firstName.isEmpty()){
        emit registrationFailed(ValidationError::FirstName, "firstname is required");
        return false;
    }

    if (lastName.isEmpty()){
        emit registrationFailed(ValidationError::LastName, "lastname is required");
        return false;
    }
    if (email.isEmpty()){
        emit registrationFailed(ValidationError::Email, "email is required");
        return false;
    }
    if (password.isEmpty()){
        emit registrationFailed(ValidationError::Password, "password cannot be empty");
        return false;
    }
    if (password2.isEmpty()){
        emit registrationFailed(ValidationError::PasswordMatch, "confirm your password");
        return false;
    }

    if (firstName.length()<2){
        emit registrationFailed(ValidationError::FirstName, "come on at least two characters");
        return false;
    }

    if (lastName.length()<2){
        emit registrationFailed(ValidationError::LastName, "come on at least two characters");
        return false;
    }

    // //role check
    // if (!(is_student && is_teacher)){
    //     emit registrationFailed(ValidationError::Role, "choose a role (student or teacher)");
    //     return false;
    // }



    if (!nameRegex.match(firstName).hasMatch()) {
        emit registrationFailed(ValidationError::FirstName, "first name invalid format");
        return false;
    }

    if (!nameRegex.match(lastName).hasMatch()) {
        emit registrationFailed(ValidationError::LastName, "lastname invalid format");
        return false;
    }

    if (!emailRegex.match(email).hasMatch()) {
        emit registrationFailed(ValidationError::Email, "emaill invalid format");
        return false;
    }

    if (password.length() < 8) {
        emit registrationFailed(ValidationError::Password, "password week <8");
        return false;
    }

    if (password != password2) {
        emit registrationFailed(ValidationError::PasswordMatch, "password do not match ");
        return false;
    }

    // emit registrationSuccess();
    return true;
}


//when to register button is clicked
void RegisterDialog::on_registerButton_clicked() {


    // MainWindow* mainWindow = qobject_cast<MainWindow*>(parent());
    // if (!mainWindow) {
    //     // optional: emit a different error here
    //     QMessageBox::critical(this, "System Error", "No parent window.");
    //     return;
    // }

    if (!validateForm()) return;


    QString firstName = ui->FNameInput->text().trimmed();
    QString lastName  = ui->LNameInput->text().trimmed();
    QString email     = ui->emailInput->text().trimmed();
    QString password  = ui->passwordInput->text().trimmed();
    QString role = ui->isStudent->isChecked() ? "student" : "teacher";


        QMessageBox::information(this, "Success", "Registration successful next page....!");

    // //store in db
    // DatabaseManager dbManager;
    // if (!dbManager.connectToDatabase()) {//connect
    //     QMessageBox::critical(this, "Database Error", "Could not connect to database");
    //     return;
    // }

    // if (dbManager.addUser(firstName, lastName, email, password, role)) {
    //     QMessageBox::information(this, "Success", "Registration successful!");
    //     accept();
    // } else {
    //     QMessageBox::warning(this, "Error", "Email already registered");
    // }

}



void RegisterDialog::on_loginLink_linkActivated(){
    reject();
    return;

}
