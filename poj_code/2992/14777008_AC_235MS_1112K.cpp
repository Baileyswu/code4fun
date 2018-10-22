/*--------------------------------------------
 * File Name: POJ 2992
 * Author: Danliwoo
 * Mail: Danliwoo@outlook.com
 * Created Time: 2015-10-03 09:53:42
--------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
int num[500], prim[500], cnt = 0;
int a[500][500];
void get(int n)
{
	int sum = n;
	for(int i = 0;i < cnt && prim[i] <= sum;i++)
	{
		int t = 0;
		while(n % prim[i] == 0)
		{
			n /= prim[i];
			t++;
		}
		a[sum][prim[i]] = a[sum-1][prim[i]]+t;
	}
	// printf("get  %d\n", sum);
	// for(int i = 0;i < cnt;i++) if(a[sum][prim[i]])
	// 	printf("%d %d\n", prim[i], a[sum][prim[i]]);
}
void set()
{
	for(int i = 0;i < 500;i++) num[i] = 1;
	for(int i = 2;i < 500;i++) if(num[i])
	{
		prim[cnt++] = i;
		for(int j = i*i;j < 500;j += i)
			num[j] = 0;
	}
	memset(a, 0, sizeof(a));
	for(int i = 1;i < 500;i++)
		get(i);
}

int main()
{
	set();
	int n, k;
	while(~scanf("%d%d", &n, &k))
	{
		long long ans = 1;
		for(int j = 0;j < cnt;j++)
		{
			//printf("prim[j] %d %d %d\n", a[n][prim[j]], a[n-k][prim[j]], a[k][prim[j]]);
			ans *= 1LL*(a[n][prim[j]]-a[n-k][prim[j]]-a[k][prim[j]]+1);
		}
		printf("%lld\n", ans);
	}
	return 0;
}