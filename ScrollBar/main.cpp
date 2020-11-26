#include "mainwindow.h"
#include <QtWidgets>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QScrollArea sa;

    QWidget *pwgt = new QWidget;
    QPixmap pix("C:\\Qt_projects\\ScrollBar\\scroll.jpg");

    QPalette pal;
    pal.setBrush(pwgt->backgroundRole(), QBrush(pix));
    pwgt->setPalette(pal);
    pwgt->setAutoFillBackground(true);
    pwgt->setFixedSize(pix.width(), pix.height());

    sa.setWidget(pwgt);
    sa.resize(350, 150);
    sa.show();

    // QStackedWidget - Содержит в себе только один элемент, полезно, когда нужно показывать только один элемент в опр. момент времени

    return a.exec();
}
