#include<stdio.h>
#include<math.h>
int mult(int a[4],int c[4])
{
    int b[4],i;
    b[0]=a[0]*c[0]+a[1]*c[2];
	b[1]=a[0]*c[1]+a[1]*c[3];
	b[2]=a[2]*c[0]+a[3]*c[2];
	b[3]=a[2]*c[1]+a[3]*c[3];
    for(i=0;i<4;i++)
    {
        a[i]=b[i]%10000;
    }
    return 0;
}
int Fi(int a[4],int n)
{
    int b[4]={1,1,1,0},e[4]={1,0,0,1};
    if(n==1)
        mult(a,e);
    else if(n%2)
    {
        Fi(a,n=(n-1)/2);
        mult(a,a);
        mult(a,b);
    }
    else
    {
        Fi(a,n=n/2);
        mult(a,a);
    }

}
int main()
{
    int a[4],b[4];
    long int n,i,k;
    while(scanf("%d",&n)&&n!=-1)
    {
        if(n==0)
            printf("0\n");
        else if(n==1)
            printf("1\n");
        else
        {
            a[0]=1,a[1]=1,a[2]=1,a[3]=0;
            n--;
            Fi(a,n);
            printf("%d\n",a[0]);
        }
    }
    return 0;
}
