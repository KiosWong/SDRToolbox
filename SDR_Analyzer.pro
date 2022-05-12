QT      += core gui
QT	+= widgets printsupport
QT	+= serialport
QT	+= network
QT      += opengl       #使用opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += \
    components/MainWindow/      \
    components/IQAnalyzePlot/   \
    components/IQVisualizer/    \
    components/FlexSDR/         \
    3rdparty/xxwcustomplot/     \
    3rdparty/lockerwidget/


SOURCES += \
    3rdparty/lockerwidget/lockerwidget.cpp \
    3rdparty/xxwcustomplot/XxwCustomPlot.cpp \
    3rdparty/xxwcustomplot/XxwTracer.cpp \
    3rdparty/xxwcustomplot/qcustomplot.cpp \
    components/FlexSDR/flexsdr.cpp \
    components/FlexSDR/flexspace.cpp \
    components/IQAnalyzePlot/iqanalyzeplot.cpp \
    components/IQAnalyzePlot/iqvisualizestack.cpp \
    components/IQVisualizer/iqvisualizer.cpp \
    components/MainWindow/mainwindow.cpp \
    main.cpp

HEADERS += \
    3rdparty/lockerwidget/lockerwidget.h \
    3rdparty/xxwcustomplot/XxwCustomPlot.h \
    3rdparty/xxwcustomplot/XxwTracer.h \
    3rdparty/xxwcustomplot/qcustomplot.h \
    components/FlexSDR/flexsdr.h \
    components/FlexSDR/flexspace.h \
    components/IQAnalyzePlot/iqanalyzeplot.h \
    components/IQAnalyzePlot/iqvisualizestack.h \
    components/IQVisualizer/iqvisualizer.h \
    components/MainWindow/mainwindow.h

FORMS += \
    components/FlexSDR/flexsdr.ui \
    components/FlexSDR/flexspace.ui \
    components/IQAnalyzePlot/iqanalyzeplot.ui \
    components/IQAnalyzePlot/iqvisualizestack.ui \
    components/IQVisualizer/iqvisualizer.ui \
    components/MainWindow/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource/qss.qrc
