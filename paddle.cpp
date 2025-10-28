#include <QCursor>
#include <QRect>

#include "paddle.h"
#include "config.h"

Paddle::Paddle() : QRect(   QCursor::pos().x(),
                            VIEW_HEIGHT - RECTANGLE_HEIGHT,
                            RECTANGLE_WIDTH,
                            RECTANGLE_HEIGHT )
{}

void Paddle::adaptPaddleToMouse(const int mouse_pos)
{
    if((mouse_pos < VIEW_WIDTH - RECTANGLE_WIDTH  / 2) && (mouse_pos > RECTANGLE_WIDTH  / 2))
    {
        this->moveTo({mouse_pos - RECTANGLE_WIDTH  / 2, this->y()});
    }
}
