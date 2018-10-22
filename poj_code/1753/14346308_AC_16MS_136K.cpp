#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <cstdlib>
using namespace std;  
#define MAXN 20
int n = 16, a[MAXN][MAXN], b[MAXN][MAXN],
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
	int i, j, k, id;
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
	//pr();
	for(int k = i; k < n; k++) if(a[k][n] != 0) 
   	{
   		return -1;//根据前面说的，无解
   	}
	return n-i;
}
int solve()
{
	int x = gauss();
	if(x == -1)
		return -1;
	int cnt = 1 << x, _min = n, ans[MAXN], res;
	for(int c = 0;c < cnt;c++)
	{
		memcpy(b, a, sizeof(b));
		memset(ans, 0, sizeof(ans));
		int d = c, i = n-1;
		for(i = n-1;i >= n-x;i--)
		{
			ans[i] = d % 2;
			d >>= 1;
		}
		for(;i >= 0;i--)
		{
			for(int k = i+1;k < n;k++)
				b[i][n] = b[i][n] ^ (b[i][k] & ans[k]);
			ans[i] = b[i][i] & b[i][n];
		}	
		res = 0;
		for(i = 0;i < n;i++)
		{
			//printf("%d%c", ans[i], " \n"[i%4==3]);
			//printf("%d%c", ans[i], " \n"[i==n-1]);
			if(ans[i])
				res++;
		}
		//printf("\n");
		if(res < _min)
			_min = res;
	}
	return _min;
}
int main()
{
	while(~scanf("%s", str[0]))
	{
		for(int i = 1;i < 4;i++)
			scanf("%s", str[i]);
		input(0);
		int p = solve();
		input(1);
		int q = solve();
		if(p == -1 && q == -1)
			printf("Impossible\n");
		else if(p != -1 && q != -1)
			printf("%d\n", min(p, q));
		else
			printf("%d\n", p == -1?q:p);
		scanf("%s", str[0]);
	}
	return 0;	
}
