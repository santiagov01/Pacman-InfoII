#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QList>
#include <QList>
#include <QKeyEvent>
#include "comida.h"
#include "personaje.h"
#include "paredes.h"
#include <QTimer>
#include <QLabel>
#include <QPalette>
#include <QFont>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QMediaPlayer>
#include <QAudioOutput>

#include "win.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool EvaluarColisionParedes();
    void EvaluarComer();

    void Display_Mapa_Inicio();
    void reiniciar();
public slots:
    void actualizarTiempo();
    void aparecer_especial();

signals:
    void comer(int x);

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    QGraphicsView* view;

    QVector<QVector<int>> mapa;
    QList<Paredes*> paredes_total;

    QList<Comida*> comida_normal;
    QList<Comida*> comida_big;
    QList<Comida*> comida_especial;

    Personaje* pacman;

    QAudioOutput* audio;
    double puntuacion;

//    QLabel* display_puntaje;
//    QLabel*  display_time;

    QGraphicsTextItem* display_puntaje;
    QGraphicsTextItem*  display_time;
    //tiempo
    QTimer* temp;
    unsigned short int tiempo;
    //-------
    void keyPressEvent(QKeyEvent *evento);

    //----sonido----
    QMediaPlayer *player;



};
#endif // MAINWINDOW_H
