#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int num[15];
int main()
{
	int n;
	char str[40];
	while(scanf("%d", &n), n)
	{
		getchar();
		memset(num, 0, sizeof(num));
		int sum = 0, _max = 0;
		for(int k = 0;k < n;k++)
		{
			gets(str);
			for(int i = 0;i < 25;i++)
				if(str[i] == 'X')
					num[k]++;
			if(num[k] > _max)
				_max = num[k];
			sum += num[k];
		}
		printf("%d\n", _max*n-sum);
	}
}