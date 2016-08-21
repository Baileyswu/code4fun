/**************************************************

            模版：平衡树SBT
            题目：POJ3481 Double Queue

**************************************************/


#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=100000+10;

int rt, cnt;
struct node
{
	int ch[2], val, idx, siz;
	node(int v=0, int i=0){ val=v, idx=i; siz=1, ch[0]=ch[1]=0; }
}tr[maxn];

void Rotate(int &k, int f)
{
	int p=tr[k].ch[f];
	tr[k].ch[f]=tr[p].ch[!f];
	tr[p].ch[!f]=k;
	tr[k].siz=tr[tr[k].ch[0]].siz+tr[tr[k].ch[1]].siz+1;
	tr[p].siz=tr[tr[p].ch[0]].siz+tr[tr[p].ch[1]].siz+1;
	k=p;
	return ;
}

void dbRotate(int &k, int f)
{
	Rotate(tr[k].ch[f], !f);
	Rotate(k, f);
	return ;
}

void Maintain(int &k, int f)
{
	if(tr[tr[tr[k].ch[f]].ch[f]].siz>tr[tr[k].ch[!f]].siz)	Rotate(k, f);
	else if(tr[tr[tr[k].ch[f]].ch[!f]].siz>tr[tr[k].ch[!f]].siz)  dbRotate(k, f);
	else return ;
	Maintain(tr[k].ch[0], 0);
	Maintain(tr[k].ch[1], 1);
	Maintain(k, 0);
	Maintain(k, 1);
	return ;
}

void Insert(int &k, int val, int idx)
{
	if(!k)	tr[k=++cnt]=node(val, idx);
	else
	{
		Insert(tr[k].ch[val>tr[k].val], val, idx);
		++tr[k].siz;
		Maintain(k, val>tr[k].val);
	}
	return ;
}

int Delete(int &k, int val)//若val不存在 删去第一个比它小的数
{
	int ans=0;
	if(val==tr[k].val || (val<tr[k].val&&!tr[k].ch[0]) || (val>tr[k].val&&!tr[k].ch[1]))
	{
		if(!tr[k].ch[0] || !tr[k].ch[1])
		{
			ans=tr[k].val;
			k=tr[k].ch[0]+tr[k].ch[1];
			return ans;
		}
		else ans=tr[k].val=Delete(tr[k].ch[0], val);
	}
	else ans=Delete(tr[k].ch[val>tr[k].val], val);
	--tr[k].siz;
	return ans;
}

int Query(int k, int f)
{
	while(tr[k].ch[f])	k=tr[k].ch[f];
	return k;
}

int main()
{	
	int d, k, val, idx;
	while(scanf("%d", &d)!=EOF&&d)
	{
		if(d==1)
		{
			scanf("%d%d", &idx, &val);
			Insert(rt, val, idx);
		}
		else
		{
			k=Query(rt, d==2);
			printf("%d\n", k?tr[k].idx:0);
			if(k)	Delete(rt, tr[k].val);
		}
	}
	return 0;
}
