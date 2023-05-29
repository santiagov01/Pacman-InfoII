#include "win.h"
#include "ui_win.h"

Win::Win(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Win)
{
    ui->setupUi(this);
}

Win::~Win()
{
    delete ui;
}

void Win::on_pushButton_clicked()
{
    qApp->quit();
}


void Win::on_pushButton_2_clicked()
{
    close();
}

