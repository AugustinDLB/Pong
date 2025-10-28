#include <QTimer>
#include <QPoint>

#include "game.h"
#include "ball.h"
#include "firstmenu.h"
#include "./ui_firstmenu.h"

Game::Game(QWidget *parent) : QWidget(  )
{
    /**** Styles parameters             ****/
    setFixedSize(VIEW_WIDTH, VIEW_HEIGHT);
    setStyleSheet("background-color: black;");

    /**** Timer initialization          ****/
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Game::updateGame);

    /**** Peripherals interactions      ****/
    setMouseTracking(1);
}

void Game::Start()
{
    /**** Parameter initializations     ****/
    ball         = new Ball();
    playerPaddle = new Paddle();
    timer->start(FRAME_DURATION_MS); // 60 FPS
}

void Game::updateGame()
{
    checkGameOver();
    ball->handleWallCollisions();
    handlePaddleCollision();
    ball->move();
    update();
}

void Game::checkGameOver()
{
    if(ball->isOutOfBoundsBottom())
    {
        timer->stop();
        emit game_is_finished();
    }
}

void Game::handlePaddleCollision()
{
    // Point le plus proche de la balle sur la raquette
    double closestX = std::clamp(ball->getPosX(), playerPaddle->left(), playerPaddle->right());
    double closestY = std::clamp(ball->getPosY(), playerPaddle->top(), playerPaddle->bottom());

    double distanceX = abs(closestX - ball->getPosX());
    double distanceY = abs(closestY - ball->getPosY());

    // Collision détectée si la balle touche le rectangle
    if (distanceX <= BALL_WIDTH && distanceY <= BALL_WIDTH) {
        handlePaddleCollisionResponse(closestX, closestY);
    }
}

void Game::handlePaddleCollisionResponse(double closestX, double closestY)
{
    // Collision sur les côtés
    if (closestX == playerPaddle->left() || closestX == playerPaddle->right()) {
        ball->setSpeedX(-ball->getSpeedX());
    }

    // Collision sur le haut/bas
    if (closestY == playerPaddle->top()) {
        ball->setSpeedY(-abs(ball->getSpeedY()));
    }
}
