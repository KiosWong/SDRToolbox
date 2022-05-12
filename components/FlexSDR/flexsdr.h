#ifndef FLEXSDR_H
#define FLEXSDR_H

#include <QWidget>
#include "flexspace.h"
#include "lockerwidget.h"

namespace Ui {
class FlexSDR;
}

class FlexSDR : public QWidget
{
    Q_OBJECT

public:
    explicit FlexSDR(QWidget *parent = nullptr);
    ~FlexSDR();

    void initLayout(void);

private:
    Ui::FlexSDR *ui;

    QFrame *pWorkspaceFrame;
    LockerWidget *pLockerWidget;
    FlexSpace *pFlexSpace;
};

#endif // FLEXSDR_H
