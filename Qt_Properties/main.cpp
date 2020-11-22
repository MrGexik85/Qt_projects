#include <QCoreApplication>
#include <QObject>
#include <QDebug>
#include <QMetaProperty>

#include "MyClass.cpp"

/*
    Здесь ничего не работает, просто показано для примера
*/

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyClass *pobj = new MyClass();

    pobj->setProperty("readOnly", true); // Из-за объявление в классе макроса Q_PROPERTY здесь будет вызван WRITE метод и установит значение переменной m_bReadOnly в true
    bool bReadOnly = pobj->property("readOnly").toBool(); // Из-за объявление в классе макроса Q_PROPERTY здесь будет вызван READ метод и вернет значение переменной m_bReadOnly из класса

    // Цикл переберет все Q_PROPERTY для данного класса и выведет по каждому информацию (тип, имя, значение)
    const QMetaObject* pmo = pobj->metaObject();
    for (int i = 0; i < pmo->propertyCount(); ++i){
        const QMetaProperty mp = pmo->property(i);
        qDebug() << "Property#:" << i;
        qDebug() <<"Туре:"<< mp.typeName();
        qDebug() << "Name:" << mp.name() ;
        qDebug() << "Value:" << pobj->property(mp.name());
    }
    return a.exec();
}
