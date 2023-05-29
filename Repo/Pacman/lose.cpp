#include "lose.h"
#include "ui_lose.h"

Lose::Lose(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Lose)
{
    ui->setupUi(this);
}

Lose::~Lose()
{
    delete ui;
}

void Lose::on_pushButton_clicked()
{
    close();
}


void Lose::on_pushButton_2_clicked()
{
    qApp->quit();
}

