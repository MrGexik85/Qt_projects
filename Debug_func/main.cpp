#include <QCoreApplication>
#include <QFile>
#include <QDateTime>
#include <QTextStream>

// Переопределение вывода LOG сообщений в файл
void messageToFile(QtMsgType type, const QMessageLogContext& context, const QString& msg);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInstallMessageHandler(messageToFile); // После этого все qDebug(), qWarning() и qFatal() будут записываться в нужный файл, а не в консоль
    // Если понадобилось снова выводить сообщения в консоль, нужно вызвать qInstallMessageHandler c параметром 0
    // Если в качестве аргумента будет пустая функция, то вывода не будет, полезно, когда нужно убрать отладочный вывод в релизной версии
    return a.exec();
}

void messageToFile(QtMsgType type, const QMessageLogContext& context, const QString& msg){
    QFile file("protocol.log");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
        return;

    QString strDateTime = QDateTime::currentDateTime().toString("dd.MM.yy-hh.mm");

    QTextStream out(&file);
    switch (type) {
        case QtDebugMsg:
            out << strDateTime << "Debug: " << msg << ", " << context.file << "\n";
            break;
        case QtWarningMsg:
            out << strDateTime << "Crtitical: " << msg << ", " << context.file << "\n";
            break;
        case QtFatalMsg:
            out << strDateTime << "Fatal: " << msg << ", " << context.file << "\n";
            abort(); // Завершает программу
            break;
    }
}

