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
long long power(long long a,long long n,long long m)
{
    long long tem=a,res=1LL;
    while(n)
    {
        if(n&1LL)
        {
            res*=tem;
            res%=m;
        }
        tem*=tem;
        tem%=m;
        n>>=1LL;
    }
    return res;
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
