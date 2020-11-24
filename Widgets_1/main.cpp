#include "mainwindow.h"
#include <QWidget>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget wgt;

    QWidget *pwgt1 = new QWidget(&wgt);
    QPalette pal1;
    pal1.setColor(pwgt1->backgroundRole(), Qt::blue);
    pwgt1->setPalette(pal1);
    pwgt1->resize(100, 100);
    pwgt1->move(25, 25);
    pwgt1->setAutoFillBackground(true);


    QWidget *pwgt2 = new QWidget(&wgt);
    QPalette pal2;
    pal2.setColor(pwgt2->backgroundRole(), Qt::black); // QBrush(QPixmap(":/stone.jpg")) - Установить в качестве фона растровое изображение
    pwgt2->setPalette(pal2);
    pwgt2->resize(100, 100);
    pwgt2->move(75, 75);
    pwgt2->setAutoFillBackground(true);

    wgt.resize(200, 200);
    wgt.show();


    return a.exec();
}
