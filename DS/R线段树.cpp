/**************************************************

            模版：线段树
            题目：HDU1698 just a hook

**************************************************/

#include<iostream>
#include<cstdio>
#define kl (k<<1)
#define kr ((k<<1)+1)
#define mid ((l+r)>>1)
using namespace std;
const int maxn=100000+10;

int T, n, m;
struct node
{
    int sum, col;
}tr[maxn<<2];

void Build(int k=1, int l=1, int r=n)
{
    tr[k].col=1, tr[k].sum=r-l+1;
    if(l==r)    return ;
    Build(kl, l, mid);
    Build(kr, mid+1, r);
    return ;
}

void Push_down(int k, int l, int r)
{
    if(tr[k].col)
    {
        tr[kl].col=tr[kr].col=tr[k].col;
        tr[kl].sum=tr[kl].col*(mid-l+1);
        tr[kr].sum=tr[kr].col*(r-mid);
        tr[k].col=0;
    }
    return ;
}

void Push_up(int k)
{
    tr[k].sum=tr[kl].sum+tr[kr].sum;
    return ;
}

void Insert(int ll, int rr, int num, int k=1, int l=1, int r=n)
{
    if(rr <l||r< ll) return ;
    if(ll<=l&&r<=rr)
    {
        tr[k].col=num, tr[k].sum=(r-l+1)*num;
        return ;
    }
    Push_down(k, l, r);
    Insert(ll, rr, num, kl, l, mid);
    Insert(ll, rr, num, kr, mid+1, r);
    Push_up(k);
    return ;
}

int main()
{
    scanf("%d", &T);
    for(int j=1; j<=T; j++)
    {
        scanf("%d%d", &n, &m);
        Build();

        for(int i=1, x, y, z; i<=m; i++)
        {
            scanf("%d%d%d", &x, &y, &z);
            Insert(x, y, z);
        }

        printf("Case %d: The total value of the hook is %d.\n", j, tr[1].sum);
    }
    return 0;
}
