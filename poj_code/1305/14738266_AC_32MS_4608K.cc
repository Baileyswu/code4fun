/*--------------------------------------------
 * File Name: POJ 1305
 * Author: Baileys Wu
 * Mail: wulidan0530@live.com
 * Created Time: 2015-09-19 11:07:46
--------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 1000001
int flag[N];
int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a%b);
}
void gao(int n)
{
	int r = 0;
	memset(flag, 0, sizeof(flag));
	int m = floor(sqrt(n)+1e-6);
	//printf("maxm %d\n", m);
	for(int i = 2;i <= m;i++)
	{
		for(int j = 1;j < i;j++)
		{
			if((i-j) % 2==0 || gcd(i, j) != 1)
				continue;
			int x = i*i-j*j, y = 2*i*j, z = i*i+j*j;
			if(z > n)
				continue;
			r++;
			//printf("=====%3d %3d %3d %3d\n", r, x, y, z);
			int tx, ty, tz;
			tx = ty = tz = 0;
			for(int k = 0;k < n/z;k++)
			{				
				tx += x, ty += y, tz += z;
				//printf("%3d %3d %3d %3d\n", r, tx, ty, tz);
				flag[tx] = flag[ty] = flag[tz] = 1;
			}
		}
	}
	int sum = 0;
	for(int i = 1;i <= n;i++)
		if(flag[i] == 0)
			sum++;
	printf("%d %d\n", r, sum);
}
int main()
{
	int n;
	while(~scanf("%d", &n))
		gao(n);
	return 0;
}