/*--------------------------------------------
 * File Name: POJ 2478
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
#define N 1000005
int phi[N]={0,1}, md[N];
long long ans[N] = {0,0,1};
void set()
{
	for(int i = 0;i < N;i++)
		md[i] = i;
	for(int i = 2;i < N;i++)if(md[i] == i)
	{
		for(int j = i;j < N;j += i)
			md[j] = i;
	}
	for(int i = 2;i < N;i++)
	{
		if(md[i] == i)
			phi[i] = i-1;
		else
		{
			phi[i] = phi[i/md[i]];
			if(i/md[i] % md[i])
				phi[i] *= md[i]-1;
			else
				phi[i] *= md[i];
		}
	}
	for(int i = 3;i < N;i++)
		ans[i] = ans[i-1]+phi[i];
}
void s()
{
	for(int i = 0;i < N;i++)
		phi[i] = i;
	for(int i = 2;i < N;i += 2)
		phi[i] /= 2;
	for(int i = 3;i < N;i += 2) if(phi[i] == i)
	{
		for(int j = i;j < N;j += i)
			phi[j] = phi[j]/i*(i-1);
	}
}
int main()
{
	set();
	int n;
	while(scanf("%d", &n), n)
		printf("%lld\n", ans[n]);
	return 0;
}