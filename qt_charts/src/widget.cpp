#include "widget.h"

#include <QSqlDatabase>
#include <QSqlQuery>

using namespace QtCharts;

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    auto layout = new QBoxLayout(QBoxLayout::LeftToRight, this);

    chartView  = new QChartView();
    barSeries  = new QBarSeries(this);
    auto axisY = new QValueAxis(this);
    auto axisX = new QBarCategoryAxis(this);

    axisX->append(QStringList {"Nota 1", "Nota 2", "Nota 3", "Nota 4", "Média"});
    axisY->setTickCount(5);
    axisY->setRange(0.0, 10.0);
    axisY->setLabelFormat("%.2f");

    chartView->chart()->setAxisX(axisX);
    chartView->chart()->setAxisY(axisY);

    loadData();

    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->chart()->setTitle("<h2>Boletim Geral</h2>");
    chartView->chart()->addSeries(barSeries);
    chartView->chart()->legend()->setAlignment(Qt::AlignBottom);
    chartView->chart()->legend()->setFont(QFont("Arial", 9));

    layout->addWidget(chartView);
}

void Widget::loadData()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("localhost");
    db.setUserName("root");
    db.setDatabaseName("escola");

    Q_ASSERT(db.open());

    QSqlQuery query("SELECT * FROM aluno", db);

    Q_ASSERT(query.exec());

    while(query.next()) {
        double nota1 = query.value("nota1").toDouble();
        double nota2 = query.value("nota2").toDouble();
        double nota3 = query.value("nota3").toDouble();
        double nota4 = query.value("nota4").toDouble();

        auto barSet = new QBarSet(query.value("nome").toString(), this);

        *barSet << nota1 << nota2 << nota3 << nota4 << (nota1 + nota2 + nota3 + nota4) / 4;

        barSeries->append(barSet);
    }
}
