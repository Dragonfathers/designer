#ifndef STATUS1_H
#define STATUS1_H
#include"wanwu.h"
class status1
{
public:
    float life;
    status1(const Wanwu &wanwu);
    void Display(QPainter &paint);
};

#endif // STATUS1_H
