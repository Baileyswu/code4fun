#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define I64 __int64
int main()
{
	I64 a;
	while(scanf("%I64d",&a)!=EOF)
	{
		I64 i;
		for(i=a;;i--)
		{

			if((a*a+1)%i==0)
			{
				printf("%I64d\n",i+(a*a+1)/i+2*a);
				break;
			}
	}
	}
	return 0;
}
