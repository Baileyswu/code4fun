#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define ep 1e-8
struct node
{
	int x, y;	
}point[205];
double k[40000];
int cmp(double a, double b)
{
	return a < b;
}
int main()
{
	int n;
	while(~scanf("%d", &n))
	{
		int extra = 0, p = 0, ans = (n-1)*n/2;
		for(int i = 0;i < n;i++)
			scanf("%d%d", &point[i].x, &point[i].y);
		for(int i = 0;i < n;i++)
			for(int j = i+1;j < n;j++)
			{
				if(point[i].x == point[j].x)
					extra++;
				else
					k[p++] = 1.0*(point[i].y-point[j].y)/(point[i].x-point[j].x);
			}
		sort(k, k+p, cmp);
		for(int i = 1;i < p;i++)
		{
			if(fabs(k[i]-k[i-1]) < ep)
				ans--;
		}
		if(extra)
			ans -= extra-1;
		printf("%d\n", ans);
	}
	return 0;
}