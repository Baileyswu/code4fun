/**************************************************

            模版：线段树开区间
            题目：URAL1019 Line Painting

**************************************************/

#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn=5000+10;
#define kl (k<<1)
#define kr ((k<<1)+1)
#define mid ((l+r)>>1)

int n, m, h[maxn*8];
struct Query
{
    int x, y; bool cl;
    void Push(int a, int b, bool c) { x=a, y=b, cl=c; }
}q[maxn];
struct node
{
    int cl, from, tot, ls, rs;
}tr[maxn*8];

void Build(int k=1, int l=1, int r=n)
{
    if(l>=r)    return ;
    tr[k].cl=1, tr[k].from=h[l], tr[k].tot=tr[k].ls=tr[k].rs=h[r]-h[l];
    if(l+1==r)  return ;
    Build(kl, l, mid);
    Build(kr, mid, r);
    return ;
}

void Push_down(int k, int l, int r)
{
    if(tr[k].cl!=-1)
    {
        tr[kl].cl=tr[kr].cl=tr[k].cl, tr[kl].from=h[l], tr[kr].from=h[mid];
        tr[kl].tot=tr[kl].ls=tr[kl].rs=tr[kl].cl*(h[mid]-h[l]);
        tr[kr].tot=tr[kr].ls=tr[kr].rs=tr[kr].cl*(h[r]-h[mid]);
    }
    return ;
}

void Push_up(int k, int l, int r)
{
    if(tr[kl].cl!=-1&&tr[kl].cl==tr[kr].cl)
        tr[k].cl=tr[kl].cl, tr[k].from=h[l], tr[k].tot=tr[k].ls=tr[k].rs=tr[kl].cl*(h[r]-h[l]);
    else
    {
        tr[k].cl=-1, tr[k].from=tr[kl].from, tr[k].tot=tr[kl].tot, tr[k].ls=tr[kl].ls, tr[k].rs=tr[kr].rs;
        if(tr[kl].rs+tr[kr].ls>tr[k].tot)   tr[k].from=h[mid]-tr[kl].rs, tr[k].tot=tr[kl].rs+tr[kr].ls;
        if(tr[kr].tot>tr[k].tot)    tr[k].from=tr[kr].from, tr[k].tot=tr[kr].tot;
        if(tr[kl].ls==h[mid]-h[l])  tr[k].ls+=tr[kr].ls;
        if(tr[kr].rs==h[r]-h[mid])  tr[k].rs+=tr[kl].rs;
    }
    return ;
}

void Insert(int ll, int rr, bool cl, int k=1, int l=1, int r=n)
{
    if(rr <l||r< ll)    return ;
    if(ll<=l&&r<=rr)
    {
        tr[k].cl=cl, tr[k].from=h[l], tr[k].tot=tr[k].ls=tr[k].rs=cl*(h[r]-h[l]);
        return ;
    }
    if(l+1>=r)  return ;
    Push_down(k, l, r);
    Insert(ll, rr, cl, kl, l, mid);
    Insert(ll, rr, cl, kr, mid, r);
    Push_up(k, l, r);
    return ;
}

int main()
{
    while(scanf("%d", &m)!=EOF)
    {
        n=0;
        h[++n]=0, h[++n]=1e9;

        int x, y; char c[5];
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d%s", &x, &y, c);
            h[++n]=x, h[++n]=y;
            q[i].Push(x, y, c[0]=='w');
        }

        sort(h+1, h+1+n);
        n=unique(h+1, h+1+n)-(h+1);
        Build();
        
        for(int i=1; i<=m; i++)
        {
            q[i].x=lower_bound(h+1, h+1+n, q[i].x)-h;
            q[i].y=lower_bound(h+1, h+1+n, q[i].y)-h;
            Insert(q[i].x, q[i].y, q[i].cl);
        }

        printf("%d %d\n", tr[1].from, tr[1].from+tr[1].tot);
    }
    return 0;
}
