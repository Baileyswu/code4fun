/*--------------------------------------------
 * File Name: POJ 1026
 * Author: Danliwoo
 * Mail: Danliwoo@outlook.com
 * Created Time: 2015-10-06 18:55:18
--------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 210
int a[N], q[N];
char str[N], ans[N];
int main()
{
	int n, k;
	while(scanf("%d", &n), n)
	{
		for(int i = 1;i <= n;i++)
			scanf("%d", &a[i]);
		for(int i = 1;i <= n;i++)
		{
			int j = i;
			q[i] = 1;
			while(a[j] != i)
			{
				j = a[j];
				q[i]++;
			}
			//printf("%d %d\n", i, q[i]);
		}
		while(scanf("%d", &k), k)
		{
			gets(str);
			//printf("%s\n", str);
			int len = strlen(str);
			for(int i = len;i <= n;i++)
				str[i] = ' ';
			str[n+1] = ans[n+1] = '\0';
			//printf("%s\n", str);
			for(int i = 1;i <= n;i++)
			{
				int b = k%q[i], z = i;
				for(int j = 0;j < b;j++)
					z = a[z];
				ans[z] = str[i];
				//printf("%d %d %c %c\n", i, z, str[i], ans[z]);
			}
			printf("%s\n", ans+1);
		}
	}
	return 0;
}