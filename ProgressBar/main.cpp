#include "mainwindow.h"
#include "Progress.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Progress progress;

    progress.show();
    return a.exec();
}
