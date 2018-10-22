#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define max_ 5845
int num[max_] = {0, 1};
int min(int x, int y)
{
	return x < y ? x : y;
}
int set()
{
	int a, b, c, d, e, t;
	a = b = c = d = e = 1;
	while(e < max_)
	{
		t = min(num[a]*2, min(num[b]*3, min(num[c]*5, num[d]*7)));
		num[++e] = t;
		//printf("%d %d %d %d t: %d  num[%d] %d\n", num[a]*2, num[b]*3, num[c]*5, num[d]*7, t, e, num[e]);
		if(num[a]*2 == t)
			a++;
		if(num[b]*3 == t)
			b++;
		if(num[c]*5 == t)
			c++;
		if(num[d]*7 == t)
			d++;
	}
}
int main()
{
	set();
	int n;
	while(scanf("%d", &n), n)
	{
		int t = n % 100, d = n % 10;
		char sre[5];
		if(t == 11 || t == 12 || t == 13)
			strcpy(sre, "th");
		else if(d == 1)
			strcpy(sre, "st");
		else if(d == 2)
			strcpy(sre, "nd");
		else if(d == 3)
			strcpy(sre, "rd");
		else
			strcpy(sre, "th");
		printf("The %d%s humble number is %d.\n", n, sre, num[n]);
	}
	return 0;
}