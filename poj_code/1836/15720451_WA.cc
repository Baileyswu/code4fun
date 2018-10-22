#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 1100
double a[N];
int x[N], y[N];
int main()
{
	int n;
	while(~scanf("%d", &n)){
		memset(x, 0, sizeof(x));
		memset(y, 0, sizeof(y));
		a[0] = -1;
		for(int i = 1;i <= n;i++)
			scanf("%lf", &a[i]);
		x[0] = 0;
		for(int i = 1;i <= n;i++)
			for(int j = 0;j < i;j++)
				if(a[i] > a[j] || fabs(a[i]-a[j]) < 1e-8){
					// printf("%d < %d\n", j, i);
					x[i] = max(x[i], x[j]+1);
				}
		a[n+1] = 100;
		y[n+1] = 0;
		for(int i = n;i >= 1;i--)
			for(int j = n+1;j > i;j--)
				if(a[i] > a[j] || fabs(a[i]-a[j]) < 1e-8)
					y[i] = max(y[i], y[j]+1);
		// for(int i = 1;i <= n;i++)
		// 	printf("%d%c", x[i], " \n"[i==n]);
		// for(int i = 1;i <= n;i++)
		// 	printf("%d%c", y[i], " \n"[i==n]);
		int ans = 0;
		for(int i = 1;i <= n;i++)
			ans = max(ans, x[i] + y[i]-1);
		printf("%d\n", n-ans);
	}
	return 0;
}