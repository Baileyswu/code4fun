#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 20002
struct line
{
    int kind;
    int left, right;
}lines[N * 6];
struct item
{
    int first;
    int last;
}poster[2 * N];
void create(int s, int t, int node)
{
    lines[node].left = s;
    lines[node].right = t;
    if(s == t)
        return ;
    int mid = ( lines[node].left + lines[node].right ) / 2;
    create(s, mid, node * 2);
    create(mid + 1, t, node * 2 + 1);
}
void update(int s, int t, int node, int cover)
{
    if(t == lines[node].right && lines[node].left == s)
    {
        lines[node].kind = cover;
        return;
    } 
    if(lines[node].kind != 0 && lines[node].kind != cover)
    {
        lines[node * 2].kind = lines[node].kind;
        lines[node * 2 + 1].kind = lines[node].kind;
        lines[node].kind = 0;
    }
    int mid = ( lines[node].left + lines[node].right) / 2;
    if(t <= mid)
    {
        update(s, t, node * 2, cover);
    }
    else if(s > mid)
        update(s, t, node * 2 + 1, cover);
    else 
    {
        update(s, mid, node * 2, cover);
        update(mid + 1, t, node * 2 + 1, cover);
    }
}
int k, result;
int re[N*6];
void cal(int node)
{
    if(lines[node].kind)
    {
        if(re[lines[node].kind] != 1)
        {
            re[lines[node].kind] = 1;
            result++;
        }
        return ;
    }
    cal(2 * node );
    cal(2 * node + 1);
}
int cmp(const void *p, const void *q)
{
    line *a = (line *)p;
    line *b = (line *)q;
    return a->kind < b->kind ? 1 : -1;
}
int cmp2(const void *p, const void *q)
{
    return (((struct item *)p)->first - ((struct item *)q)->first);
}
int main()
{
    int i, j, t, n, l[N], r[N];
    struct item *x, *y, xx, yy;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        memset(poster, 0, sizeof(poster));
        for(i=1, k=0; i<=n; i++)
        {
            scanf("%d%d", &l[i], &r[i]);
            poster[++k].first = l[i];
            poster[++k].first = r[i];
        }
        qsort(poster+1, n * 2, sizeof(poster[0]), cmp2);
        i=1, k=0;
        while(1)
        {
            if(i > n * 2)
                break;
            k++;
            poster[k].first = poster[i].first;
            poster[k].last = k;
            while(poster[i+1].first == poster[i].first)
                i++;
            i++;
        }
        memset(lines, 0, sizeof(lines));
        create(1, k, 1); //建树
        for(i=1; i<=n; i++)
        {
            xx.first = l[i];
            yy.first = r[i];
            x = (struct item *)bsearch(&xx, poster+1, k, sizeof(poster[1]), cmp2);
            y = (struct item *)bsearch(&yy, poster+1, k, sizeof(poster[1]), cmp2);
            update(x->last, y->last, 1, i); //更新
        }
        result = 0;
        memset(re, 0, sizeof(re));
        cal(1); //计数      
        printf("%d\n", result);
    }
    return 0;
}