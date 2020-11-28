#include "mainwindow.h"
#include "Buttons.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Buttons buttons;
    buttons.show();

    return a.exec();
}
