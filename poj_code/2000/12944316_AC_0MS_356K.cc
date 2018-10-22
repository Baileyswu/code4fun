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
int coin(int n)
{
    if(n==1) R 1;
    else R coin(n-1)+n*n;
}
int main()
{
    int x,sum,n;
    while((S("%d",&x))!=EOF&&x!=0)
    {
        if(x==1)sum=1;
        else
        {
            n=find(x);
            sum=coin(n-1)+(x-(n-1)*n/2)*n;
        }
        P("%d %d\n",x,sum);
    }
    R 0;
}
