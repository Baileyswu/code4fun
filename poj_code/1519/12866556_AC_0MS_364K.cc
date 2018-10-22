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
	char c;
	int sum;
input:
	sum=0;
	while((c=getchar())!='\n')
	{
		sum+=c-'0';
	}
	while(sum>9)
		sum=f(sum);
	if(sum)
	{
		printf("%d\n",sum);
		goto input;
	}
	return 0;
}
