#include <QObject>

// Сигнал - объект "телефон" подал сигнал "звонок", слот - объект "человек" отреагировал слотом "снятия трубки"

class MyClass : public QObject { // При множественном наследовании QObject должен стоять первым
    Q_OBJECT // Этот макрос необходимо писать, если класс использует механизм сигналов и слотов или если ему необходима информация о свойствах (как в данном случае)
    Q_PROPERTY(bool readOnly READ isReadOnly WRITE setReadOnly)

private:
    bool m_bReadOnly;

public:
    MyClass(QObject* pobj = 0) : QObject(pobj), m_bReadOnly(false) {}

public:
    void setReadOnly(bool bReadOnly){
        m_bReadOnly = bReadOnly;
    }

    bool isReadOnly() const {
        return m_bReadOnly;
    }
};
