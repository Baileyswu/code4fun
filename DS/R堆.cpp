/**************************************************

            模版：堆
            题目：UESTC 204 合并果子

**************************************************/


#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define kl (k<<1)
#define kr ((k<<1)+1)
using namespace std;
const int maxn=10000+10;

int n, a[maxn];

void Maintain(int k)//维护以k为根的子堆
{
	while(kl<=n)
	{
		if(kr<=n&&a[kl]>a[kr]&&a[k]>a[kr])  swap(a[k], a[kr]), k=kr;
		else if(a[k]>a[kl]) swap(a[k], a[kl]), k=kl;
		else break;
	}
	return ;
}

void Build()
{
	for(int i=n>>1; i; i--) Maintain(i);//叶子节点自然满足条件 i从n/2开始调整
	return ;
}

void Delete()//删除操作只会出现在堆顶
{
	swap(a[1], a[n]);
	--n;
	Maintain(1);
	return ;
}

void Add(int val)//新元素加入到堆底 向下调整
{
	a[++n]=val;
	for(int k=n; k>1&&a[k]<a[k>>1]; k>>=1)  swap(a[k], a[k>>1]);
	return ;
}

int main()
{
	while(scanf("%d", &n)!=EOF)
	{
		for(int i=1; i<=n; i++) scanf("%d", &a[i]);
		Build();

		int ans=0;
		while(n-1)
		{
			int tmp=a[1];
			Delete();
			tmp+=a[1];
			Delete();

			Add(tmp);
			ans+=tmp;
		}
		cout<<ans<<endl;
	}
	return 0;
}
