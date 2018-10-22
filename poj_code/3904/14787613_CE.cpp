/*--------------------------------------------
 * File Name: POJ 3904
 * Author: Danliwoo
 * Mail: Danliwoo@outlook.com
 * Created Time: 2015-10-06 12:36:28
--------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 10001
#define LL long long
int mobi[N]={0,1}, num[N], prim[N], cnt = 0, a[N];
void set()
{
	for(int i = 0;i < N;i++) num[i] = 1;
	for(int i = 2;i < N;i++)
	{
		if(num[i])
		{
			prim[cnt++] = i;
			mobi[i] = -1;
		}
		for(int j = 0;j < cnt && prim[j]*i < N;j++)
		{
			num[prim[j]*i] = 0;
			if(i % prim[j] == 0)
			{
				mobi[prim[j]*i] = 0;
				break;
			}
			mobi[prim[j]*i] = -mobi[i];
		}
	}
}
void sep(int n)
{
	int s = sqrt(n);
	for(int i = 1;i <= s;i++) if(n % i == 0)
	{
		a[i]++;
		a[n/i]++;
	}
	if(s*s == n)
		a[s]--;
}
LL get(LL i)
{
	return i*(i-1)*(i-2)*(i-3)/24;
}
int main()
{
	set();
	int n, tp;
	while(~scanf("%d", &n))
	{
		memset(a, 0, sizeof(a));
		for(int i = 0;i < n;i++)
		{
			scanf("%d", &tp);
			sep(tp);
		}
		//for(int i = 0;i < N;i++) if(a[i])
		//	printf("%d %d\n", i, a[i]);
		LL ans = 0;
		for(LL i = 1;i < N;i++)
		{
			if(mobi[i] == 0 || a[i] < 4) continue;
			ans += get(a[i])*mobi[i];
		}
		printf("%lld\n", ans);
	}
	return 0;
}