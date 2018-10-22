#include<stdio.h>
#include<math.h>
int spa(long long x)
{
    if(x==1)
        return 0;
    long long i;
    for(i=2;i<=sqrt(x);i++)
        if(x%i==0)
            return 0;
    return 1;
}
long long pow2(long long x)
{
    return x*x;
}
long long power(long long a,long long p,long long q)
{
    if(p==0)
        return 1;
    else if(p==1)
        return a%q;
    else if(p%2)
        return a*pow2(power(a,(p-1)/2,q)%q)%q;
    else
        return pow2(power(a,p/2,q)%q)%q;
}
int miller(long long x,long long a)
{
    return power(a,x,x)%x==a;
}
int main()
{
	long long x,a;
	while(scanf("%lld%lld",&x,&a)!=EOF&&x!=0&&a!=0)
	{
	    if(!spa(x)&&miller(x,a))
            printf("yes\n");
        else
            printf("no\n");
	}
    return 0;
}
