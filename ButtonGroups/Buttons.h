#ifndef BUTTONS_H
#define BUTTONS_H

#include <QGroupBox>

class QCheckBox;
class QRadioButton;

class Buttons : public QGroupBox {
    Q_OBJECT
private:
    QCheckBox *m_pBtnCheck;
    QRadioButton *m_pRBtnRed;
    QRadioButton *m_pRBtnGreen;
    QRadioButton *m_pRBtnBlue;

public:
    Buttons(QWidget *pwgt = 0);

public slots:
    void slotButtonClicked();

};

#endif // BUTTONS_H
