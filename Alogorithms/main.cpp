#include <QCoreApplication>
#include <QtAlgorithms>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString values[] = {"Xandria", "Therion", "Nightwish", "Haggard"};
    const int n = sizeof(values)/sizeof(QString);
    QString copyOfValues[n];
    qCopy(values, values+n, copyOfValues);

    return 0; // a.exec
}
