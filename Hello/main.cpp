#include "mainwindow.h"
#include <QtWidgets>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLabel lbl("Hello world!");
    lbl.show();
    return a.exec();
}
