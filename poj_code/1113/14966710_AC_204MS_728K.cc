/*--------------------------------------------
 * File Name: POJ 1113
 * Author: Danliwoo
 * Mail: Danliwoo@outlook.com
 * Created Time: 2015-12-02 23:15:00
--------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 1005
int n;
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
double solve()
{
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
			return ans;
		p[good].flag = 1;
		st = good;
	}
}
int main()
{
	int r;
	while(~scanf("%d%d", &n, &r))
	{
		for(int i = 0;i < n;i++)
			p[i].sc();
		double ans = solve() + 2*acos(-1)*r;
		// printf("%f\n", ans);
		//ans /= 12;
		printf("%.0f\n", ans);
	}
	return 0;
}