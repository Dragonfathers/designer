/*小明开了个养猪场，一共有100个猪圈（按照0-99编号），
每个猪圈最多养10头猪（按照0到9编号），猪一共有三个品种：
黑猪、小花猪和大花白猪，其中黑猪不能与其他两种猪放在一个
猪圈里，会打架。规定每3个月，养猪场要出圈一批猪，包括：
体重超过150斤的和饲养超过1年的；同时补充一批猪崽儿（猪的
品种、数量录入或者选择随机生成）。试利用随机数方法构造猪
崽儿的初始体重等信息（20-50kg），利用随机数方法按照秒或次
数刷新每头猪随时间的体重增长函数（一秒/一次表示一天，一天
增重0.0 ~1.2kg）。试利用结构体链表形式管理猪圈的猪，为新
进的猪自动分配猪圈（要求猪均匀分布在各个猪圈中），自动统
计本次出圈的猪的总体售价（黑猪15元一斤，小花猪7元一斤，大
花白猪6元一斤）；（到此60起评）
（1）可任意查询当前某一猪圈的猪的数量和种类；
（2）可任意查询当前某一猪圈某头猪的状态信息；
（3）可任意统计当前猪场每个品种猪的数量和体重、饲养时间分
布情况；（到此70起评）
（4）可任意查询近5年猪的销售记录和猪崽儿的购入记录（记录用文
件形式存储）；
（5）所有当前猪的信息使用文件形式保存，程序再启动时，自动读取
养猪场信息并显示。（到此75起评）
（6）模拟养猪场某一只猪得了猪瘟，猪瘟的扩展几率是，同一个猪圈
的猪每天被传染几率是50%，相邻猪圈的猪每天被传染的几率是15%，
不相邻的猪圈的猪不传染。编写程序模拟多久后养猪场的猪死光光。
（7）当发现有猪得了猪瘟已经发病后，请采取合理的隔离措施，进行
风险控制。（到此80起评）
提高部分：（1）可使用MFC 或者QT等IDE设计用户界面；（2）显示
每个品种猪的数量和体重、饲养时间分布图；（3）可根据自己的理解
，加入功能（比如转换为一个养猪游戏）。（到此90起评）
*/
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
enum pinzhong{black,small,big,null};
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
		}
		void setweight(float a)
		{
			weight=a;
		}
		void setprice(int a)
		{
			price=a; 
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
void setpigs(pig p[][10],int b)
{
	int c,d=0;
	srand((unsigned)time(NULL));
	for(int i=0;i<b;i++)
	{
		c=rand()%3;
		if(c==0)
		{
			for(int j=0;j<100;j++)
			{
				if(p[j][0].getpinzhong()==black||p[j][0].getpinzhong()==null)
				{
					for(int k=0;k<10;k++)
					{
						if(p[j][k].getpinzhong()==null)
						{
							d=1;
							p[j][k].setpinzhong(0);
							p[j][k].setweight(((rand()%(301))+200)/10.0);
							p[j][k].setprice(15);
							break;
						}	
						else d=0;	
					}
					if(d==1)break;
				}		
			}
		}
		else if(c==1||c==2)
		{
			d=0;
			for(int j=0;j<100;j++)
			{
				if(p[j][0].getpinzhong()!=black)
				{
					for(int k=0;k<10;k++)
					{
						if(p[j][k].getpinzhong()==null)
						{
							d=1;
							p[j][k].setpinzhong(c);
							p[j][k].setweight(((rand()%(301))+200)/10.0);
							if(c==1)p[j][k].setprice(7);
							else p[j][k].setprice(6);
							break;
						}
						else d=0;		
					}
					if(d==1)break;
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
double sell(pig p[][10])
{
	double sum=0;
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<10;j++)
		{
			if(p[i][j].getweight()>=150&&p[i][j].gettime()>=365)
			{
				sum+=p[i][j].getweight()*p[i][j].getprice();
			}
		}
	}
	return sum; 
}
int main()
{
	pig p[100][10];
	setpigs0(p);
	int b;
	cin>>b;
	setpigs(p,b);
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<10;j++)
		{
			if(p[i][j].getpinzhong()!=null)
				cout<<p[i][j].getpinzhong()<<" "<<p[i][j].getweight()<<" "<<p[i][j].getprice()<<endl;
		}
	}
	cout<<"所要查询的猪圈：";
	int a; 
	cin>>a;
	while(a>=0&&a<100)
	{
		tongji(p,a);
		cout<<"所要查询的猪圈：";
		cin>>a;
	}
	return 0;	
} 
