#ifndef MAINWINDOW_H//游戏类
#define MAINWINDOW_H
#include <QMainWindow>
#include<QKeyEvent>
#include<QMouseEvent>
#include<QPainter>
#include<QTimer>
#include<QPushButton>
#include<QMessageBox>
#include<QComboBox>
#include<QMediaPlayer>
#include"main.h"
#include "gamemap.h"
#include"tank.h"
#include"bullet.h"
#include"status.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    enum Gamestatus{mapedit,gameing,pause};//游戏状态
    Gamestatus gamestatus;
    void isgameover();
    QMediaPlayer *player=new QMediaPlayer(this);
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void closeEvent(QCloseEvent *event);
    void timefun();
    void musicon();
    void musicoff();
    void boxChange(int i);
private:
    int leftorright;//左右
    int laststyle;//上一次方块样式
    int nandu=0;
    QPushButton b1,b2,b3,b4;
    QComboBox b;
    void play();
    void setgame(Gamestatus status)
    {
        gamestatus=status;
    }//设置游戏状态
    QTimer *timer;
    QPainter paint;
};
#endif // MAINWINDOW_H
