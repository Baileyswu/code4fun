#include<stdio.h>
#include<math.h>
long long spa(long long x)
{
	long long i,a=1;
	if(x==1)
        return 0;
	for(i=2;i<=sqrt(x);i++)
		if(x%i==0){a=0;break;}
	return a;
}
long long pow2(long long x)
{
    return x*x;
}
long long power(long long a,long long p,long long q)
{
    if(p==1)
        return a%q;
    else if(p%2)
        return a*pow2(power(a,(p-1)/2,q)%q)%q;
    else
        return pow2(power(a,p/2,q)%q)%q;

}
int miller(long long p,long long a)
{
    return power(a,p,p)%p==a;
}
int main()
{
	long long p,a;
	while(scanf("%lld%lld",&p,&a)!=EOF&&(p!=0||a!=0))
	{
	    if(miller(p,a)&&!spa(p))
            printf("yes\n");
        else
            printf("no\n");
	}
    return 0;
}
