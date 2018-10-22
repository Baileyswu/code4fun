/*--------------------------------------------
 * File Name: POJ 1995
 * Author: Baileys Wu
 * Mail: wulidan0530@live.com
 * Created Time: 2015-09-16 00:53:02
--------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define LL long long
LL M;
LL po(LL a, LL b)
{
	if(b == 0)
		return 1;
	if(b == 1)
		return a;
	LL t = po(a, b/2);
	t = t*t%M;
	if(b&1LL)
		t *= a;
	return t%M;
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		LL n, a, b, ans = 0;
		scanf("%lld%lld", &M, &n);
		while(n--)
		{
			scanf("%lld%lld", &a, &b);
			ans += po(a, b);
			ans %= M;
		}
		printf("%lld\n", ans);
	}
	return 0;
}