#include <QPoint>

#include "ball.h"
#include "config.h"

Ball::Ball()
{
    pos    = {VIEW_WIDTH / 2 , VIEW_HEIGHT / 2};
    speed  = {INITIAL_SPEED_X, INITIAL_SPEED_Y};
}

void Ball::move()
{
    pos += speed;
}

int Ball::getPosX() const
{
    return pos.x();
}

int Ball::getPosY() const
{
    return pos.y();
}

int Ball::getSpeedX() const
{
    return speed.x();
}

int Ball::getSpeedY() const
{
    return speed.y();
}

void Ball::setSpeedX(const int newSpeedX)
{
    speed.setX(newSpeedX);
}

void Ball::setSpeedY(const int newSpeedY)
{
    speed.setY(newSpeedY);
}

void Ball::handleWallCollisions()
{
    /* Ball collides with right of left wall */
    if (getPosX() - BALL_WIDTH <= 0 || getPosX() + BALL_WIDTH >= VIEW_WIDTH) {
        setSpeedX(-getSpeedX());
    }

    /* Ball collides with top wall */
    if (getPosY() - BALL_WIDTH <= 0) {
        setSpeedY(abs(getSpeedY())); // Rebond vers le bas
    }
}

bool Ball::isOutOfBoundsBottom() const
{
    return getPosY() + BALL_WIDTH >= VIEW_HEIGHT;
}

