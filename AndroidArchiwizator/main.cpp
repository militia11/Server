#include "mainwindow.h"
#include <QApplication>
#include "server.h"
int main(int argc, char *argv[])
{
    // takie tam
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
