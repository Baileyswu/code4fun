#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char first[201],second[201],third[401];
int res[201][201];
int init(int n,int m)
{
    int i;
    for(i=1;i<=m;i++)
        if(second[i]==third[i]) res[0][i]=1;
        else break;
    for(i=1;i<=n;i++)
        if(first[i]==third[i]) res[i][0]=1;
        else break;
    return 0;
}
int dp(int n,int m)
{
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(third[i+j]==first[i] && res[i-1][j]) res[i][j]=1;
            if(third[i+j]==second[j] && res[i][j-1]) res[i][j]=1;
        }
    if(res[n][m]) return 1;
    return 0;
}
int main()
{
    int n,len1,len2,count=0;;
    scanf("%d",&n);
    while(n--)
    {
        count++;
        scanf("%s %s %s",first+1,second+1,third+1);
        len1=strlen(first+1);
        len2=strlen(second+1);
        memset(res,0,sizeof(res));
        init(len1,len2);
    
        if(dp(len1,len2))
            printf("Data set %d: yes\n",count);
        else
            printf("Data set %d: no\n",count);
    }
    return 0;
}