#include "tank.h"
int Tank::steps[5]={4,8,8,16,16};
float Tank::lifes[5]={200,400,600,800,900};
float Tank::wulis[5]={20,40,80,160,160};
float Tank::hujias[5]={50,70,90,110,130};
int Tank::gongjijianges[5]={8,7,6,5,4};
Tank::Tank()
{
    this->wuli=200;
    this->group=0;//0玩家组，1敌人组
    m_step=16;
    gongjijiange=3;
    this->style=0;
    ismove=false;
    m_dir=UP;
    isfire=false;
    m_bDisappear=false;
    life=1000;
    CalculateSphere();
}
Tank::Tank(int iIndex,int jIndex,Dir dir,int style,int group)
{
    this->m_dir=dir;
    this->style=style;
    this->group=group;
    isfire=false;
    wuli=wulis[style];
    hujia=hujias[style];
    m_step=steps[style];
    gongjijiange=gongjijianges[style];
    m_bDisappear=false;
    life=lifes[style];
    CalculateSphere();
}
