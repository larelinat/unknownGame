#include "scene1.h"
#include "ui_scene1.h"
#include <QTimer>
#include <QUrl>
#include <QMediaPlayer>
#include <ctime>



scene1::scene1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::scene1)
{
    ui->setupUi(this);
    ui->centralWidget->showFullScreen();
    QPixmap bkgnd(":/pic/back.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    winn = new QMediaPlayer;
    winn->setMedia(QUrl("qrc:/sound/win.wav"));
    hit = new QMediaPlayer;
    hit->setMedia(QUrl("qrc:/sound/hit.wav"));
    kick = new QMediaPlayer;
    kick->setMedia(QUrl("qrc:/sound/kick.wav"));
    smash = new QMediaPlayer;
    smash->setMedia(QUrl("qrc:/sound/smash.wav"));
    roar1 = new QMediaPlayer;
    roar1->setMedia(QUrl("qrc:/sound/bear1.wav"));
    roar2 = new QMediaPlayer;
    roar2->setMedia(QUrl("qrc:/sound/bear2.wav"));
    roar3 = new QMediaPlayer;
    roar3->setMedia(QUrl("qrc:/sound/bear3.wav"));
    click = new QMediaPlayer;
    click->setMedia(QUrl("qrc:/sound/click.wav"));
    click->setVolume(15);


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

void scene1::on_pushButton_3_clicked()  {
    you a(ui->progressBar_2->value(), 10);
    a.hp = a.hp + 20;
    ui->progressBar->setValue(a.hp);
    ui->pushButton_3->hide();
}

void scene1::on_button1_clicked()
{
    click->play();

    QPixmap bkgnd(":/pic/back2.png");
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
    click->play();
    ui->pushButton_4->show();
    ui->pushButton_5->show();
    ui->pushButton_6->show();


    ui->pushButton->hide();
    ui->pushButton_7->show();
}

void scene1::on_pushButton_7_clicked()
{
    click->play();
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
    int i;

    srand(time(0));

    ui->pushButton_8->setDisabled(true);
    ui->pushButton_9->setDisabled(true);
    ui->pushButton_10->setDisabled(true);

    i = (rand() % 5 - 2);
    if (b.hp > 0 && a.hp > 0){
    b.hp = b.hp - (a.dmg /2 + i);
    if(b.hp <= 0){
         ui->progressBar_2->setValue(0);
    } else {
    ui->progressBar_2->setValue(b.hp);
    }
    strdmg = QString::number(a.dmg /2 + i);
    hit->play();
    str = "Вы нанесли противнику " + strdmg + " урона!" ;



    ui->textBrowser->append(str);

    if (b.hp <= 0){
      winn->play();
      ui->textBrowser->append("Поздравляю! Вы победили!");
      timer.setInterval(10000);
      connect (&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
      timer.start();
      loop.exec();
      qApp->quit();

  }

       ui->textBrowser->append("Противник думает чем ответить.");
       timer.setInterval(3000); //5 sec

       connect (&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
       timer.start();
       loop.exec();

    srand(time(0));
    i = (rand() % 5 - 2);
    a.hp = a.hp - (b.dmg + i);
    if(a.hp <= 0){
         ui->progressBar->setValue(0);
    } else {
    ui->progressBar->setValue(a.hp);
    }
    strdmg = QString::number(b.dmg + i);

    roar1->play();
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
    click->play();
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
    int i;
    ui->pushButton_8->setDisabled(true);
    ui->pushButton_9->setDisabled(true);
    ui->pushButton_10->setDisabled(true);

    srand(time(0));
    i = (rand() % 5 - 2);
    if (b.hp > 0 && a.hp > 0){
    b.hp = b.hp - (a.dmg * 2 + i);
    if(b.hp <= 0){
         ui->progressBar_2->setValue(0);
    } else {
    ui->progressBar_2->setValue(b.hp);
    }
    strdmg = QString::number(a.dmg *2 + i);
    smash->play();
    str = "Вы нанесли противнику " + strdmg + " урона!" ;



    ui->textBrowser->append(str);

    if (b.hp <= 0){
      winn->play();
      ui->textBrowser->append("Поздравляю! Вы победили!");
      timer.setInterval(10000);
      connect (&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
      timer.start();
      loop.exec();
      qApp->quit();

  }

       ui->textBrowser->append("Противник думает чем ответить.");
       timer.setInterval(3000); //5 sec
       connect (&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
       timer.start();
       loop.exec();

    srand(time(0));
    i = (rand() % 5 - 2);
    a.hp = a.hp - (b.dmg + i);
    if(a.hp <= 0){
         ui->progressBar->setValue(0);
    } else {
    ui->progressBar->setValue(a.hp);
    }
    strdmg = QString::number(b.dmg + i);
    roar2->play();
    str = "Противник наносит вам " + strdmg + " урона атакой по корпусу! \n" ;

    ui->textBrowser->append(str);
    ui->pushButton_8->setEnabled(true);
    ui->pushButton_9->setEnabled(true);
    ui->pushButton_10->setEnabled(true);

    if (a.hp <= 0){

     ui->textBrowser->append("Вы проиграли этот бой!");
     timer.setInterval(5000);
     connect (&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
     timer.start();
     loop.exec();
     qApp->quit();

 }
}
}

void scene1::on_button3_clicked()
{
    click->play();
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
    int i;

    ui->pushButton_8->setDisabled(true);
    ui->pushButton_9->setDisabled(true);
    ui->pushButton_10->setDisabled(true);

    srand(time(0));
    i = (rand() % 5 - 2);
    if (b.hp > 0 && a.hp > 0){
    b.hp = b.hp - (a.dmg + i);
    if(b.hp <= 0){
         ui->progressBar_2->setValue(0);
    }else{
    ui->progressBar_2->setValue(b.hp);
    }

    strdmg = QString::number(a.dmg + i);
    kick->play();
    str = "Вы нанесли противнику " + strdmg + " урона!" ;



    ui->textBrowser->append(str);

    if (b.hp <= 0){
      winn->play();
      ui->textBrowser->append("Поздравляю! Вы победили!");
      timer.setInterval(10000);
      connect (&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
      timer.start();
      loop.exec();
      qApp->quit();

  }

       ui->textBrowser->append("Противник думает чем ответить.");
       timer.setInterval(3000); //5 sec
       connect (&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
       timer.start();
       loop.exec();

    srand(time(0));
    i = (rand() % 5 - 2);
    a.hp = a.hp - (b.dmg + i);
    if(a.hp <= 0){
         ui->progressBar->setValue(0);
    } else
    ui->progressBar->setValue(a.hp);
    }
    strdmg = QString::number(b.dmg + i);
    roar3->play();
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

