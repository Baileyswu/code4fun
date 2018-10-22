/*--------------------------------------------
 * File Name: POJ 1284
 * Author: Danliwoo
 * Mail: Danliwoo@outlook.com
 * Created Time: 2015-10-01 21:37:44
--------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int phi(int n)
{
	int ans = n;
	for(int i = 2;i*i <= n;i++)if(n % i == 0)
	{
		ans -= ans/i;
		while(n % i == 0)
			n /= i;
	}
	if(n != 1)
		ans -= ans/n;
	return ans;
}

int main()
{
	int n;
	while(~scanf("%d", &n))
		printf("%d\n", phi(n-1));
	return 0;
}