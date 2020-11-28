#include "Buttons.h"

#include <QtWidgets>

Buttons::Buttons(QWidget *pwgt) : QGroupBox("QroupBox", pwgt) {
    this->resize(100, 100);
    this->setCheckable(true);
    this->setChecked(true);

    m_pRBtnRed = new QRadioButton("&Red");
    m_pRBtnGreen = new QRadioButton("&Green");
    m_pRBtnBlue = new QRadioButton("&Blue");
    m_pRBtnGreen->setChecked(true);
    connect(m_pRBtnGreen, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    connect(m_pRBtnRed, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    connect(m_pRBtnBlue, SIGNAL(clicked()), SLOT(slotButtonClicked()));

    m_pBtnCheck = new QCheckBox("&Light");
    m_pBtnCheck->setChecked(true);
    connect(m_pBtnCheck, SIGNAL(clicked()), SLOT(slotButtonClicked()));

    QPushButton *pBtnExit = new QPushButton("&Exit");
    connect(pBtnExit, SIGNAL(clicked()), qApp, SLOT(quit()));

    QVBoxLayout *pVBxLayout = new QVBoxLayout();
    pVBxLayout->addWidget(m_pRBtnRed);
    pVBxLayout->addWidget(m_pRBtnGreen);
    pVBxLayout->addWidget(m_pRBtnBlue);
    pVBxLayout->addWidget(m_pBtnCheck);
    pVBxLayout->addWidget(pBtnExit);
    this->setLayout(pVBxLayout);

    slotButtonClicked();
}

void Buttons::slotButtonClicked(){
    QPalette pal = this->palette();
    int nLight = m_pBtnCheck->isChecked() ? 150 : 80;
    if(m_pRBtnRed->isChecked()){
        pal.setColor(backgroundRole(), QColor(Qt::red).lighter(nLight));
    } else if(m_pRBtnGreen->isChecked()){
        pal.setColor(backgroundRole(), QColor(Qt::green).lighter(nLight));
    } else {
        pal.setColor(backgroundRole(), QColor(Qt::blue).lighter(nLight));
    }
    this->setPalette(pal);
}
