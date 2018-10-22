#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int cmp(int x, int y)
{
	return x > y;
}
int main()
{
	int t, num[10], p;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &p);
		for(int i = 0;i < 10;i++)
			scanf("%d", &num[i]);
		sort(num, num+10, cmp);
		printf("%d %d\n", p, num[2]);
	}
	return 0;
}
