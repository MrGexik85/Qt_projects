#include "mainwindow.h"
#include <QtWidgets>
#include <QApplication>

//#define STANDART_SPINBOX
#define DATETIME

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
#ifdef STANDART_SPINBOX
    QSpinBox spb;

    spb.setRange(0, 100);
    spb.setSuffix(" MB");
    spb.setButtonSymbols(QSpinBox::PlusMinus);
    spb.setWrapping(true);
    spb.show();
    spb.resize(100, 30);

    QApplication::setStyle("windows");
#endif
#ifdef DATETIME
    QDateTimeEdit dateTimeEdit(QDateTime::currentDateTime());
    dateTimeEdit.setWrapping(true);
    dateTimeEdit.show();
#endif
    return a.exec();
}
