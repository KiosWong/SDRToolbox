#ifndef IQVISUALIZER_H
#define IQVISUALIZER_H

#include <QMainWindow>
#include "iqanalyzeplot.h"

namespace Ui {
class IQVisualizer;
}

class IQVisualizer : public QMainWindow
{
    Q_OBJECT

public:
    explicit IQVisualizer(QWidget *parent = nullptr,
                          int visualizer_id = 0,
                          QString visualizer_name = nullptr,
                          int type = 0,
                          QString ip = nullptr,
                          int port = 0);
    ~IQVisualizer();

    bool selected();

    QFrame *m_pPlotFrame;
    QVBoxLayout *m_pPlotVerticalLayout;
    IQAnalyzePlot *analyzePlot;



private:
    Ui::IQVisualizer *ui;
    bool is_selected;

    int id;
    QString name;
    int type;
    QString ip;
    int port;

protected:
    void mousePressEvent(QMouseEvent *event);

};

#endif // IQVISUALIZER_H
