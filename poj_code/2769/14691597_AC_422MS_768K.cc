/*--------------------------------------------
 * File Name: POJ 2769
 * Author: Baileys
 * Mail: wulidan0530@live.com
 * Created Time: 2015-09-03 17:21:57
--------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 400
int num[N], n;
bool flag[100001];
int gao(int m)
{
	memset(flag, false, sizeof(flag));
	for(int i = 0;i < n;i++)
	{
		int t = num[i]%m;
		if(flag[t])
			return 1;
		flag[t] = true;
	}
	return 0;
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i = 0;i < n;i++)
			scanf("%d", &num[i]);
		int ans = n;
		while(gao(ans))
			ans++;
		printf("%d\n", ans);
	}
	return 0;
}