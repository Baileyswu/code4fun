#include<stdio.h>
#define S scanf
#define P printf
#define R return
int main()
{
    int a,b,c,d,i,ca=1;
    while((S("%d%d%d%d",&a,&b,&c,&d))!=EOF&&a!=-1)
    {
        for(i=d+1;i<=d+21252;i++)
        {
            if((i-a)%23==0&&(i-b)%28==0&&(i-c)%33==0)
            break;
        }
        P("Case %d: the next triple peak occurs in %d days.\n",ca++,i-d);
    }
    R 0;
}
