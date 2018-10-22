#include<stdio.h>
#include<math.h>
int spa(long int x)
{
	long int i,a=1;
	for(i=2;i<=sqrt(x);i++)
		if(x%i==0){a=0;break;}
	return a;
}
int pow2(int x)
{
    return x*x;
}
int power(int a,long int p,long int q)
{
    if(p==1)
        return a%q;
    else if(p%2)
        return a*pow2(power(a,p/2,q)%q)%q;
    else
        return pow2(power(a,p/2,q)%q)%q;;

}
int miller(long int x,int a)
{
    return power(a,x,x)%x==a;
}
int main()
{
	long int x;
	int a;
	while(scanf("%d%d",&x,&a)!=EOF&&x!=0&&a!=0)
	{
	    if(miller(x,a)&&!spa(x))
            printf("yes\n");
        else
            printf("no\n");
	}
    return 0;
}
