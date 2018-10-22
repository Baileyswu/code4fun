#include<stdio.h>
int main()
{
	int a,b,t;
	while((scanf("%d%d",&a,&b))!=EOF)
	{
		if(a>b)
		{t=a;a=b;b=t;}
		if((a-b)%2)
			printf("0\n");
		else
			printf("1\n");
	}

	return 0;
}