#include<stdio.h>
#include<string.h>
#define S scanf
#define P printf
#define R return
int main()
{
    int a[10005],n,i,j,t;
    S("%d",&n);
    for(i=0;i<n;i++)
    {
        S("%d",&a[i]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i;j<n;j++)
        {
            if(a[i]>a[j])
            {
                t=a[i];a[i]=a[j];a[j]=t;
            }
        }
    }
    P("%d\n",a[n/2]);
    R 0;
}
