#include "mainwindow.h"
#include <QtWidgets>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSplitter spl(Qt::Vertical);
    QTextEdit* pText1 = new QTextEdit;
    QTextEdit* pText2 = new QTextEdit;
    spl.addWidget(pText1);
    spl.addWidget(pText2);

    pText1->setPlainText("Line 1\n"
                         "Line 2\n"
                         "Line 3\n"
                         "Line 4\n"
                         "Line 5\n"
                         "Line 6\n"
                         "Line 7\n");
    pText2->setPlainText(pText1->toPlainText());

    spl.resize(200, 220);
    spl.show();

    return a.exec();
}
