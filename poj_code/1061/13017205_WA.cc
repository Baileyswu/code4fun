#include<stdio.h>
#include<math.h>
int gcd(int x,int y)
{
    if(x==0)
        return y;
    else if(y==0)
        return x;
    else return gcd(y,x%y);
}
int ojld(int m,int l,int a[3])
{
    if(l==1)
    {
        a[0]=0,a[1]=1;
    }
    else
    {
        ojld(l,m%l,a);
        a[3]=a[0];
        a[0]=a[1];
        a[1]=a[3]-floor(m/l)*a[1];
    }
    return 0;
}
int abs(int x)
{
    if(x<0)
        return -x;
    else
        return x;
}
int main()
{
    long int x,y,m,n,l,step;
    int a[3];
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
        printf("%d\n",a[0]);
    }
    return 0;
}
