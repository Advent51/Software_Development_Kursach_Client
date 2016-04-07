#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QApplication::setOrganizationName("Adventorium Incorporated");
    QApplication::setApplicationName("Kursach_Client");

    MainWindow w;
    w.Runne();
    w.show();

    return a.exec();
}
