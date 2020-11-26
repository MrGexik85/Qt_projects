#include "Calculator.h"

Calculator::Calculator(QWidget *pwgt) : QWidget(pwgt){
    m_plcd = new QLCDNumber(12);
    m_plcd->setSegmentStyle(QLCDNumber::Flat);
    m_plcd->setMinimumSize(150, 50);

    QChar aButtons[4][4] = {{'7', '8', '9', '/'},
                            {'4', '5', '6', '*'},
                            {'1', '2', '3', '-'},
                            {'0', '.', '=', '+'}
                           };

    // Layout setup
    QGridLayout *pTopLayout = new QGridLayout;
    pTopLayout->addWidget(m_plcd, 0, 0, 1, 4);
    pTopLayout->addWidget(createButton("CE"), 1, 3);


    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            pTopLayout->addWidget(createButton(aButtons[i][j]), i+2, j);
        }
    }

    this->setLayout(pTopLayout);
}

QPushButton* Calculator::createButton(const QString& str){
    QPushButton *pBtn = new QPushButton(str);
    pBtn->setMinimumSize(40, 40);
    connect(pBtn, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    return pBtn;
}

void Calculator::calculate(){
    qreal fOperand2 = m_stk.pop().toFloat();
    QString strOperation = m_stk.pop();
    qreal fOperand1 = m_stk.pop().toFloat();
    qreal fResult = 0;

    if(strOperation == "+"){
        fResult = fOperand1 + fOperand2;
    } else if(strOperation == "-"){
        fResult = fOperand1 - fOperand2;
    } else if(strOperation == "/"){
        if(fOperand2 == 0){
            m_plcd->display("ERR");
            return;
        } else {
            fResult = fOperand1 / fOperand2;
        }
    } else if(strOperation == "*"){
        fResult = fOperand1 * fOperand2;
    }
    m_plcd->display(fResult);
}

void Calculator::slotButtonClicked(){
    QString str = ((QPushButton*) sender())->text();

    if(str == "CE"){
        m_stk.clear();
        m_strDisplay = "";
        m_plcd->display("0");
        return;
    }
    if(str.contains(QRegExp("[0-9]"))){
        m_strDisplay += str;
        m_plcd->display(m_strDisplay.toDouble());
    } else if (str == "."){
        m_strDisplay += str;
        m_plcd->display(m_strDisplay);
    } else {
        if(m_stk.count() >= 2){
            m_stk.push(QString().setNum(m_plcd->value()));
            calculate();
            m_stk.clear();
            m_stk.push(QString().setNum(m_plcd->value()));
            if(str != "="){
                m_stk.push(str);
            }
        } else {
            m_stk.push(QString().setNum(m_plcd->value()));
            m_stk.push(str);
            m_strDisplay = "";
        }
    }
}
