#ifndef COMIDA_H
#define COMIDA_H

#include <QGraphicsItem>
#include <QPainter>
class Comida:public QGraphicsItem
{
private:
    int posx,posy,w,h;
    int tipo;
    //0 comida normal
    //1 especial
    //2 aleatoria
public:
    Comida(int x, int y, int _tipo);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr);
    QRectF boundingRect() const;
};

#endif // COMIDA_H
