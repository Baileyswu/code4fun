/*--------------------------------------------
 * File Name: POJ 1006
 * Author: Baileys Wu
 * Mail: wulidan0530@live.com
 * Created Time: 2015-09-16 21:31:18
--------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
int m[4]={23,28,33}, a[4];
int extend_Euclid(int a, int b, int &x, int &y){
    if(b==0){
	    x = 1; y = 0;
	    return a;
    }
    int r = extend_Euclid(b, a%b, y, x);
    y -= a/b*x;
    return r;
}
int China()
{
	int M = 1, ans = 0;
	for (int i = 0; i < 3; ++i)
		M *= m[i];
	for(int i = 0;i < 3;i++)
	{
		int N = M/m[i];
		int x, y;
		extend_Euclid(N, m[i], x, y);
		ans = (ans+a[i]*N*x)%M;
	}
	ans = (ans - a[3])%M;
	return (ans+M-1)%M+1;
}
int main()
{
	int o = 0;
	while(1)
	{
		for(int i = 0;i < 4;i++)
			scanf("%d", &a[i]);
		if(a[0] == -1)
			break;
		printf("Case %d: the next triple peak occurs in %d days.\n",++o,China());
	}
	return 0;
}