/**************************************************

            模版：EXKMP
            题目：HDU4333 Revolving Digits

**************************************************/

#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=200000+10;
#define Max(a, b) ((a)>(b)?(a):(b))

int T, n, m, nx[maxn], ex[maxn];
char t[maxn], s[maxn];

void Read()
{
    scanf("%s", t);
    n=strlen(t);

    for(int i=0; i<n; i++)  s[i]=s[n+i]=t[i];
    m=n+n;
    
    memset(nx, 0, sizeof nx);
    memset(ex, 0, sizeof ex);
    return ;
}

void Exkmp()
{
    nx[0]=n;
    for(int i=1; i<n; i++)
    {
        if(t[i]!=t[i-1])    break;
        nx[1]=i;
    }
    for(int i=2, j, k=1, p, w; i<n; i++)
    {
        p=k+nx[k]-1, w=nx[i-k];
        if(i+w<p+1) nx[i]=w;
        else
        {
            j=Max(p-i+1, 0);
            while(i+j<n && t[i+j]==t[j])    ++j;
            nx[i]=j, k=i;
        }
    }

    for(int i=0; i<n&&i<m; i++)
    {
        if(s[i]!=t[i])  break;
        ex[0]=i+1;
    }
    for(int i=1, j, k=0, p, w; i<m; i++)
    {
        p=k+ex[k]-1, w=nx[i-k];
        if(i+w<p+1) ex[i]=w;
        else
        {
            j=Max(p-i+1, 0);
            while(i+j<m && j<n && s[i+j]==t[j]) ++j;
            ex[i]=j, k=i;
        }
    }
    return ;
}

int Kmp()
{
    nx[0]=0;
    for(int j=0, i=1; i<n; i++)
    {
        while(j && t[j]!=t[i])  j=nx[j-1];
        if(t[j]==t[i])  ++j;
        nx[i]=j;
    }
    return nx[n-1];
}

void Work()
{
    int le=0, eq=0, gr=0;
    Exkmp();

    for(int i=0; i<n; i++)
    {
        if(ex[i]==n)    ++eq;
        else
        {
            if(s[i+ex[i]]>t[ex[i]]) ++gr;
            else ++le;
        }
    }

    int tmp=n-Kmp();
    int cnt=(n%tmp)?(1):(n/tmp);
    printf(" %d %d %d\n", le/cnt, eq/cnt, gr/cnt);
    return ;
}

int main()
{
    scanf("%d", &T);
    for(int i=1; i<=T; i++)
    {
        printf("Case %d:", i);
        Read(), Work();
    }
    return 0;
}
