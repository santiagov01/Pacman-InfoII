#ifndef PAREDES_H
#define PAREDES_H

#include <QGraphicsItem>
#include <QPainter>
class Paredes:public QGraphicsItem
{
    int posx,posy,w,h;

public:
    Paredes();
    Paredes(int x,int y,int w, int h);
    Paredes(int x,int y);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr);
    QRectF boundingRect() const;
};


#endif // PAREDES_H
