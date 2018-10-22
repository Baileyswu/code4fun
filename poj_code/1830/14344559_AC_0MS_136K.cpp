#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <cstdlib>
using namespace std;  
#define MAXN 35
int n, a[MAXN][MAXN];
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
	scanf("%d", &n);
	for(i = 0;i < n;i++)
	{
		scanf("%d", &a[i][n]);
		a[i][i] = 1;
	}
	for(i = 0;i < n;i++)
	{
		scanf("%d", &t);
		a[i][n] = t ^ a[i][n];
	}
	while(scanf("%d%d", &j, &i))
	{
		if(!i && !j)
			break;
		a[i-1][j-1] = 1;
	}
	//pr();
}
int gauss()//根据伪代码这个很好理解
{
   int i,j,k;
   for(i = 0, j = 0; i < n,j < n;)
   {
      int id = i;
      for(k = i+1; k < n; k++)
         if(abs(a[k][j]) > abs(a[id][j]))
            id = k;
      if(id != i)
      {
         for(k = j; k <= n; k++)
            swap(a[i][k],a[id][k]);
      }//使a[id][k](i<=k<=n)是最大的,并把这行移到第i行
      //printf("%d %d\n", i+1, j+1);
      if(a[i][j] == 0) { j++; continue; }//最大的a[id][k]=0
      for(k = i+1; k < n; k++)//线性变换化0
      {
         if(a[k][j] == 0) continue;
         for(int l = j; l <= n; l++)
            a[k][l] = a[k][l] ^ a[i][l];
      }
      i++,j++;
      //pr();
   }
   for(int k = i; k < n; k++) if(a[k][n] != 0) 
   {
   	//printf("k %d\n", k);
   	return(-1);//根据前面说的，无解
   }
   return 1<<(n-i);//因为解只能是0和1，所以最后剩了多少个变元，就有2的多少次方个解
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		input();
		int ans = gauss();
		if(ans == -1)
			printf("Oh,it's impossible~!!\n");
		else
			printf("%d\n", ans);
	}
	return 0;	
}
