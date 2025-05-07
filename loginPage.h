// loginpage.h
#include <QWidget>
#include "ui_loginPage.h"
#include "registerDialog.h"

namespace Ui {
class LoginPage;
}
class LoginPage : public QWidget {
    Q_OBJECT

public:
    explicit LoginPage(QWidget *parent = nullptr);
    ~LoginPage();
    bool validateForm();
    void clearForm();

signals:
    void loginSuccess();
    void loginFailed( ValidationError type, const QString &message);

private slots:
    void on_loginButton_clicked();
    void on_registerLink_linkActivated();

private:
    Ui::LoginPage *ui;
};
