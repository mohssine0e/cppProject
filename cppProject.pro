QT += core gui  widgets
CONFIG += c++17 debug_and_release

# Ensure build directory is in include path
INCLUDEPATH += $$OUT_PWD
DEPENDPATH += $$OUT_PWD

# # MySQL configuration
# unix:!macx: {
#     LIBS += -L/usr/lib/x86_64-linux-gnu -lmysqlclient
#     INCLUDEPATH += /usr/include/mysql
#     DEPENDPATH += /usr/include/mysql
# }

SOURCES += \
    dashboardPage.cpp \
    helpers.cpp \
    loginPage.cpp \
    main.cpp \
    mainwindow.cpp \
    registerDialog.cpp \
    student.cpp \
    teacher.cpp \
    user.cpp

HEADERS += \
    dashboardPage.h \
    helpers.h \
    loginPage.h \
    mainwindow.h \
    registerDialog.h \
    student.h \
    teacher.h \
    user.h

FORMS += \
    dashboardPage.ui \
    loginPage.ui \
    mainwindow.ui \
    registerDialog.ui \
    studentDash.ui \
    teacherDash.ui
# Default rules for deployment
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
