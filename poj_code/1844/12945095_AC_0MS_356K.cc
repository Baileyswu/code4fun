#include<stdio.h>
#include<math.h>
#define S scanf
#define P printf
#define R return
int find(int x)
{
    int i,n;
    if(x==1)R 1;
    else
    {
        n=sqrt(2*x)-2;
        for(i=n;;i++)
        {
            if(x<=i*(i+1)/2)
                break;
        }
        R i;
    }
}
int main()
{
    int x,n;
    S("%d",&x);
    n=find(x);
    if(x%2==0)
    {
        if(n%4==1)n+=2;
        else if(n%4==2)n+=1;
    }
    else if(x%2==1)
    {
        if(n%4==3)n+=2;
        else if(n%4==0)n+=1;
    }
    P("%d\n",n);
    R 0;
}