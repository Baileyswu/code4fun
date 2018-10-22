/*--------------------------------------------
 * File Name: POJ 2752
 * Author: Baileys Wu
 * Mail: wulidan0530@live.com
 * Created Time: 2015-08-28 20:41:15
--------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 400010
char s[N];
int pre[N], n, v;
int kmp()
{
	memset(pre, 0, sizeof(pre));
	pre[0] = -1;
	n = strlen(s);
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
void solve(int x)
{
	if(pre[x] == -1)
		return;
	solve(pre[x]);
	if(v) printf(" ");
	printf("%d", pre[x]+1, v = 1);
}
int main()
{
	while(~scanf("%s", s))
	{
		v = 0;
		kmp();
		solve(n-1);
		printf(" %d\n", n);
	}
	return 0;
}