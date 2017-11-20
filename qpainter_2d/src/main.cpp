#include <QApplication>
#include <QTime>
#include "paintingwindow.h"

QWidget *setup()
{
    static auto wnd = new PaintingWindow();

    qsrand(QTime::currentTime().msec());

    wnd->setWindowTitle("Gráficos 2D com QPainter");

    return wnd;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    setup()->show();

    return a.exec();
}
