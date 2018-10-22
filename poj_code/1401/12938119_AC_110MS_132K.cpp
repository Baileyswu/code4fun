#include<stdio.h>
int main()
{
	long int b,i,j,w,r;
	long int f;
    scanf("%d",&j);
	for(i=0;i<j;i++)
	{
		scanf("%d",&f);
		b=0,r=1;
		for(w=1;w<14;w++)
			{r=5*r;
			b=b+f/r;}
		printf("%ld\n",b);
	}

	return 0;

}