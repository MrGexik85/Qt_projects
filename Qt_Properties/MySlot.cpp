#include <QObject>
#include <QDebug>

class MySlot : public QObject{
    Q_OBJECT

public:
    MySlot();

private slots: // Перечисление здесь всех слотов
    void slot(){ // Так выглядит схема слота (в теле выполняются необходимые действия при вызове слота)
        qDebug() << "I'm a slot!";
        qDebug() << sender()->objectName(); // Можно узнать кто выслал сигналы
    }
};

/*
    Связывание сигнал-слот
    QObject::connect(const QObject*     sender,
                     const char*        signal,  // Должно быть заключено в макрос SIGNAL(method(param));
                     const QObject      receiver,
                     const char*        slot,    // Должно быть заключено в макрос SLOT(method(param));
                     Qt::ConnectionType type = Qt::AutoConnection
);

    Альтернативное связывание сигнал-слот находятся ошибки на этапе компиляции
    QObject::connect(const QObject*         sender,
                     const QMetaMethod&     signal,  // Передается конструкция вида SenderClass::signalMethod
                     const QObject          receiver,
                     const QMetaMethod&     slot,
                     Qt::ConnectionType     type = Qt::AutoConnection
);

    connect(pSender, SIGNAL(method()), SIGNAL(method())); // Просто передает сигнал дальше
*/
