/*--------------------------------------------
 * File Name: POJ 2653
 * Author: Danliwoo
 * Mail: Danliwoo@outlook.com
 * Created Time: 2015-10-23 20:44:04
--------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define eps 1e-8
#define N 100010
struct point
{
	double x, y;
	void sc(){
		scanf("%lf%lf", &x, &y);
	}
	point operator - (const point &b) const{
		point c;
		c.x = x-b.x, c.y = y-b.y;
		return c;
	}
	point(){}
	point(double x, double y):x(x), y(y){}
}p[2*N];
double cross(point P, point Q){
	return P.x*Q.y - P.y*Q.x;
}
int stk[N], top;
bool h(point A, point B, point C, point D)
{
	double sa = cross(C-A, D-A);
	double sb = cross(C-B, D-B);
	//printf("%.3f %.3f\n", sa, sb);
	if(sa * sb > eps) return false;
	return true;
}
bool check(point A, point B, point C, point D)
{
	if(h(A, B, C, D) && h(C, D, A, B)) return true;
	return false;
}
int main()
{
	int n;
	while(scanf("%d", &n), n)
	{
		int top = 0;
		for(int i = 0;i < n;i++)
		{
			p[2*i].sc();
			p[2*i+1].sc();
		}
		memset(stk, 0, sizeof(stk));
		for(int j = n-1;j >= 0;j--) if(!stk[j])
			for(int i = 0;i < j;i++) if(!stk[i])
				if(check(p[2*i], p[2*i+1], p[2*j], p[2*j+1]))
					stk[i] = 1;
		printf("Top sticks: ");
		for(int i = 0;i < n;i++) if(!stk[i])
			stk[top++] = i;
		for(int i = 0;i < top;i++)
			printf("%d%c%c", stk[i]+1, ",."[i==top-1], " \n"[i == top-1]);
	}
	return 0;
}