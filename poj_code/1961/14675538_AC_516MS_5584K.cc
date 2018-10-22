/*--------------------------------------------
 * File Name: POJ 1961
 * Author: Baileys Wu
 * Mail: wulidan0530@live.com
 * Created Time: 2015-08-28 21:12:54
--------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 1000010
char s[N];
int pre[N], n, ans[N];
int kmp()
{
	memset(pre, 0, sizeof(pre));
	pre[0] = -1;
	for(int i = 1;i < n;i++)
	{
		int j = pre[i-1];
		while(j >= 0 && s[j+1] != s[i])
			j = pre[j];
		pre[i] = s[j+1] == s[i] ? j+1 : -1;
	}
	/*for(int i = 0;i < n;i++)
		printf(" %c%c", s[i], " \n"[i==n-1]);
	for(int i = 0;i < n;i++)
		printf("%2d%c", i, " \n"[i==n-1]);
	for(int i = 0;i < n;i++)
		printf("%2d%c", pre[i], " \n"[i==n-1]);*/
}
void solve()
{
	ans[0] = 1;
	if(s[0] == s[1])
	{
		ans[1] = 2;
		printf("2 2\n");
	}
	for(int i = 2;i < n;i++)
	{
		if(pre[i] == 0 || pre[i] == -1)
		{
			ans[i] = 1;
			continue;
		}
		/*if((i+1)%(pre[i]+1) == 0)
		{
			ans[i] = (i+1)/(pre[i]+1);
			printf("--%d %d\n", i+1, ans[i]);
			continue;
		}*/
		int t = i-pre[i];
		if(t != ((pre[i]+1)/ans[pre[i]]))
		{
			ans[i] = 1;
			continue;
		}
		ans[i] = (i+1)/t;
		if(ans[i] > 1)
			printf("%d %d\n", i+1, ans[i]);
	}
}
void solve2()
{
	for(int i = 1;i < n;i++)
	{
		int t = i-pre[i];
		if((i+1)%t == 0)
		{
			int x = (i+1)/t;
			if(x > 1)
				printf("%d %d\n", i+1, x);
		}
	}
}
int main()
{
	int o = 0;
	while(scanf("%d", &n), n)
	{
		printf("Test case #%d\n", ++o);
		scanf("%s", s);
		kmp();
		solve2();
		printf("\n");
	}
	return 0;
}