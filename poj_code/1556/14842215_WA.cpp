/*--------------------------------------------
 * File Name: POJ 1556
 * Author: Danliwoo
 * Mail: Danliwoo@outlook.com
 * Created Time: 2015-10-23 17:41:32
--------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define eps 1e-8
int n;
double d[200][200], ans[200];
struct point
{
	double x, y;
	void pr(){
		printf("(%.2lf %.2lf) ", x, y);
	}
	point operator - (const point &b) const{
		point c;
		c.x = x-b.x, c.y = y-b.y;
		return c;
	}
	point(){}
	point(double x, double y):x(x), y(y){}
}p[200];
point start = point(0, 5), end = point(10, 5);
double cross(point P, point Q){
	return P.x*Q.y - P.y*Q.x;
}
double dis(point P, point Q){
	return sqrt(pow(P.x-Q.x, 2)+pow(P.y-Q.y, 2));
}
bool check(point P, point Q, int a, int b)
{
	for(int i = a;i <= b;i++)
	{
		for(int j = 0;j < 3;j++)
		{
			double sa = cross(p[6*i+2*j]-P, p[6*i+2*j]-Q);
			double sb = cross(p[6*i+2*j+1]-P, p[6*i+2*j+1]-Q);
			if(sa*sb < 0) return false;
		}
	}
	return true;
}
void add(int u, int v, double c){
	// if(u == 0) start.pr();
	// else p[u].pr();
	// if(v == 6*n) end.pr();
	// else p[v].pr();
	// printf("%d %d %.3f\n", u, v, c);
	d[u][v] = c;
}
void set()
{
	for(int i = 0;i <= 6*n;i++)
		for(int j = 0;j <= 6*n;j++)
			d[i][j] = -1;
	if(check(start, end, 0, n-1))
		add(0, 6*n, dis(start, end));
	for(int i = 0;i < n;i++)
		for(int j = 1;j < 5;j++)
		{
			if(check(start, p[6*i+j], 0, i-1))
				add(0, 6*i+j, dis(start, p[6*i+j]));
			if(check(end, p[6*i+j], i+1, n-1))
				add(6*i+j, 6*n, dis(end, p[6*i+j]));
			for(int k = i+1;k < n;k++)
				for(int l = 1;l < 5;l++)
				{
					if(check(p[6*i+j], p[6*k+l], i+1, k-1))
						add(6*i+j, 6*k+l, dis(p[6*i+j], p[6*k+l]));
				}
		}
	// for(int i = 0;i <= 6*n;i++)
	// 	for(int j = 0;j <= 6*n;j++)
	// 		printf("%.2f%c", d[i][j], " \n"[j==6*n]);
}
int sel[200], vis[200];
void dij()
{
	memset(vis, 0, sizeof(vis));
	for(int i = 0;i <= 6*n;i++) ans[i] = -1;
	int top = 0, k;
	sel[top++] = 0; vis[0] = 1; ans[0] = 0;
	while(sel[top-1] != 6*n)
	{
		//printf("top %d %d\n", top, sel[top-1]);
		double t = 1e10;
		for(int o = 0;o < top;o++)
		{
			int i = sel[o];
			for(int j = 1;j <= 6*n;j++) if(!vis[j] && d[i][j] > 0)
			{
				// printf("i, j %d %d %d %.3lf", i, j, vis[j], d[i][j]);
				// printf(" compare %.3lf %.3lf\n", ans[j], d[i][j]+ans[i]);
				if(ans[j] < 0 || d[i][j] + ans[i] < ans[j])
					ans[j] = ans[i]+d[i][j];
				if(t > ans[j]){
					t = ans[j];
					k = j;
				}
				//printf(" %.5lf %.5lf\n", t, ans[j]);
			}
		}
		vis[k] = 1;
		sel[top++] = k;
	}
	printf("%.2f\n", ans[6*n]);
}
int main()
{
	while(scanf("%d", &n))
	{
		if(n == -1) break;
		double tx, ty[6];
		for(int i = 0;i < n;i++)
		{
			scanf("%lf", &tx);
			for(int j = 1;j < 5;j++)
			{
				scanf("%lf", &ty[j]);
				p[6*i+j] = point(tx, ty[j]);
			}
			p[6*i] = point(tx, 0);
			p[6*i+5] = point(tx, 10);
		}
		set();
		dij();
	}
	return 0;
}