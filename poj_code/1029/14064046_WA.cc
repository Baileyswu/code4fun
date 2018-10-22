#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct node
{
	int num, count;
}p[1005];

int set(int n)
{
	for(int i = 0;i < n;i++)
		p[i].count = 0, p[i].num = i+1;
}
int cmp(struct node x, struct node y)
{
	return x.count > y.count;
}
int main()
{
	int n, k, m, l[505], r[505], flag[1005];
	while(~scanf("%d%d", &n, &k))
	{
		set(n);
		memset(flag, 0, sizeof(flag));
		while(k--)
		{
			int m, temp;
			scanf("%d", &m);
			for(int i = 0;i < m;i++)
				scanf("%d", &l[i]);
			for(int i = 0;i < m;i++)
				scanf("%d", &r[i]);
			char com[5];
			scanf("%s", com);
			if(com[0] == '=')
			{
				for(int i = 0;i < m;i++)
					flag[l[i]-1] = flag[r[i]-1] = 1;
			}
			else if(com[0] == '<')
			{
				for(int i = 0;i < m;i++)
					p[l[i]-1].count--;
				for(int i = 0;i < m;i++)
					p[r[i]-1].count++;
			}
			else if(com[0] == '>')
			{
				for(int i = 0;i < m;i++)
					p[l[i]-1].count++;
				for(int i = 0;i < m;i++)
					p[r[i]-1].count--;
			}
			int v = 0, ans;
			for(int i = 0;i < n;i++)
				if(!flag[i])
				{
					v++;
					ans = i+1;
				}
			if(v == 1)
			{
				printf("%d\n", ans);
				continue;
			}
			sort(p, p+n, cmp);
			int ma = p[0].count, mi = p[n-1].count;
			int ca = 0, ci = 0;
			for(int i = 0;i < n;i++)
				if(p[i].count == ma)
					ca++;
				else if(p[i].count == mi)
					ci++;
			if(ca == 1 || ci == 1)
				printf("0\n");
			else if(ca == 1 && ci != 1)
				printf("%d\n", p[0].num);
			else if(ca != 1 && ci == 1)
				printf("%d\n", p[n-1].num);

		}
	}
	return 0;
}