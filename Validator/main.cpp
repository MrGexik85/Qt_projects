#include "mainwindow.h"
#include <QtWidgets>
#include <QApplication>

class NameValidator : public QValidator{
public:
    NameValidator(QObject *parent) : QValidator(parent){}
    virtual State validate(QString& str, int& pos) const {
        QRegExp rxp = QRegExp("[0-9]");
        if(str.contains(rxp)){
            return Invalid;
        }
        return Acceptable;
    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget wgt;

    QLabel *pLblText = new QLabel("&Name (The digits will not be accepted!)");
    QLineEdit *pLineEdit = new QLineEdit();
    NameValidator *pNameValidator = new NameValidator(pLineEdit);
    pLineEdit->setValidator(pNameValidator);
    pLblText->setBuddy(pLineEdit);

    QVBoxLayout *pVBxLayout = new QVBoxLayout();
    pVBxLayout->addWidget(pLblText);
    pVBxLayout->addWidget(pLineEdit);
    wgt.setLayout(pVBxLayout);
    wgt.show();
    return a.exec();
}


