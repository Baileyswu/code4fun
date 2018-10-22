#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;
queue <int>line;
int flag[300010];
int main()
{
	int n, m, sta;
	while(~scanf("%d%d", &n, &m))
	{
		if(n==m)
		{
			printf("0\n");
			continue;
		}
		memset(flag, 0, sizeof(flag));
		line.push(n);
		flag[n] = 1;
		while(1)
		{
			sta = line.front();
			line.pop();
			if(!flag[sta+1] && sta+1<300000)
			{
				flag[sta+1] = flag[sta] + 1;
				if(sta+1 == m)
					break;
				line.push(sta+1);
			}
			if(!flag[sta-1] && sta-1 > 0)
			{
				flag[sta-1] = flag[sta] + 1;
				if(sta-1 == m)
					break;
				line.push(sta-1);
			}
			if(!flag[sta*2] && sta*2<300000)
			{
				flag[sta*2] = flag[sta] + 1;
				if(sta*2 == m)
					break;
				line.push(sta*2);
			}
		}
		printf("%d\n", flag[m]-1);
		while(!line.empty())
			line.pop();
	}
	return 0;
}