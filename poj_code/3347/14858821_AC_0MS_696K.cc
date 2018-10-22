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
		for(int i = 0;i < n;i++){
			int L = x[i]-a[i], R = x[i]+a[i];
			for(int j = 0;j < i;j++){
				if(a[j] <= a[i]) continue;
				L = max(L, x[j] + a[j]);
				if(L >= R) break;
			}
			for(int j = i+1;j < n;j++){
				if(a[j] <= a[i]) continue;
				R = min(R, x[j] - a[j]);
				if(L >= R) break;
			}
			if(L >= R) flag[i] = 1;
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