#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct Node
{
    int a,b;
};
Node s[300];
int ans[300];
int comp(Node x,Node y)
{
    if(x.a!=y.a)
        return x.a<y.a;
}
int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        int cmx,cmy;
        for(int i=0; i<n; i++)
        {
            scanf("%d%d",&cmx,&cmy);
            cmx=(cmx+1)/2,cmy=(cmy+1)/2;
            if(cmx>cmy)
            {
                int temp=cmx;
                cmx=cmy;
                cmy=temp;
            }
            s[i].a=cmx,s[i].b=cmy;
        }
        sort(s,s+n,comp);
        int cas=0,last;
        memset(ans,0,sizeof(ans));
        for(int i=0; i<n; i++)
        {
            if(ans[i]==0)
            {
                //printf("%d %d\n",s[i].a,s[i].b);
                last=s[i].b;
                ans[i]=1;
                cas++;
                for(int j=i+1; j<n; j++)
                {
                    if(ans[j]==0&&s[j].a>last)
                    {
                        last=s[j].b;
                        ans[j]=1;
                    }
                }
            }
        }
        printf("%d\n",cas*10);
    }
    return 0;
}
