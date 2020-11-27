#include "mainwindow.h"
#include <QtWidgets>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget wgt;
    QLCDNumber *pLCD = new QLCDNumber;
    QSpinBox *pSpb = new QSpinBox;

    pLCD->setSegmentStyle(QLCDNumber::Filled);
    pLCD->setMode(QLCDNumber::Hex);

    pSpb->setFixedHeight(30);

    QObject::connect(pSpb, SIGNAL(valueChanged(int)), pLCD, SLOT(display(int)));

    // Layout setup
    QVBoxLayout *pVBxLayout = new QVBoxLayout;
    pVBxLayout->addWidget(pLCD);
    pVBxLayout->addWidget(pSpb);

    wgt.setLayout(pVBxLayout);
    wgt.resize(250, 150);
    wgt.show();

    return a.exec();
}
