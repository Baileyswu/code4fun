#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 1100
int n, tree[3*N][3*N], ans;
void up(int xrt, int yrt, int yb, int ye, int yl, int yr)
{
	if(yr < yb || ye < yl || yl > yr) return;
	if(yl <= yb && ye <= yr)
	{
		tree[xrt][yrt] ^= 1;
		return;
	}
	int ym = yb+ye >> 1;
	up(xrt, yrt<<1, yb, ym, yl, min(ym, yr));
	up(xrt, yrt<<1|1, ym+1, ye, max(ym+1, yl), yr);
}
void update(int xrt, int xb, int xe, int xl, int xr, int yl, int yr)
{
	if(xr < xb || xe < xl || xl > xr) return;
	if(xl <= xb && xe <= xr)
	{
		up(xrt, 1, 1, n, yl, yr);
		return;
	}
	int xm = xb+xe >> 1;
	update(xrt<<1, xb, xm, xl, min(xr, xm), yl, yr);
	update(xrt<<1|1, xm+1, xe, max(xm+1, xl), xr, yl, yr);
}
void que(int xrt, int yrt, int yb, int ye, int yl, int yr)
{
	if(yr < yb || ye < yl || yl > yr) return;
	ans ^= tree[xrt][yrt];
	if(yl <= yb && ye <= yr) return;
	int ym = yb+ye >> 1;
	que(xrt, yrt<<1, yb, ym, yl, min(ym, yr));
	que(xrt, yrt<<1|1, ym+1, ye, max(ym+1, yl), yr);
}
void query(int xrt, int xb, int xe, int xl, int xr, int yl, int yr)
{
	if(xr < xb || xe < xl || xl > xr) return;
	que(xrt, 1, 1, n, yl, yr);
	if(xl <= xb && xe <= xr) return;
	int xm = xb+xe >> 1;
	query(xrt<<1, xb, xm, xl, min(xr, xm), yl, yr);
	query(xrt<<1|1, xm+1, xe, max(xm+1, xl), xr, yl, yr);
}
int pr()
{
	for(int i = 1;i <= 3*n;i++)
		for(int j = 1;j <= 3*n;j++)
			printf("%d%c", tree[i][j], " \n"[j==3*n]);
	printf("\n");
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int m;
		while(~scanf("%d%d", &n, &m))
		{
			memset(tree, 0, sizeof(tree));
			while(m--)
			{
				char str[10];
				scanf("%s", str);
				switch(str[0])
				{
					case 'C':
						int x1, y1, x2, y2;
						scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
						update(1, 1, n, x1, x2, y1, y2);
						break;
					case 'Q':
						int x, y;
						scanf("%d%d", &x, &y);
						ans = 0;
						query(1, 1, n, x, x, y, y);
						printf("%d\n", ans);
						break;
				}
				// pr();
			}
			if(T)
				printf("\n");
		}
	}
	return 0;
}