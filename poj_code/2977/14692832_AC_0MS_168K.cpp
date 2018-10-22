/*--------------------------------------------
 * File Name: POJ 2977
 * Author: Baileys Wu
 * Mail: wulidan0530@live.com
 * Created Time: 2015-09-04 10:01:09
--------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
int q(int x)
{
	return x*x;
}
void gao(int x, int y, int z, int ly, int lz)
{
	int r = 1000000000;
	r = min(r, q(x+z)+y*y);
	r = min(r, q(x+y)+z*z);
	r = min(r, q(x+lz-z)+q(lz+y));
	r = min(r, q(x+ly-y)+q(ly+z));
	printf("%d\n", r);
}
int main()
{
	int lx, ly, lz, x, y, z;
	while(~scanf("%d%d%d%d%d%d", &lx, &ly, &lz, &x, &y, &z))
	{
		if(!lx)
			break;
		if(!x || !y || !z)
		{
			printf("%d\n", x*x+y*y+z*z);
			continue;
		}
		if(x == lx)
			gao(x, y, z, ly, lz);
		else if(y == ly)
			gao(y, z, x, lz, lx);
		else
			gao(z, x, y, lx, ly);
	}
	return 0;
}