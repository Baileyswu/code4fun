#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 1100
int a[N][N], n, C[N][N], L[N];
void set()
{
	for(int i = 0;i < N;i++)
		L[i] = i&((i-1)^i);
}
void init()
{
	scanf("%d", &n);
	memset(a, 0, sizeof(a));
	memset(C, 0, sizeof(C));
}
void add()
{
	int x, y, z;
	scanf("%d%d%d", &x, &y, &z);
	x++; y++;
	int t = max(0, a[x][y]+z)-a[x][y];
	a[x][y] += z;
	while(x <= n)
	{
		int ty = y;
		while(ty <= n)
		{
			C[x][ty] += t;
			ty += L[ty];
		}
		x += L[x];
	}
}
int sum(int x, int y)
{
	//printf("%d %d ", x, y);
	int r = 0;
	while(x > 0)
	{
		int ty = y;
		while(ty > 0)
		{
			r += C[x][ty];
			ty -= L[ty];
		}
		x -= L[x];
	}
	//printf("%d\n", r);
	return r;
}
void query()
{
	int x1, y1, x2, y2;
	scanf("%d%d%d%d",&x1, &y1, &x2, &y2);
	x2++; y2++;
	int ans = sum(x2,y2)-sum(x1,y2)-sum(x2,y1)+sum(x1,y1);
	printf("%d\n", ans);
}
int pr()
{
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			printf("%d%c", a[i][j], " \n"[j==n]);
	printf("\n");
}
int main()
{
	set();
	int command;
	while(~scanf("%d", &command))
	{
		int st = 0;
		switch(command)
		{
			case 0: init(); break;
			case 1: add(); break;
			case 2: query(); break;
			default: st = 1; break;
		}
		if(st)
			break;
		//pr();
	}
	return 0;
}