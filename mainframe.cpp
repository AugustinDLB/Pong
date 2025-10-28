#include <QPainter>

#include "mainframe.h"

MainFrame::MainFrame(QWidget *parent)
    : QWidget{parent}
{
    setFixedSize(300, 300);

    ball_pos = QPoint(400, 300);  // Position initiale de la balle (au centre)
    ball_speed = QPoint(3, 3);    // Vitesse initiale de la balle
}
