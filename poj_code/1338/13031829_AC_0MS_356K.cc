#include<stdio.h>
int main()
{
	long n,m;
	int h1=1,h2=1,h3=1,tail=1;
	long a[2000],b[2000],c[2000],d[2000];
	a[1]=1,b[1]=1,c[1]=1,d[1]=1;
	while (tail<1600)
	{
		if (a[h1]*2<=b[h2]*3)
			m=a[h1]*2;
		else
			m=b[h2]*3;
		if (m>c[h3]*5) m=c[h3]*5;
		if (m==a[h1]*2) h1++;
		if (m==b[h2]*3) h2++;
		if (m==c[h3]*5) h3++;
		tail++;
		d[tail]=m,a[tail]=m,b[tail]=m,c[tail]=m;
	}
	while (1)
	{
		scanf("%d",&n);
		if (n!=0)
			printf("%d\n",d[n]);
		else
			break;
	}
	return 0;
}
