#include "mainwindow.h"
#include <QApplication>
#include "socket.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(500,500);
    w.show();

    return a.exec();
}
