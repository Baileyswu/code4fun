#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
	int t, len, sum;
	char num[9];
	scanf("%d", &t);
	while(t--)
	{
		sum = 0;
		scanf("%s", num);
		len = strlen(num);
		for(int i = 0;i < len;i++)
			sum += (num[i] - '0') * pow(10, len - 1 - i) + 0.1;
		int k = len - 1;
		while(k--)
			sum = (sum + 5)/10;
		sum = sum * (pow(10, len - 1) + 0.000000001);
		printf("%d\n", sum);
	}
	return 0;
}