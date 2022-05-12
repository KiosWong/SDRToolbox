#ifndef FLEXSPACE_H
#define FLEXSPACE_H

#include <QWidget>
#include <QPen>
#include <QPainter>
#include <QMouseEvent>

namespace Ui {
class FlexSpace;
}

class FlexSpace : public QWidget
{
    Q_OBJECT

    enum {
        RELEASED = 0,
        PRESSED,
        MOVING
    };
public:
    explicit FlexSpace(QWidget *parent = nullptr, int height = 3000, int width = 3000);
    ~FlexSpace();

    void paintBackground(void);

private:
    QSize spaceSize;
    Ui::FlexSpace *ui;

    void paintSelectRect(void);

    int gridSize;
    int mouseStatus;
    QPoint selectStartPoint;
    QPoint selectEndPoint;

protected:
    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
};

#endif // FLEXSPACE_H
