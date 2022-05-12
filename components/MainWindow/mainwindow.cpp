#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initStyle();
    initLayout();

//    ui->verticalLayout->addWidget(stack);
//    contentVerticalLayout->addWidget(stack);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initStyle()
{
    //加载样式表
    QString qss;
    QFile file(":/qss/psblack.css");
//    QFile file(":/qss/flatwhite.css");
//    QFile file(":/qss/lightblue.css");
    if (file.open(QFile::ReadOnly)) {
#if 1
        //用QTextStream读取样式文件不用区分文件编码 带bom也行
        QStringList list;
        QTextStream in(&file);
        //in.setCodec("utf-8");
        while (!in.atEnd()) {
            QString line;
            in >> line;
            list << line;
        }

        qss = list.join("\n");
#else
        //用readAll读取默认支持的是ANSI格式,如果不小心用creator打开编辑过了很可能打不开
        qss = QLatin1String(file.readAll());
#endif
        QString paletteColor = qss.mid(20, 7);
        qApp->setPalette(QPalette(QColor(paletteColor)));
        qApp->setStyleSheet(qss);
        file.close();
    }
}

void MainWindow::initLayout()
{
    applicationTabs = new QTabWidget(this);
    applicationTabs->setTabsClosable(true);
    applicationTabs->setMovable(true);
    ui->mainGridLayout->addWidget(applicationTabs, 0, 1);
    connect(applicationTabs, SIGNAL(tabCloseRequested(int)), this, SLOT(on_tabCloseClicked(int)));
//    contentVerticalLayout = new QVBoxLayout(applicationTabs);
}

void MainWindow::on_tabCloseClicked(const int& index)
{
    if (index == -1) {
        return;
    }

    QWidget* tabItem = applicationTabs->widget(index);
    // Removes the tab at position index from this stack of widgets.
    // The page widget itself is not deleted.
    applicationTabs->removeTab(index);

    delete(tabItem);
    tabItem = nullptr;
}

void MainWindow::on_appIQAnalyzerPushButton_clicked()
{
    IQVisualizeStack *pIQVisualizeStack = new IQVisualizeStack();
    applicationTabs->addTab(pIQVisualizeStack, "IQ Analyzer");
    applicationTabs->setCurrentIndex(applicationTabs->count() - 1);
}

void MainWindow::on_flexSDRPushButton_clicked()
{
    FlexSDR *pFlexSDR = new FlexSDR();
    applicationTabs->addTab(pFlexSDR, "FlexSDR");
    applicationTabs->setCurrentIndex(applicationTabs->count() - 1);
}
