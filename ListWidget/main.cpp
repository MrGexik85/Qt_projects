#include "mainwindow.h"
#include <QtWidgets>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QStringList strList;
    QListWidget lwgt;
    QListWidgetItem *pItem = 0;

    strList << "Linux" << "Windows" << "MacOS" << "Android";
    lwgt.setSelectionMode(QAbstractItemView::MultiSelection); // Множественное выделение
    lwgt.setIconSize(QSize(48, 48));
    foreach(QString str, strList){
        pItem = new QListWidgetItem(str, &lwgt);
        pItem->setIcon(QPixmap("://img.jpg"));
    }
    lwgt.resize(125, 175);
    lwgt.show();

    return a.exec();
}
