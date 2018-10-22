#include<stdio.h>
#include<math.h>
#define S scanf
#define P printf
#define R return
long int found(long int a[],int n)
{
    int i,j;
    if(n==1)
        R 0;
    else if(a[n-1]==n)
        R found(a,n-1);
    else
    {
        for(i=0;i<n;i++)
        {
            if(a[i]==n)
            {
                j=i;
                break;
            }
        }
        for(i=j;i<n-1;i++)
        {
            a[i]=a[i+1];
        }
        R n-1-j+found(a,n-1);
    }
}
int main()
{
    int t,n,i,j,pos[1005],tp,v=1;
    long int a[1005],temp;
    S("%d",&t);
    while(t--)
    {
        S("%d",&n);
        for(i=0;i<n;i++)
        {
            S("%d",&a[i]);
            pos[i]=i;
        }
        for(i=0;i<n-1;i++)
            for(j=i+1;j<n;j++)
            {
                if(a[j]<a[i])
                {
                    temp=a[i];a[i]=a[j];a[j]=temp;
                    tp=pos[i];pos[i]=pos[j];pos[j]=tp;
                }
            }
        for(i=0;i<n;i++)
        {
            a[pos[i]]=i+1;
        }
        if(v>1)
            P("\n");
        P("Scenario #%d:\n%ld\n",v++,found(a,n));
    }
    R 0;
}
