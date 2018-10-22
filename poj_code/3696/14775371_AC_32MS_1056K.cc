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
#define LL long long
LL num[N], prim[N];
int cnt = 0;
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
LL phi(LL n)
{
	LL ans = n;
	for(int i = 0;prim[i]*prim[i]<=n;i++) if(n%prim[i] == 0)
	{
		ans -= ans/prim[i];
		while(n%prim[i] == 0) n /= prim[i];
	}
	if(n != 1)
		ans -= ans/n;
	return ans;
}
LL gcd(LL a, LL b)
{
	return b == 0?a:gcd(b, a%b);
}
LL mult(LL a, LL b, LL c)
{
	a %= c; b %= c;
	LL ret = 0, tmp = a;
	while(b)
	{
		if(b & 1LL)
		{
			ret += tmp;
			if(ret > c) ret -= c;
		}
		tmp <<= 1;
		if(tmp > c) tmp -= c;
		b >>= 1;
	}
	return ret;
}
LL po(LL a, LL k, LL m)
{
	if(k == 0) return 1;
	if(k == 1) return a;
	LL t = po(a, k/2, m);
	t = mult(t, t, m);
	if(k & 1LL) t *= a;
	//printf("po %lld %lld %lld %lld\n", a, k, m, t%m);
	return t%m;
}
LL solve(LL x, LL p, LL m, LL f)
{
	LL d = po(10, x, m);
	//printf("s -- %lld %lld %lld %lld %lld\n", x, p, m, f, d);
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
	int o = 0;
	LL n;
	while(scanf("%lld", &n), n)
	{
		printf("Case %d: ", ++o);
		LL m = n/gcd(n, 8)*9;
		if(gcd(m,10) != 1)
		{
			printf("0\n");
			continue;
		}
		LL x = phi(m);
		//printf("%lld %lld %lld\n", n, m, x);
		if(po(10, 1, m) == 1)
		{
			printf("1\n");
			continue;
		}
		LL ans = x, t = x;
		for(int i = 0; prim[i]*prim[i] <= x && i < cnt;i++) if(ans%prim[i] == 0)
		{
			while(t % prim[i] == 0) t /= prim[i];
			//printf("pp %lld %lld %lld\n", prim[i], ans, t);
			ans = solve(ans, prim[i], m, 0);
			//printf("pp %lld %lld %lld\n", prim[i], ans, t);
		}
		//printf("t--%lld\n", t);
		if(t != 1)
			ans = solve(ans, t, m, 0);
		if(ans == x)
			printf("0\n");
		else
			printf("%lld\n", ans);
	}
	return 0;
}