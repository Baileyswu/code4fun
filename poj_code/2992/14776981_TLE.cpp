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
int a[500][500], b[500];
void get(int n)
{
	int sum = n;
	for(int i = 0;i < cnt && prim[i] <= n;i++) if(n % prim[i] == 0)
	{
		while(n % prim[i] == 0)
		{
			n /= prim[i];
			a[sum][prim[i]]++;
		}
	}
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
			int b = 0;
			for(int i = n-k+1;i <= n;i++)
				b += a[i][prim[j]];
			for(int i = 1;i <= k;i++)
				b -= a[i][prim[j]];
			ans *= 1LL*(b+1);
		}
		printf("%lld\n", ans);
	}
	return 0;
}