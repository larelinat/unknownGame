#include "scene1.h"
#include "ui_scene1.h"
#include <QTimer>


scene1::scene1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::scene1)
{

    ui->setupUi(this);
    ui->centralWidget->showFullScreen();
    QPixmap bkgnd("E:/shit/game_interface/back.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);



    ui->textBrowser->hide();

    ui->pushButton->hide();

    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    ui->pushButton_7->hide();
    ui->pushButton_8->hide();
    ui->pushButton_9->hide();
    ui->pushButton_10->hide();
    ui->pushButton_4->hide();
    ui->pushButton_5->hide();
    ui->pushButton_6->hide();

    ui->progressBar->hide();
    ui->progressBar_2->hide();
}

scene1::~scene1()
{
    delete ui;
}


class enemy{
    public:
    int hp;
    int dmg;

    enemy(){
        hp = 100;
        dmg = 10;
    }

  enemy(int hpin,int dmgin){
      this->hp = hpin;
      this->dmg = dmgin;
  }

};




class you{
    public:
    int hp;
    int dmg;

    you(){
        hp = 100;
        dmg = 10;
    }

  you(int hpin,int dmgin){
      this->hp = hpin;
      this->dmg = dmgin;
  }

};

void scene1::on_button1_clicked()
{


    QPixmap bkgnd("E:/shit/game_interface/back2.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    ui->centralWidget->setPalette(palette);

    ui->progressBar->show();
    ui->progressBar_2->show();


    ui->button1->~QPushButton();
    ui->button2->~QPushButton();
    ui->button3->~QPushButton();
    ui->pushButton->show();
    ui->pushButton_7->hide();

    ui->textBrowser->show();

    ui->pushButton_2->show();
    ui->pushButton_3->show();

    ui->pushButton_8->show();
    ui->pushButton_9->show();
    ui->pushButton_10->show();

    ui->pushButton_4->hide();
    ui->pushButton_5->hide();
    ui->pushButton_6->hide();
}







void scene1::on_pushButton_clicked()
{
    ui->pushButton_4->show();
    ui->pushButton_5->show();
    ui->pushButton_6->show();


    ui->pushButton->hide();
    ui->pushButton_7->show();
}

void scene1::on_pushButton_7_clicked()
{
    ui->pushButton_4->hide();
    ui->pushButton_5->hide();
    ui->pushButton_6->hide();

    ui->pushButton->show();
    ui->pushButton_7->hide();
}

void scene1::on_pushButton_10_clicked()
{
    you a(ui->progressBar->value(), 10);
    enemy b(ui->progressBar_2->value(), 15);
    QString strdmg;
    QString str;
    QEventLoop loop;
    QTimer timer;

    ui->pushButton_8->setDisabled(true);
    ui->pushButton_9->setDisabled(true);
    ui->pushButton_10->setDisabled(true);


    if (b.hp > 0 && a.hp > 0){
    b.hp = b.hp - a.dmg /2;
    if(b.hp <= 0){
         ui->progressBar_2->setValue(0);
    } else {
    ui->progressBar_2->setValue(b.hp);
    }
    strdmg = QString::number(a.dmg /2);

    str = "Вы нанесли противнику " + strdmg + " урона!" ;



    ui->textBrowser->append(str);

    if (b.hp <= 0){

      ui->textBrowser->append("Поздравляю! Вы победили!");
      timer.setInterval(10000);
      connect (&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
      timer.start();
      loop.exec();
      qApp->quit();

  }

       ui->textBrowser->append("Противник думает чем ответить.");
       timer.setInterval(5000); //5 sec
       connect (&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
       timer.start();
       loop.exec();

    a.hp = a.hp - b.dmg;
    if(a.hp <= 0){
         ui->progressBar->setValue(0);
    } else {
    ui->progressBar->setValue(a.hp);
    }
    strdmg = QString::number(b.dmg);

    str = "Противник наносит вам " + strdmg + " урона атакой по корпусу! \n" ;

    ui->textBrowser->append(str);
    ui->pushButton_8->setEnabled(true);
    ui->pushButton_9->setEnabled(true);
    ui->pushButton_10->setEnabled(true);

    if (a.hp <= 0){

     ui->textBrowser->append("Вы проиграли этот бой!");
     timer.setInterval(10000);
     connect (&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
     timer.start();
     loop.exec();
     qApp->quit();

 }
}
}

void scene1::on_pushButton_6_clicked()
{
    qApp->quit();

}

void scene1::on_pushButton_8_clicked()
{
    you a(ui->progressBar->value(), 10);
    enemy b(ui->progressBar_2->value(), 15);
    QString strdmg;
    QString str;
    QEventLoop loop;
    QTimer timer;

    ui->pushButton_8->setDisabled(true);
    ui->pushButton_9->setDisabled(true);
    ui->pushButton_10->setDisabled(true);

    if (b.hp > 0 && a.hp > 0){
    b.hp = b.hp - a.dmg * 2;
    if(b.hp <= 0){
         ui->progressBar_2->setValue(0);
    } else {
    ui->progressBar_2->setValue(b.hp);
    }
    strdmg = QString::number(a.dmg *2);

    str = "Вы нанесли противнику " + strdmg + " урона!" ;



    ui->textBrowser->append(str);

    if (b.hp <= 0){

      ui->textBrowser->append("Поздравляю! Вы победили!");
      timer.setInterval(10000);
      connect (&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
      timer.start();
      loop.exec();
      qApp->quit();

  }

       ui->textBrowser->append("Противник думает чем ответить.");
       timer.setInterval(5000); //5 sec
       connect (&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
       timer.start();
       loop.exec();

    a.hp = a.hp - b.dmg;
    if(a.hp <= 0){
         ui->progressBar->setValue(0);
    } else {
    ui->progressBar->setValue(a.hp);
    }
    strdmg = QString::number(b.dmg);

    str = "Противник наносит вам " + strdmg + " урона атакой по корпусу! \n" ;

    ui->textBrowser->append(str);
    ui->pushButton_8->setEnabled(true);
    ui->pushButton_9->setEnabled(true);
    ui->pushButton_10->setEnabled(true);

    if (a.hp <= 0){

     ui->textBrowser->append("Вы проиграли этот бой!");
     timer.setInterval(10000);
     connect (&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
     timer.start();
     loop.exec();
     qApp->quit();

 }
}
}

void scene1::on_button3_clicked()
{
    qApp->quit();
}

void scene1::on_pushButton_9_clicked()
{
    you a(ui->progressBar->value(), 10);
    enemy b(ui->progressBar_2->value(), 15);
    QString strdmg;
    QString str;
    QEventLoop loop;
    QTimer timer;

    ui->pushButton_8->setDisabled(true);
    ui->pushButton_9->setDisabled(true);
    ui->pushButton_10->setDisabled(true);

    if (b.hp > 0 && a.hp > 0){
    b.hp = b.hp - a.dmg;
    if(b.hp <= 0){
         ui->progressBar_2->setValue(0);
    }else{
    ui->progressBar_2->setValue(b.hp);
    }

    strdmg = QString::number(a.dmg);

    str = "Вы нанесли противнику " + strdmg + " урона!" ;



    ui->textBrowser->append(str);

    if (b.hp <= 0){

      ui->textBrowser->append("Поздравляю! Вы победили!");
      timer.setInterval(10000);
      connect (&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
      timer.start();
      loop.exec();
      qApp->quit();

  }

       ui->textBrowser->append("Противник думает чем ответить.");
       timer.setInterval(5000); //5 sec
       connect (&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
       timer.start();
       loop.exec();

    a.hp = a.hp - b.dmg;
    if(a.hp <= 0){
         ui->progressBar->setValue(0);
    } else
    ui->progressBar->setValue(a.hp);
    }
    strdmg = QString::number(b.dmg);

    str = "Противник наносит вам " + strdmg + " урона атакой по корпусу! \n" ;

    ui->textBrowser->append(str);


    ui->pushButton_8->setEnabled(true);
    ui->pushButton_9->setEnabled(true);
    ui->pushButton_10->setEnabled(true);


    if (a.hp <= 0){

     ui->textBrowser->append("Вы проиграли этот бой!");
     timer.setInterval(10000);
     connect (&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
     timer.start();
     loop.exec();
     qApp->quit();

 }
}

