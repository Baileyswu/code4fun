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
void set()
{
	for(int i = 0;i < 500;i++) num[i] = 1;
	for(int i = 2;i < 500;i++) if(num[i])
	{
		prim[cnt++] = i;
		for(int j = i*i;j < 500;j += i)
			num[j] = 0;
	}
	// for(int i = 0;i < cnt;i++)
	// 	printf("%d %d\n", i, prim[i]);
}
int a[500];
void get(int n, int f)
{
	for(int i = 0;i < cnt && prim[i] <= n;i++) if(n % prim[i] == 0)
	{
		while(n % prim[i] == 0)
		{
			n /= prim[i];
			a[prim[i]] += f;
		}
	}
	//printf("get %d %d\n", n, f);
	// for(int i = 0;i < cnt;i++) if(a[prim[i]])
	// {
	// 	printf("%d %d\n", prim[i], a[prim[i]]);
	// }
}
void solve()
{
	long long r = 1;
	for(int i = 0;i < cnt;i++) if(a[prim[i]])
	{
		//printf("%d %d %d\n", prim[i], a[prim[i]], r);
		r *= 1LL*a[prim[i]]+1;
	}
	printf("%lld\n", r);
}
int main()
{
	set();
	int n, k;
	while(~scanf("%d%d", &n, &k))
	{
		memset(a, 0, sizeof(a));
		for(int i = n-k+1;i <= n;i++)
			get(i, 1);
		for(int i = 1;i <= k;i++)
			get(i, -1);
		solve();
	}
	return 0;
}