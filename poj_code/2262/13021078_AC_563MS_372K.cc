#include<stdio.h>
#include<math.h>
int prime(int x)
{
    int i,v=1;
    for(i=2;i<=sqrt(x);i++)
        if(x%i==0){v=0;break;}
    return v;
}
int main()
{
    int n,k;
    while(~scanf("%d",&n))
    {
        for(k=3;k<=n/2;k++)
        {
            if(prime(k)&&prime(n-k))
            {
                printf("%d = %d + %d\n",n,k,n-k);
                break;
            }
        }
    }
    return 0;
}
