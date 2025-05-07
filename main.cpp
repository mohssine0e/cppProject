#include "mainwindow.h"
// #include "DatabaseManager.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    // Check available database drivers
    // qDebug() << "Available database drivers:" << QSqlDatabase::drivers();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
