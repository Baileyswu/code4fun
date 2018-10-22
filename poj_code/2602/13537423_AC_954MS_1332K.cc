#include <stdio.h>
char a[1000005];
int main()
{
	int t, i;
	char s[4];
	scanf("%d", &t);
	getchar();
	for(i = 0;i < t;i++)
	{
		gets(s);
		a[i] = s[0] - '0' + s[2] - '0';
	}
	for(i = t - 1;i >= 0;i--)
	{
		if(a[i] > 9)
		{
			a[i] -= 10;
			a[i - 1]++;
		}
		a[i] += '0';
	}
	printf("%s\n", a);
	return 0;
}