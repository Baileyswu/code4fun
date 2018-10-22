#include <stdio.h>
int head[10001], rela[10001], n, m;
int clear()
{
    for(int i = 1;i <= n;i++)
    {
        head[i] = i;
        rela[i] = 0;
    }
    return 0;
}
int find(int a)
{
    if(head[a] == a)
        return a;
    int temp = head[a];
    head[a] = find(head[a]);
    if(rela[a] == rela[temp])
        rela[a] = 0;
    else
        rela[a] = 1;
    return head[a];
}
int set(int a, int b, int fa, int fb)
{

    head[fa] = fb;
    if(rela[a] == rela[b])
        rela[fa] = 1;
    else
        rela[fa] = 0;
    return 0;
}
int main()
{
    int t, a, b, fa, fb;
    char q[2];
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &m);
        clear();
        while(m--)
        {
            scanf("%s%d%d", q, &a, &b);
            fa = find(a), fb = find(b);
            if(q[0] == 'A')
            {
                if(fa != fb)
                {
                    printf("Not sure yet.\n");
                    continue;
                }
                if(rela[a] == rela[b])
                {
                    printf("In the same gang.\n");
                    continue;
                }
                printf("In different gangs.\n");
            }
            else if(q[0] == 'D')
            {
                if(fa != fb)
                    set(a, b, fa, fb);
            }
        }
    }
    return 0;
}