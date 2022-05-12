#include "flexspace.h"
#include "ui_flexspace.h"

FlexSpace::FlexSpace(QWidget *parent, int height, int width) :
    QWidget(parent),
    ui(new Ui::FlexSpace)
{
    ui->setupUi(this);
    spaceSize.setHeight(height);
    spaceSize.setWidth(width);

    gridSize = 50;
    mouseStatus = RELEASED;
    paintBackground();

}

FlexSpace::~FlexSpace()
{
    delete ui;
}

void FlexSpace::paintBackground()
{

}

void FlexSpace::paintEvent(QPaintEvent* e)
{
    QPainter p(this);
    QPen pen;
   //实线
    pen.setStyle(Qt::DotLine);
    //线粗
    pen.setWidth(1);
    //线刷子
    pen.setBrush(QColor(210, 210, 210));
    //结尾端样式
    pen.setCapStyle(Qt::RoundCap);

    //连接处样式
    pen.setJoinStyle(Qt::RoundJoin);

    p.setPen(pen);
    for(int i = 0; i < spaceSize.height() / gridSize; i++) {
        p.drawLine(QLine(0, (i * gridSize), spaceSize.width(), (i * gridSize)));
    }

    for(int i = 0; i < spaceSize.width() / gridSize; i++) {
        p.drawLine(QLine((i * gridSize), 0, (i * gridSize), spaceSize.width()));
    }

    if(mouseStatus == MOVING) {
        paintSelectRect();
    }
}

void FlexSpace::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton) {
        if(mouseStatus == RELEASED) {
            selectStartPoint = event->pos();
            mouseStatus = PRESSED;
        }
    }
}

void FlexSpace::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() == Qt::LeftButton){
        if(mouseStatus == PRESSED){
           mouseStatus = MOVING;
        }
        if(mouseStatus == MOVING) {
            selectEndPoint = event->pos();
            update();
        }
    }
}

void FlexSpace::mouseReleaseEvent(QMouseEvent *event)
{
    selectEndPoint = QPoint(0,0);
    selectStartPoint = QPoint(0,0);
    update();
    mouseStatus = RELEASED;


}

void FlexSpace::paintSelectRect()
{
    QPainter p(this);
    QPen pen;
   //实线
    pen.setStyle(Qt::SolidLine);
    //线粗
    pen.setWidth(2);
    //线刷子
    pen.setBrush(QColor(200, 200, 200));
    //结尾端样式
    pen.setCapStyle(Qt::RoundCap);

    //连接处样式
    pen.setJoinStyle(Qt::RoundJoin);
    p.setPen(pen);
    p.drawRect(QRect(selectStartPoint, selectEndPoint));

}




