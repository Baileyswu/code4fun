#include<stdio.h>
int main()
{
	int x,i,a[100000],k,b[1000],n,g,j;
	scanf("%d",&x);
	for(i=0;i<x;i++)
	{	scanf("%d",&a[i]);
		for(k=0;k<a[i];k++)
			b[k]=k+1;
		for(n=2;n<=a[i];n++)
		{	for(g=0;g<a[i];g++)
			if((g+1)%n==0)
			{	if(b[g]==0) b[g]=1;
				else b[g]=0;
			}
		}
		j=0;
		for(k=0;k<a[i];k++)
			if(b[k]==1)
				j=j+1;
		a[i]=j;	

	}

	for(i=0;i<x;i++)
		printf("%d\n",a[i]);

	return 0;
}