/*--------------------------------------------
 * File Name: POJ 1066
 * Author: Danliwoo
 * Mail: Danliwoo@outlook.com
 * Created Time: 2015-10-24 19:23:54
--------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 50
#define eps 1e-8
int n, pn;
struct point
{
	double x, y;
	int bu;
	point(){}
	point(double x, double y):x(x), y(y){}
	point operator - (const point &b)const{
		return point(x-b.x, y-b.y);
	}
	double operator ^ (const point &b)const{
		return x*b.y - y*b.x;
	}
	void sc(){
		scanf("%lf%lf", &x, &y);
	}
	void pr(){
		printf("(%.2f %.2f)\n", x, y);
	}
}start;
bool cmp(point P, point Q){
	if(fabs(P.x-Q.x) < eps) return P.y < Q.y;
	return P.x < Q.x;
}
struct line
{
	double a, b, c;
	int m;
	point in[N], s, e;
	void k(){
		a = s.y-e.y;
		b = e.x-s.x;
		c = s^e;
		m = 0;
	}
	void get(){
		s.sc(); e.sc();
		k();
	}
	void set(point x, point y){
		s = x, e = y;
		k();
	}
	void add(point P){
		in[m++] = P;
	}

	void sot(){
		sort(in, in+m, cmp);
	}
}L[N];
void init()
{
	point E1 = point(0,0), E2 = point(0,100);
	point E3 = point(100,100), E4 = point(100,0);
	L[n].set(E1, E2); L[n+1].set(E2, E3);
	L[n+2].set(E3, E4); L[n+3].set(E4, E1);
	for(int i = 0;i < n;i++)
		L[i].get();
	start.sc();
	for(int i = 0;i < n+4;i++)
		for(int j = i+1; j < n+4;j++)
		{
			double z = point(L[i].a, L[i].b)^point(L[j].a, L[j].b);
			if(fabs(z) < eps) continue;
			double x = point(-L[i].c, L[i].b)^point(-L[j].c, L[j].b);
			double y = point(L[i].a, -L[i].c)^point(L[j].a, -L[j].c);
			x /= z, y /= z;
			if(x < 0 || x > 100 || y < 0 || y > 100) continue;
			L[i].add(point(x, y));
			L[j].add(point(x, y));
		}
	for(int i = 0;i < n+4;i++)
	{
		L[i].sot();
		/*printf("%.3lf %.3lf %.3lf %d\n", L[i].a, L[i].b, L[i].c, L[i].m);
		L[i].s.pr(), L[i].e.pr();
		printf("+\n");
		for(int j = 0;j < L[i].m;j++)
			L[i].in[j].pr();
		printf("\n");*/
	}
}
int flag[N][N];
queue <point> Qu;
bool border(point P){
	return fabs(P.x) < eps || fabs(P.y) < eps || fabs(P.x-100)<eps || fabs(P.y-100)<eps;
}
int cross(point P, point Q, point O){
	double t = (P-O)^(Q-O);
	if(fabs(t) < eps) return 0;
	return t > 0? 1 : -1;
}
bool h(point A, point B, point C, point D){
	return cross(A, D, C)*cross(B, D, C) < 0;
}
bool check(point A, point B, point C, point D){
	return max(A.x,B.x) >= min(C.x,D.x)&&
		max(A.y,B.y) >= min(C.y,D.y)&&
		max(C.x,D.x) >= min(A.x,B.x)&&
		max(C.y,D.y) >= min(A.y,B.y)&&
		h(A, B, C, D) && h(C, D, A, B);
}
bool junc(point M, point S, int x){
	for(int i = 0;i < n+4;i++)
	{
		if(i == x) continue;
		if(check(M, S, L[i].s, L[i].e)) return true;
	}
	return false;
}
void bfs()
{
	memset(flag, 0, sizeof(flag));
	while(!Qu.empty()) Qu.pop();
	start.bu = 0;
	Qu.push(start);
	int ans = 1;
	while(!Qu.empty())
	{
		point st = Qu.front();  Qu.pop();
		//st.pr();
		for(int i = 0;i < n+4;i++)
		{
			for(int j = 1;j < L[i].m;j++) if(!flag[i][j])
			{
				point mid = point((L[i].in[j].x+L[i].in[j-1].x)/2, (L[i].in[j].y+L[i].in[j-1].y)/2);
				if(!junc(mid, st, i))
				{
					//printf("mid: ");
					mid.bu = st.bu+1;
					//printf("%d ", mid.bu);
					//mid.pr();
					flag[i][j] = 1;
					if(border(mid)){
						printf("Number of doors = %d\n", mid.bu);
						return;
					}
					Qu.push(mid);
					break;
				}
			}
		}
	}
}
int main()
{
	while(~scanf("%d", &n))
	{
		init();
		bfs();
	}
	return 0;
}
