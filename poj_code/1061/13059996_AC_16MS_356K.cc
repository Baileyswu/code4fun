#include <stdio.h>
#include <math.h>
long long gcd(long long x,long long y)
{
    if(x==0)
        return y;
    else if(y==0)
        return x;
    else return gcd(y,x%y);
}
long long ojld(long long m,long long l,long long a[3])
{
    if(l==1)
    {
        a[0]=0,a[1]=1;
    }
    else
    {
        ojld(l,m%l,a);
        a[2]=a[0];
        a[0]=a[1];
        a[1]=a[2]-m/l*a[1];
    }
    return 0;
}
long long abs(long long x)
{
    if(x<0)
        return -x;
    else
        return x;
}
int main()
{
    long long x,y,m,n,l,step,a[3];
    scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l);
    m=m-n,l=-l,y=y-x;
    n=gcd(m,l);
    if(y%n!=0)
        printf("Impossible\n");
    else
    {
        m=m/n,l=l/n,y=y/n,step=abs(l);
        ojld(m,l,a);
        a[0]*=y;
        a[0]%=step;
        if(a[0]<=0)
            a[0]+=step;
        printf("%lld\n",a[0]);
    }
    return 0;
}
