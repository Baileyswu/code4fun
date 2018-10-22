#include <stdio.h>
int main()
{
	long int b,i,t,w,r,f;
    scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&f);
		b=0,r=1;
		for(w=1;w<14;w++)
		{
			r*=5;
			b+=f/r;
		}
		printf("%ld\n",b);
	}
	return 0;
} 