#include <stdio.h>
#include <string.h>
int main()
{
	int flag[1010];
	int n;
	while(scanf("%d", &n), n)
	{
		int head;
		while(scanf("%d", &head), head)
		{
			memset(flag, 0, sizeof(flag));
			flag[head] = 1;
			int temp, v = 0, j;
			for(int i = 1;i<n;i++)
			{
				scanf("%d", &temp);
				if(v)
					continue;
				flag[temp] = 1;
				if(temp > head)
					head = temp;
				else
				{
					for(j = temp+1;j < head;j++)
						if(!flag[j])
							break;
					if(j!=head)
						v = 1;
					else
					{
						for(j = temp-1;j > 0;j--)
							if(!flag[j])
								break;
						head = j+1;
					}
				}
			}
			if(v)
				printf("No\n");
			else
				printf("Yes\n");

		}
		printf("\n");
	}
	return 0;
}