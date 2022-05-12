#include "iqvisualizestack.h"
#include "ui_iqvisualizestack.h"

IQVisualizeStack::IQVisualizeStack(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IQVisualizeStack)
{
    ui->setupUi(this);
    initLayout();
}

IQVisualizeStack::~IQVisualizeStack()
{
    delete ui;
}

void IQVisualizeStack::initLayout()
{

    ui->analyzePlotScrollArea->setWidgetResizable(true);
    QFrame *m_pModeFrame = new QFrame(ui->analyzePlotScrollArea);
    ui->analyzePlotScrollArea->setWidget(m_pModeFrame);
    m_pStackVerticalLayout = new QVBoxLayout(m_pModeFrame);

}

void IQVisualizeStack::addVisulazer()
{
    IQVisualizer *pVisualizer = new IQVisualizer();
    visualizerList.append(pVisualizer);
    m_pStackVerticalLayout->addWidget(pVisualizer);
}

void IQVisualizeStack::on_addVisualizerPushButton_clicked()
{
    addVisulazer();
}

void IQVisualizeStack::on_deleteVisualizerPushButton_clicked()
{
    int original_length = visualizerList.length();
    for(int i = 0; i < original_length; i++) {
        for(int idx = 0; idx < visualizerList.length(); idx++) {
            IQVisualizer *pVisualizer = visualizerList.at(idx);
            if(pVisualizer->selected()) {
                visualizerList.remove(idx);
                delete pVisualizer;
            }
        }
    }
}
