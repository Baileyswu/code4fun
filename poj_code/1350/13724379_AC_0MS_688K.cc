#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <cmath>
using namespace std;
int cmp2(const void*a, const void*b)
{
	return *(int*)b - *(int*)a;
}
int main()
{
	int a[5], n, a1, a2, times, num, counts, i;
	while (scanf("%d", &n) && n != -1)
	{
		printf("N=%d:\n", n);
		if (n % 1111 == 0 || n >= 10000 || n<1000)
		{
			printf("No!!\n");
			continue;
		}
		a[0] = n % 10;
		a[1] = n / 10 % 10;
		a[2] = n / 100 % 10;
		a[3] = n / 1000;
		times = 1;
		qsort(a, 4, sizeof(a[0]), cmp2);
		counts = 4, a1 = 0, a2 = 0;
		for (i = 0; i<counts; i++)
		{
			a1 += a[i] * pow(10, counts - 1 - i);
			a2 += a[i] * pow(10, i);
		}
		num = a1 - a2;
		printf("%d-%d=%d\n", a1, a2, num);
		while (1)
		{
			if (num == 6174 || num == 0)
			{
				printf("Ok!! %d times\n", times);
				break;
			}
			a[0] = num % 10;
			a[1] = num / 10 % 10;
			a[2] = num / 100 % 10;
			a[3] = num / 1000;
			counts = 0, a1 = 0, a2 = 0;
			qsort(a, 4, sizeof(a[0]), cmp2);
			if (num<10)
				counts = 1;
			if (num >= 10)
				counts = 2;
			if (num >= 100)
				counts = 3;
			if (num >= 1000)
				counts = 4;
			for (i = 0; i<counts; i++)
			{
				a1 += a[i] * pow(10, counts - 1 - i);
				a2 += a[i] * pow(10, i);
			}
			num = a1 - a2;
			printf("%d-%d=%d\n", a1, a2, num);
			++times;
		}
	}
	return 0;
}