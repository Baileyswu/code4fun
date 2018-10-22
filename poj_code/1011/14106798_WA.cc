#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
int cmp(int x, int y)
{
	return x > y;
}
int main()
{
	int n, a[100], flag[100];
	while(scanf("%d", &n), n)
	{
		int sum = 0;
		memset(a, 0, sizeof(a));
		memset(flag, 0, sizeof(flag));
		for(int i = 0;i < n;i++)
		{
			scanf("%d", &a[i]);
			sum += a[i];
			flag[i] = 1;
		}
		sort(a, a+n, cmp);
		for(int ans = a[0];ans <= sum;ans++)
		{
			if(ans == sum)
			{
				printf("%d\n", ans);
				break;
			}
			if(sum%ans)
				continue;
			int th = ans, num = sum/ans, v = 0;
			while(num)
			{
				th = ans;
				for(int i = 0;i < n;i++)
				{
					if(th >= a[i] && flag[i])
						th -= a[i], flag[i] = 0;
					if(th == 0)
					{
						num--;
						break;
					}
				}
				if(th)
				{
					v = 1;
					break;
				}
			}
			if(!v && !num)
			{
				printf("%d\n", ans);
				break;
			}
		}
	}
	return 0;
}