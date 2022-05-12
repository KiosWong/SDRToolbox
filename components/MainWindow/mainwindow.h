#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "iqvisualizestack.h"
#include "flexsdr.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initStyle(void);
    void initLayout(void);

private:
    Ui::MainWindow *ui;
    QVBoxLayout *contentVerticalLayout;
    QTabWidget *applicationTabs;

public slots:
    void on_tabCloseClicked(const int& index);
private slots:
    void on_appIQAnalyzerPushButton_clicked();
    void on_flexSDRPushButton_clicked();
};
#endif // MAINWINDOW_H
