#include "mainwindow.h"
#include <QtWidgets>
#include <QApplication>

//#define SLIDER
//#define SCROLL_BAR
#define DIAL

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
#ifdef SLIDER
    QWidget wgt;

    QSlider *pSldr = new QSlider(Qt::Horizontal);
    QLabel *pLbl = new QLabel("3");

    pSldr->setRange(0, 9);
    pSldr->setPageStep(2);
    pSldr->setValue(3);
    pSldr->setTickInterval(2);
    pSldr->setTickPosition(QSlider::TicksBelow);
    QObject::connect(pSldr, SIGNAL(valueChanged(int)), pLbl, SLOT(setNum(int)));

    QHBoxLayout *pHBxLayout = new QHBoxLayout();
    pHBxLayout->addWidget(pSldr);
    pHBxLayout->addWidget(pLbl);

    wgt.setLayout(pHBxLayout);
    wgt.show();
#endif

#ifdef SCROLL_BAR
    QWidget wgt;
    QLCDNumber *pLcd = new QLCDNumber(4);
    QScrollBar *pScrlBar = new QScrollBar(Qt::Horizontal);
    pScrlBar->setRange(0, 9999);
    pScrlBar->setSingleStep(20);

    QObject::connect(pScrlBar, SIGNAL(valueChanged(int)), pLcd, SLOT(display(int)));

    QVBoxLayout *pVBxLayout = new QVBoxLayout();
    pVBxLayout->addWidget(pLcd);
    pVBxLayout->addWidget(pScrlBar);

    wgt.setLayout(pVBxLayout);
    wgt.resize(250, 150);
    wgt.show();
#endif

#ifdef DIAL
    QWidget wgt;
    QDial *pDial = new QDial();
    QProgressBar *pPrBar = new QProgressBar();

    pDial->setRange(0, 100);
    pDial->setNotchTarget(5);
    pDial->setNotchesVisible(true);
    QObject::connect(pDial, SIGNAL(valueChanged(int)), pPrBar, SLOT(setValue(int)));

    QVBoxLayout *pVBxLayout = new QVBoxLayout();
    pVBxLayout->addWidget(pDial);
    pVBxLayout->addWidget(pPrBar);

    wgt.setLayout(pVBxLayout);
    wgt.resize(180, 200);
    wgt.show();
#endif
    return a.exec();
}
