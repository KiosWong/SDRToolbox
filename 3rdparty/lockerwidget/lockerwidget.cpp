#include "lockerwidget.h"

LockerButton::LockerButton(QWidget* parent)
    : QPushButton(parent)
{
    this->setMinimumWidth(200);
    m_imageLabel = new QLabel;
    m_imageLabel->setFixedWidth(32);
    m_imageLabel->setScaledContents(true);
    m_imageLabel->setStyleSheet("QLabel{background-color:transparent;}");

    m_textLabel = new QLabel;
    m_textLabel->setFixedWidth(200);
    m_textLabel->setStyleSheet("QLabel{color:rgb(50,50,50);background-color:transparent;}");

    QHBoxLayout* mainLayout = new QHBoxLayout;
    mainLayout->addWidget(m_imageLabel);
    mainLayout->addWidget(m_textLabel);
    mainLayout->setMargin(0);
    mainLayout->setSpacing(4);
    this->setLayout(mainLayout);
    isOpen = false;
}

void LockerButton::SetImageLabel(const QPixmap &pixmap)
{
    m_imageLabel->setPixmap(pixmap);
}

void LockerButton::SetTextLabel(QString text)
{
    m_textLabel->setText(text);
}

QLabel* LockerButton::GetImageHandle()
{
    return m_imageLabel;
}

QLabel* LockerButton::GetTextHandle()
{
    return m_textLabel;
}

//==================================================================

LockerWidget::LockerWidget(QWidget* parent) : QWidget(parent)
{
    mainLayout = new QVBoxLayout;
    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);
    this->setLayout(mainLayout);

    scrollArea = new QScrollArea;
    mainLayout->addWidget(scrollArea);

    scrollWidget = new QWidget(this);
    scrollWidget->setMinimumHeight(600);

    layout_widgetScroll = new QVBoxLayout(scrollWidget);
    layout_widgetScroll->setMargin(0);
    layout_widgetScroll->setSpacing(0);

    pixmap_open = QPixmap(OPEN_ICON);
    pixmap_close = QPixmap(CLOSE_ICON);
}
LockerWidget::~LockerWidget()
{
    LockerButton* l = nullptr;
    QWidget* w = nullptr;

    if(Buttons.count()>0) {
        for(int i=0; i<Buttons.count(); ++i) {
            l = Buttons[i];
            if(l != nullptr) {
                delete l;
                l = nullptr;
            }
        }
    }

    if(Widgets.count()>0) {
        for(int i=0; i<Widgets.count(); ++i) {
            w = Widgets[i];
            if(w != nullptr) {
                delete w;
                w = nullptr;
            }
        }
    }
}

void LockerWidget::add_locker(QStringList names,QList<QWidget*> widgets)
{
    if(names.count() != widgets.count()) {
        return;
    }

    for(int i=0; i<names.count(); ++i) {
        m_Button = new LockerButton(this);
        m_Button->SetTextLabel(names[i]);
        m_Button->SetImageLabel(pixmap_close);
        connect(m_Button,&LockerButton::clicked,this,&LockerWidget::slot_btn);

        m_Widget = new QWidget(this);
        m_Widget->setVisible(false);
        QHBoxLayout* layout_widget = new QHBoxLayout(m_Widget);
        layout_widget->setMargin(0);
        layout_widget->setSpacing(0);
        layout_widget->addWidget(widgets[i]);

        Buttons.push_back(m_Button);
        Widgets.push_back(m_Widget);
    }

    deleteAllitemsOfLayout(layout_widgetScroll);
    for(int i=0; i<Buttons.count(); ++i) {
        layout_widgetScroll->addWidget(Buttons[i]);
        layout_widgetScroll->addWidget(Widgets[i]);
    }
    layout_widgetScroll->addStretch();

    scrollArea->setWidget(scrollWidget);
}

void LockerWidget::deleteAllitemsOfLayout(QLayout* layout)
{
    QLayoutItem *child;
    while ((child = layout->takeAt(0)) != nullptr)
    {
        ///setParent为NULL，防止删除之后界面不消失
        if(child->widget())
        {
            child->widget()->setParent(nullptr);
        }
        else if(child->layout())
        {
            deleteAllitemsOfLayout(child->layout());
        }
        delete child;
    }
}

void LockerWidget::slot_btn(bool)
{
    LockerButton *btn = qobject_cast<LockerButton *>(sender());

    int record = -1;
    for(int i=0; i<Buttons.count(); ++i) {
        if(btn == Buttons[i]) {
            record = i;
            break;
        }
    }
    if(record == -1) {
        return;
    }

    btn->isOpen = !btn->isOpen;
    if(btn->isOpen) {   //true
        //切换图标
        btn->SetImageLabel(pixmap_open);

        //显示widget
        Widgets[record]->setVisible(true);

    }else {     //false
        //切换图标
        btn->SetImageLabel(pixmap_close);

        //隐藏widget
        Widgets[record]->setVisible(false);
    }
}
//==================================================================

