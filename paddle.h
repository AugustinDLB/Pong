#ifndef PADDLE_H
#define PADDLE_H

#include <QRect>


class Paddle : public QRect
{
public:
    Paddle();
    void adaptPaddleToMouse(const int mouse_pos);

signals:
    void updateGame();
};

#endif // PADDLE_H
