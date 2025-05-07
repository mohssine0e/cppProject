#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>

namespace Ui {
class RegisterDialog;
}
enum class ValidationError {
    Empty,
    None,
    FirstName,
    LastName,
    Email,
    Password,
    PasswordMatch,
    Role
};


class RegisterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterDialog(QWidget *parent = nullptr);
    ~RegisterDialog();


    bool validateForm();
    //getters methodes
    QString getUsername() const;
    QString getEmail() const;
    QString getFName() const;
    QString getLName() const;
    QString getPassword() const;



signals:
    // void registrationSuccess();
    void registrationFailed(ValidationError errorType, const QString& customMessage);






private:
    Ui::RegisterDialog *ui;// connect to the ui design

    ////////
private:
    //these will be created once and shared by all registration forms
    static const QRegularExpression emailRegex;
    static const QRegularExpression usernameRegex;
    static const QRegularExpression nameRegex;



private slots:
    void on_registerButton_clicked();//when the button is clicked
    void on_loginLink_linkActivated();



};

#endif // REGISTERDIALOG_H
