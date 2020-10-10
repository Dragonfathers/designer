#ifndef BULLET_H
#define BULLET_H
#include"wanwu.h"
class Bullet : public Wanwu
{
public:
    Bullet(const Tank &tank); 
    void Display(QPainter &paint) ;// 绘图
    void Move() ;// 移动
protected:
    void CalculateSphere();
private:
    int style;
    int group;//子弹所在组
};
#endif // BULLET_H
