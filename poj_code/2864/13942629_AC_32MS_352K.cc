#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int n, D, a[105], t;
	while(~scanf("%d%d", &n, &D))
	{
		if(!n && !D)
			break;
		for(int i = 0; i < n;i++)
			scanf("%d", &a[i]);
		D--;
		while(D--)
		{
			for(int i = 0;i < n;i++)
			{
				scanf("%d", &t);
				a[i] &= t;
			}
		}
		int ans = 0;
		for(int i = 0;i < n;i++)
		{
			ans = ans || a[i];
			if(ans)
			{
				printf("yes\n");
				break;
			}
		}
		if(!ans)
			printf("no\n");
	}
	return 0;
}