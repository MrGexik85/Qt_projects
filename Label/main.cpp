#include "mainwindow.h"
#include <QtWidgets>
#include <QApplication>

//#define LABEL_HTML
#define LABEL_IMG
//#define LABEL_FORM

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
#ifdef LABEL_HTML
    QLabel lbl("<h1><center>QLabel - HTML Demo</center></h1>"
               "<h2><center>List</center></h2>"
               "<ol>"
                "<li>One</li>"
                "<li>Two</li>"
                "<li>Three</li>"
               "</ol>");
    lbl.show();
#endif

#ifdef LABEL_IMG
    QPixmap pix;
    pix.load("C:\\Qt_projects\\Label\\img.jpg");

    // Можно открывать гиперссылки
    QLabel *plbl2 = new QLabel("<a href=\"http://vk.com\">Вконтакте</a>");
    plbl2->setOpenExternalLinks(true);
    plbl2->show();

    QLabel lbl;
    lbl.resize(500, 500);
    lbl.setPixmap(pix);

    lbl.show();
#endif

#ifdef LABEL_FORM
    QWidget wgt;

    QLabel *pLblName = new QLabel("&Name:");
    QLineEdit *pTxtName = new QLineEdit;
    pLblName->setBuddy(pTxtName); // а вот и само назначение

    QLabel *pLblAge = new QLabel("&Age:");
    QSpinBox *pSpbAge = new QSpinBox;
    pLblAge->setBuddy(pSpbAge);

    // Layout setup
    QVBoxLayout *pVBxLayout = new QVBoxLayout;
    pVBxLayout->addWidget(pLblName);
    pVBxLayout->addWidget(pTxtName);
    pVBxLayout->addWidget(pLblAge);
    pVBxLayout->addWidget(pSpbAge);

    wgt.setLayout(pVBxLayout);
    wgt.show();
#endif
    return a.exec();
}
