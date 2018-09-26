/**************************************************

            模版：平衡树Treap
            题目：POJ3481 Double Queue

**************************************************/


#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
const int maxn=100000+10;

int rt, cnt;
struct node
{
	int ch[2], val, idx, rval;
	node(int v=0, int i=0, int r=0){ val=v, idx=i, rval=r; ch[0]=ch[1]=0; }
}tr[maxn];

void Rotate(int &k, int f)
{
	int p=tr[k].ch[f];
	tr[k].ch[f]=tr[p].ch[!f];
	tr[p].ch[!f]=k;
	k=p;
	return ;
}

void Insert(int &k, int val, int idx)
{
	if(!k)	tr[k=++cnt]=node(val, idx, rand());
	else
	{
		int f=(val>tr[k].val);
		Insert(tr[k].ch[f], val, idx);
		if(tr[k].rval<tr[tr[k].ch[f]].rval)	Rotate(k, f);
	}
	return ;
}

void Delete(int &k, int val)
{
	if(tr[k].val==val)
	{
		if(tr[k].ch[0]&&tr[k].ch[1])
		{
			int f=tr[tr[k].ch[1]].rval>tr[tr[k].ch[0]].rval;
			Rotate(k, f);
			Delete(tr[k].ch[f], val);
		}
		else k=tr[k].ch[!tr[k].ch[0]]; 
	}
	else Delete(tr[k].ch[val>tr[k].val], val);
	return ;
}

int Query(int k, int f)
{
	while(tr[k].ch[f])	k=tr[k].ch[f];
	return k;
}

int main()
{
	srand(time(NULL));
	
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
