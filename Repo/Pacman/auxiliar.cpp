#include "auxiliar.h"
#include <QDebug>



void LeerArchivo(QString filename)
{
    QFile file(filename) ;
    if (!file. exists()){
        qCritical() << "File not found";
        return;
    }

    if (!file.open(QIODevice::ReadOnly)){
        qCritical() << file.errorString();
    }
    return;
    QTextStream stream(&file);
    while (!stream.atEnd()){
        QString line = stream.readLine();
        std::cout << line.toStdString()<< std::endl;
    }
    file.close();
}
