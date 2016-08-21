/**************************************************

            模版：01背包
            题目：POJ 2184 Cow Exhibition

**************************************************/


#include<iostream>
#include<cstring>
#include<cstdio>
#define Max(a, b) ((a)>(b)?(a):(b))
using namespace std;
const int pos=100000, maxn=100+10, maxm=100000*2+10, INF=0x7fffffff;

int n, ans, v[maxn], w[maxn], f[maxm];

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d%d", &v[i], &w[i]);
    for(int i=0; i<maxm; i++)   f[i]=-INF;

    f[pos]=0;
    for(int i=1; i<=n; i++)
    {
        if(v[i]>0)
        {
            for(int j=pos+pos; j>=v[i]; j--)//f[i][j]=max(f[i-1][j], f[i-1][j-v[i]]+w[i]);
                if(f[j-v[i]]>-INF)//表示f[j-v[i]]点有访问过 即体积恰好装满
                    f[j]=Max(f[j], f[j-v[i]]+w[i]);
        }
        else 
        {
            for(int j=0; j<=pos+pos+v[i]; j++)//体积为负时注意循环顺序
                if(f[j-v[i]]>-INF)
                    f[j]=Max(f[j], f[j-v[i]]+w[i]);
        }
    }

    for(int i=0; i<=pos; i++)
        if(f[i+pos]>=0) ans=Max(ans, f[i+pos]+i);

    cout<<ans<<endl;
    return 0;
}
