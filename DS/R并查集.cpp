/**************************************************

            模版：并查集
            题目：POJ1182 食物链

**************************************************/

#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=50000+10;

int n, m, a[5], b[5], f[maxn*3], p[maxn*3];

void Pre()
{
    for(int i=1; i<=n; i++) p[i]=i, p[i+n]=i+n, p[i+n*2]=i+n*2;
    for(int i=1; i<=n; i++) f[i]=i+n, f[i+n]=i+n*2, f[i+n*2]=i;
    return ;
}

int Root(int x)
{
    return (x==p[x])?(x):(p[x]=Root(p[x]));
}

int main()
{
    scanf("%d%d", &n, &m);
    Pre();

    int d, x, y, ans=0;

    for(int i=1; i<=m; i++)
    {
        scanf("%d%d%d", &d, &x, &y);

        if(x>n||y>n||(d==2&&x==y))  
        {
            ++ans;
            continue;
        }
            
        a[0]=Root(x), a[1]=f[a[0]], a[2]=f[a[1]];
        b[0]=Root(y), b[1]=f[b[0]], b[2]=f[b[1]];
            
        bool flag=false;
        for(int j=0; j<3&&!flag; j++)  if(a[0]==b[j])  flag=true;

        if(d==1)
        {
            if(flag)    ans+=(a[0]!=b[0]);
            else for(int j=0; j<3; j++) p[b[j]]=a[j];
        }
        else
        {
            if(flag)    ans+=(a[0]!=b[1]);
            else for(int j=0; j<3; j++) p[b[j]]=a[(j+2)%3];
        }
            
    }

    printf("%d\n", ans);
    return 0;
}
