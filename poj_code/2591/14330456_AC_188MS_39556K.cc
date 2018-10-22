#include <stdio.h>
int min(int a,int b)
{
    return a<b?a:b;
}
int data[10000001];
int main()
{
    int n,two=1,three=1;
    data[1]=1;

    for(int i=2;i<=10000000;i++)
    {
        data[i]=min(data[two]*2+1,data[three]*3+1);
        if(data[i]==data[two]*2+1)
            two++;
        if(data[i]==data[three]*3+1)
            three++;
    }
    while(scanf("%d",&n)!=EOF)
        printf("%d\n",data[n]);
    return 0;
}
