/*--------------------------------------------
 * File Name: POJ 2480
 * Author: Danliwoo
 * Mail: Danliwoo@outlook.com
 * Created Time: 2015-10-03 17:36:23
--------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 50000
#define LL long long
int num[N], prim[N], cnt = 0;
void set()
{
	for(int i = 0;i < N;i++) num[i] = 1;
	for(int i = 2;i < N;i++) if(num[i])
	{
		prim[cnt++] = i;
		for(LL j = 2*i;j < N;j += (LL)i) if(num[j])
			num[j] = 0;
	}
}
void solve(LL n)
{
	LL sum = n, ans = 1;
	for(int i = 0;i < cnt && prim[i]*prim[i] <= n;i++) if(sum % prim[i] == 0)
	{
		LL r = 0, p = 1;
		while(sum % prim[i] == 0)
		{
			sum /= prim[i];
			r++;
			p *= prim[i];
		}
		LL t = 1LL*r*(p-p/prim[i])+p;
		ans = ans*t;
		//printf("p %d %lld %lld %lld\n", prim[i], r, t, ans);
	}
	if(sum != 1)
	{
		ans *= 2*sum-1;
		//printf("remain %lld %lld %lld\n", sum, 2*sum-1, ans);
	}
	printf("%lld\n", ans);
}
int main()
{
	set();
	LL n;
	while(~scanf("%lld", &n))
		solve(n);
	return 0;
}