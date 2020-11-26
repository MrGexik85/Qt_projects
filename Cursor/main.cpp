#include "mainwindow.h"
#include <QWidget>
#include <QDebug>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget wgt;
    QPixmap pix("C:\\Qt_projects\\Cursor\\fuck.png");
    qDebug() << pix;
    QCursor cur(pix);

    wgt.setCursor(cur);
    wgt.resize(180, 100);
    wgt.show();

    return a.exec();
}
