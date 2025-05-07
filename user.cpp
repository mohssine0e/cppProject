#include "user.h"



//defuaot constractor
User::User() {
    this->firstName="";
    this->lastName="";
    this->email="";
    this->password="";

}

//constructoru with paras

User::User(const QString &firstName,
                const QString &lastName,
                const QString &email,
                const QString &password
){
    this->firstName=firstName;
    this->lastName=lastName;
    this->email=email;
    this->password=password;
}


//gettters
QString User::getFName()const {
    return this->firstName;
}


QString User::getLName()const{
    return this->lastName;
}


QString User::getEmail()const{
    return this->email;
}


QString User::getPassword()const{
    return this->password;
}



//setters
void User::setFName(const QString& firstName){
    this->firstName=firstName;
}

void User::setLName(const QString& lastName){
    this->lastName=lastName;
}

void User::setEmail(const QString& email){
    this->email=email;
}

void User::setPassword(const QString& password){
    this->password=password;
}

