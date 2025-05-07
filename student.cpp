// student.cpp
#include "student.h"

// Default constructor
Student::Student() : User()
{
    // Default constructor
}

// Constructor with parameters
Student::Student(const QString &firstName,
                 const QString &lastName,
                 const QString &email,
                 const QString &password)
    : User(firstName, lastName, email, password) // Calling Person constructor
{
    // Initialize student
}
