#include "comida.h"

Comida::Comida(int x, int y, int _tipo)
{
    this->posx = x;
    this->posy = y;
    this->tipo = _tipo;
}

void Comida::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    if(tipo == 0){
        painter->setBrush(Qt::white);
        painter->setPen(Qt::NoPen);
        painter->drawRect(boundingRect());

    }else if(tipo == 1){
        painter->setBrush(Qt::white);
        painter->setPen(Qt::NoPen);
        painter->drawEllipse(boundingRect());
    }else if(tipo == 2){
        QPixmap pixmap(":/especialfood.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
//        painter->setBrush(Qt::red);
//        painter->setPen(Qt::NoPen);
//        painter->drawEllipse(boundingRect());
    }

}

QRectF Comida::boundingRect() const
{
    unsigned short int a_normal = 4;
    unsigned short int a_big = 16, special = 12;
    if(tipo == 0){
        return QRectF(-a_normal/2,-a_normal/2, a_normal, a_normal);//definir tamaño de la comida
    }else if (tipo == 1){
        return QRectF(-a_big/2, -a_big/2, a_big,a_big);
    }else if (tipo == 2){
        return QRectF(-special/2,-special/2,special,special);
    }
    return QRectF(-a_normal/2,-a_normal/2, a_normal, a_normal);
}
