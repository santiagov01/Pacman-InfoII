#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    mapa = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 2, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0},
        {0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 2, 0, 0, 1, 0},
        {0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 5},
        {0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0},
        {0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0},
        {5, 1, 1, 1, 1, 0, 2, 0, 1, 0, 1, 2, 1, 1, 0},
        {0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0},
        {0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 2, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0},
        {0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/pacman1.png"));
    this->setWindowTitle("Pacman");
    view = new QGraphicsView(this);
    scene = new QGraphicsScene(this);
    view->setScene(scene);
    view->setGeometry(0,0,480,1000);
    scene->setSceneRect(0,0,480,1000);
    setCentralWidget(view);


    view->scale(1.2,1.2);
    scene->setBackgroundBrush(Qt::black);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //------cargar elementos del archivo o matriz-----
    //definir dimensiones de matriz;
//    paredes_total.push_back(new Paredes(0,0));
//    scene->addItem(paredes_total.back());
//    paredes_total.push_back(new Paredes(0,32));
//    scene->addItem(paredes_total.back());
//    paredes_total.push_back(new Paredes(0,64));
//    scene->addItem(paredes_total.back());

//    comida_normal.push_back((new Comida(20,20,0)));
//    scene->addItem(comida_normal.back());
//    comida_normal.back()->setPos(32+16,32+16);

//    comida_big.push_back((new Comida(20,20,1)));
//    scene->addItem(comida_big.back());
//    comida_big.back()->setPos(32+16,64+16);
    Display_Mapa_Inicio();

    //-----Crear Pacman-----
    pacman = new Personaje(448-16,64-16);
    scene->addItem(pacman);
    //tiempo
    temp = new QTimer();
    tiempo = 50;
    //-----Conexiones-----
    connect(pacman,&Personaje::moviendo,this,&MainWindow::EvaluarComer);

    //-----variables iniciales----
    puntuacion = 0;

    //------Puntaje en Pantalla-------

//    display_puntaje = new QLabel(this);
//    display_puntaje->setGeometry(300,10,200,200);
//        //Cambiar Color
//    QPalette palette = display_puntaje->palette();
//    palette.setColor(QPalette::WindowText, Qt::white);
//    display_puntaje->setPalette(palette);
//        //poner Texto
//    QString msg = QString("PUNTAJE: %1").arg(puntuacion);
//    display_puntaje->setText(msg);
//        //Definir Fuente
//    QFont font("Gill Sans Ultra Bold Condensed", 20, QFont::Bold);
//    font.setPointSize(20);
//   // Cambiar la fuente del QLabel
//    display_puntaje->setFont(font);
//    scene->addWidget(display_puntaje);
    display_puntaje = new QGraphicsTextItem();
    //definir texto
    QString msg = QString("PUNTAJE: %1").arg(puntuacion);
    display_puntaje->setPlainText(msg);
    //fuente cool

    display_puntaje->setDefaultTextColor(Qt::white);
    QFont font("Gill Sans Ultra Bold Condensed", 20, QFont::Bold);
    font.setPointSize(20);
    display_puntaje->setFont(font);

    scene->addItem(display_puntaje);
    display_puntaje->setPos(300,0);
    //scene->addText(msg);

    //----Temporizador en Pantalla------
    display_time = new QGraphicsTextItem();
    //definir texto
    QString msg2 = QString("TIEMPO RESTANTE: %1").arg(tiempo);
    display_time->setPlainText(msg2);
    //fuente cool
    display_time->setDefaultTextColor(Qt::white);
    QFont font2("Gill Sans Ultra Bold Condensed", 10);
    font2.setPointSize(10);
    display_time->setFont(font2);
    scene->addItem(display_time);
    display_time->setPos(100,10);
    //--Conexion temporizador----
    connect(temp, SIGNAL(timeout()), this, SLOT(actualizarTiempo()));
    temp->start(1000);

    //-----sonido----
    player = new QMediaPlayer();
    QString projectPath = QCoreApplication::applicationDirPath();
    QString path_audio = "qrc:/eat.mp3";
    qDebug() << "URL local del proyecto: " << projectPath;
    player->setSource(QUrl::fromLocalFile(projectPath+path_audio));

    //------Objetos Especiales---------------
    srand(time(NULL));
    QTimer* temp_especial = new QTimer();
    connect(temp_especial, SIGNAL(timeout()),this, SLOT(aparecer_especial()));
    temp_especial->start(5000);
}

MainWindow::~MainWindow()
{
    delete ui;
}
bool MainWindow::EvaluarColisionParedes(){
    QList<Paredes*>::Iterator it;
    for(it = paredes_total.begin();it!=paredes_total.end();++it){
        if((*it)->collidesWithItem(pacman)){
            return true;
        }
    }
    return false;
}

void MainWindow::EvaluarComer()
{
    QList<Comida*>::Iterator it;
    //puntuacion = pacman->getPuntaje();
    for(it = comida_normal.begin();it!=comida_normal.end();++it){
        if((*it)->collidesWithItem(pacman)){
            puntuacion +=100;
            pacman->setPuntaje(puntuacion);
            scene->removeItem(*it);
            comida_normal.erase(it);
            QString msg = QString("PUNTAJE: %1").arg(puntuacion);
            display_puntaje->setPlainText(msg);
            player->play();
            qDebug() << player->errorString();

            break;
        }
    }
    QList<Comida*>::Iterator it2;
    for(it2 = comida_big.begin();it2!=comida_big.end();++it2){
        if((*it2)->collidesWithItem(pacman)){
            puntuacion +=200;
            pacman->setPuntaje(puntuacion);
            scene->removeItem(*it2);
            comida_big.erase(it2);
            QString msg = QString("PUNTAJE: %1").arg(puntuacion);
            display_puntaje->setPlainText(msg);
            player->play();


            break;
        }
    }
    QList<Comida*>::Iterator it3;
    for(it3 = comida_especial.begin();it3!=comida_especial.end();++it3){
        if((*it3)->collidesWithItem(pacman)){
            puntuacion +=500;
            pacman->setPuntaje(puntuacion);
            scene->removeItem(*it3);
            comida_especial.erase(it3);
            //Actualizar el puntaje en pantalla
            QString msg = QString("PUNTAJE: %1").arg(puntuacion);
            display_puntaje->setPlainText(msg);
            player->play();

            break;
        }
    }
}

void MainWindow::Display_Mapa_Inicio()
{
    qreal posx;
    qreal posy;
    for(int n = 0; n< mapa.size(); n++){
        for(int m = 0; m< mapa[0].size();m++){
            posx = m*32;
            posy = n*32;
            switch (mapa.at(n).at(m)) {
            case 2:
                comida_big.push_back((new Comida(20,20,1)));
                scene->addItem(comida_big.back());
                comida_big.back()->setPos(posx+16,posy+16);
                break;
            case 1:

                comida_normal.push_back((new Comida(20,20,0)));
                scene->addItem(comida_normal.back());
                comida_normal.back()->setPos(posx+16,posy+16);
                break;
            case 0:
                paredes_total.push_back(new Paredes(posx,posy));
                scene->addItem(paredes_total.back());
                break;
            default:
                break;
            }
        }

    }
}

void MainWindow::reiniciar()
{
    qreal posx;
    qreal posy;
    tiempo = 50;
    QString msg_time = QString("Tiempo Restante: %1").arg(tiempo);
    display_time->setPlainText(msg_time);
    puntuacion = 0;
    QString msg = QString("PUNTAJE: %1").arg(puntuacion);
    display_puntaje->setPlainText(msg);


    foreach(Comida *obj, comida_big) {
        delete obj;
    }
    comida_big.clear();
    foreach(Comida *obj, comida_normal) {
        delete obj;
    }
    comida_normal.clear();
    for(int n = 0; n< mapa.size(); n++){
        for(int m = 0; m< mapa[0].size();m++){
            posx = m*32;
            posy = n*32;
            switch (mapa.at(n).at(m)) {
            case 2:
                comida_big.push_back((new Comida(20,20,1)));
                scene->addItem(comida_big.back());
                comida_big.back()->setPos(posx+16,posy+16);
                break;
            case 1:

                comida_normal.push_back((new Comida(20,20,0)));
                scene->addItem(comida_normal.back());
                comida_normal.back()->setPos(posx+16,posy+16);
                break;
            default:
                break;
            }
        }
    }

}

void MainWindow::actualizarTiempo()
{
    tiempo--;
    if(tiempo == 0){
        //codigo para reiniciar

        reiniciar();
        pacman->reiniciar_pos();
        //Display_Mapa_Inicio();
    }else{
        QString msg_time = QString("Tiempo Restante: %1").arg(tiempo);
        display_time->setPlainText(msg_time);
    }
}

void MainWindow::aparecer_especial()
{
    // Generar el primer número aleatorio entre 1 y 15
    int numero1 = std::rand() % 14 + 2;

    // Generar el segundo número aleatorio entre 1 y 18
    int numero2 = std::rand() % 17 + 2;
    int numero3 = std::rand() %2;
    if(numero3>1)return;
    comida_especial.push_back((new Comida(20,20,1)));
    scene->addItem(comida_especial.back());
    comida_especial.back()->setPos(numero1*32+16,numero2*32+16);


}


void MainWindow::keyPressEvent(QKeyEvent *evento){
    if(evento->key()==Qt::Key_S){ //arriba
        pacman->moveUp();
        pacman->setRotation(-90);
            if(!EvaluarColisionParedes())
                pacman->moveUp();
            else
                pacman->moveDown();


    }else if(evento->key()==Qt::Key_Z){//abajo
        pacman->moveDown();
        pacman->setRotation(90);
        if(!EvaluarColisionParedes())
            pacman->moveDown();
        else
            pacman->moveUp();
    }else if(evento->key()==Qt::Key_D){//derecha
        pacman->moveRight();
        pacman->setRotation(0);
        if(!EvaluarColisionParedes())
            pacman->moveRight();
        else
            pacman->moveLeft();
    }else if(evento->key()==Qt::Key_A){//izquierda
        pacman->moveLeft();
        pacman->setRotation(-180);
        if(!EvaluarColisionParedes())
            pacman->moveLeft();
        else
            pacman->moveRight();
    }


}
