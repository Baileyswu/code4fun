#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int num[50005], ans[50005][20], n, q, t[50005][20];
int set()
{
	int i, j, e;
	for(i = 1;i <= n;i++)
	{
		ans[i][0] = num[i];
		t[i][0] = num[i];
		//printf("%3d ", ans[i][0]);
	}
	//printf("\n");
	int w = log(n)/log(2);
	for(j = 1;j <= w;j++)
	{
		e = n+1-pow(2,j);
		for(i = 1;i <= e;i++)
		{
			int d = pow(2,j-1);
			ans[i][j] = max(ans[i][j-1], ans[i+d][j-1]);
			t[i][j] = min(t[i][j-1], t[i+d][j-1]);
			//printf("%3d ", ans[i][j]);
		}
		//printf("\n");
	}
}
int main()
{
	while(scanf("%d", &n), n)
	{
		scanf("%d", &q);
		for(int i = 1;i <= n;i++)
			scanf("%d", &num[i]);
		set();
		while(q--)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			int k = log(b-a+1)/log(2);
			int d = pow(2,k);
			printf("%d\n", max(ans[a][k], ans[b-d+1][k])-min(t[a][k], t[b-d+1][k]));
		}
	}
	return 0;
}//10 3 -1 -1 1 1 1 1 3 10 10 10