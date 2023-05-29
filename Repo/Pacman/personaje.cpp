#include "personaje.h"
#include "qtimer.h"

Personaje::Personaje(double x, double y)
{
    //pixmap = new QPixmap(":/pacman1.png");
    pixmap=new QPixmap();

//    Cargar_imagen(path,&Imagenes_personaje);
//    this->path = ":/pacman-sprite.png";
    this->posx=x;
    this->posy = y;
    this->puntaje = 0;
    this->velocidad = 8;
    this->columnas = 2;
    this->ancho = 19;
    this->alto = 20;
    setPos(posx,posy);
    AnimacionTimer=new QTimer();
    AnimacionTimer->start(200);
    connect(AnimacionTimer,&QTimer::timeout,this,&Personaje::actualizar_sprite);

}

void Personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget){

    //painter->drawPixmap(boundingRect(),*pixmap,pixmap->rect());
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->drawPixmap(-ancho/2,-alto/2, *pixmap,columnas,0,ancho,alto);

}
QRectF Personaje::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

unsigned int Personaje::getPuntaje() const
{
    return puntaje;
}

void Personaje::setPuntaje(unsigned int newPuntaje)
{
    puntaje = newPuntaje;
}

void Personaje::reiniciar_pos()
{
    posx = 288-16;
    posy = 256-16;
    setPos(posx,posy);
}

void Personaje::moveUp()
{
    posy -= velocidad;
    setPos(posx, posy);
    sprite();
    emit moviendo();
    //this->setRotation(-90);
}

void Personaje::moveDown()
{
    posy += velocidad;
    setPos(posx, posy);
    sprite();
    emit moviendo();
    //this->setRotation(90);
}

void Personaje::moveLeft()
{
    posx =posx- velocidad;
    if(posx<0){
        posx = 480-8;
        posy = 192-16;
    }
    setPos(posx, posy);
    sprite();
    emit moviendo();
    //this->setRotation(180);
}

void Personaje::moveRight()
{
    posx += velocidad;
    //setPos(posx, posy);

    if(posx> 480-16){
        posx = 8;
        posy = 320-16;
    }
    setPos(posx, posy);
    sprite();
    emit moviendo();
    //this->setRotation(0);
}

void Personaje::sprite()
{
    pixmap->load(":/pacman-sprite.png");

}

void Personaje::actualizar_sprite(){
    columnas+=ancho;
    if (columnas>=pixmap->size().width()) columnas=0;
    this->update(-ancho/2,-alto/2,ancho,alto);
}
