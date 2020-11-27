#ifndef PROGRESS_H
#define PROGRESS_H

#include <QWidget>

class QProgressBar;

class Progress : public QWidget {
    Q_OBJECT

private:
    QProgressBar *m_pPbr;
    int m_nStep;

public:
    Progress(QWidget *pObj = 0);

public slots:
    void slotStep();
    void slotReset();
};

#endif // PROGRESS_H
