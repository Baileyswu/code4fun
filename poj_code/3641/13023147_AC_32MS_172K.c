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
long long int power(long long int a,long long int n,long long int m)
{
    long long int tmp=a,res=1LL;
    while(n)
    {
        if(n&1LL)
        {
            res*=tmp;
            res%=m;
        }
        tmp*=tmp;
        tmp%=m;
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
