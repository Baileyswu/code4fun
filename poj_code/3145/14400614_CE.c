#include <stdio.h>
#include <string.h>
#define N 1000100
int pos[N][3], num[N];
int main()
{
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);

	int n, tail, o = 0;
	while(scanf("%d", &n), n)
	{
		if(o)
			printf("\n");
		printf("Case %d:\n", ++o);
		tail = 0;
		char com[10];
		int d;
		memset(pos, 0, sizeof(pos));
		for(int s = 1;s <= n;s++)
		{
			scanf("%s%d", com, &d);
			if(com[0] == 'B')
			{
				num[++tail] = d;
				continue;
			}
			if(tail == 0)
			{
				printf("-1\n");
				continue;
			}
			if(!pos[d][0])
			{
				pos[d][1] = d;
				for(int i = pos[d][0]+1;i <= tail;i++)
					if(num[i] % d <= pos[d][1])
					{
						pos[d][1] = num[i]%d;
						pos[d][0] = i;
					}
				pos[d][2] = tail;
				printf("%d\n", pos[d][0]);
				continue;
			}
			for(int i = pos[d][2];i <= tail;i++)
				if(num[i] % d <= pos[d][1])
				{
					pos[d][1] = num[i]%d;
					pos[d][0] = i;
				}
			pos[d][2] = tail;
			printf("%d\n", pos[d][0]);
		}
	}
	return 0;
}