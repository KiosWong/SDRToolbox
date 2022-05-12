#ifndef IQVISUALIZESTACK_H
#define IQVISUALIZESTACK_H

#include <QWidget>
#include "iqvisualizer.h"

namespace Ui {
class IQVisualizeStack;
}

class IQVisualizeStack : public QWidget
{
    Q_OBJECT

public:
    explicit IQVisualizeStack(QWidget *parent = nullptr);
    ~IQVisualizeStack();

    void initLayout(void);
    void addVisulazer(void);

private slots:

    void on_addVisualizerPushButton_clicked();

    void on_deleteVisualizerPushButton_clicked();

private:
    Ui::IQVisualizeStack *ui;

    QVector<IQVisualizer *> visualizerList;
    QVBoxLayout *m_pStackVerticalLayout;

};

#endif // IQVISUALIZESTACK_H
