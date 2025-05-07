// student.h
#ifndef STUDENT_H
#define STUDENT_H

#include "user.h"

class Student : public User{

    public:
        Student();  // Default constructor
        Student(const QString &firstName, const QString &lastName, const QString &email, const QString &password);

};

#endif // STUDENT_H
