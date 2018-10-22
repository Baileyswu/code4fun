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
#define N 7100
int num[N], prim[N], cnt = 0;
void set()
{
	for(int i = 0;i < 7100;i++) num[i] = 1;
	for(int i = 2;i < 7100;i++) if(num[i])
	{
		prim[cnt++] = i;
		for(int j = i*i;j < 7100;j += i)
			num[j] = 0;
	}
}
int extend_Euclid(int a, int b, int &x, int &y){
    if(b==0){
    x = 1; y = 0;
    return a;
    }
    int r = extend_Euclid(b, a%b, y, x);
    y -= a/b*x;
    return r;
}
int anti(int a, int m)
{
	int x, y;
	extend_Euclid(a, m, x, y);
	return (x%m+m)%m;
}
int po(int a, int k, int m)
{
	if(k == 0) return 1;
	int t = po(a, k/2, m);
	t = t*t%m;
	if(k & 1LL)
		t *= a;
	return t%m;
}
int main()
{
	set();
	int a, b, m = 9901;
	while(~scanf("%d%d", &a, &b))
	{
		int ans = 1;
		int t = a;
		for(int i = 0;i < cnt && prim[i]*prim[i] <= a;i++) if(t%prim[i] == 0)
		{
			int s = 0;
			while(t % prim[i] == 0)
			{
				t /= prim[i];
				s++;
			}
			ans = ans*anti(prim[i]-1, m)%m*(po(prim[i], (s%m*b%m+1)%m, m)-1)%m;
		}
		//printf("t %d\n", t);
		if(t != 1)
			ans = ans*anti(t-1, m)%m*(po(t, b%m+1, m)-1)%m;
		printf("%d\n", ans);
	}
	return 0;
}