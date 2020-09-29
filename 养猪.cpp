#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string.h>
using namespace std;
enum pinzhong{black,small,big,null,die};//品种的枚举 
class pig								//猪的类 
{
	private:
		pinzhong x;						//私有成员包括猪的品种，体重，价格和饲养时间 
		int time;
		int price;
		float weight;
	public:
		void setpinzhong(int a)			//设置猪的品种 
		{
			if(a==0)x=black;
			if(a==1)x=small;
			if(a==2)x=big;
			if(a==3)x=null;
			if(a==4)x=die;
		}
		void setweight(float a)			//设置猪的体重 
		{
			weight=a;
		}
		void setprice(int a)			//设置猪的价格 
		{
			price=a; 
		}
		void settime(int a)				//设置猪的养殖时间 
		{
			time=a; 
		}
		int getpinzhong()				//获得猪的品种 
		{
			return x;
		}
		int gettime()					//获得饲养时间 
		{
			return time;
		}
		float getweight()				//获得猪的体重 
		{
			return weight;
		}
		int getprice()					//获得猪的价格 
		{
			return price;
		}
};
void setpigs0(pig p[][10])				//将猪圈初始化 ，全部置空 
{
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<10;j++)
		{
			p[i][j].setpinzhong(3);
		}
	}
}
bool check(int a,pig p[][10])			//检查所有猪圈中有无猪的位置 
{
	if(a==0)							//如果是黑猪 
	{
		for(int i=0;i<100;i++)			//检查一百个猪圈中有无有空位的黑猪圈	
		{
			if((p[i][0].getpinzhong()==black||p[i][0].getpinzhong()==null)&&p[i][9].getpinzhong()==null)
			return false;
		}
		return true;
	}
	if(a==1||a==2)						//如果是小花猪或大花白猪 
	{
		for(int i=0;i<100;i++)			//检查一百个猪圈中有无有空位的花猪圈 
		{
			if(p[i][0].getpinzhong()!=black&&p[i][9].getpinzhong()==null)
			return false;
		}
		return true;
	}
}
void reset(pig p[][10])					//将猪圈中的猪重新编号 
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
void setpigs(pig p[][10],int b)			//将猪放置在各个猪圈 
{
	int c,d,j;
	srand((unsigned)time(NULL));
	for(int i=0;i<b;i++)				//设置b头猪 
	{
		c=rand()%3;						//随机设置该猪品种			
		if(c==0)						//如果该猪为黑猪 
		{
			while(1) 
			{
				j=rand()%100;			//随机取一猪圈 
				if(p[j][0].getpinzhong()==black||p[j][0].getpinzhong()==null)	//判断该猪圈是否为空或是否为黑猪圈 
				{
					for(int k=0;k<10;k++)
					{
						if(p[j][k].getpinzhong()==null)							//寻找该猪圈中的空位 
						{
							d=1;												//如果找到空位d置1，并将猪初始化 
							p[j][k].setpinzhong(0);
							p[j][k].setweight(((rand()%(301))+200)/10.0);
							p[j][k].setprice(30);
							p[j][k].settime(0);
							break;												//如果找到了位置，break 
						}	
						else d=0;	
					}
					if(d==1)break;												//如果d=1，即已经找到了位置，break 
					if(check(c,p))break;										//或者，如果所有猪圈都不能安置这头猪，则重新生成该猪的品种 
				}		
			}
		}
		else if(c==1||c==2)				//如果是小花猪或大花白猪 
		{
			while(1)
			{
				j=rand()%100;			//随机取一猪圈 
				if(p[j][0].getpinzhong()!=black)								//如果不是黑猪圈 
				{
					for(int k=0;k<10;k++)
					{
						if(p[j][k].getpinzhong()==null)							//寻找该猪圈中的空位 
						{
							d=1;												//如果找到，d置1，并初始化该猪 
							p[j][k].setpinzhong(c);
							p[j][k].setweight(((rand()%(301))+200)/10.0);
							if(c==1)p[j][k].setprice(14);
							else p[j][k].setprice(12);
							p[j][k].settime(0);
							break;												//如果找到了位置，break 
						}
						else d=0;		
					}
					if(d==1)break;												//如果d=1，即已经找到了位置，break 
					if(check(c,p))break;										//或者，如果所有猪圈都不能安置这头猪，则重新生成该猪的品种
				}
						
			}
		}
		if(d==0)i--;															//如果以上循环都没有找到该猪的位置，则重新生成一头猪，该猪不计入总数 
	}
}
void tongji(pig p[][10],int a)			//统计某一猪圈中每个品种猪的数量 
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
void sell(pig p[][10])					//将符合售出标准的猪出售 
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
void chaxun(pig p[][10],int a,int b)		//查询某一只猪的信息 
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
int zongshu(pig p[][10])				//获得养猪场当前猪的数量 
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
void zonglan(pig p[][10])				//查询猪圈现状 
{
	int x=0,x1=0,x2=0,x3=0,x4=0,x5=0,x6=0,y=0,y1=0,y2=0,y3=0,y4=0,y5=0,y6=0,z=0,z1=0,z2=0,z3=0,z4=0,z5=0,z6=0;
	
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<10;j++)
		{
			if(p[i][j].getpinzhong()==black)
			{
				x++;
				if(p[i][j].getweight()<75)x1++;
				if(p[i][j].getweight()>=75)x2++;
				if(p[i][j].gettime()<365)x3++;
				if(p[i][j].gettime()>=365)x4++;
			}
			if(p[i][j].getpinzhong()==small)
			{
				y++;
				if(p[i][j].getweight()<75)y1++;
				if(p[i][j].getweight()>=75)y2++;
				if(p[i][j].gettime()<365)y3++;
				if(p[i][j].gettime()>=365)y4++;
			}
			if(p[i][j].getpinzhong()==big)
			{
				z++;
				if(p[i][j].getweight()<75)z1++;
				if(p[i][j].getweight()>=75)z2++;
				if(p[i][j].gettime()<365)z3++;
				if(p[i][j].gettime()>=365)z4++;
			}
			
		}
	}
	cout<<"现猪圈内共有黑猪"<<x<<"头"<<endl<<"其体重分布情况为："<<endl<<"75kg以下"<<x1<<"头"<<endl<<"75kg以上"
	<<x2<<"头"<<endl<<"其饲养时间分布情况为："<<endl<<"365天以下"<<x3<<"头"<<endl<<"365天以上"<<x4<<"头"<<endl;
	cout<<"现猪圈内共有小花猪"<<y<<"头"<<endl<<"其体重分布情况为："<<endl<<"75kg以下"<<y1<<"头"<<endl<<"75kg以上"
	<<y2<<"头"<<endl<<"其饲养时间分布情况为："<<endl<<"365天以下"<<y3<<"头"<<endl<<"365天以上"<<y4<<"头"<<endl;
	cout<<"现猪圈内共有大花白猪"<<z<<"头"<<endl<<"其体重分布情况为："<<endl<<"75kg以下"<<z1<<"头"<<endl<<"75kg以上"
	<<z2<<"头"<<endl<<"其饲养时间分布情况为："<<endl<<"365天以下"<<z3<<"头"<<endl<<"365天以上"<<z4<<"头"<<endl;
}
void wen(pig p[][10],int &x,int &y)			//让随机一头猪感染猪瘟 
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
bool dead(pig p[][10])						//判断猪圈中的猪是否死光 
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
int count(pig p[][10],int a)				//计算某一猪圈中猪的数量 
{
	int x=0;
	for(int i=0;i<10;i++)
	{
		if(p[a][i].getpinzhong()!=null)
			x++;	
	}
	return x;
}
int check2(pig p[][10])						//检查是否每个猪圈都有猪 
{
	for(int i=1;i<99;i++)
	{
		if(p[i][0].getpinzhong()==null)
		return true;
	}
	return false;
}
int increase(pig p[][10])					//模拟猪瘟的扩散 
{		
	srand((unsigned)time(NULL));
	int a,b,i=0;
	for(;;i++)
	{
		for(int j=0;j<100;j++)
		{
			for(int k=0;k<10;k++)
			{
				if(p[j][k].getpinzhong()==die)			//找到感染猪瘟的猪 
				{
					for(int o=0;o<10;o++)				//对猪圈内部进行一轮感染 
					{
						a=rand()%1000;
						if(a<500&&p[j][o].getpinzhong()!=null)
						p[j][o].setpinzhong(4);
					}
					if(j>0&&j<99)						//对相邻猪圈进行一轮感染 
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
		if(dead(p))break;					//当猪圈中的猪全部死光时break 
	}
	return i;
}
void move(pig p[][10],int x,int y) 				//移动猪圈里的猪 
{
	int d=0;
	for(int i=0;i<10;i++)
	{
		if(p[x][i].getpinzhong()==black)	//如果该猪为黑猪 
		{
			for(int j=0;j<100;j++)
			{
				if((p[j][0].getpinzhong()==black||p[j][0].getpinzhong()==null)&&j!=x&&j!=y)	//在猪场中找到一黑猪圈或空闲猪圈 
				{
					for(int k=0;k<10;k++)
					{
						if(p[j][k].getpinzhong()==null)							//找到空闲位置 
						{
							p[j][k].setpinzhong(p[x][i].getpinzhong());
							p[j][k].setweight(p[x][i].getweight());
							p[j][k].settime(p[x][i].gettime());
							p[j][k].setprice(p[x][i].getprice());
							d=1;												//复制该猪，d置1，break 
							break;
						}	
						else d=0;
					}
					if(d==1)break;												//如果d=1，即已找到位置，break 
				}	
			}
			if(d==0)															//如果整个养猪场都找不到能放置该猪的位置，则现在的养猪场不能通过隔离抑制猪瘟的扩散 
			{
				cout<<"您的猪数量过于密集，无法通过合理隔离来抑制猪瘟的扩散"<<endl;
				return; 
			}
		}
		if(p[x][i].getpinzhong()!=black)				//如果该猪为花猪 
		{
			for(int j=0;j<100;j++)
			{
				if(p[j][0].getpinzhong()!=black&&j!=x&&j!=y)		//在猪场中找一花猪圈 
				{
					for(int k=0;k<10;k++)
					{
						if(p[j][k].getpinzhong()==null)	//如果在该猪圈中找到了位置 ,复制该猪，d置1，break 
						{
							p[j][k].setpinzhong(p[x][i].getpinzhong());
							p[j][k].setweight(p[x][i].getweight());
							p[j][k].settime(p[x][i].gettime());
							p[j][k].setprice(p[x][i].getprice());
							d=1;
							break;
						}	
						else d=0;
					}
					if(d==1)break;							//如果d=1，即已找到了位置，break 
				}	
			}
			if(d==0)										//如果整个养猪场都找不到能放置该猪的位置，则现在的养猪场不能通过隔离抑制猪瘟的扩散 
			{
				cout<<"您的猪数量过于密集，无法通过合理隔离来抑制猪瘟的扩散"<<endl;
				return; 
			}
		}
	}	
}
void geli(pig p[][10],int x)			//模拟隔离 
{
	if(x==0)
	{
		move(p,x+1,x);
	}
	if(x==99)
	{
		move(p,x-1,x);
	}
	else 
	{
		move(p,x-1,x);
		move(p,x+1,x);
	}
} 
int main()
{
	srand((unsigned)time(NULL));
	pig p[100][10];					//猪的二维数组 
	setpigs0(p);					//将猪圈初始化 
	int b;
	cout<<"请输入初始的猪崽数：";
	cin>>b;		
	setpigs(p,b);					//设置b头猪 
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
			for(int i=0;i<90;i++)					//猪增长三个月 
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
			y=rand()%(1001-x);					//随机补充猪 
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
