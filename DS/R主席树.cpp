/**************************************************

            模版：主席树
            题目：HDU5919 Sequence II

**************************************************/


#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<map>
#include<algorithm>
#define mid ((l+r)>>1)
using namespace std;
const int maxn=200000+10;

int T, n, m, a[maxn], tot, id[maxn];
struct node
{
	int ch[2], val;
}tr[maxn*50];
map<int, int> mmp;

void Build(int &k, int l=1, int r=n)
{
	k=++tot;
	tr[k].ch[0]=tr[k].ch[1]=tr[k].val=0;
	if(l==r)	return ;
	Build(tr[k].ch[0], l, mid);
	Build(tr[k].ch[1], mid+1, r);
	return ;
}

void Insert(int &k, int p, int x, int v, int l=1, int r=n)
{
	tr[k=++tot]=tr[p], tr[k].val+=v;
	if(l==r)	return ;
	if(x<=mid)	Insert(tr[k].ch[0], tr[p].ch[0], x, v, l, mid);
	else Insert(tr[k].ch[1], tr[p].ch[1], x, v, mid+1, r);
	return ;
}

int Query1(int k, int x, int l=1, int r=n)
{
	if(l==r)	return tr[k].val;
	if(x<=mid)	return Query1(tr[k].ch[0], x, l, mid);
	return tr[tr[k].ch[0]].val+Query1(tr[k].ch[1], x, mid+1, r);
}

int Query2(int k, int cnt, int l=1, int r=n)
{
	if(l==r)	return l;
	if(cnt<=tr[tr[k].ch[0]].val)	return Query2(tr[k].ch[0], cnt, l, mid);
	return Query2(tr[k].ch[1], cnt-tr[tr[k].ch[0]].val, mid+1, r);
}

int main()
{
	scanf("%d", &T);
	for(int TT=1; TT<=T; TT++)
	{
		printf("Case #%d: ", TT);

		scanf("%d%d", &n, &m);
		for(int i=1; i<=n; i++)	scanf("%d", &a[i]);

		tot=0;
		Build(id[n+1]);

		mmp.clear();
		for(int i=n; i; i--)
		{
			if(!mmp[a[i]])	Insert(id[i], id[i+1], i, 1);
			else
			{
				Insert(id[i], id[i+1], mmp[a[i]], -1);
				Insert(id[i], id[i], i, 1);
			}
			mmp[a[i]]=i;
		}

		int ans=0, l=0, r=0, tmp=0;
		for(int i=1; i<=m; i++)
		{
			scanf("%d%d", &l, &r);
			l=(l+ans)%n+1, r=(r+ans)%n+1;
			if(l>r)	swap(l, r);

			tmp=Query1(id[l], r);
			printf("%d%c", ans=Query2(id[l], (tmp+1)>>1), " \n"[i==m]);
		}
	}
	return 0;
}
