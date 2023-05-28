#include "paredes.h".h"

#include <QGraphicsItem>
Paredes::Paredes()
{

}

Paredes::Paredes(int x, int y, int w, int h)
{
    this->posx = x;
    this->posy = y;
    this->w = w;
    this->h = h;
}
Paredes::Paredes(int x, int y)
{
    this->posx = x;
    this->posy = y;
    this->w = 32;
    this->h = 32;
}
void Paredes::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::blue);
    painter->setPen(Qt::NoPen);
    painter->drawRect(boundingRect());
}

QRectF Paredes::boundingRect() const
{
    return QRectF(posx, posy, w,h);
}
