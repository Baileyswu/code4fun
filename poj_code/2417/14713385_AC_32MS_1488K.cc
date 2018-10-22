/*--------------------------------------------
 * File Name: POJ 3358
 * Author: Baileys Wu
 * Mail: wulidan0530@live.com
 * Created Time: 2015-09-10 15:43:14
--------------------------------------------*/


#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define MOD 76543
int hs[MOD],head[MOD],next[MOD],id[MOD],top;
void insert(int x, int y)
{
	int k = x%MOD;
	hs[top] = x, id[top] = y, next[top] = head[k], head[k] = top++;
	//printf("top %d k %d hs %d id %d next %d head %d\n", top-1, k, hs[top-1], id[top-1], next[top-1], head[k]);
}
int find(int x)
{
	int k = x%MOD;
	for(int i = head[k]; i != -1; i = next[i])
		if(hs[i] == x)
			return id[i];
	return -1;
}
int BSGS(int a,int b,int c)
{
	memset(head, -1, sizeof(head));
	top = 1;
	if(b == 1)
		return 0;
	int m = sqrt(c*1.0), j;
	long long x = 1, p = 1;
	for(int i = 0; i < m; ++i, p = p*a%c)
		insert(p*b%c, i);
	for(long long i = m; ;i += m)
	{
		if( (j = find(x = x*p%c)) != -1 )
			return i-j;
		if(i > c)
			break;
	}
	return -1;
}
int main()
{
	int a, b, c;
	while(~scanf("%d%d%d", &c, &a, &b))
	{
		int r = BSGS(a, b, c);
		if(r == -1)
			printf("no solution\n");
		else
			printf("%d\n", r);
	}
	return 0;
}