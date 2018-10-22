#include <stdio.h>
#include <math.h>
int mult(int a[4],int b[4])
{
    int c[4],i;
    c[0]=a[0]*b[0]+a[1]*b[2];
	c[1]=a[0]*b[1]+a[1]*b[3];
	c[2]=a[2]*b[0]+a[3]*b[2];
	c[3]=a[2]*b[1]+a[3]*b[3];
    for(i=0;i<4;i++)
        a[i]=c[i];
    return 0;
}
int Fi(int a[4],int n)
{
    int b[4]={1,1,1,0},e[4]={1,0,0,1};
    if(n==1)
        mult(a,e);
    else if(n&1LL)
    {
        Fi(a,n/=2);
        mult(a,a);
        mult(a,b);
    }
    else
    {
        Fi(a,n/=2);
        mult(a,a);
    }
    return 0;
}
int main()
{
    int a[4],b[4],n,i,k,te,p=0;
    scanf("%d", &te);
    while(te--)
    {
    	scanf("%d",&n);
        a[0]=1,a[1]=1,a[2]=1,a[3]=0;
        n++;
        Fi(a,n);
        printf("Scenario #%d:\n%d\n\n",++p,a[0]);
	}
    return 0;
}
