#include "mainwindow.h"
#include <QtWidgets>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget wgt;

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
    wgt.show();
    return a.exec();
}
