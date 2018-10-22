#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int flag[30];
int num[30];
int main()
{
	int n, m, C, o = 0;
	while(scanf("%d%d%d", &n, &m, &C))
	{
		if(!n && !m && !C)
			break;
		memset(flag, 0, sizeof(flag));
		for(int i = 1;i <= n;i++)
			scanf("%d", &num[i]);
		int sum = 0, temp, v = 0, ma = 0;
		for(int k = 1;k <= m;k++)
		{
			scanf("%d", &temp);
			if(v)
				continue;
			if(flag[temp])
				sum -= num[temp];
			else
			{
				sum += num[temp];
				if(sum > C)
				{
					printf("Sequence %d\nFuse was blown.\n", ++o);
					v = 1;
					continue;
				}
				if(sum > m)
					ma = sum;
			}
			flag[temp] = 1-flag[temp];
		}
		if(!v )
			printf("Sequence %d\nFuse was not blown.\nMaximal power consumption was %d amperes.\n", ++o, ma);
		//else if(!v && ma == 1)
			//printf("Sequence %d\nFuse was not blown.\nMaximal power consumption was %d ampere.\n", ++o, ma);


	}
}
