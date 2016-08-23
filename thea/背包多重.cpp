/**************************************************

            模版：多重背包
            题目：POJ1742 Coins
            tips：单调队列优化

**************************************************/


#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=100+10, maxm=100000+10;

int n, m, v[maxn], c[maxn], f[maxm];
int fir, tail, q[maxm], p[maxm];

void Zero(int i)
{
	for(int j=m; j>=v[i]; j--)  f[j]=max(f[j], f[j-v[i]]+v[i]);
	return ;
}

void Com(int i)
{
	for(int j=v[i]; j<=m; j++)  f[j]=max(f[j], f[j-v[i]]+v[i]);
	return ;
}

void Multi(int i)
{
	for(int j=0; j<v[i]; j++)
	{
		fir=tail=1;
		for(int k=j, h=0; k<=m; k+=v[i], h++)
		{
			while(fir!=tail&&k-p[fir]>v[i]*c[i])    ++fir;//p[]记录队列中元素在原数组中的下标 保证队列区间在范围内
			int tmp=f[k]-h*v[i];                          //将f[i-1][k]放入队列
			while(fir!=tail&&q[tail-1]<tmp)   --tail;
			q[tail++]=tmp, p[tail]=k;
			f[k]=q[fir]+h*v[i];
		}
	}
	return ;
}

int main()
{
	while(scanf("%d%d", &n, &m)!=EOF)
	{
		memset(f, 0, sizeof f);

		for(int i=1; i<=n; i++) scanf("%d", &v[i]);
		for(int i=1; i<=n; i++) scanf("%d", &c[i]);

		for(int i=1; i<=n; i++)
		{
			if(c[i]==1) Zero(i);
			else if(c[i]*v[i]>=m) Com(i);
			else Multi(i);
		}

		int ans=0;
		for(int i=1; i<=m; i++) ans+=(f[i]==i);
		cout<<ans<<endl;
	}
	return 0;
}
