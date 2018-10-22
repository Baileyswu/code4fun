#include <stdio.h>
int father[30000];
int find(int x)
{
	if(x == father[x])
		return x;
	father[x] = find(father[x]);
	return father[x];
}
int set(int x, int y)
{
	int fx = find(x), fy = find(y);
	father[fy] = fx;
	return 0;
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
			int k, id1, id2;
			scanf("%d%d", &k, &id1);
			k--;
			while(k--)
			{
				scanf("%d", &id2);
				set(id1, id2);
			}
		}
		int o = find(0), count = 1;
		for(int i = 1;i < n;i++)
			if(find(i) == o)
				count++;
		printf("%d\n", count);
	}
	return 0;
}