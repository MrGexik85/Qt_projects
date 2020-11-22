#include <QObject>

// Тут опять же нихрена не работает, а написано ради примеров создания сигналов

class MySignal : public QObject {
    Q_OBJECT

    // Здесь какое-то описание класса

    void sendSignal(){
        emit doIt(); // Ключевое слово служит для отправки сигнала из объекта класса MySignal
    }

    void sendStringSignal(){
        emit sendString("Information"); // Вот и отправка сигнала с параметром "Information"
    }

signals:
    void doIt(); // Основная конструкция сигнала (похоже на обычный прототип функции без ее реализации, реализация берет на себя MOC)
    void sendString(const QString&); // Отправка сигнала со строкой в качестве параметра
};
