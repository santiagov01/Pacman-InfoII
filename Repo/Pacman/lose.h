#ifndef LOSE_H
#define LOSE_H

#include <QDialog>

namespace Ui {
class Lose;
}

class Lose : public QDialog
{
    Q_OBJECT

public:
    explicit Lose(QWidget *parent = nullptr);
    ~Lose();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Lose *ui;
};

#endif // LOSE_H
