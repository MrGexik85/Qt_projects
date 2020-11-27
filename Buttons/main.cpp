#include "mainwindow.h"
#include <QtWidgets>
#include <QApplication>

//#define FIRST_BUTTONS
//#define MENU_BUTTONS
//#define CHECKBOX
#define RADIO_BUTTON

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget wgt;

#ifdef FIRST_BUTTONS
    QPushButton *pBtnNormal = new QPushButton("&Normal Button");

    QPushButton *pBtnChecked = new QPushButton("&Toggle Button");
    pBtnChecked->setCheckable(true);
    pBtnChecked->setChecked(true);

    QPushButton *pBtnFlat = new QPushButton("&Flat Button");
    pBtnFlat->setFlat(true);

    QPixmap pix("C:\\Qt_projects\\Label\\img.jpg");
    QPushButton *pBtnPix = new QPushButton("&Pixmap Button");
    pBtnPix->setIcon(pix);
    pBtnPix->setIconSize(QSize(50, 50));

    QVBoxLayout *pVBxLayout = new QVBoxLayout();
    pVBxLayout->addWidget(pBtnNormal);
    pVBxLayout->addWidget(pBtnChecked);
    pVBxLayout->addWidget(pBtnFlat);
    pVBxLayout->addWidget(pBtnPix);

    wgt.setLayout(pVBxLayout);
    wgt.show();
#endif

#ifdef MENU_BUTTONS
    QPushButton *pBtnMenu = new QPushButton("Menu");
    QMenu *pMenu = new QMenu(pBtnMenu);

    pMenu->addAction("Item1");
    pMenu->addAction("Item2");
    pMenu->addAction("&Quit", &a, SLOT(quit()));

    pBtnMenu->setMenu(pMenu);
    pBtnMenu->show();

#endif

#ifdef CHECKBOX
    QCheckBox *pCheckNormal = new QCheckBox("&Normal Check Box");
    pCheckNormal->setChecked(true);

    QCheckBox *pCheckTristate = new QCheckBox("&Tristate Check Box"); // Чек бокс с неопределенным значением
    pCheckTristate->setTristate(true);
    pCheckTristate->setCheckState(Qt::PartiallyChecked);

    //Layout setup
    QVBoxLayout *pVBxLayout = new QVBoxLayout();
    pVBxLayout->addWidget(pCheckNormal);
    pVBxLayout->addWidget(pCheckTristate);

    wgt.setLayout(pVBxLayout);
    wgt.show();

#endif

#ifdef RADIO_BUTTON
    QGroupBox gbx("&Colors");

    QRadioButton *pRBtnRed = new QRadioButton("&Red");
    QRadioButton *pRBtnGreen = new QRadioButton("&Green");
    QRadioButton *pRBtnBlue = new QRadioButton("&Blue");
    pRBtnGreen->setChecked(true);

    QVBoxLayout *pVBxLayout = new QVBoxLayout();
    pVBxLayout->addWidget(pRBtnRed);
    pVBxLayout->addWidget(pRBtnGreen);
    pVBxLayout->addWidget(pRBtnBlue);

    gbx.setLayout(pVBxLayout);
    gbx.show();
#endif
    return a.exec();
}
