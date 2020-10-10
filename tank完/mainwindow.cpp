#include "mainwindow.h"
#include"bullet.h"
#include"QRect"
#include<QDebug>
#include<QMainWindow>
#include<QPushButton>
#include<QMessageBox>
#include<QComboBox>
#include<QMediaPlayer>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    b.setParent(this);
    b1.setParent(this);
    b2.setParent(this);
    b3.setParent(this);
    b4.setParent(this);
    b1.setText("play");
    b2.setText("exit");
    b3.setText("播放音乐");
    b4.setText("关闭音乐");
    b4.hide();
    b.setFixedSize(100,40);
    b1.setFixedSize(100,40);
    b2.setFixedSize(100,40);
    b3.setFixedSize(100,40);
    b4.setFixedSize(100,40);
    b.move(494,350);
    b1.move(494,300);
    b2.move(494,400);
    b.addItem("    入门");
    b.addItem("    简单");
    b.addItem("    普通");
    b.addItem("    困难");
    b.addItem("    地狱");
    connect(&b1,&QPushButton::clicked,this,&MainWindow::play);
    connect(&b2,&QPushButton::clicked,
            [=]()
            {
                int ret=QMessageBox::question(this,"是否退出游戏？","是否退出游戏？");
                switch (ret)
                {
                    case QMessageBox::Yes:
                        close();
                        break;
                    case QMessageBox::No:
                        break;
                    default:
                    break;
                }
            }
            );
    connect(&b3,&QPushButton::clicked,this,&MainWindow::musicon);
    connect(&b4,&QPushButton::clicked,this,&MainWindow::musicoff);
    QFont font;
    font.setPointSize(32);
    paint.setFont(font);
    paint.setPen(QColor(255,0,0));    
    //初始发全局结构体
    glo.framei=0;
    glo.status=new Status();
    glo.blockimage=new QImage(":/images/map_block.png");
    glo.tankimage=new QImage(":/images/player_tank.png");
    glo.bulletimage=new QImage(":/images/bullet.png");
    glo.gamemap=new GameMap();
    glo.player=new Tank();
    connect(&b, SIGNAL(currentIndexChanged(int)), this, SLOT(boxChange(int)));
    gamestatus=pause;
    laststyle=0;
    leftorright=1;
    timer=new QTimer(this);
    timer->setInterval(25);
    connect(timer,SIGNAL(timeout()),this,SLOT(timefun()));
    timer->start();
    player->setMedia(QUrl::fromLocalFile("C:/Users/Y7000P/Desktop/yuanjian/tank/红色警戒.mp3"));
    player->setVolume(100);
}
MainWindow::~MainWindow()
{
    timer->stop();
    delete timer;
}
void MainWindow::musicon()
{
    player->play();
    b3.hide();
    b4.show();
    connect(&b4,&QPushButton::clicked,this,&MainWindow::musicoff);
}
void MainWindow::musicoff()
{
    player->stop();
    b4.hide();
    b3.show();
    connect(&b3,&QPushButton::clicked,this,&MainWindow::musicon);
}
void MainWindow::isgameover()
{
    if(glo.badtanks.count()==0)
    {
        gamestatus=pause;
        int ret=QMessageBox::question(this,"是否继续游戏？","你赢了！是否继续游戏？");
        switch (ret)
        {
            case QMessageBox::Yes:
                {
                    b.show();
                    b1.show();
                    b2.show();
                }
                break;
            case QMessageBox::No:
                close();
                break;
            default:
            break;
        }
    }
    if(glo.player->life==0)
    {
        gamestatus=pause;
        int ret=QMessageBox::question(this,"是否继续游戏？","你输了！是否继续游戏？");
        switch (ret)
        {
            case QMessageBox::Yes:
                {
                    b.show();
                    b1.show();
                    b2.show();
                }
                break;
            case QMessageBox::No:
                close();
                break;
            default:
            break;
        }
    }
}
void MainWindow::boxChange(int i)
{
    nandu=i;
}
void MainWindow::closeEvent(QCloseEvent *event)
{
    int ret=QMessageBox::question(this,"确认退出游戏？","确认退出游戏？");
    switch (ret)
    {
        case QMessageBox::Yes:
            event->accept();
            break;
        case QMessageBox::No:
            {
                b.show();
                b1.show();
                b2.show();
                event->ignore();
            }
            break;
        default:
            break;
    }
}
void MainWindow::play()
{
    glo.player=new Tank();
    glo.badtanks.clear();
    laststyle=0;
    leftorright=1;
    b.hide();
    b1.hide();
    b2.hide();
    switch (nandu)
    {
        case 0:
            {
                Tank *tmp=new Tank(2,3,UP,nandu);
                glo.badtanks.append(tmp);
                break;
            }
        case 1:
            {
                for (int k=0;k<=nandu;k++)
                {
                    Tank*tmp=new Tank(rand()%17,rand()%11,UP,nandu);
                    glo.badtanks.append(tmp);
                }
                break;
            }
        case 2:
            {
                for (int k=0;k<=nandu;k++)
                {
                    Tank*tmp=new Tank(rand()%17,rand()%11,UP,nandu);
                    glo.badtanks.append(tmp);
                }
                break;
            }
        case 3:
            {
                for (int k=0;k<=nandu;k++)
                {
                    Tank*tmp=new Tank(rand()%17,rand()%11,UP,nandu);
                    glo.badtanks.append(tmp);
                }
                break;
            }
        case 4:
            {
                for (int k=0;k<=nandu;k++)
                {
                    Tank*tmp=new Tank(rand()%17,rand()%11,UP,nandu);
                    glo.badtanks.append(tmp);
                }
                break;
            }
        default:
            break;
    }
    gamestatus=gameing;
}
void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    setFixedSize(WIDTH,HEIGHT);
    paint.begin(this);
    glo.gamemap->Display(paint);
    if(gamestatus==gameing)
    {
        glo.player->Display(paint);
        glo.status->Display(paint);
        for(int i=0;i<glo.badtanks.count();i++)
        {
            glo.badtanks.at(i)->Display(paint);
        }
    }
    paint.end();
}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_M)//当按键为M时设置游戏状态为mapedit
    {
        gamestatus=mapedit;
    }
    else if(event->key()==Qt::Key_G)
    {
        gamestatus=gameing;
    }
    if(gamestatus==mapedit)
    {
        if(event->key()==Qt::Key_S)
        {
            glo.gamemap->savemap("1.dat");
        }
        else if(event->key()==Qt::Key_L)
        {
            glo.gamemap->loadmap("1.dat");
        }
    }
    else if(gamestatus==gameing)
    {
        if(event->key()==Qt::Key_S)
        {
            glo.player->setdir(DOWN);glo.player->startmove();
        }
        else if(event->key()==Qt::Key_A)
        {
            glo.player->setdir(LEFT);glo.player->startmove();
        }
        else if(event->key()==Qt::Key_W)
        {
            glo.player->setdir(UP);glo.player->startmove();
        }
        else if(event->key()==Qt::Key_D)
        {
            glo.player->setdir(RIGHT);glo.player->startmove();

        }else if(event->key()==Qt::Key_J)
        {
            glo.player->startfire();
        }
    }
    update();
}
void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_J)
    {
        glo.player->stopfire();
    }
    else
    {
        glo.player->stopmove();
    }
}
void MainWindow::mouseMoveEvent(QMouseEvent *event)// 鼠标移动事件       默认情况下，触发事件需要按下鼠标，才能触发。可设置为自动触发:setMouseTracking(true);
{
    if(gamestatus==mapedit)
    {
        int i,j;//地图块的二维编号地址
        glo.gamemap->cal(event->x(),event->y(),i,j);
        if(leftorright==1)
        {//如果移动时候按下左键
            glo.gamemap->setstyle(i,j,laststyle);
        }
        else
        {
            glo.gamemap->deletecell(i,j);
        }
    }
    update();
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    int i,j;//地图块的二维编号地址
    if(gamestatus==mapedit)
    {
        glo.gamemap->cal(event->x(),event->y(),i,j);
        if(event->button()==Qt::LeftButton)
        {
            leftorright=1;
            laststyle=glo.gamemap->switchstyle(i,j);
        }
        else
        {
            glo.gamemap->deletecell(i,j);
            leftorright=2;
        }
    }
    update();
}
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{

}
void MainWindow::timefun()
{
    if(gamestatus!=gameing)
        return;
    glo.framei++;
    Dir tmpdir;int tmp;
    for(int i=0;i<glo.badtanks.count();i++)/**敌人坦克控制**/
    {
        if(qrand()%5==0)
        {
            glo.badtanks.at(i)->startmove();
            glo.badtanks.at(i)->startfire();
        }
        if(qrand()%10==0)
            glo.badtanks.at(i)->stopmove();
        if(qrand()%10==0)
            glo.badtanks.at(i)->stopfire();
        if(qrand()%10==0)
        {
            tmp=qrand()%4;
            switch(tmp)
            {
                case 0:
                    tmpdir=UP;
                    break;
                case 1:
                    tmpdir=DOWN;
                    break;
                case 2:
                    tmpdir=LEFT;
                    break;
                case 3:
                    tmpdir=RIGHT;
                    break;
            }
            glo.badtanks.at(i)->setdir(tmpdir);
        }
    }
    glo.player->Move();
    glo.player->fire();
    for(int i=0;i<glo.badtanks.count();i++)
    {
        glo.badtanks.at(i)->Move();
        glo.badtanks.at(i)->fire();
    }
    isgameover();
    update();
}
