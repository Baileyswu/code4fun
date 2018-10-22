#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	char p1[80], p2[80];
	while(~scanf("%s%s", p1, p2))
	{
		int len = strlen(p1);
		if(len == 1 && p1[0] == 'E')
			break;
		int q1 = 0, q2 = 0;
		for(int i = 0;i < len;i++)
		{
			if(p1[i] == p2[i])
				continue;
			if(p1[i] == 'R')
			{
				if(p2[i] == 'S')
					q1++;
				else
					q2++;
			}
			else if(p1[i] == 'P')
			{
				if(p2[i] == 'R')
					q1++;
				else
					q2++;
			}
			else if(p1[i] == 'S')
			{
				if(p2[i] == 'P')
					q1++;
				else
					q2++;
			}
		}
		printf("P1: %d\nP2: %d\n", q1, q2);
	}
	return 0;
}
