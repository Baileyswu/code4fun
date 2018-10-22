/*--------------------------------------------
 * File Name: POJ 3347
 * Author: Danliwoo
 * Mail: Danliwoo@outlook.com
 * Created Time: 2015-10-28 11:53:50
--------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 60
int n, a[N], x[N], flag[N];
int main()
{
	while(scanf("%d", &n), n){
		for(int i = 0;i < n;i++)
			scanf("%d", &a[i]);
		x[0] = a[0];
		for(int i = 1;i < n;i++)
		{
			if(a[i] <= a[i-1])
				x[i] = x[i-1]+2*a[i];
			else{
				x[i] = x[i-1]+2*a[i-1];
				for(int j = i-1;j >= 0;j--)
					x[i] = max(x[i], x[j]+2*min(a[j], a[i]));
			}
		}
		// for(int i = 0;i < n;i++)
		// 	printf("%d%c", x[i], " \n"[i==n-1]);
		memset(flag, 0, sizeof(flag));
		for(int i = 0;i < n;i++)
		{
			//printf("i a[i] x[i] %d %d %d\n", i, a[i], x[i]);
			for(int j = 0;j < i;j++) if(!flag[j])
			{
				//printf("j %d a[j] %d x[j] %d x[i]-a[i] %d x[j]+a[j] %d\n", j, a[j], x[j], x[i]-a[i], x[j]+a[j]);
				if(x[i]-a[i] <= x[j])
					flag[j] = 1;
				if(x[j] + a[j] >= x[i])
					flag[i] = 1;
			}
		}
		int first = 1;
		for(int i = 0;i < n;i++)
			if(!flag[i]){
				if(first){
					first = 0;
					printf("%d", i+1);
				}
				else{
					printf(" %d", i+1);
				}
			}
		printf("\n");
	}
	return 0;
}