#ifndef TANK_H
#define TANK_H
#include"wanwu.h"
class Tank : public Wanwu
{
public:
    static int steps[5];
    static float lifes[5];
    static float wulis[5];
    static float hujias[5];
    static int gongjijianges[5];
    int  group;//坦克所在组
    virtual void CalculateSphere();// 计算势力范围
public:
    Tank();//wanjia player
    Tank(int iIndex,int jIndex,Dir dir=UP,int style=0,int group=1);//element player
    void Display(QPainter &paint);// 绘图
    void Move();// 移动
    void Move1();//fangzhi si xun huan
    void startmove()//设置移动状态为开
    {
        ismove=true;
    }
    void stopmove()//设置移动状态为关
    {
        ismove=false;
    }
    void fire();
    void startfire();
    void stopfire();
    void setdir(Dir dir)//设置方向
    {
        m_dir=dir;
    }
    bool nextsiboom();//坦克下一步 是否和地图块碰撞
private:
    int style;
    bool ismove;
    bool isfire;
    int gongjijiange;
};
#endif // TANK_H
