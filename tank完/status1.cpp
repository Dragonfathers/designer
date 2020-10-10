#include "status1.h"
#include<QColor>
status1::status1(const Wanwu &wanwu)
{
    life=wanwu.life;
}
void status1::Display(QPainter &paint)
{
    paint.drawText(500,200,QString("yourlife:")+QString::number(life));
}
