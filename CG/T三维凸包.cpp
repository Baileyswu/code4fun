#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;

const int N=505;
const double eps=0.000001;

struct Point
{
	double x,y,z;
	Point(){}
	Point(double _x,double _y,double _z)
	{
		x=_x; y=_y;	z=_z;
	}
	Point operator-(Point t1)//向量减法
	{
		return Point(x-t1.x,y-t1.y,z-t1.z);
	}
	Point operator*(Point t2)//叉积
	{
		return Point(y*t2.z-t2.y*z,z*t2.x-x*t2.z,x*t2.y-y*t2.x);
	}
	double operator^(Point t3)//点积
	{
		return x*t3.x+y*t3.y+z*t3.z;
	}
}point[N];

struct Plane
{
	int a,b,c;//a,b,c为三个点的编号，a,b,c要满足从凸包外面看成右手系
	bool in;//表示该平面是否在凸包内
}plane[N*10];

void Swap(Point &a,Point &b)
{
	Point c;
	c=a; a=b; b=c;
}

int n,plen;//计算过的面的个数
int edge[N][N];

void dfs(int p,int t);

double vol(Point p,Plane f)//p与平面abc组成的四面体的有向体积的6倍
{
	Point a=point[f.a]-p,b=point[f.b]-p,c=point[f.c]-p;
	return (a*b)^c;
}

double vlen(Point a)//求向量a的模
{
	return sqrt(a.x*a.x+a.y*a.y+a.z*a.z);
}

void deal(int p,int t1,int t2)
{
	int t=edge[t1][t2];//搜索与该边相邻的另外一个平面
	if(plane[t].in)
		if(vol(point[p],plane[t])>eps)	dfs(p,t);
		else
		{
			Plane add;
			add.a=t2,add.b=t1,add.c=p,add.in=true;//这里注意顺序,就可以不用Swap了,add.a,add.b,add.c要成右手系
			edge[add.a][add.b]=edge[add.b][add.c]=edge[add.c][add.a]=plen;
			plane[plen++]=add;
		}
}

void dfs(int p,int t)//递归搜索所有应该从凸包内删除的面
{
	plane[t].in=false;
	deal(p,plane[t].b,plane[t].a);//注意:a和b的顺序刚好跟下面的相反,为的就是搜索与边(point[plane[t].a],point[plane[t].b])相邻的另外一个平面
	deal(p,plane[t].c,plane[t].b);
	deal(p,plane[t].a,plane[t].c);
}

int solve(int n)//增量法,有n个点,返回计算过的平面个数,若无法构成凸包,则返回-1
{
	if(n<4)//如果点数小于,则无法构成凸包,若已保证点数大于或等于4,可略去
	return -1;
	plen=0;//计算过的面的个数
	Plane add;
	for(int i=0;i<4;i++)
	{
		add.a=(i+1)%4,add.b=(i+2)%4,add.c=(i+3)%4,add.in=true;
		if(vol(point[i],add)>0)	swap(add.a,add.b);
		edge[add.a][add.b]=edge[add.b][add.c]=edge[add.c][add.a]=plen;//记录与该边相邻的其中一个面,并且该顺序在该面内成右手系
		plane[plen++]=add;
	}
	for(int i=4;i<n;i++)
		for(int j=0;j<plen;j++)
			if(plane[j].in && vol(point[i],plane[j])>eps)
			{
				dfs(i,j);
				break;
			}
	return plen;
}

double area(Plane a)//求平面三角形的面积 
{
	return vlen((point[a.b]-point[a.a])*(point[a.c]-point[a.a]))/2.0;
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)	cin>>point[i].x>>point[i].y>>point[i].z;
	int m=solve(n);
	if(m==-1)	printf("0.000\n");
	else
	{
		double ans=0.0;
		for(int i=0;i<m;i++)	if(plane[i].in) ans+=area(plane[i]);
		printf("%.3lf\n",ans);
	}
	return 0;
}
