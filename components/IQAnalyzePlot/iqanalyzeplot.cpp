#include "iqanalyzeplot.h"
#include "ui_iqanalyzeplot.h"

IQAnalyzePlot::IQAnalyzePlot(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::IQAnalyzePlot)
{
    ui->setupUi(this);
    initAllPlots();

    this->setMinimumHeight(400);
}

IQAnalyzePlot::~IQAnalyzePlot()
{
    delete ui;
}

void IQAnalyzePlot::initAllPlots()
{
    initRealTimePlot();
    initSpectrumPlot();
    initLofarPlot();
    initConstellationPlot();
}

void IQAnalyzePlot::initRealTimePlot()
{
    pRealTimePlot = ui->realTimePlot; //创建一个画图指针
    pRealTimePlot->setBackground(Qt::black);
    pRealTimePlot->plotLayout()->insertRow(0);
    QCPTextElement *m_title = new QCPTextElement(pRealTimePlot, "Real Time Plot", QFont("Arial", 12, QFont::Normal));
    m_title->setTextColor(Qt::white);
    pRealTimePlot->plotLayout()->addElement(0, 0, m_title);
    pRealTimePlot->xAxis->setLabel("Time/ms");
    pRealTimePlot->yAxis->setLabel("Scale/mV");

    pRealTimePlot->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom);//可拖拽+可滚轮缩放
    pRealTimePlot->rescaleAxes();//自适应大小
    pRealTimePlot->showTracer(true);

    pRealTimePlot->xAxis->setLabelColor(QColor(255, 255, 255));
    pRealTimePlot->xAxis->setTickLabelColor(QColor(255, 255, 255));

    pRealTimePlot->yAxis->setLabelColor(QColor(255, 255, 255));
    pRealTimePlot->yAxis->setTickLabelColor(QColor(255, 255, 255));

    QPen pen = pRealTimePlot->xAxis->basePen();
    pen.setColor(QColor(0, 132, 114));

    pRealTimePlot->xAxis->setBasePen(pen);
    pRealTimePlot->xAxis->setTickPen(pen);
    pRealTimePlot->xAxis->setSubTickPen(pen);
    pRealTimePlot->yAxis->setBasePen(pen);
    pRealTimePlot->yAxis->setTickPen(pen);
    pRealTimePlot->yAxis->setSubTickPen(pen);
    QPen gridPen = QPen(QColor(0, 132, 114), 0, Qt::DotLine);
    pRealTimePlot->xAxis->grid()->setPen(gridPen);
    pRealTimePlot->yAxis->grid()->setPen(gridPen);

    pRealTimePlot->legend->setVisible(true); //设置可见
    pRealTimePlot->legend->setBrush(QColor(255, 255, 255, 120));
    pRealTimePlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop | Qt::AlignRight);//设置位置
    pRealTimePlot->legend->setBorderPen(Qt::NoPen); //边框隐藏

    pRealTimePlot->addGraph();
    pRealTimePlot->graph(0)->setName(QString::fromLocal8Bit("I"));
    pRealTimePlot->graph(0)->setPen(QPen(Qt::green, 2));

    pRealTimePlot->addGraph();
    pRealTimePlot->graph(1)->setName(QString::fromLocal8Bit("Q"));
    pRealTimePlot->graph(1)->setPen(QPen(Qt::yellow, 2));

    pRealTimePlot->replot();
}

void IQAnalyzePlot::initSpectrumPlot()
{
    pSpectrumPlot = ui->spectrumPlot; //创建一个画图指针
    pSpectrumPlot->setBackground(Qt::black);
    pSpectrumPlot->plotLayout()->insertRow(0);
    QCPTextElement *m_title = new QCPTextElement(pSpectrumPlot, "Spectrum Plot", QFont("Arial", 12, QFont::Normal));
    m_title->setTextColor(Qt::white);
    pSpectrumPlot->plotLayout()->addElement(0, 0, m_title);
    pSpectrumPlot->xAxis->setLabel("Frequency/MHz");
    pSpectrumPlot->yAxis->setLabel("Scale");

    pSpectrumPlot->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom);//可拖拽+可滚轮缩放
    pSpectrumPlot->rescaleAxes();//自适应大小
    pSpectrumPlot->showTracer(true);

    pSpectrumPlot->xAxis->setLabelColor(QColor(255, 255, 255));
    pSpectrumPlot->xAxis->setTickLabelColor(QColor(255, 255, 255));

    pSpectrumPlot->yAxis->setLabelColor(QColor(255, 255, 255));
    pSpectrumPlot->yAxis->setTickLabelColor(QColor(255, 255, 255));

    QPen pen = pSpectrumPlot->xAxis->basePen();
    pen.setColor(QColor(0, 132, 114));

    pSpectrumPlot->xAxis->setBasePen(pen);
    pSpectrumPlot->xAxis->setTickPen(pen);
    pSpectrumPlot->xAxis->setSubTickPen(pen);
    pSpectrumPlot->yAxis->setBasePen(pen);
    pSpectrumPlot->yAxis->setTickPen(pen);
    pSpectrumPlot->yAxis->setSubTickPen(pen);
    QPen gridPen = QPen(QColor(0, 132, 114), 0, Qt::DotLine);
    pSpectrumPlot->xAxis->grid()->setPen(gridPen);
    pSpectrumPlot->yAxis->grid()->setPen(gridPen);

    pSpectrumPlot->legend->setVisible(true); //设置可见
    pSpectrumPlot->legend->setBrush(QColor(255, 255, 255, 120));
    pSpectrumPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop | Qt::AlignRight);//设置位置
    pSpectrumPlot->legend->setBorderPen(Qt::NoPen); //边框隐藏
//    pSpectrumPlot->legend->addElement(0, 0, pSpectrumPlot->legend->item(i));

    pSpectrumPlot->addGraph();
    pSpectrumPlot->graph(0)->setName(QString::fromLocal8Bit("Real Time"));
    pSpectrumPlot->graph(0)->setPen(QPen(Qt::green, 2));

    pSpectrumPlot->addGraph();
    pSpectrumPlot->graph(1)->setName(QString::fromLocal8Bit("Maximum"));
    pSpectrumPlot->graph(1)->setPen(QPen(Qt::red, 2));

    pSpectrumPlot->addGraph();
    pSpectrumPlot->graph(2)->setName(QString::fromLocal8Bit("Mininum"));
    pSpectrumPlot->graph(2)->setPen(QPen(Qt::blue, 2));

    pSpectrumPlot->replot();
}

void IQAnalyzePlot::initLofarPlot()
{
    pLofarPlot = ui->lofarPlot; //创建一个画图指针
    pLofarPlot->setBackground(Qt::black);
    pLofarPlot->plotLayout()->insertRow(0);
    QCPTextElement *m_title = new QCPTextElement(pLofarPlot, "Lofar Plot", QFont("Arial", 12, QFont::Normal));
    m_title->setTextColor(Qt::white);
    pLofarPlot->plotLayout()->addElement(0, 0, m_title);
    pLofarPlot->xAxis->setLabel("Frequency/MHz");
    pLofarPlot->yAxis->setLabel("Time");
    pLofarPlot->yAxis->setSubTicks(false);
    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%h:%m:%s %z");
    pLofarPlot->yAxis->setTicker(timeTicker);

//    pLofarPlot->showTracer(true);
//    pLofarPlot->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom);//可拖拽+可滚轮缩放
    pColorMap = new QCPColorMap(pLofarPlot->xAxis,pLofarPlot->yAxis);
    pColorMap->data()->setSize(1024 + 1, 51);//设置整个图（x,y）点数

    QCPColorScale *pColorScale = new QCPColorScale(pLofarPlot);
    pColorScale->setType(QCPAxis::atRight  );   // 水平显示atLeft,atRight,atTop,atBottom

    pLofarPlot->plotLayout()->addElement(1, 1, pColorScale); // 在颜色图右边显示
    pColorScale->setDataRange(QCPRange(-60.0, 120.0));  //设置色条的数值最大最小
    pColorScale->axis()->setTickLabelColor(Qt::white);
    pColorMap->setColorScale(pColorScale);

    pColorMap->setGradient(QCPColorGradient::gpSpectrum);//设置默认渐进色变化（可在QCPColorGradient中查看）
    pColorMap->rescaleDataRange(true);

   // 立即刷新图像
    pLofarPlot->rescaleAxes();//自适应大小

    pLofarPlot->xAxis->setLabelColor(QColor(255, 255, 255));
    pLofarPlot->xAxis->setTickLabelColor(QColor(255, 255, 255));

    pLofarPlot->yAxis->setLabelColor(QColor(255, 255, 255));
    pLofarPlot->yAxis->setTickLabelColor(QColor(255, 255, 255));

    QPen pen = pLofarPlot->xAxis->basePen();
    pen.setColor(QColor(0, 132, 114));

    pLofarPlot->xAxis->setBasePen(pen);
    pLofarPlot->xAxis->setTickPen(pen);
    pLofarPlot->xAxis->setSubTickPen(pen);
    pLofarPlot->yAxis->setBasePen(pen);
    pLofarPlot->yAxis->setTickPen(pen);
    pLofarPlot->yAxis->setSubTickPen(pen);

    pLofarPlot->replot();
}

void IQAnalyzePlot::initConstellationPlot()
{
    pConstellationPlot = ui->constellationPlot; //创建一个画图指针
    pConstellationPlot->setBackground(Qt::black);
    pConstellationPlot->plotLayout()->insertRow(0);
    QCPTextElement *m_title = new QCPTextElement(pConstellationPlot, "Constellation Plot", QFont("Arial", 12, QFont::Normal));
    m_title->setTextColor(Qt::white);
    pConstellationPlot->plotLayout()->addElement(0, 0, m_title);
    pConstellationPlot->xAxis->setLabel("I");
    pConstellationPlot->yAxis->setLabel("Q");

    pConstellationPlot->setInteractions(QCP::iRangeZoom);//可拖拽+可滚轮缩放
    pConstellationPlot->rescaleAxes();//自适应大小
    pConstellationPlot->showTracer(true);

    pConstellationPlot->xAxis->setLabelColor(QColor(255, 255, 255));
    pConstellationPlot->xAxis->setTickLabelColor(QColor(255, 255, 255));

    pConstellationPlot->yAxis->setLabelColor(QColor(255, 255, 255));
    pConstellationPlot->yAxis->setTickLabelColor(QColor(255, 255, 255));

    QPen pen = pConstellationPlot->xAxis->basePen();
    pen.setColor(QColor(0, 132, 114));

    pConstellationPlot->xAxis->setBasePen(pen);
    pConstellationPlot->xAxis2->setBasePen(pen);
    pConstellationPlot->yAxis->setBasePen(pen);
    pConstellationPlot->yAxis2->setBasePen(pen);
    pConstellationPlot->xAxis->setTickPen(pen);
    pConstellationPlot->xAxis->setSubTickPen(pen);
    pConstellationPlot->yAxis->setTickPen(pen);
    pConstellationPlot->yAxis->setSubTickPen(pen);
    pConstellationPlot->xAxis->grid()->setPen(Qt::NoPen);
    pConstellationPlot->yAxis->grid()->setPen(Qt::NoPen);
    pConstellationPlot->xAxis->setRange(-1,1);
    pConstellationPlot->yAxis->setRange(-1,1);

    pConstellationPlot->replot();
}

