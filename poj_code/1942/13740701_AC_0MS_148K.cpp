#include <stdio.h>
int main()
{   
	double sum;
	unsigned n,m,a,b;
	while(scanf("%d%d",&n,&m),n||m)
	{   
		a=n+m;
		b=n<m?n:m;
		sum=1;
		while(b>0)
		 sum*=a--/double(b--);
		printf("%.0f\n",sum);
     } 
	return 0;
}