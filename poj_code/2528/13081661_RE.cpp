#include <stdio.h>
typedef struct node
{
    int left, right, type;
}Node;
Node tree[30003];
int n;
bool see[10001];
int set()
{
    for(int i = 0;i <= n;i++)
        see[i] = false;
    return 0;
}
int build(int v, int l, int r)
{
    tree[v].left = l, tree[v].right = r;
    tree[v].type = 0;
    if(l == r)
        return 0;
    int mid = (l + r) / 2;
    build(v * 2, l, mid);
    build(v * 2 + 1, mid + 1, r);
    return 0;
}
int update(int v, int l, int r, int m)
{
    if(tree[v].left == l && tree[v].right == r)
    {
        tree[v].type = m;
        return 0;
    }
    if(tree[v].type != -1)
    {
        tree[v * 2].type = tree[v].type;
        tree[v * 2 + 1].type = tree[v].type;
        tree[v].type = -1;
    }
    int mid = (tree[v].left + tree[v].right) / 2;
    if(r <= mid)
        update(2 * v, l, r, m);
    else if(l > mid)
        update(2 * v + 1, l, r, m);
    else
    {
        update(2 * v, l, mid, m);
        update(2 * v + 1, mid + 1, r, m);
    }
    return 0;
}
int solve(int v)
{
    if(tree[v].type != -1)
    {
        see[tree[v].type] = true;
        return 0;
    }
    solve(2 * v);
    solve(2 * v + 1);
    return 0;
}
int ans()
{
    int s = 0;
    for(int i = 1;i <= n;i++)
        if(see[i])
            s++;
    return s;
}
int main()
{
    int t, l, r;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        build(1, 1, 10001);
        for(int i = 1;i <= n;i++)
        {
            scanf("%d%d", &l, &r);
            update(1, l, r, i);
        }
        set();
        solve(1);
        printf("%d\n", ans());
    }
}