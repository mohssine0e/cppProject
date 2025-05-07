// teacher.h
#ifndef TEACHER_H
#define TEACHER_H

#include "user.h"
class Teacher : public User{

    public:
        Teacher();  // Default constructor
        Teacher(const QString &firstName,
                const QString &lastName,
                const QString &email,
                const QString &password);

};

#endif // TEACHER_H
