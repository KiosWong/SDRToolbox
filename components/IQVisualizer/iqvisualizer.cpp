#include "iqvisualizer.h"
#include "ui_iqvisualizer.h"

IQVisualizer::IQVisualizer(QWidget *parent,
                           int visualizer_id,
                           QString visualizer_name,
                           int type,
                           QString ip,
                           int port) :
    QMainWindow(parent),
    ui(new Ui::IQVisualizer)
{
    ui->setupUi(this);
    analyzePlot = new IQAnalyzePlot();
    ui->gridLayout->addWidget(analyzePlot);

    QMenuBar *m_menuBar = menuBar();
    setMenuBar(m_menuBar);

    //添加菜单
    QMenu *fileMenu = m_menuBar->addMenu("File");
    QMenu *settingMenu = m_menuBar->addMenu("Setting");
    QMenu *moveMenu = m_menuBar->addMenu("Move");

    //添加选项
    QAction *newAction = fileMenu->addAction("Load");
    QAction *openAction = fileMenu->addAction("Save");

    QAction *upwardAction = moveMenu->addAction("Move Up");
    QAction *downwardAction = moveMenu->addAction("Move Down");

    this->setAutoFillBackground(true);
    is_selected = false;
    this->id = visualizer_id;
    this->name = visualizer_name;
    this->type = type;
    this->ip = ip;
    this->port = port;

}

IQVisualizer::~IQVisualizer()
{
    delete ui;
}

bool IQVisualizer::selected()
{
    return is_selected;
}

void IQVisualizer::mousePressEvent(QMouseEvent *event)
{
  // 如果是鼠标左键按下
  if(event->button() == Qt::LeftButton) {
      qDebug() << "left clicked";
      is_selected = !is_selected;
      if(is_selected) {
        QPalette pal(this->palette());
        pal.setColor(QPalette::Background, QColor(105, 105, 105));
        this->setPalette(pal);
      } else {
          QPalette pal(this->palette());
          pal.setColor(QPalette::Background, QColor(68, 68, 68));
          this->setPalette(pal);
      }
  }
  // 如果是鼠标右键按下
  else if(event->button() == Qt::RightButton) {
     qDebug() << "right clicked";
  }
}
