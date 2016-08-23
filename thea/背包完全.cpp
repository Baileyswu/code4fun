/**************************************************

            模版：完全背包
            题目：UVA 674 Coin Change

**************************************************/


#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int maxm=7489+10, INF=0x7f7f7f7f;

int n=5, v[10]={0, 50, 25, 10, 5, 1}, m, f[maxm];

int main()
{
    while(scanf("%d", &m)!=EOF)
    {
        memset(f, 0, sizeof f);
        f[0]=1;

        for(int i=1; i<=n; i++)
            for(int j=v[i]; j<=m; j++)//f[i][j]=f[i-1][j]+f[i][j-v[i]];
                f[j]=f[j]+f[j-v[i]];

        cout<<f[m]<<endl;
    }
    return 0;
}
