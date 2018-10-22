#include<stdio.h>
#include<math.h>
int min(int a,int b)
{
    return a<b?a:b;
}
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    int i,a,b,c,d;
    while(~scanf("%d%d",&c,&b))
    {
        a=min(c,b);
        b=max(b,c);
        i=b-a;
        d=i*(sqrt(5)+1)/2;
        if(a==d)
            printf("0\n");
        else
            printf("1\n");
    }
    return 0;
}
