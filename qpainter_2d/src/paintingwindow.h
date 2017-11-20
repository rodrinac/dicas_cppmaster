#ifndef PAINTINGWINDOW_HXX
#define PAINTINGWINDOW_HXX

#include <QWidget>
#include <QVector>
#include "ball.hpp"

class PaintingWindow : public QWidget
{
    Q_OBJECT

public:
    PaintingWindow(QWidget *parent = nullptr);

private:
    QVector<Ball> balls;

    // QObject interface
protected:
    void timerEvent(QTimerEvent *) override;

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *) override;
};

#endif // PAINTINGWINDOW_HXX
