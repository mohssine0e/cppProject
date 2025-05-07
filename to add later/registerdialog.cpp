#include "ui_registerDialog.h"
#include "registerdialog.h"
#include <QRegularExpression>
#include <QMessageBox>

RegisterDialog::RegisterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterDialog),
    roleGroup(new QButtonGroup(this))
{
    ui->setupUi(this);

    // Set up role selection
    roleGroup->addButton(ui->isTeacher, 0);
    roleGroup->addButton(ui->isStudent, 1);
    ui->isTeacher->setChecked(true);

    // // Connect signals
    // connect(ui->registerButton, &QPushButton::clicked, this, &RegisterDialog::onRegisterClicked);
    // connect(ui->loginLink, &QLabel::linkActivated, this, &RegisterDialog::on_loginLink_linkActivated);

    // Live validation
    connect(ui->FNameInput, &QLineEdit::textChanged, this, [this](){ clearError(ui->labelFName); });
    connect(ui->LNameInput, &QLineEdit::textChanged, this, [this](){ clearError(ui->labelLName); });
    connect(ui->emailInput, &QLineEdit::textChanged, this, [this](){ clearError(ui->labelEmail); });
    connect(ui->passwordInput, &QLineEdit::textChanged, this, [this](){ clearError(ui->labelPassword); });
    connect(ui->password2Input, &QLineEdit::textChanged, this, [this](){ clearError(ui->labelPassword2); });
}

RegisterDialog::UserData RegisterDialog::getUserData() const
{
    return {
        ui->FNameInput->text().trimmed(),
        ui->LNameInput->text().trimmed(),
        ui->emailInput->text().trimmed(),
        ui->passwordInput->text(),
        ui->isTeacher->isChecked()
    };
}

void RegisterDialog::showError(QLabel* label, const QString& message)
{
    label->setText(QString("<span style='color: red; font-size: small;'>%1</span>").arg(message));
}

void RegisterDialog::clearError(QLabel* label)
{
    label->clear();
}

void RegisterDialog::validateForm()
{
    bool isValid = true;

    // First name validation
    if (ui->FNameInput->text().trimmed().isEmpty()) {
        showError(ui->labelFName, "First name is required");
        isValid = false;
    }

    // Last name validation
    if (ui->LNameInput->text().trimmed().isEmpty()) {
        showError(ui->labelLName, "Last name is required");
        isValid = false;
    }

    // Email validation
    QRegularExpression emailRegex(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
    if (!emailRegex.match(ui->emailInput->text().trimmed()).hasMatch()) {
        showError(ui->labelEmail, "Invalid email format");
        isValid = false;
    }

    // Password validation
    if (ui->passwordInput->text().length() < 8) {
        showError(ui->labelPassword, "Minimum 8 characters");
        isValid = false;
    }

    // Password confirmation
    if (ui->passwordInput->text() != ui->password2Input->text()) {
        showError(ui->labelPassword2, "Passwords don't match");
        isValid = false;
    }

    ui->registerButton->setEnabled(isValid);
}

void RegisterDialog::on_registerButton_clicked()
{
    validateForm();
    if (ui->registerButton->isEnabled()) {
        accept();
    } else {
        QMessageBox::warning(this, "Incomplete Form", "Please correct the highlighted fields");
    }
}

void RegisterDialog::on_loginLink_linkActivated()
{
    reject(); // Close the registration dialog
}
