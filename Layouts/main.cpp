#include "mainwindow.h"
#include <QtWidgets>
#include <QApplication>

//#define BOX
//#define BOX_STRETCH
//#define H_LAYOUT
//#define V_LAYOUT
//#define HV_LAYOUT
#define GRID_LAYOUT

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget wgt;

#ifdef BOX
    QPushButton *pBtn1 = new QPushButton("A");
    QPushButton *pBtn2 = new QPushButton("B");
    QPushButton *pBtn3 = new QPushButton("C");

    // Layout setup
    QBoxLayout *pBxLayout = new QBoxLayout(QBoxLayout::LeftToRight);

    pBxLayout->addWidget(pBtn1, 1);
    pBxLayout->addWidget(pBtn2, 2);
    pBxLayout->addWidget(pBtn3, 3);
    // Второй параметр - фактор растяжения (пропорции между собой)

    wgt.setLayout(pBxLayout);
    wgt.resize(450, 40);
#endif

#ifdef BOX_STRETCH
    QPushButton *pBtn1 = new QPushButton("A");
    QPushButton *pBtn2 = new QPushButton("B");

    QBoxLayout *pBxLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    pBxLayout->addWidget(pBtn1);
    pBxLayout->addStretch(1); // Растяжение зависит от порядка добавления - в данном случае добавлен между элементами
    pBxLayout->addWidget(pBtn2);

    wgt.setLayout(pBxLayout);
    wgt.resize(450, 40);
#endif

#ifdef H_LAYOUT
    QPushButton *pBtn1 = new QPushButton("A");
    QPushButton *pBtn2 = new QPushButton("B");
    QPushButton *pBtn3 = new QPushButton("C");

    QHBoxLayout *pHBxLayout = new QHBoxLayout();
    pHBxLayout->setContentsMargins(10, 10, 10, 10);
    pHBxLayout->setSpacing(20);
    pHBxLayout->addWidget(pBtn1);
    pHBxLayout->addWidget(pBtn2);
    pHBxLayout->addWidget(pBtn3);


    wgt.setLayout(pHBxLayout);
#endif

#ifdef V_LAYOUT
    QPushButton *pBtn1 = new QPushButton("A");
    QPushButton *pBtn2 = new QPushButton("B");
    QPushButton *pBtn3 = new QPushButton("C");

    QVBoxLayout *pVBxLayout = new QVBoxLayout();
    pVBxLayout->setContentsMargins(10, 10, 10, 10);
    pVBxLayout->setSpacing(20);
    pVBxLayout->addWidget(pBtn1);
    pVBxLayout->addWidget(pBtn2);
    pVBxLayout->addWidget(pBtn3);


    wgt.setLayout(pVBxLayout);
#endif

#ifdef HV_LAYOUT
    QPushButton *pBtnA = new QPushButton("A");
    QPushButton *pBtnB = new QPushButton("B");
    QPushButton *pBtnC = new QPushButton("C");
    QPushButton *pBtnD = new QPushButton("D");

    QVBoxLayout *pVBxLayout = new QVBoxLayout();
    QHBoxLayout *pHBxLayout = new QHBoxLayout();

    //pHBxLayout->setContentsMargins(5, 5, 5, 5);
    pHBxLayout->setSpacing(15);
    pHBxLayout->addWidget(pBtnC);
    pHBxLayout->addWidget(pBtnD);

    pVBxLayout->setContentsMargins(5, 5, 5, 5);
    pVBxLayout->setSpacing(15);
    pVBxLayout->addWidget(pBtnA);
    pVBxLayout->addWidget(pBtnB);
    pVBxLayout->addLayout(pHBxLayout);

    wgt.setLayout(pVBxLayout);
#endif

#ifdef GRID_LAYOUT
    QPushButton *pBtnA = new QPushButton("A");
    QPushButton *pBtnB = new QPushButton("B");
    QPushButton *pBtnC = new QPushButton("C");
    QPushButton *pBtnD = new QPushButton("D");

    QGridLayout *pGrLayout = new QGridLayout();
    pGrLayout->setContentsMargins(5, 5, 5, 5);
    pGrLayout->setSpacing(15);
    pGrLayout->addWidget(pBtnA, 0, 0);
    pGrLayout->addWidget(pBtnB, 0, 1);
    pGrLayout->addWidget(pBtnC, 1, 0);
    pGrLayout->addWidget(pBtnD, 1, 1);

    wgt.setLayout(pGrLayout);
#endif

    wgt.show();
    return a.exec();
}
