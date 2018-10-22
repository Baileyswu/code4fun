#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int num[100005], ans[100005][20], n, q;
int rig[100005], v[100005];
int ccc()
{
	v[1] = 1;
	int p = 1;
	for(int i = 1;i < n;i++)
	{
		if(num[i] == num[i+1])
			v[i+1] = ++p;
		else
			v[i+1] = p = 1;
	}
	rig[n] = n;
	for(int i = n-1;i > 0;i--)
	{
		if(num[i] == num[i+1])
			rig[i] = rig[i+1];
		else
			rig[i] = i;
	}
	//for(int i = 1;i <= n;i++)
		//printf("%d%c", v[i], " \n"[i==n]);
	//for(int i = 1;i <= n;i++)
		//printf("%d%c", rig[i], " \n"[i==n]);
}
int judge(int a, int k, int b)
{
	if(v[k]+1 != v[k+1])
		return 0;
	int p=k-v[k]+1, q=rig[k];
	if(q > b)
		q = b;
	if(a > p)
		p = a;
	return q - p + 1;
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
			int o = judge(i, i+d-1, i+2*d-1);
			ans[i][j] = max(ans[i][j], o);
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
		ccc();
		set();
		while(q--)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			int k = log(b-a+1)/log(2);
			int d = pow(2,k);
			int o = max(ans[a][k], ans[b-d+1][k]);
			int temp = judge(a, a+d-1, b);
			o = max(o, temp);
			printf("%d\n", o);
		}
	}
	return 0;
}//10 3 -1 -1 1 1 1 1 3 10 10 10