#include "Calculator.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Calculator calc;

    calc.setWindowTitle("Калькулятор");
    calc.resize(230, 200);

    calc.show();

    return a.exec();
}
