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
void gao(int x, int y, int z)
{
	int r = 1000000000;
	r = min(r, (x+z)*(x+z)+y*y);
	r = min(r, (x+y)*(x+y)+z*z);
	//r = min(r, pow(x+z, 2)+pow(y,2));
	//r = min(r, pow(x+y, 2)+pow(z,2));
	//r = min(r, pow(x+2*lz-z, 2)+pow(y,2));
	//r = min(r, pow(x+2*ly-y, 2)+pow(z,2));
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
			gao(x, y, z);
		else if(y == ly)
			gao(y, z, x);
		else
			gao(z, x, y);
	}
	return 0;
}