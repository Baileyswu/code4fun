/*--------------------------------------------
 * File Name: POJ 1320
 * Author: Baileys Wu
 * Mail: wulidan0530@live.com
 * Created Time: 2015-09-19 00:07:38
--------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
	int x1 = 3, y1 = 1;
	int x2 = x1, y2 = y1, x3, y3;
	for(int i = 1;i <= 10;i++)
	{
		x3 = x2*x1+8*y2*y1;
		y3 = x2*y1+y2*x1;
		x2 = x3, y2 = y3;
		printf("%10d%10d\n", y3, (x3-1)/2);
	}
	return 0;
}