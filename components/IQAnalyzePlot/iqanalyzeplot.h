#ifndef IQANALYZEPLOT_H
#define IQANALYZEPLOT_H

#include <QWidget>
#include "XxwCustomPlot.h"

QT_BEGIN_NAMESPACE
namespace Ui { class IQAnalyzePlot; }
QT_END_NAMESPACE

class IQAnalyzePlot : public QWidget
{
    Q_OBJECT

public:
    IQAnalyzePlot(QWidget *parent = nullptr);
    ~IQAnalyzePlot();
    void initLayout(void);
    void initRealTimePlot(void);
    void initSpectrumPlot(void);
    void initLofarPlot(void);
    void initConstellationPlot(void);
    void initAllPlots(void);
private:
    Ui::IQAnalyzePlot *ui;
    XxwCustomPlot   *pRealTimePlot;
    XxwCustomPlot   *pSpectrumPlot;
    XxwCustomPlot   *pLofarPlot;
    XxwCustomPlot   *pConstellationPlot;
    QCPColorMap     *pColorMap;
};
#endif // IQANALYZEPLOT_H
