#ifndef BALL_H
#define BALL_H

class Ball
{
public:
    Ball();
    void move();
    int getPosX() const;
    int getPosY() const;
    int getSpeedX() const;
    int getSpeedY() const;
    void setSpeedX(const int newSpeedX);
    void setSpeedY(const int newSpeedY);
    void handleWallCollisions();
    bool isOutOfBoundsBottom() const;
private:
    QPoint pos;
    QPoint speed;
};

#endif // BALL_H
