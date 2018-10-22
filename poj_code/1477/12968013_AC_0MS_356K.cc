#include<stdio.h>
#include<string.h>
#define S scanf
#define P printf
#define R return
int main()
{
    int a[55],n,i,sum,ave,v=1;
    while((S("%d",&n))!=EOF&&n!=0){
        sum=0;
        for(i=0;i<n;i++)
        {
            S("%d",&a[i]);
            sum+=a[i];
        }
        ave=sum/n;
        sum=0;
        for(i=0;i<n;i++)
            if(a[i]>ave)
                sum+=a[i]-ave;
        P("Set #%d\nThe minimum number of moves is %d.\n\n",v++,sum);
    }

    R 0;
}
