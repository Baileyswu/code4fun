#include<stdio.h>
int main()
{
     int a[1005]={0},i,j,k,n,m,sum;
     scanf("%d",&m);
     for(k=1;k<=m;k++)
     {
         sum=0;
         scanf("%d",&n);
         for(i=0;i<n;i++)
            scanf("%d",&a[i]);
         for(i=0;i<n;i++)
            for(j=i+1;j<n;j++)
                if(a[i]>a[j])
                    sum++;
         printf("Scenario #%d:\n%d\n\n",k,sum);
      }
      return 0;
}
