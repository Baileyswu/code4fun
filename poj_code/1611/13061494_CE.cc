#include <stdio.h>
int father[30000];
int getfather(int x)
{
	if(x == father(x))
		return x;
	return getfather[father[x]];
}
int main()
{
	int n, m, i;
	while(scanf("%d%d", &n, &m) && n != 0)
	{
		for(i = 0;i < n;i++)
			father[i] = i;
		while(m--)
		{
			int k, id1;
			scanf("%d%d", &k, &id1);
			k--;
			while(k--)
			{
				scanf("%d", &id2);
				father[id2] = id1;
				getfather(id2);
			}
		}
		int o = getfather(0), count = 0;
		for(int i = 0;i < n;i++)
			if(father[i] == o)
				count++;
		printf("%d\n", count);
	}
	return 0;
}