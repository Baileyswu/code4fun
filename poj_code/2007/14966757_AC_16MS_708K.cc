/*--------------------------------------------
 * File Name: POJ 2007
 * Author: Danliwoo
 * Mail: Danliwoo@outlook.com
 * Created Time: 2015-12-02 23:54:52
--------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 1005
struct point
{
	double x, y;
	int flag;
	void sc(){
		scanf("%lf%lf", &x, &y);
		flag = 0;
	}
	point(){}
	point(double x, double y):x(x), y(y){}
	double operator * (const point b){
		return x * b.x + y * b.y;
	}
	double dis(){
		return sqrt(x*x+y*y);
	}
}p[N], A, B;
int ord[N], n;
int cp(double x)
{
	if(fabs(x) < 1e-8) return 0;
	return x > 0 ? 1 : -1;
}
void pr(int x)
{
	for(int i = 0;i < n;i++)
	{
		int s = (i+x)%n;
		printf("(%.0f,%.0f)\n", p[ord[s]].x, p[ord[s]].y);
	}
}
void solve()
{
	int on = 0;
	double d = p[0].y, temp;
	int st;
	for(int i = 1;i < n;i++)
	{
		if(p[i].y < d)
		{
			d = p[i].y;
			st = i;
		}
	}
	p[st].flag = 1;
	A = point(1, 0);
	double ans = 0;
	for(;;)
	{
		ord[on++] = st;
		int s = st%n, good;
		for(int j = 1;j < n;j++)
		{
			int t = (s+j)%n;
			B = point(p[t].x-p[s].x, p[t].y-p[s].y);
			// printf("s, t %d %d\n", s, t);
			if(j == 1)
			{
				temp = A*B/B.dis();
				good = t;
			}
			else
			{
				double k = A*B/B.dis();
				if(k > temp)
				{
					temp = k;
					good = t;
				}
			}
		}
		// printf("good %d\n", good);
		A = point(p[good].x-p[s].x, p[good].y-p[s].y);		
		ans += A.dis();
		// printf("ans --%.2f\n", ans);
		if(p[good].flag == 1)
		{
			ord[on++] = good;
			break;
		}
		p[good].flag = 1;
		st = good;
	}
	for(int i = 0;i < on;i++)
		if(!cp(p[ord[i]].x) && !cp(p[ord[i]].y))
			pr(i);
}

int main()
{
	n = 0;
	while(~scanf("%lf%lf", &p[n].x, &p[n].y))
	{
		p[n].flag = 0;
		n++;
	}
	solve();
	return 0;
}