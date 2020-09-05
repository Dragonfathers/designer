/*С�����˸�������һ����100����Ȧ������0-99��ţ���
ÿ����Ȧ�����10ͷ������0��9��ţ�����һ��������Ʒ�֣�
����С����ʹ󻨰������к��������������������һ��
��Ȧ����ܡ��涨ÿ3���£�����Ҫ��Ȧһ����������
���س���150��ĺ���������1��ģ�ͬʱ����һ�����̶������
Ʒ�֡�����¼�����ѡ��������ɣ������������������������
�̶��ĳ�ʼ���ص���Ϣ��20-50kg�������������������������
��ˢ��ÿͷ����ʱ�����������������һ��/һ�α�ʾһ�죬һ��
����0.0 ~1.2kg���������ýṹ��������ʽ������Ȧ����Ϊ��
�������Զ�������Ȧ��Ҫ������ȷֲ��ڸ�����Ȧ�У����Զ�ͳ
�Ʊ��γ�Ȧ����������ۼۣ�����15Ԫһ�С����7Ԫһ���
������6Ԫһ���������60������
��1���������ѯ��ǰĳһ��Ȧ��������������ࣻ
��2���������ѯ��ǰĳһ��Ȧĳͷ���״̬��Ϣ��
��3��������ͳ�Ƶ�ǰ��ÿ��Ʒ��������������ء�����ʱ���
�������������70������
��4���������ѯ��5��������ۼ�¼�����̶��Ĺ����¼����¼����
����ʽ�洢����
��5�����е�ǰ�����Ϣʹ���ļ���ʽ���棬����������ʱ���Զ���ȡ
������Ϣ����ʾ��������75������
��6��ģ������ĳһֻ�������������������չ�����ǣ�ͬһ����Ȧ
����ÿ�챻��Ⱦ������50%��������Ȧ����ÿ�챻��Ⱦ�ļ�����15%��
�����ڵ���Ȧ������Ⱦ����д����ģ���ú�������������⡣
��7��������������������Ѿ����������ȡ����ĸ����ʩ������
���տ��ơ�������80������
��߲��֣���1����ʹ��MFC ����QT��IDE����û����棻��2����ʾ
ÿ��Ʒ��������������ء�����ʱ��ֲ�ͼ����3���ɸ����Լ������
�����빦�ܣ�����ת��Ϊһ��������Ϸ����������90������
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
	cout<<"����"<<x<<"ͷ"<<endl<<"С����"<<y<<"ͷ"<<endl<<"�󻨰���"<<z<<"ͷ"<<endl; 
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
	cout<<"��Ҫ��ѯ����Ȧ��";
	int a; 
	cin>>a;
	while(a>=0&&a<100)
	{
		tongji(p,a);
		cout<<"��Ҫ��ѯ����Ȧ��";
		cin>>a;
	}
	return 0;	
} 
