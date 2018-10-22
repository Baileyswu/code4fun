#include<stdio.h>
#include<math.h>
long long int spa(long long int x)
{
	long long int i,a=1;
	for(i=2;i<=sqrt(x);i++)
		if(x%i==0){a=0;break;}
	return a;
}
long long int pow2(long long int x)
{
    return x*x;
}
long long int power(long long int a,long long int p,long long int q)
{
    if(p==1)
        return a%q;
    else if(p%2)
        return a*pow2(power(a,p/2,q)%q)%q;
    else
        return pow2(power(a,p/2,q)%q)%q;;

}
int miller(long long int x,long long int a)
{
    return power(a,x,x)%x==a;
}
int main()
{
	long long int x,a;
	while(scanf("%lld%lld",&x,&a)!=EOF&&x!=0&&a!=0)
	{
	    if(miller(x,a)&&!spa(x))
            printf("yes\n");
        else
            printf("no\n");
	}
    return 0;
}

