#ifndef USER_H
#define USER_H

#include <QString>

class User{
    protected:
        QString firstName, lastName, email, password;


    public:
        User();//defualt construct;oru
        User(const QString &firstName, const QString &lastName, const QString &email, const QString &password);//constructor with params

    //getters ( // const function that does not modify the object)
        QString getFName()const;
        QString getLName()const;
        QString getEmail()const;
        QString getPassword() const;

    //setters (  // non-const function that can modify the object)
        void setFName(const QString& firstName);
        void setLName(const QString& lastName);
        void setEmail(const QString& email);
        void setPassword(const QString& password);

};



#endif //USER_H
