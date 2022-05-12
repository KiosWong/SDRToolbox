#ifndef LOCKERWIDGET_H
#define LOCKERWIDGET_H

#include <QWidget>
#include <QToolButton>
#include <QLabel>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QDebug>
#include <QPixmap>
#include <QHBoxLayout>
#include <QMenu>
#include <QMenuBar>

#define OPEN_ICON ":/images/Boxopen.png"
#define CLOSE_ICON ":/images/Boxclose.png"

class LockerButton : public QPushButton
{
    Q_OBJECT
public:
    explicit LockerButton(QWidget* parent = nullptr);

    void SetImageLabel(const QPixmap &pixmap);
    void SetTextLabel(QString text);
    QLabel* GetImageHandle();
    QLabel* GetTextHandle();

    bool isOpen;

private:
    // 按钮图标
    QLabel* m_imageLabel;
    // 按钮文字
    QLabel* m_textLabel;
};
//==================================================================
class LockerWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LockerWidget(QWidget* parent = nullptr);
    ~LockerWidget();
    void add_locker(QStringList names,QList<QWidget*> widgets);
    void deleteAllitemsOfLayout(QLayout* layout);

    QScrollArea* get_scrollArea() const
    {
        return this->scrollArea;
    }
    QWidget* get_scrollWidget() const
    {
        return this->scrollWidget;
    }

private:
    void SetUpUI();
    QVBoxLayout* mainLayout;
    QVBoxLayout* layout_widgetScroll;

    LockerButton* m_Button;
    QWidget* m_Widget;
    QList<LockerButton*> Buttons;
    QList<QWidget*> Widgets;

    QScrollArea* scrollArea;
    QWidget* scrollWidget;

    QPixmap pixmap_open;
    QPixmap pixmap_close;

public slots:
    void slot_btn(bool);
};

#endif // LOCKERWIDGET_H

