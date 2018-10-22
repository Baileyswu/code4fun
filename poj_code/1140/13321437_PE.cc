#include <stdio.h>
int gcd(int x, int y)
{
	if(x == y)
		return x;
	if(x == 0)
		return y;
	if(y == 0)
		return x;
	return gcd(y, x % y);
}
int a, b, c, left, t, count, enter;
int print()
{
	left = a * 10 % b;
	if(enter == 50)
		printf("\n", enter = 0);
	printf("%d", a * 10 / b, enter++);
	while(a != left && left && count < b)
	{
		t = left;
		left = t * 10 % b;
		if(enter == 50)
			printf("\n", enter = 0);
		printf("%d", t * 10 / b, enter++);
	}
	printf("\n");
	return 0;
}
int move()
{
	left = a * 10 % b;
	count = 1;
	while(a != left && left && count < b)
	{
		t = left;
		left = t * 10 % b;
		count++;
	}
	if(!left)
	{
		print();
		return 1;
	}
	if(count < b)
	{
		print();
		return 0;
	}
	if(enter == 50)
		printf("\n", enter = 0);
	printf("%d", a * 10 / b, enter++);
	a = a * 10 % b;
	move();
	return 0;
}
int main()
{
	while(scanf("%d%d", &a, &b) && a && b)
	{
		enter = 0;
		c = gcd(a, b);
		a = a / c, b = b / c;
		a = a % b;
		printf(".");
		if(move())
			printf("This expansion terminates.\n");
		else
			printf("The last %d digits repeat forever.\n", count);
	}
	return 0;
}