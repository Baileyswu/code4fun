#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <cstdlib>
using namespace std;  
#define MAXN 35
int n = 30, a[MAXN][MAXN],
 dp[5][2] = {0, 1, 0, -1, 1, 0, -1, 0, 0, 0};
void pr()
{
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n+1;j++)
			printf("%d%c", a[i][j], " \n"[j==n]);
	printf("\n");
}
void input()
{
	memset(a, 0, sizeof(a));
	int t, i, j;
	for(i = 0;i < n;i++)
		scanf("%d", &a[i][n]);
	for(i = 0;i < n;i++)
	{
		int x = i/6, y = i%6;
		for(int k = 0;k < 5;k++)
		{
			int tx = x+dp[k][0], ty = y+dp[k][1];
			if(tx < 0 || tx >= 5 || ty < 0 || ty >= 6)
				continue;
			a[tx*6+ty][i] = 1;
		}
	}
	//pr();
}
void gauss()//根据伪代码这个很好理解
{
	int i, j, k, id[MAXN], ans[MAXN];
	memset(id, 0, sizeof(id));
	memset(ans, 0, sizeof(ans));
	for(i = 0, j = 0; i < n,j < n;)
	{
		id[i] = i;
		for(k = i+1; k < n; k++)
			if(abs(a[k][j]) > abs(a[id[i]][j]))
				id[i] = k;
		if(id[i] != i)
		{
			for(k = j; k <= n; k++)
				swap(a[i][k],a[id[i]][k]);
		}//使a[id][k](i<=k<=n)是最 大的,并把这行移到第i行
		//printf("%d %d\n", i+1, j+1);
		if(a[i][j] == 0) { j++; continue; }//最大的a[id][k]=0
		for(k = i+1; k < n; k++)//线性变换化0
		{
			if(a[k][j] == 0) continue;
			for(int l = j; l <= n; l++)
				a[k][l] = a[k][l] ^ a[i][l];
		}
		i++,j++;
	}
	//pr();
	for(int i = n-1;i >= 0;i--)
	{
		int t = 1;
		for(int k = i+1;k < n;k++)
			a[i][n] = a[i][n] ^ (a[i][k] & ans[k]);
		ans[i] = a[i][i] & a[i][n];
	}
	for(int i = 0;i < 30;i++)
		printf("%d%c", ans[i], " \n"[i%6==5]);
	/*for(int i = n-1;i > 0;i--)
	{
		if(id[i] != i)
			swap(ans[i], ans[id[i]]);
	}
	for(int i = 0;i < 30;i++)
		printf("%d%c", ans[i], " \n"[i==29]);*/
}
int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 0;i < t;i++)
	{
		input();
		printf("PUZZLE #%d\n", i+1);
		gauss();
	}
	return 0;	
}
