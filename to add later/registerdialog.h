// registerdialog.h
#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QButtonGroup>

namespace Ui {
class RegisterDialog;
}

class RegisterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterDialog(QWidget *parent = nullptr);
    ~RegisterDialog();

    struct UserData {
        QString firstName;
        QString lastName;
        QString email;
        QString password;
        bool isTeacher;
    };

    UserData getUserData() const;

private slots:
    void validateForm();

    void on_registerButton_clicked();//when the button is clicked
    void on_loginLink_linkActivated();


private:
    Ui::RegisterDialog *ui;
    QButtonGroup *roleGroup;
    void showError(QLabel* label, const QString& message);
    void clearError(QLabel* label);
};

#endif // REGISTERDIALOG_H
