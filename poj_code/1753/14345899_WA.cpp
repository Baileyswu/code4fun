#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <cstdlib>
using namespace std;  
#define MAXN 20
int n = 16, a[MAXN][MAXN],
 dp[5][2] = {0, 1, 0, -1, 1, 0, -1, 0, 0, 0};
char str[4][10];
void pr()
{
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n+1;j++)
			printf("%d%c", a[i][j], " \n"[j==n]);
	printf("\n");
}
void input(int z)
{
	memset(a, 0, sizeof(a));
	int t, i, j;
	for(i = 0;i < 4;i++)
		for(j = 0;j < 4;j++)
		{
			if(str[i][j] == 'b')
				a[i*4+j][n] = 1-z;
			else
				a[i*4+j][n] = z;
		}
	for(i = 0;i < n;i++)
	{
		int x = i/4, y = i%4;
		for(int k = 0;k < 5;k++)
		{
			int tx = x+dp[k][0], ty = y+dp[k][1];
			if(tx < 0 || tx >= 4 || ty < 0 || ty >= 4)
				continue;
			a[tx*4+ty][i] = 1;
		}
	}
}
int gauss()//根据伪代码这个很好理解
{
	//pr();
	int i, j, k, id, ans[MAXN];
	memset(ans, 0, sizeof(ans));
	for(i = 0, j = 0; i < n,j < n;)
	{
		id = i;
		for(k = i+1; k < n; k++)
			if(abs(a[k][j]) > abs(a[id][j]))
				id = k;
		if(id != i)
		{
			for(k = j; k <= n; k++)
				swap(a[i][k],a[id][k]);
		}//使a[id][k](i<=k<=n)是最 大的,并把这行移到第i行
		if(a[i][j] == 0) { j++; continue; }//最大的a[id][k]=0
		for(k = i+1; k < n; k++)//线性变换化0
		{
			if(a[k][j] == 0) continue;
			for(int l = j; l <= n; l++)
				a[k][l] = a[k][l] ^ a[i][l];
		}
		i++,j++;
	}
	for(int k = i; k < n; k++) if(a[k][n] != 0) 
   	{
   		//printf("k %d\n", k);
   		return -1;//根据前面说的，无解
   	}

	//pr();
	for(i = n-1;i >= 0;i--)
	{
		int t = 1;
		for(int k = i+1;k < n;k++)
			a[i][n] = a[i][n] ^ (a[i][k] & ans[k]);
		ans[i] = a[i][i] & a[i][n];
	}
	int res = 0;
	for(i = 0;i < n;i++)
	{
		//printf("%d%c", ans[i], " \n"[i%4==3]);
		//printf("%d%c", ans[i], " \n"[i==n-1]);
		if(ans[i])
			res++;
	}
	return res;
}
int main()
{
	while(~scanf("%s", str[0]))
	{
		for(int i = 1;i < 4;i++)
			scanf("%s", str[i]);
		input(0);
		int p = gauss();
		input(1);
		int q = gauss();
		if(p == -1 && q == -1)
			printf("Impossible\n");
		else if(p != -1 && q != -1)
			printf("%d\n", min(p, q));
		else
			printf("%d\n", p == -1?q:p);
	}
	return 0;	
}
