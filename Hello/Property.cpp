#include <QObject>

class MyClass : public QObject { // При множественном наследовании QObject должен стоять первым
    Q_OBJECT
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
