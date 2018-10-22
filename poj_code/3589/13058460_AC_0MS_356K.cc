#include <stdio.h>
int main()
{
	int t, i, j, a, b;
	char x[5], y[5];
	scanf("%d", &t);
	while(t--)
	{
		scanf("%s%s", x, y);
		a = 0, b = 0;
		for(i = 0;i < 4;i++)
			if(x[i] == y[i])
				a++;
		for(i = 0;i < 4;i++)
			for(j = 0;j < 4;j++)
				if(y[j] == x[i])
					b++;
		printf("%dA%dB\n", a, b - a);
	}
}