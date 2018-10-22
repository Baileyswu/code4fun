#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	while(scanf("%d", &n), n)
	{
		int p, q = 0;
		while(n--)
		{
			scanf("%d", &p);
			if(p != q)
			{
				printf("%d ", p);
				q = p;
			}
		}
		printf("$\n");
	}
	return 0;
}
