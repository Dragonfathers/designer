#ifndef WANWU_H
#define WANWU_H
#include<QPoint>
#include<QRect>
#include<QPainter>
enum Dir { UP, DOWN, LEFT, RIGHT };
class Wanwu
{
public:
    virtual void CalculateSphere() = 0;// 计算势力范围
    QPoint m_pos;// 位置
    QRect m_rectSphere;// 势力范围
    Dir m_dir;// 方向
    bool m_bDisappear;// 存在状态
    int m_step;// 单次前进步长
    float life;//生命值
    float hujia;//护甲
    float wuli;//物理攻击
    friend class Status;
    Wanwu(){};
    virtual void Display(QPainter &paint) = 0;// 绘图
    virtual void Move() = 0;// 移动
    bool IsDisappear()// 判断是否消失
    {
        return m_bDisappear;
    }
    bool IsBoom(const Wanwu &wanwu)const;//判断两物体是否碰撞
    void SetDisappear(bool tmp)
    {
        m_bDisappear=tmp;
    }
    QPoint getpos()
    {
        return m_pos;
    }
    void downlife(float gongji,int astyle=0);//攻击力,攻击类型astyle
};
#endif // WANWU_H
