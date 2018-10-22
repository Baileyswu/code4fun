#include<stdio.h>
int main()
{
	int a,b;
	while((scanf("%d%d",&a,&b))!=EOF)
	{
		if(a%2-b%2)
			printf("0\n");
		else
			printf("1\n");
	}

	return 0;
}