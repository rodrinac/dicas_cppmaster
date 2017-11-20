#ifndef BALL_HPP
#define BALL_HPP

#include <QPainter>
#include <QRect>

constexpr int WndWidth {1000}, WndHeight {1000};
constexpr int Diameter {40}, Velocity {8};

class Ball final : public QRect
{
public:
    Ball() /* : QRect() */
    {
        int x = qrand() % 801 + 100;
        int y = qrand() % 801 + 100;
        int vx = qrand() % 2? Velocity : -Velocity;
        int vy = qrand() % 2? Velocity : -Velocity;

        setRect(x, y, Diameter, Diameter);

        velocity.setX(vx);
        velocity.setY(vy);
    }

    void update()
    {
        if(left() < 0)
            velocity.setX(Velocity);
        else if(right() > WndWidth)
            velocity.setX(-Velocity);

        if(top() < 0)
            velocity.setY(Velocity);
        else if(bottom() > WndHeight)
            velocity.setY(-Velocity);

        adjust(velocity.x(), velocity.y(), velocity.x(), velocity.y());
    }

    void draw(QPainter &painter) { painter.drawEllipse(* this); }

private:
    QPoint velocity {0, 0};
};

#endif // BALL_HPP
