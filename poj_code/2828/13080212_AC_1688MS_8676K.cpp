#include <stdio.h>
int a[200000], val[200000], solve[200000], n;
typedef struct node
{
    int left, right, len;
}Node;
Node tree[800000];
int build(int v, int l, int r)
{
    tree[v].left = l, tree[v].right = r;
    tree[v].len = r - l + 1;
    if(l == r)
        return 0;
    int mid = (l + r) / 2;
    build(v * 2, l, mid);
    build(v * 2 + 1, mid + 1, r);
    return 0;
}
int scan(int v, int k)
{
    tree[v].len--;
    if(tree[v].left == tree[v].right)
        return tree[v].left;
    if(k <= tree[2 * v].len)
        return scan(2 * v, k);
    else
        return scan(2 * v + 1, k - tree[2 * v].len);
}
int main()
{
    int v;
    while(~scanf("%d", &n))
    {
        v = 0;
        for(int i = 1;i <= n;i++)
            scanf("%d%d", &a[i], &val[i]);
        build(1, 1, n);
        for(int i = n;i > 0;i--)
            solve[i] = scan(1, a[i] + 1);
        for(int i = 1;i <= n;i++)
            a[solve[i]] = val[i];
        for(int i = 1;i <= n;i++)
        {
            if(v)printf(" ");
            printf("%d", a[i], v = 1);
        }
        printf("\n");
    }
    return 0;
}