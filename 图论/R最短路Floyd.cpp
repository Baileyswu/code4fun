/**************************************************

            模版：最短路Floyd
            题目：HDU2544 最短路

**************************************************/

#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=100+10;
#define Min(a, b) ((a)<(b)?(a):(b))
int n, m, d[maxn][maxn];

void Read()
{
    memset(d, 0xf, sizeof d);
    for(int i=1, u, v, c; i<=m; i++)
    {
        scanf("%d%d%d", &u, &v, &c);
        d[u][v]=d[v][u]=c;
    }
    return ;
}

void Work()
{
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                if(i!=j&&j!=k&&i!=k)
                    d[i][j]=Min(d[i][j], d[i][k]+d[k][j]);
    printf("%d\n", d[1][n]);
    return ;
}

int main()
{
    while(scanf("%d%d", &n, &m)!=EOF&&n+m)  Read(), Work();
    return 0;
}
