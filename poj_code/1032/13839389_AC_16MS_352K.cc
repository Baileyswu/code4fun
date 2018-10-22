#include <stdio.h>
#include <math.h>
int main()
{
	int n;
	int a[50];
	while(~scanf("%d", &n))
	{
		int x = (sqrt(1+8*(n+1))-1)/2;
		int m = n+1 - (x+1)*x/2;
		for(int i = 0;i < x-1;i++)
			a[i] = i+2+m/(x-1);
		for(int i = x-1;i >= x-1-m%(x-1);i--)
			a[i]++;
		for(int i = 0;i < x-1;i++)
			printf("%d%c", a[i], " \n"[i==x-2]);
	}
	return 0;
}