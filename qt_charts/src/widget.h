#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets>
#include <QtCharts>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);

    void loadData();

private:
    QtCharts::QChartView *chartView;
    QtCharts::QBarSeries *barSeries;
};

#endif // WIDGET_H
