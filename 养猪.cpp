#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string.h>
using namespace std;
enum pinzhong{black,small,big,null,die};//Ʒ�ֵ�ö�� 
class pig								//����� 
{
	private:
		pinzhong x;						//˽�г�Ա�������Ʒ�֣����أ��۸������ʱ�� 
		int time;
		int price;
		float weight;
	public:
		void setpinzhong(int a)			//�������Ʒ�� 
		{
			if(a==0)x=black;
			if(a==1)x=small;
			if(a==2)x=big;
			if(a==3)x=null;
			if(a==4)x=die;
		}
		void setweight(float a)			//����������� 
		{
			weight=a;
		}
		void setprice(int a)			//������ļ۸� 
		{
			price=a; 
		}
		void settime(int a)				//���������ֳʱ�� 
		{
			time=a; 
		}
		int getpinzhong()				//������Ʒ�� 
		{
			return x;
		}
		int gettime()					//�������ʱ�� 
		{
			return time;
		}
		float getweight()				//���������� 
		{
			return weight;
		}
		int getprice()					//�����ļ۸� 
		{
			return price;
		}
};
void setpigs0(pig p[][10])				//����Ȧ��ʼ�� ��ȫ���ÿ� 
{
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<10;j++)
		{
			p[i][j].setpinzhong(3);
		}
	}
}
bool check(int a,pig p[][10])			//���������Ȧ���������λ�� 
{
	if(a==0)							//����Ǻ��� 
	{
		for(int i=0;i<100;i++)			//���һ�ٸ���Ȧ�������п�λ�ĺ���Ȧ	
		{
			if((p[i][0].getpinzhong()==black||p[i][0].getpinzhong()==null)&&p[i][9].getpinzhong()==null)
			return false;
		}
		return true;
	}
	if(a==1||a==2)						//�����С�����󻨰��� 
	{
		for(int i=0;i<100;i++)			//���һ�ٸ���Ȧ�������п�λ�Ļ���Ȧ 
		{
			if(p[i][0].getpinzhong()!=black&&p[i][9].getpinzhong()==null)
			return false;
		}
		return true;
	}
}
void reset(pig p[][10])					//����Ȧ�е������±�� 
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
void setpigs(pig p[][10],int b)			//��������ڸ�����Ȧ 
{
	int c,d,j;
	srand((unsigned)time(NULL));
	for(int i=0;i<b;i++)				//����bͷ�� 
	{
		c=rand()%3;						//������ø���Ʒ��			
		if(c==0)						//�������Ϊ���� 
		{
			while(1) 
			{
				j=rand()%100;			//���ȡһ��Ȧ 
				if(p[j][0].getpinzhong()==black||p[j][0].getpinzhong()==null)	//�жϸ���Ȧ�Ƿ�Ϊ�ջ��Ƿ�Ϊ����Ȧ 
				{
					for(int k=0;k<10;k++)
					{
						if(p[j][k].getpinzhong()==null)							//Ѱ�Ҹ���Ȧ�еĿ�λ 
						{
							d=1;												//����ҵ���λd��1���������ʼ�� 
							p[j][k].setpinzhong(0);
							p[j][k].setweight(((rand()%(301))+200)/10.0);
							p[j][k].setprice(30);
							p[j][k].settime(0);
							break;												//����ҵ���λ�ã�break 
						}	
						else d=0;	
					}
					if(d==1)break;												//���d=1�����Ѿ��ҵ���λ�ã�break 
					if(check(c,p))break;										//���ߣ����������Ȧ�����ܰ�����ͷ�����������ɸ����Ʒ�� 
				}		
			}
		}
		else if(c==1||c==2)				//�����С�����󻨰��� 
		{
			while(1)
			{
				j=rand()%100;			//���ȡһ��Ȧ 
				if(p[j][0].getpinzhong()!=black)								//������Ǻ���Ȧ 
				{
					for(int k=0;k<10;k++)
					{
						if(p[j][k].getpinzhong()==null)							//Ѱ�Ҹ���Ȧ�еĿ�λ 
						{
							d=1;												//����ҵ���d��1������ʼ������ 
							p[j][k].setpinzhong(c);
							p[j][k].setweight(((rand()%(301))+200)/10.0);
							if(c==1)p[j][k].setprice(14);
							else p[j][k].setprice(12);
							p[j][k].settime(0);
							break;												//����ҵ���λ�ã�break 
						}
						else d=0;		
					}
					if(d==1)break;												//���d=1�����Ѿ��ҵ���λ�ã�break 
					if(check(c,p))break;										//���ߣ����������Ȧ�����ܰ�����ͷ�����������ɸ����Ʒ��
				}
						
			}
		}
		if(d==0)i--;															//�������ѭ����û���ҵ������λ�ã�����������һͷ�������������� 
	}
}
void tongji(pig p[][10],int a)			//ͳ��ĳһ��Ȧ��ÿ��Ʒ��������� 
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
void sell(pig p[][10])					//�������۳���׼������� 
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
	cout<<"���ι�����"<<a<<"ͷ��"<<"����"<<sum<<"Ԫ"<<endl;
	reset(p); 
}
void chaxun(pig p[][10],int a,int b)		//��ѯĳһֻ�����Ϣ 
{
	if(p[a][b].getpinzhong()==null)
	cout<<"������ѯ������Ϊ��";
	else
	{
		cout<<"����Ϊ";
		if(p[a][b].getpinzhong()==black)
		cout<<"����"<<"  ";
		if(p[a][b].getpinzhong()==small)
		cout<<"С����"<<"  ";
		if(p[a][b].getpinzhong()==big)
		cout<<"�󻨰���"<<"  ";
		cout<<"����Ϊ"<<p[a][b].getweight()<<"kg"<<"  ";
		cout<<"��ֳʱ��Ϊ"<<p[a][b].gettime()<<"��"<<endl;
	 } 
}
int zongshu(pig p[][10])				//���������ǰ������� 
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
void zonglan(pig p[][10])				//��ѯ��Ȧ��״ 
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
	cout<<"����Ȧ�ڹ��к���"<<x<<"ͷ"<<endl<<"�����طֲ����Ϊ��"<<endl<<"75kg����"<<x1<<"ͷ"<<endl<<"75kg����"
	<<x2<<"ͷ"<<endl<<"������ʱ��ֲ����Ϊ��"<<endl<<"365������"<<x3<<"ͷ"<<endl<<"365������"<<x4<<"ͷ"<<endl;
	cout<<"����Ȧ�ڹ���С����"<<y<<"ͷ"<<endl<<"�����طֲ����Ϊ��"<<endl<<"75kg����"<<y1<<"ͷ"<<endl<<"75kg����"
	<<y2<<"ͷ"<<endl<<"������ʱ��ֲ����Ϊ��"<<endl<<"365������"<<y3<<"ͷ"<<endl<<"365������"<<y4<<"ͷ"<<endl;
	cout<<"����Ȧ�ڹ��д󻨰���"<<z<<"ͷ"<<endl<<"�����طֲ����Ϊ��"<<endl<<"75kg����"<<z1<<"ͷ"<<endl<<"75kg����"
	<<z2<<"ͷ"<<endl<<"������ʱ��ֲ����Ϊ��"<<endl<<"365������"<<z3<<"ͷ"<<endl<<"365������"<<z4<<"ͷ"<<endl;
}
void wen(pig p[][10],int &x,int &y)			//�����һͷ���Ⱦ���� 
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
bool dead(pig p[][10])						//�ж���Ȧ�е����Ƿ����� 
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
int count(pig p[][10],int a)				//����ĳһ��Ȧ��������� 
{
	int x=0;
	for(int i=0;i<10;i++)
	{
		if(p[a][i].getpinzhong()!=null)
			x++;	
	}
	return x;
}
int check2(pig p[][10])						//����Ƿ�ÿ����Ȧ������ 
{
	for(int i=1;i<99;i++)
	{
		if(p[i][0].getpinzhong()==null)
		return true;
	}
	return false;
}
int increase(pig p[][10])					//ģ����������ɢ 
{		
	srand((unsigned)time(NULL));
	int a,b,i=0;
	for(;;i++)
	{
		for(int j=0;j<100;j++)
		{
			for(int k=0;k<10;k++)
			{
				if(p[j][k].getpinzhong()==die)			//�ҵ���Ⱦ�������� 
				{
					for(int o=0;o<10;o++)				//����Ȧ�ڲ�����һ�ָ�Ⱦ 
					{
						a=rand()%1000;
						if(a<500&&p[j][o].getpinzhong()!=null)
						p[j][o].setpinzhong(4);
					}
					if(j>0&&j<99)						//��������Ȧ����һ�ָ�Ⱦ 
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
		if(dead(p))break;					//����Ȧ�е���ȫ������ʱbreak 
	}
	return i;
}
void move(pig p[][10],int x,int y) 				//�ƶ���Ȧ����� 
{
	int d=0;
	for(int i=0;i<10;i++)
	{
		if(p[x][i].getpinzhong()==black)	//�������Ϊ���� 
		{
			for(int j=0;j<100;j++)
			{
				if((p[j][0].getpinzhong()==black||p[j][0].getpinzhong()==null)&&j!=x&&j!=y)	//�������ҵ�һ����Ȧ�������Ȧ 
				{
					for(int k=0;k<10;k++)
					{
						if(p[j][k].getpinzhong()==null)							//�ҵ�����λ�� 
						{
							p[j][k].setpinzhong(p[x][i].getpinzhong());
							p[j][k].setweight(p[x][i].getweight());
							p[j][k].settime(p[x][i].gettime());
							p[j][k].setprice(p[x][i].getprice());
							d=1;												//���Ƹ���d��1��break 
							break;
						}	
						else d=0;
					}
					if(d==1)break;												//���d=1�������ҵ�λ�ã�break 
				}	
			}
			if(d==0)															//��������������Ҳ����ܷ��ø����λ�ã������ڵ���������ͨ������������������ɢ 
			{
				cout<<"���������������ܼ����޷�ͨ�����������������������ɢ"<<endl;
				return; 
			}
		}
		if(p[x][i].getpinzhong()!=black)				//�������Ϊ���� 
		{
			for(int j=0;j<100;j++)
			{
				if(p[j][0].getpinzhong()!=black&&j!=x&&j!=y)		//��������һ����Ȧ 
				{
					for(int k=0;k<10;k++)
					{
						if(p[j][k].getpinzhong()==null)	//����ڸ���Ȧ���ҵ���λ�� ,���Ƹ���d��1��break 
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
					if(d==1)break;							//���d=1�������ҵ���λ�ã�break 
				}	
			}
			if(d==0)										//��������������Ҳ����ܷ��ø����λ�ã������ڵ���������ͨ������������������ɢ 
			{
				cout<<"���������������ܼ����޷�ͨ�����������������������ɢ"<<endl;
				return; 
			}
		}
	}	
}
void geli(pig p[][10],int x)			//ģ����� 
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
	pig p[100][10];					//��Ķ�ά���� 
	setpigs0(p);					//����Ȧ��ʼ�� 
	int b;
	cout<<"�������ʼ����������";
	cin>>b;		
	setpigs(p,b);					//����bͷ�� 
	cout<<"�����������ѯ����Ϣ:"; 
	string str;
	int x,y;
	while(cin>>str)
	{
		if(str=="��ѯ��Ȧ")
		{
			cout<<"��������Ҫ��ѯ��Ȧ�ı�ţ�";
			cin>>x;
			if(x>=0&&x<100)
			tongji(p,x);
			else
			cout<<"���������Ϣ����"; 
		} 
		else if(str=="��ѯ�����Ϣ")
		{
			cout<<"��������Ȧ��ź���ı�ţ�";
			cin>>x>>y;
			if((x>=0&&x<100)&&(y>=0&&y<10)) 
			chaxun(p,x,y);
			else
			cout<<"���������Ϣ����"<<endl;
		} 
		else if(str=="��ѯ��Ȧ��״")
		{
			zonglan(p); 
		} 
		else if(str=="�����۳��ļ۸�")
		{
			for(int i=0;i<90;i++)					//������������ 
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
			y=rand()%(1001-x);					//��������� 
			setpigs(p,y);
			cout<<"���β�������"<<y<<"ֻ"<<endl; 
		} 
		else if(str=="��������")
		{
			wen(p,x,y);
			cout<<"�Ƿ��ȡ�����ʩ��";
			cin>>str;
			if(str=="��")
			{
				geli(p,x);
			}
			else
			{
				if(check2(p))
				{
					cout<<"����������ķ����м������������ȫ������"; 
				}
				else 
				{
					cout<<increase(p)<<"�����ȫ������"<<endl; 
				} 
			}
			
		}
		else 
		cout<<"���������Ϣ����"; 
		cout<<"�����������ѯ����Ϣ:"; 
	}
	return 0;	
} 
