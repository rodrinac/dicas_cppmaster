#include "widget.h"
#include <QApplication>

QWidget *setup()
{
    auto w = new Widget();

    w->setWindowTitle("Boletim da Turma");

    w->resize(650, 400);

    return w;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    setup()->show();

    return a.exec();
}
