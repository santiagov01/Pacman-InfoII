#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QGraphicsItem>
#include <QPainter>
#include <QObject>
#include <QMovie>
#include <string>
class Personaje: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Personaje(double x, double y);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void mover(int dx, int dy);

    void sprite();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr);
    QRectF boundingRect() const;
    QString path;
    QPixmap *pixmap;
    QTimer *AnimacionTimer;

    //Ya no se están usando las siguientes
    unsigned int getPuntaje() const;
    void setPuntaje(unsigned int newPuntaje);

    //std::map<int, std::string> Imagenes_personaje;


    void reiniciar_pos();
signals:
    void moviendo();
private:
    unsigned short int ancho, alto, columnas;
    double radio, velocidad, posx, posy;
    unsigned int puntaje;
public slots:
     void actualizar_sprite();
};

#endif // PERSONAJE_H
