#include "mainwindow.h"
#include <QtWidgets>
#include <QtPrintSupport>
#include <QApplication>

//#define LINE_EDIT
//#define TEXT_EDIT
//#define WRITER
#define PRINT_PDF

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

#ifdef LINE_EDIT
    QWidget wgt;

    QLabel *pLblDisplay = new QLabel();
    pLblDisplay->setFrameStyle(QFrame::Box | QFrame::Raised);
    pLblDisplay->setLineWidth(2);
    pLblDisplay->setFixedHeight(50);

    QLabel *pLblText = new QLabel("&Text");
    QLineEdit *pTxt = new QLineEdit();
    pLblText->setBuddy(pTxt);
    QObject::connect(pTxt, SIGNAL(textChanged(const QString&)), pLblDisplay, SLOT(setText(const QString&)));


    QLabel *pLblPassword = new QLabel("&Password");
    QLineEdit *pPassword = new QLineEdit(); // Можно ограничить длину ввода методом setMatLength()
    pLblPassword->setBuddy(pPassword);
    pPassword->setEchoMode(QLineEdit::Password);

    /*
        Слоты для работы с буфером обмена: copy(), cut(), paste()
        undo() и redo() - действие назад или вперед соответственно(Есть проверка isUndoAvailable() и isRedoAvailable())
    */

    QVBoxLayout *pVBxLayout = new QVBoxLayout();
    pVBxLayout->addWidget(pLblDisplay);
    pVBxLayout->addWidget(pLblText);
    pVBxLayout->addWidget(pTxt);
    pVBxLayout->addWidget(pLblPassword);
    pVBxLayout->addWidget(pPassword);

    wgt.setLayout(pVBxLayout);

    wgt.show();
#endif

#ifdef TEXT_EDIT
    QTextEdit txt;
    txt.setHtml("<html>"
                "<body bgcolor=yellow>"
                "<center><img src=\"C:\\Qt_projects\\Label\\img.jpg\"></center>"
                "<h2><center>BIG SUR</center></h2>"
                "<font color=blue>"
                    "<p align=\"center\""
                    "<i>"
                        "Magic! Magic!<br>"
                        "Magic! Magic!<br>"
                        "Magic! Magic!<br>"
                        "..."
                    "</i>"
                    "</p>"
                "</font>"
                "</body>"
                "</html>");

    txt.resize(320, 350);
    txt.show();
#endif
#ifdef WRITER
    QTextEdit *pTxtEdit = new QTextEdit("This is a <b>TEST</b>");
    QTextDocumentWriter writer;
    writer.setFormat("odf");
    writer.setFileName("output.odf");
    writer.write(pTxtEdit->document());
#endif

#ifdef PRINT_PDF
    QTextEdit *pTxtEdit = new QTextEdit("This is a <b>TEST</b>");
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("output.pdf");
    pTxtEdit->document()->print(&printer);
#endif
    return a.exec();
}
