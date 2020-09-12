#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string.h>
using namespace std;
enum pinzhong{black,small,big,null,die};
class pig
{
	private:
		pinzhong x;
		int time;
		int price;
		float weight;
	public:
		void setpinzhong(int a)
		{
			if(a==0)x=black;
			if(a==1)x=small;
			if(a==2)x=big;
			if(a==3)x=null;
			if(a==4)x=die;
		}
		void setweight(float a)
		{
			weight=a;
		}
		void setprice(int a)
		{
			price=a; 
		}
		void settime(int a)
		{
			time=a; 
		}
		int getpinzhong()
		{
			return x;
		}
		int gettime()
		{
			return time;
		}
		float getweight()
		{
			return weight;
		}
		int getprice()
		{
			return price;
		}
};
void setpigs0(pig p[][10])
{
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<10;j++)
		{
			p[i][j].setpinzhong(3);
		}
	}
}
bool check(int a,pig p[][10])
{
	if(a==0)
	{
		for(int i=0;i<100;i++)
		{
			if((p[i][0].getpinzhong()==black||p[i][0].getpinzhong()==null)&&p[i][9].getpinzhong()==null)
			return false;
		}
		return true;
	}
	if(a==1||a==2)
	{
		for(int i=0;i<100;i++)
		{
			if(p[i][0].getpinzhong()!=black&&p[i][9].getpinzhong()==null)
			return false;
		}
		return true;
	}
}
void reset(pig p[][10])
{
	int k;
	for(int i=0;i<100;i++)
	{
		k=0;
		for(int j=0;j<10;j++)
		{
			if(p[i][j].getpinzhong()!=null)
			{
				p[i][k].setpinzhong(p[i][j].getpinzhong());
				p[i][k].setweight(p[i][j].getweight());
				p[i][k].settime(p[i][j].gettime());
				p[i][k].setprice(p[i][j].getprice());
				k++;
			}
		}
	}	
} 
void setpigs(pig p[][10],int b)
{
	int c,d,j;
	srand((unsigned)time(NULL));
	for(int i=0;i<b;i++)
	{
		c=rand()%3;
		if(c==0)
		{
			while(1) 
			{
				j=rand()%100;
				if(p[j][0].getpinzhong()==black||p[j][0].getpinzhong()==null)
				{
					for(int k=0;k<10;k++)
					{
						if(p[j][k].getpinzhong()==null)
						{
							d=1;
							p[j][k].setpinzhong(0);
							p[j][k].setweight(((rand()%(301))+200)/10.0);
							p[j][k].setprice(30);
							p[j][k].settime(0);
							break;
						}	
						else d=0;	
					}
					if(d==1)break;
					if(check(c,p))break;
				}		
			}
		}
		else if(c==1||c==2)
		{
			while(1)
			{
				j=rand()%100;
				if(p[j][0].getpinzhong()!=black)
				{
					for(int k=0;k<10;k++)
					{
						if(p[j][k].getpinzhong()==null)
						{
							d=1;
							p[j][k].setpinzhong(c);
							p[j][k].setweight(((rand()%(301))+200)/10.0);
							if(c==1)p[j][k].setprice(14);
							else p[j][k].setprice(12);
							p[j][k].settime(0);
							break;
						}
						else d=0;		
					}
					if(d==1)break;
					if(check(c,p))break;
				}
						
			}
		}
		if(d==0)i--;
	}
}
void tongji(pig p[][10],int a)
{
	int x=0,y=0,z=0;
	for(int i=0;i<10;i++)
	{
		if(p[a][i].getpinzhong()==black)x++;
		if(p[a][i].getpinzhong()==small)y++;
		if(p[a][i].getpinzhong()==big)z++;
	}
	cout<<"黑猪："<<x<<"头"<<endl<<"小花猪："<<y<<"头"<<endl<<"大花白猪："<<z<<"头"<<endl; 
}
void sell(pig p[][10])
{
	double sum=0;
	int a=0;
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<10;j++)
		{
			if(p[i][j].getpinzhong()!=null)
			{
				if(p[i][j].getweight()>=75||p[i][j].gettime()>=365)
				{
					a++;
					sum+=p[i][j].getweight()*p[i][j].getprice();
					p[i][j].setpinzhong(3);
					p[i][j].settime(0);
					p[i][j].setweight(0);
				}
			}
		}
	}
	cout<<"本次共卖出"<<a<<"头猪，"<<"卖得"<<sum<<"元"<<endl;
	reset(p); 
}
void chaxun(pig p[][10],int a,int b)
{
	if(p[a][b].getpinzhong()==null)
	cout<<"您所查询的内容为空";
	else
	{
		cout<<"该猪为";
		if(p[a][b].getpinzhong()==black)
		cout<<"黑猪"<<"  ";
		if(p[a][b].getpinzhong()==small)
		cout<<"小花猪"<<"  ";
		if(p[a][b].getpinzhong()==big)
		cout<<"大花白猪"<<"  ";
		cout<<"体重为"<<p[a][b].getweight()<<"kg"<<"  ";
		cout<<"养殖时间为"<<p[a][b].gettime()<<"天"<<endl;
	 } 
}
int zongshu(pig p[][10])
{
	int a=0;
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<10;j++)
		{
			if(p[i][j].getpinzhong()!=null)
			{
				a++;
			}
		}
	} 
	return a;
}
void zonglan(pig p[][10])
{
	int x=0,x1=0,x2=0,x3=0,x4=0,x5=0,x6=0,y=0,y1=0,y2=0,y3=0,y4=0,y5=0,y6=0,z=0,z1=0,z2=0,z3=0,z4=0,z5=0,z6=0;
	
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<10;j++)
		{
			if(p[i][j].getpinzhong()==black)
			{
				x++;
				if(p[i][j].getweight()<50)x1++;
				if(p[i][j].getweight()>=50&&p[i][j].getweight()<100)x2++;
				if(p[i][j].getweight()>=100&&p[i][j].getweight()<150)x3++;
				if(p[i][j].getweight()>=150)x4++;
				if(p[i][j].gettime()<365)x5++;
				if(p[i][j].gettime()>=365)x6++;
			}
			if(p[i][j].getpinzhong()==small)
			{
				y++;
				if(p[i][j].getweight()<50)y1++;
				if(p[i][j].getweight()>=50&&p[i][j].getweight()<100)y2++;
				if(p[i][j].getweight()>=100&&p[i][j].getweight()<150)y3++;
				if(p[i][j].getweight()>=150)y4++;
				if(p[i][j].gettime()<365)y5++;
				if(p[i][j].gettime()>=365)y6++;
			}
			if(p[i][j].getpinzhong()==big)
			{
				z++;
				if(p[i][j].getweight()<50)z1++;
				if(p[i][j].getweight()>=50&&p[i][j].getweight()<100)z2++;
				if(p[i][j].getweight()>=100&&p[i][j].getweight()<150)z3++;
				if(p[i][j].getweight()>=150)z4++;
				if(p[i][j].gettime()<365)z5++;
				if(p[i][j].gettime()>=365)z6++;
			}
			
		}
	}
	cout<<"现猪圈内共有黑猪"<<x<<"头"<<endl<<"其体重分布情况为："<<endl<<"50kg以下"<<x1<<"头"<<endl
	<<"50kg到100kg"<<x2<<"头"<<endl<<"100kg到150kg"<<x3<<"头"<<endl<<"150kg以上"<<x4<<"头"<<endl<<
	"其饲养时间分布情况为："<<endl<<"365天以下"<<x5<<"头"<<endl<<"365天以上"<<x6<<"头"<<endl;
	cout<<"现猪圈内共有小花猪"<<y<<"头"<<endl<<"其体重分布情况为："<<endl<<"50kg以下"<<y1<<"头"<<endl
	<<"50kg到100kg"<<y2<<"头"<<endl<<"100kg到150kg"<<y3<<"头"<<endl<<"150kg以上"<<y4<<"头"<<endl<<
	"其饲养时间分布情况为："<<endl<<"365天以下"<<y5<<"头"<<endl<<"365天以上"<<y6<<"头"<<endl;
	cout<<"现猪圈内共有大花白猪"<<z<<"头"<<endl<<"其体重分布情况为："<<endl<<"50kg以下"<<z1<<"头"<<endl
	<<"50kg到100kg"<<z2<<"头"<<endl<<"100kg到150kg"<<z3<<"头"<<endl<<"150kg以上"<<z4<<"头"<<endl<<
	"其饲养时间分布情况为："<<endl<<"365天以下"<<z5<<"头"<<endl<<"365天以上"<<z6<<"头"<<endl;
}
void wen(pig p[][10],int &x,int &y)
{
	srand((unsigned)time(NULL)); 
	while(1)
	{
		x=rand()%100;
		y=rand()%10;
		if(p[x][y].getpinzhong()!=null)
		{
			p[x][y].setpinzhong(4);
			break;
		}
	}
}
bool dead(pig p[][10])
{
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<10;j++)
		{
			if(p[i][j].getpinzhong()!=null&&p[i][j].getpinzhong()!=die)
			return false;
		}
	} 
	return true;
}
int count(pig p[][10],int a)
{
	int x=0;
	for(int i=0;i<10;i++)
	{
		if(p[a][i].getpinzhong()!=null)
			x++;	
	}
	return x;
}
int check2(pig p[][10])
{
	for(int i=1;i<99;i++)
	{
		if(p[i][0].getpinzhong()==null)
		return true;
	}
	return false;
}
int increase(pig p[][10])
{
	srand((unsigned)time(NULL));
	int a,b,i=0;
	for(;;i++)
	{
		for(int j=0;j<100;j++)
		{
			for(int k=0;k<10;k++)
			{
				if(p[j][k].getpinzhong()==die)
				{
					for(int o=0;o<10;o++)
					{
						a=rand()%1000;
						if(a<500&&p[j][o].getpinzhong()!=null)
						p[j][o].setpinzhong(4);
					}
					if(j>0&&j<99)
					{
						for(int s=0;s<10;s++)
						{
							a=rand()%1000;
							if(a<150&&p[j-1][s].getpinzhong()!=null)
							p[j-1][s].setpinzhong(4);
							a=rand()%1000;
							if(a<150&&p[j+1][s].getpinzhong()!=null)
							p[j+1][s].setpinzhong(4);
						}
					}
					else if(j==0)
					{
						for(int s=0;s<10;s++)
						{
							a=rand()%1000;
							if(a<150&&p[j+1][s].getpinzhong()!=null)
							p[j+1][s].setpinzhong(4);
						}
					}
					else if(j==99)
					{
						for(int s=0;s<10;s++)
						{
							a=rand()%1000;
							if(a<150&&p[j-1][s].getpinzhong()!=null)
							p[j-1][s].setpinzhong(4);
						}	
					}
				}
			}
		}
		if(dead(p))break;
	}
	return i;
}
void move(pig p[][10],int x) 
{
	int d=0;
	for(int i=0;i<10;i++)
	{
		if(p[x][i].getpinzhong()==black)
		{
			for(int j=0;j<100;j++)
			{
				if(p[j][0].getpinzhong()==black||p[j][0].getpinzhong()==null)
				{
					for(int k=0;k<10;k++)
					{
						if(p[j][k].getpinzhong()==null)
						{
							p[j][k].setpinzhong(p[x-1][i].getpinzhong());
							p[j][k].setweight(p[x-1][i].getweight());
							p[j][k].settime(p[x-1][i].gettime());
							p[j][k].setprice(p[x-1][i].getprice());
							d=1;
							break;
						}	
						else d=0;
					}
					if(d==1)break;	
				}	
			}
			if(d==0)
			{
				cout<<"您的猪数量过于密集，无法通过合理隔离来抑制猪瘟的扩散"<<endl;
				return; 
			}
		}
		if(p[x][i].getpinzhong()!=black)
		{
			for(int j=0;j<100;j++)
			{
				if(p[j][0].getpinzhong()!=black)
				{
					for(int k=0;k<10;k++)
					{
						if(p[j][k].getpinzhong()==null)
						{
							p[j][k].setpinzhong(p[x-1][i].getpinzhong());
							p[j][k].setweight(p[x-1][i].getweight());
							p[j][k].settime(p[x-1][i].gettime());
							p[j][k].setprice(p[x-1][i].getprice());
							d=1;
							break;
						}	
						else d=0;
					}
					if(d==1)break;	
				}	
			}
			if(d==0)
			{
				cout<<"您的猪数量过于密集，无法通过合理隔离来抑制猪瘟的扩散"<<endl;
				return; 
			}
		}
	}	
}
void geli(pig p[][10],int x)
{
	if(x==0)
	{
		move(p,x+1);
	}
	if(x==99)
	{
		move(p,x-1);
	}
	else 
	{
		move(p,x-1);
		move(p,x+1);
	}
} 
int main()
{
	srand((unsigned)time(NULL));
	pig p[100][10];
	setpigs0(p);
	int b;
	cout<<"请输入初始的猪崽数：";
	cin>>b;
	setpigs(p,b);
	cout<<"请输入您想查询的信息:"; 
	string str;
	int x,y;
	while(cin>>str)
	{
		if(str=="查询猪圈")
		{
			cout<<"请输入所要查询猪圈的编号：";
			cin>>x;
			if(x>=0&&x<100)
			tongji(p,x);
			else
			cout<<"您输入的信息有误"; 
		} 
		else if(str=="查询猪的信息")
		{
			cout<<"请输入猪圈编号和猪的编号：";
			cin>>x>>y;
			if((x>=0&&x<100)&&(y>=0&&y<10)) 
			chaxun(p,x,y);
			else
			cout<<"您输入的信息有误"<<endl;
		} 
		else if(str=="查询猪圈现状")
		{
			zonglan(p); 
		} 
		else if(str=="本次售出的价格")
		{
			for(int i=0;i<90;i++)
			{
				for(int j=0;j<100;j++)
				{
					for(int k=0;k<10;k++)
					{
						if(p[j][k].getpinzhong()!=null)
						{
							p[j][k].setweight(p[j][k].getweight()+(rand()%13)/10.0);
							p[j][k].settime(p[j][k].gettime()+1);
						}	
					}	
				}
			}
			sell(p); 
			x=zongshu(p);
			y=rand()%(1001-x);
			setpigs(p,y);
			cout<<"本次补充猪崽"<<y<<"只"<<endl; 
		} 
		else if(str=="猪瘟来了")
		{
			wen(p,x,y);
			cout<<"是否采取隔离措施？";
			cin>>str;
			if(str=="是")
			{
				geli(p,x);
			}
			else
			{
				if(check2(p))
				{
					cout<<"由于您的猪的分配有间隔，所以猪不会全部死光"; 
				}
				else 
				{
					cout<<increase(p)<<"天后猪全部死光"<<endl; 
				} 
			}
			
		}
		else 
		cout<<"您输入的信息有误"; 
		cout<<"请输入您想查询的信息:"; 
	}
	return 0;	
} 
