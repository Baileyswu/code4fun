/**************************************************

            模版：平衡树Avl
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
	int ch[2], val, idx, h;
	node(int v=0, int i=0){ val=v, idx=i; h=1, ch[0]=ch[1]=0; }
}tr[maxn];

void Rotate(int &k, int f)
{
	int p=tr[k].ch[f];
	tr[k].ch[f]=tr[p].ch[!f];
	tr[p].ch[!f]=k;
	tr[k].h=max(tr[tr[k].ch[0]].h, tr[tr[k].ch[1]].h)+1;
	tr[p].h=max(tr[tr[p].ch[0]].h, tr[tr[p].ch[1]].h)+1;
	k=p;
	return ;
}

void dbRotate(int &k, int f)
{
	Rotate(tr[k].ch[f], !f);
	Rotate(k, f);
	return ;
}

void Maintain(int &k)
{
	if(tr[tr[k].ch[0]].h==tr[tr[k].ch[1]].h+2)
	{
		if(tr[tr[k].ch[0]].h==tr[tr[tr[k].ch[0]].ch[0]].h+1)	Rotate(k, 0);
		else dbRotate(k, 0);
	}
	else if(tr[tr[k].ch[0]].h+2==tr[tr[k].ch[1]].h)
	{
		if(tr[tr[k].ch[1]].h==tr[tr[tr[k].ch[1]].ch[1]].h+1)	Rotate(k, 1);
		else dbRotate(k, 1);
	}
	return ;
}

void Insert(int &k, int val, int idx)
{
	if(!k)	tr[k=++cnt]=node(val, idx);
	else
	{
		Insert(tr[k].ch[val>tr[k].val], val, idx);
		Maintain(k);
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
	Maintain(k);
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
