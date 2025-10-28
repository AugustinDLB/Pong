#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QPoint>

#include "config.h"
#include "paddle.h"
#include "ball.h"

class Game : public QWidget
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = nullptr);

private:
    Paddle *playerPaddle;
    Ball   *ball;
    QTimer *timer;

    void updateGame();
    void initializePaddle();
    void handlePaddleCollision();
    void handlePaddleCollisionResponse();
    void checkGameOver();
    void handlePaddleCollisionResponse(double closestX, double closestY);

    void paintEvent(QPaintEvent *event) override
    {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setBrush(Qt::white);

        painter.drawRect(*playerPaddle);
        painter.drawEllipse({ball->getPosX(),ball->getPosY()}, BALL_WIDTH, BALL_WIDTH);
    }

    void mouseMoveEvent(QMouseEvent *event) override
    {
        playerPaddle->adaptPaddleToMouse(event->position().x());
    }
protected:

signals:
    void game_is_finished();

public slots:
    void Start();

};

#endif
