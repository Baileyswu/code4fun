#include <stdio.h>
int main()
{
	int f[10000],i;
	for(i=0;i<10000;i++)
	f[i]=i+1;
	int a,b,c,d,x;
	for(a=0;a<10;a++)
		for(b=0;b<10;b++)
			for(c=0;c<10;c++)
				for(d=0;d<10;d++)
				{
					x=1001*a+101*b+11*c+2*d;
				  	for(i=0;i<10000;i++)
					  if(x==f[i])
						f[i]=0;
				}
   for(i=0;i<10000;i++)
	   if(f[i]!=0)
	   printf("%d\n",f[i]);
	return 0;
}