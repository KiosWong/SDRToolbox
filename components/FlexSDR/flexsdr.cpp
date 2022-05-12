#include "flexsdr.h"
#include "ui_flexsdr.h"

FlexSDR::FlexSDR(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FlexSDR)
{
    ui->setupUi(this);
    initLayout();
}

FlexSDR::~FlexSDR()
{
    delete ui;
}


void FlexSDR::initLayout()
{

    QMenuBar *m_menuBar = new QMenuBar();

    //添加菜单
    QMenu *fileMenu = m_menuBar->addMenu("File");
    QMenu *settingMenu = m_menuBar->addMenu("Setting");
    QMenu *moveMenu = m_menuBar->addMenu("Move");

    //添加选项
    QAction *newAction = fileMenu->addAction("Load");
    QAction *openAction = fileMenu->addAction("Save");

    QAction *upwardAction = moveMenu->addAction("Move Up");
    QAction *downwardAction = moveMenu->addAction("Move Down");

    pLockerWidget = new LockerWidget();

    //准备好抽屉widget（内部放啥自己布局决定）
    QWidget* widget_Basic = new QWidget(pLockerWidget);                 //基本
    QWidget* widget_Communication = new QWidget(pLockerWidget);         //通信方
    QWidget* widget_Inference = new QWidget(pLockerWidget);             //干扰方
    QWidget* widget_Algorithm = new QWidget(pLockerWidget);             //算法
    QWidget* widget_Variable = new QWidget(pLockerWidget);              //外部变量
    QWidget* widget_Others = new QWidget(pLockerWidget);                //其他

    QGridLayout *m_pBranchDeviceLayout = new QGridLayout();
    m_pBranchDeviceLayout->addWidget(new QPushButton("test"), 0, 0);
    m_pBranchDeviceLayout->addWidget(new QPushButton("test"), 0, 1);
    m_pBranchDeviceLayout->addWidget(new QPushButton("test"), 0, 2);
    m_pBranchDeviceLayout->addWidget(new QPushButton("test"), 1, 0);
    m_pBranchDeviceLayout->addWidget(new QPushButton("test"), 1, 1);
    m_pBranchDeviceLayout->addWidget(new QPushButton("test"), 1, 2);
    m_pBranchDeviceLayout->addWidget(new QPushButton("test"), 2, 0);
    m_pBranchDeviceLayout->addWidget(new QPushButton("test"), 2, 1);
    m_pBranchDeviceLayout->addWidget(new QPushButton("test"), 2, 2);
    widget_Communication->setLayout(m_pBranchDeviceLayout);

    widget_Communication->setLayout(m_pBranchDeviceLayout);


    //准备好抽屉的名字集合、widget集合
    QStringList names;
    names << "basic" << "Coummunication" << "Inference" << "Algorithm" << "Variable" << "Others";

    QList<QWidget*> widgets;
    widgets << widget_Basic << widget_Communication << widget_Inference << widget_Algorithm
            << widget_Variable << widget_Others;

    //向抽屉盒子中添加抽屉
    pLockerWidget->add_locker(names, widgets);
    pLockerWidget->setMaximumWidth(220);

    //工作区控件
    pFlexSpace = new FlexSpace();

    QVBoxLayout *m_pWorkspaceLayout = new QVBoxLayout();
    QScrollArea *pWorkspaceScrollArea = new QScrollArea();
    pWorkspaceFrame = new QFrame(pWorkspaceScrollArea);

    QPalette pal(pWorkspaceScrollArea->palette());
    pal.setColor(QPalette::Background, QColor(240, 240, 240));
    pWorkspaceScrollArea->setPalette(pal);

    QGridLayout *m_pFlexspaceLayout = new QGridLayout();
    m_pFlexspaceLayout->addWidget(pFlexSpace);
    pWorkspaceFrame->setLayout(m_pFlexspaceLayout);

    pFlexSpace->setFixedSize(QSize(3000, 3000));
    pWorkspaceScrollArea->setWidgetResizable(false);
    pWorkspaceScrollArea->setWidget(pWorkspaceFrame);
    m_pWorkspaceLayout->addWidget(pWorkspaceScrollArea);

    ui->mainHorizontalLayout->addWidget(pLockerWidget);
    ui->mainHorizontalLayout->addLayout(m_pWorkspaceLayout);
    ui->mainVerticalLayout->insertWidget(0, m_menuBar);
}
