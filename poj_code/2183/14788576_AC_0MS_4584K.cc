/*--------------------------------------------
 * File Name: POJ 2183
 * Author: Danliwoo
 * Mail: Danliwoo@outlook.com
 * Created Time: 2015-10-06 18:38:22
--------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
int a[1000000];
int get(int x)
{
	x /= 10;
	x %= 10000;
	x = x*x;
	return x%1000000;
}
int main()
{
	int n;
	while(~scanf("%d", &n))
	{
		memset(a, 0, sizeof(a));
		int co = 0;
		while(a[n] == 0)
		{
			a[n] = ++co;
			//printf("%6d %d\n", n, a[n]);
			n = get(n);
		}
		printf("%d %d %d\n", n, co-a[n]+1, co);
	}
	return 0;
}