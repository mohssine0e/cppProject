#include "teacher.h"


Teacher::Teacher() : User()
{
    // Default constructor
}

// Constructor with parameters
Teacher::Teacher(const QString &firstName,
                 const QString &lastName,
                 const QString &email,
                 const QString &password)
    : User(firstName, lastName, email, password) // Calling Person constructor
{
    // Initialize teacher
}
