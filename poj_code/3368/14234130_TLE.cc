#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int num[100005], ans[100005][20], n, q;
int seq(int i, int k, int j)
{
	int r = 0;
	for(int s = k;s >= i;s--)
		if(num[s] == num[k])
			r++;
		else
			break;
	for(int s = k+1;s <= j;s++)
		if(num[s] == num[k])
			r++;
		else
			break;
	return r;
}
int set()
{
	int i, j, e;
	for(i = 1;i <= n;i++)
	{
		ans[i][0] = 1;
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
			int temp = seq(i, i+d-1, i+d*2-1);
			ans[i][j] = max(ans[i][j], temp);
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
			int o = max(ans[a][k], ans[b-d+1][k]);
			int temp = seq(a, a+d-1, b);
			o = max(o, temp);
			printf("%d\n", o);
		}
	}
	return 0;
}//10 3 -1 -1 1 1 1 1 3 10 10 10