#include <stdio.h>
int main()
{
	int sum, u;
	while(~scanf("%d", &sum))
	{
		if(sum == -1)
			break;
		printf("%d coconuts, ", sum);
		u = 0;
		int person = sum, i, s, v;
		while(person > 1)
		{
			s = sum;
			v = 0;
			for(i = 0;i < person;i++)
			{
				s--;
				if(s % person != 0)
				{
					person--;
					v = 1;
					break;
				}
				s = s / person * (person - 1);
			}
			if(v)
				continue;
			if(s % person != 0)
				continue;
			else
			{
				printf("%d people and 1 monkey\n", person);
				u = 1;
				break;
			}
		}
		if(!u)
			printf("no solution\n");
	}
	return 0;
}