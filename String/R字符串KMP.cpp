/**************************************************

            模版：KMP
            题目：HDU1711 Number Sequence

**************************************************/

#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=1000000+10;

int T, n, m, a[maxn], b[maxn];
int nx[maxn], ex[maxn];

int Kmp()
{
    nx[0]=0;
    for(int i=1, j=0; i<m; i++)
    {
        while(j&&b[j]!=b[i])    j=nx[j-1];
        if(b[j]==b[i])  ++j;
        nx[i]=j;
    }
    
    for(int i=0, j=0; i<n; i++)
    {
        while(j&&b[j]!=a[i])    j=nx[j-1];
        if(b[j]==a[i])  ++j;
        if(j==m)    return i-m+2;
    }

    return -1;
}

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &m);
        for(int i=0; i<n; i++)  scanf("%d", &a[i]);
        for(int i=0; i<m; i++)  scanf("%d", &b[i]);

        printf("%d\n", Kmp());
    }
    return 0;
}
