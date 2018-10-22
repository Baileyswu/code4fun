#include<stdio.h>
int f(long int x)
{
	int a[10],i;
	long int m=1000000000,y=0;
	if(x<10) y=x;
		else
		{
			for(i=0;i<10;i++)
			{
				a[i]=x/m;
				x-=m*a[i];
				m/=10;
				y+=a[i];
			}
		}
	return y;
}
int main()
{
	long int n;
	while((scanf("%d",&n))!=EOF&&n!=0)
	{		
		while(n>9)n=f(n);		
		printf("%d\n",n);
	}
	return 0;
}