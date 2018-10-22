/*--------------------------------------------
 * File Name: POJ 3696
 * Author: Danliwoo
 * Mail: Danliwoo@outlook.com
 * Created Time: 2015-10-02 14:26:08
--------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 44725
int num[N], prim[N], cnt = 0;
void get_prim()
{
	for(int i = 0;i < N;i++) num[i] = i;
	for(int i = 2;i < N;i++) if(num[i])
	{
		for(int j = i*i;j < N;j += i)
			num[j] = 0;
		prim[cnt++] = i;
	}
}
int phi(int n)
{
	int ans = n;
	for(int i = 0;prim[i]*prim[i]<=n;i++) if(n%prim[i] == 0)
	{
		ans -= ans/prim[i];
		while(n%prim[i] == 0) n /= prim[i];
	}
	return ans;
}
int gcd(int a, int b)
{
	return b == 0?a:gcd(b, a%b);
}
int po(int a, int k, int m)
{
	if(k == 0) return 1;
	int t = po(a, k/2, m);
	t = t*t%m;
	if(k & 1LL) t *= a;
	return t%m;
}
int solve(int x, int p, int m, int f)
{
	int d = po(10, x, m);
	//printf("s -- %d %d %d %d %d\n", x, p, m, f, d);
	if(d == 1)
	{
		if(x%p == 0)
			return solve(x/p, p, m, f+1);
		else
			return x;
	}
	if(f == 0) return x;
	return x*p;
}
int main()
{
	get_prim();
	int n, o = 0;
	while(scanf("%d", &n), n)
	{
		printf("Case %d: ", ++o);
		int m = 9*n/gcd(n, 8);
		if(gcd(m,10)!=1)
		{
			printf("0\n");
			continue;
		}
		int x = phi(m);
		//printf("%d %d %d\n", n, m, x);
		if(po(10, 1, m) == 1)
		{
			printf("1\n");
			continue;
		}
		int ans = x, t = x;
		for(int i = 0; prim[i]*prim[i] <= x;i++) if(ans%prim[i] == 0)
		{
			while(t % prim[i] == 0) t /= prim[i];
			ans = solve(ans, prim[i], m, 0);
			//printf("pp %d %d\n", prim[i], ans);
		}
		//printf("t--%d\n", t);
		if(t != 1)
			ans = solve(ans, t, m, 0);
		if(ans == x)
			printf("0\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}