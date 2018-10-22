#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 33000
int L[N], C[N], ans[N], n;
void set()
{
    for(int i = 0;i < N;i++)
        L[i] = i&(i^(i-1));
}
int sum(int x)
{
    int r = 0;
    for(;x > 0;x -= L[x])
        r += C[x];
    return r;
}
void update(int x)
{
    for(;x < N;x += L[x])
        C[x]++;
}
int main()
{
    set();
    while(~scanf("%d", &n))
    {
        memset(C, 0, sizeof(C));
        memset(ans, 0, sizeof(ans));

        for(int i = 0;i < n;i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            ans[sum(++x)]++;
            update(x);
        }
        for(int i = 0;i < n;i++)
            printf("%d\n", ans[i]);
    }
    return 0;
}