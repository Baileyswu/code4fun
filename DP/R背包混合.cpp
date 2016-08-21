/**************************************************

            模版：混合背包
            题目：POJ 3260 The Fewest Coins
            tips：二进制拆分

**************************************************/


#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;
const int maxn=100+10, maxm=20000+10, p=20000, INF=0x7f7f7f7f;

int n, m, v[maxn], v1[maxn], c[maxn], f[maxm];
int N, v2[maxm], w[maxm];
int main()
{
    while(scanf("%d%d", &n, &m)!=EOF)
    {
        for(int i=1; i<=n; i++)
        {
            scanf("%d", &v[i]);
            v1[i]=-v[i];
        }
        for(int i=1; i<=n; i++) scanf("%d", &c[i]);

        N=0;
        for(int i=1; i<=n; i++)
            for(int sum=0, tmp=1; sum<=c[i]; tmp<<=1)//二进制拆分
                if(sum+tmp<c[i]) v2[++N]=tmp*v[i], w[N]=tmp, sum+=tmp;
                else
                {
                    v2[++N]=(c[i]-sum)*v[i], w[N]=(c[i]-sum);
                    break;
                }

        memset(f, 0x7f, sizeof f);
        f[0]=0;
        for(int i=1; i<=N; i++)
            for(int j=p; j>=v2[i]; j--)
                if(f[j-v2[i]]!=INF) f[j]=min(f[j], f[j-v2[i]]+w[i]);

        for(int i=1; i<=n; i++)
            for(int j=p+v1[i]; j>=0; j--)
                if(f[j-v1[i]]!=INF) f[j]=min(f[j], f[j-v1[i]]+1);

        if(f[m]!=INF) cout<<f[m]<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
