#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int swap(int a[],int i,int j)
{
    int t;
    t=a[i];a[i]=a[j];a[j]=t;
    return 0;
}
int partition(int a[],int m,int k)
{
    int i=m,j=k+1,x=a[m];
    while(1)
    {
        while(a[++i]<a[m]);
        while(a[--j]>a[m]);
        if(i>=j)
        {
            a[m]=a[j];
            a[j]=x;
            break;
        }
        swap(a,i,j);
    }
    return j;
}
int qsort(int a[],int m,int k)
{
    if(m<k)
    {
        int j=partition(a,m,k);
        qsort(a,m,j-1);
        qsort(a,j+1,k);
    }
    return 0;
}
int main()
{
	int a[100],i=0,n,count,j;
	while(scanf("%d",&a[i])&&a[i]!=-1)
	{
	    count=0;
	    i=1,n=1;
	    while(scanf("%d",&a[i])&&a[i]!=0)
		{
		    i++;
            n++;
		}
        qsort(a,0,n-1);
        for(i=0;i<n;i++)
            for(j=i;j<n;j++)
                if(a[j]==2*a[i]){count++;break;}
        printf("%d\n",count);
        i=0;
	}
    return 0;
}

