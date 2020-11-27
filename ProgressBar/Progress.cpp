#include "Progress.h"
#include <QtWidgets>

Progress::Progress(QWidget *pobj) : QWidget(pobj), m_nStep(0) {
    m_pPbr = new QProgressBar;
    m_pPbr->setRange(0, 5);
    m_pPbr->setMinimumWidth(200);
    m_pPbr->setAlignment(Qt::AlignCenter);

    QPushButton *pBtnStep = new QPushButton("&Step");
    QPushButton *pBtnReset = new QPushButton("&Reset");

    QObject::connect(pBtnStep, SIGNAL(clicked()), SLOT(slotStep()));
    QObject::connect(pBtnReset, SIGNAL(clicked()), SLOT(slotReset()));

    // Layout setup
    QHBoxLayout *pHBxLayout = new QHBoxLayout;
    pHBxLayout->addWidget(m_pPbr);
    pHBxLayout->addWidget(pBtnStep);
    pHBxLayout->addWidget(pBtnReset);

    this->setLayout(pHBxLayout);
}

void Progress::slotStep(){
    m_pPbr->setValue(++m_nStep);
}

void Progress::slotReset(){
    m_nStep = 0;
    m_pPbr->reset();
}
