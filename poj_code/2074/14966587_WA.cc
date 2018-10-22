/*--------------------------------------------
 * File Name: POJ 2074
 * Author: Danliwoo
 * Mail: Danliwoo@outlook.com
 * Created Time: 2015-12-02 17:48:54
--------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 1000
struct point
{
	double x1, x2, y, L, R;
	point(){}
	point(double x1, double x2, double y):x1(x1), x2(x2), y(y){}
	void sc(){
		scanf("%lf%lf%lf", &x1, &x2, &y);
	}
}top, bot, p[N];
int cp(double x)
{
	if(fabs(x) < 1e-8) return 0;
	return x > 0 ? 1 : -1;
}
int n;
void get(double sx, double sy, double ex,
	double ey, double &a, double &b, double &c)
{
	a = sy - ey;
	b = ex - sx;
	c = sx*ey - sy*ex;
}
bool cmp(point a, point b)
{
	return a.L < b.L || (!cp(a.L-b.L) && a.R < b.R);
}
double st[N], end[N];
double solve()
{
	for(int i = 0;i < n;i++)
	{
		if(cp(p[i].y-bot.y) <= 0 || cp(p[i].y - top.y) >= 0)
			p[i].R = p[i].L = bot.x1 - 1;
		else{
			double a, b, c;
			get(p[i].x1, p[i].y, top.x2, top.y, a, b, c);
			p[i].L = -(b*bot.y+c)/a;
			get(p[i].x2, p[i].y, top.x1, top.y, a, b, c);
			p[i].R = -(b*bot.y+c)/a;
		}
		// printf("%.2f %.2f\n", p[i].L, p[i].R);

	}
	sort(p, p+n, cmp);
	int all = 0;
	st[all] = p[0].L, end[all] = p[0].R;
	for(int i = 1;i < n;i++)
	{
		if(p[i].L > end[all])
		{
			all++;
			st[all] = p[i].L, end[all] = p[i].R;
		}
		else
			end[all] = max(end[all], p[i].R);
	}
	double cv = 0;
	for(int i = 0;i <= all;i++)
	{
		// printf("sort %.2f %.2f\n", st[i], end[i]);
		if(end[i] < bot.x1 || st[i] > bot.x2)
			continue;
		cv += min(end[i], bot.x2) - max(st[i], bot.x1);
		// printf("cover %.2f\n", cv);
	}
	cv = bot.x2 - bot.x1 - cv;
	if(cp(cv) <= 0) return -1;
	double ans = 0;
	for(int i = 0;i < all;i++)
	{
		double t = min(st[i+1], bot.x2)-max(end[i], bot.x1);
		ans = max(ans, t);
		// printf("ans %.2f\n", ans);
	}
	return ans;
}
int main()
{
	while(1)
	{
		top.sc();
		if(!cp(top.x1) && !cp(top.x2) && !cp(top.y))
			break;
		bot.sc();
		scanf("%d", &n);
		for(int i = 0;i < n;i++)
			p[i].sc();
		double ans = solve();
		if(ans < 0)
			printf("No View\n");
		else
			printf("%.2f\n", ans);
	}
	return 0;
}