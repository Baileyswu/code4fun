#include<stdio.h>
#include<math.h>
long int gcd(long int x,long int y)
{
    if(x==0)
        return y;
    else if(y==0)
        return x;
    else return gcd(y,x%y);
}
long int ojld(long int m,long int l,long int a[3])
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
        a[1]=a[2]-floor(m/l)*a[1];
    }
    return 0;
}
long int abs(long int x)
{
    if(x<0)
        return -x;
    else
        return x;
}
int main()
{
    long int x,y,m,n,l,step,a[3];
    scanf("%d%d%d%d%d",&x,&y,&m,&n,&l);
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
        if(a[0<0])
            a[0]+=step;
        printf("%ld\n",a[0]);
    }
    return 0;
}
