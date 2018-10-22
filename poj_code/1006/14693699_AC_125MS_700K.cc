/*--------------------------------------------
 * File Name: POJ 1006
 * Author: Baileys Wu
 * Mail: wulidan0530@live.com
 * Created Time: 2015-09-03 19:46:25
--------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 10000
int extend_Euclid(int a, int b, int &x, int &y){
    if(b==0){
    x = 1; y = 0;
    return a;
    }
    int r = extend_Euclid(b, a%b, y, x);
    y -= a/b*x;
    return r;
}
int X[N], Y[N], l[3], pp[3]={23,28,33};
int equation(int a, int b, int c)
{
	//printf("%dx + %dy = %d\n", a,b,c);
	int x, y;
	int g = extend_Euclid(a, b, x, y);
	if(c % g)
		return 0;    //表示无解
	x *= c/g, y *= c/g;
	for(int k = 0;k < g;k++)
	{
		X[k] = (x+b/g*k)%b;
		Y[k] = (c-a*X[k])/b;
		//printf("k---%d %d\n", X[k], Y[k]);
	}
	return g;
}
//ax=b(mod m)
int mod(int a, int b, int m)
{
	int n = equation(a, m, b);
}
int lcm(int a, int b)
{
	int x, y;
	int r = extend_Euclid(a, b, x, y);
	return a/r*b;
}
int eq_set()
{
	int d;
	int n = 3, b1, m1, b2, m2, m;
	//while(~scanf("%d", &n))
	//{
		//scanf("%d%d", &b1, &m1);
		b1 = l[0], m1 = pp[0];
		n--;
		int r = 1;
		int i = 1;
		while(n--)
		{
			//scanf("%d%d", &b2, &m2);
			b2 = l[i]; m2 = pp[i++];
			//if(!r)
			//	continue;
			r = equation(m1, m2, b2-b1);
			//if(!r)
			//	continue;
			b1 += m1*X[0];
			m1 = lcm(m1, m2);
			b1 = (b1%m1+m1)%m1;
			//printf("==%d %d\n", b1, m1);
		}
		/*if(!r)
		{
			printf("NO\n\n");
			continue;
		}*/
		//mod(1, b1, m1);
		scanf("%d", &d);
		printf("%d days.\n", ((b1-d)%m1+m1-1)%m1+1);
	//}
	return 0;
}
int main()
{
	int o = 0;
	while(~scanf("%d%d%d", &l[0], &l[1], &l[2]))
	{
		if(l[0] == -1)
			break;
		printf("Case %d: the next triple peak occurs in ", ++o);
		eq_set();
	}
}
