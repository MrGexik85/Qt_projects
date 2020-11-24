#include <QCoreApplication>
#include <QList>
#include <QVector>
#include <QByteArray>
#include <QBitArray>
#include <QString>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /*
        Итераторы в стиле Java
    */
    QList<QString> list;
    list << "Element 1" << "Element 2" << "Element 3";
    QListIterator<QString> listIterator(list);
    QMutableListIterator<QString> mutableListIterator(list); // Итератор с возможностью изменения элементов
    mutableListIterator.insert("Element 5"); // Вставка на текущее место
    mutableListIterator.setValue("Element 4"); // Изменение значения текущего элемента
    mutableListIterator.remove(); // Удаляет текущий элемент
    qDebug() << "Работа с итераторами в стиле Java";
    while(listIterator.hasNext()){
        qDebug() << listIterator.next();
    }

    /*
        Итераторы в стиле STL
    */

    // Если значения не будут меняться, лучше использовать const_iterator и соотв методы constBegin() и constEnd()
    QVector<QString> sVec;
    sVec << "Element 1" << "Element 2" << "Element 3";
    QVector<QString>::iterator vecIterator;
    qDebug() << "\nРабота с итераторами в стиле STL";
    for(vecIterator = sVec.begin(); vecIterator != sVec.end(); ++vecIterator){
        qDebug() << *vecIterator;
    }

    // foreach - не меняет значения в контейнере, т.к. создает его копию
    qDebug() << "\nКонструкция foreach";
    foreach(QString s, sVec){
        qDebug() << s;
    }

    qDebug() << "\nQByteArray - массив байтов";
    QByteArray arrByte(3, '0'); // Массив байтов размером 3 со значениями \0

    qDebug() << arrByte;
    arrByte[1] = 0xFF;
    qDebug() << arrByte;


    qDebug() << "\nQBitArray - массив битов";
    QBitArray arrBit(3);
    arrBit[2] = true;
    qDebug() << arrBit;


    // QMap<K, T>, QMultiMap<K, T>, QStack<T>, QQueue<T>, QLinkedList<T>
    // QHash<K, T>, QMultiHash<K, T>, QSet<T>
    // Для Qmap и тд нужно в конструкторе задавать простое число, большее количества элементов

    // Чтобы размещать в QHash<> свои классы в них нужно добавить оператор == и функцию qhash
    /*
        inline bool operator==(const MyClass& mc1, const MyClass& mc1){
            return (mc1.firstName() == mc2.firstName() && mc1.secondName() == mc2.secondName());
        }

        inline uint qHash(const MyClass& mc){
            return qHash(mc.firstName() ^ mc.secondName());
        }
    */




    return 0; // a.exec()
}
