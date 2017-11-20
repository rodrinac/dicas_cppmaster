#include "paintingwindow.h"

PaintingWindow::PaintingWindow(QWidget *parent)
    : QWidget(parent)
{
    balls.resize(30);

    /**
     * @brief startTimer
     * @abstract // inicia um timer que chamará
     * <code>timerEvent(QTimerEvent *)</code> a cada 30 milllisegundos
     */
    startTimer(20);
    // 16msecs ~== 60fps
    // 20msecs == 50fps
    // 30msecs == 30fps
}

void PaintingWindow::timerEvent(QTimerEvent *)
{
    for(Ball &b : balls) b.update();

    /**
     * @brief update
     * @abstract Prepara a janela para ser repintada e chama
     * <code>paintEvent(QPaintEvent *)</code>
     */
    update();
}

void PaintingWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.setWindow(0, 0, WndWidth, WndHeight);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(Qt::red, 3.0));
    painter.setBrush(Qt::green);

    for(Ball &b : balls) b.draw(painter);
}
