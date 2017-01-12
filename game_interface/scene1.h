#ifndef SCENE1_H
#define SCENE1_H

#include <QMainWindow>
#include <QMediaPlayer>

namespace Ui {
class scene1;
}

class scene1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit scene1(QWidget *parent = 0);
    ~scene1();
    QMediaPlayer * roar1;
    QMediaPlayer * roar2;
    QMediaPlayer * roar3;
    QMediaPlayer * kick;
    QMediaPlayer * smash;
    QMediaPlayer * hit;
    QMediaPlayer * winn;

private slots:
    void on_pushButton_3_clicked();

    void on_button1_clicked();

    void on_button3_clicked();

    void on_pushButton_clicked(bool checked);

    void on_pushButton_toggled(bool checked);

    void on_pushButton_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::scene1 *ui;
};



#endif // SCENE1_H
