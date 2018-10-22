#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int num[1030];
int pr(int n)
{
	for(int i = 0;i < n;i++)
		printf("%d%c", num[i], " \n"[i==n-1]);
}
int swap(int x, int y)
{
	int t = num[x];
	num[x] = num[y];
	num[y] = t;
}
int cmp(int x, int y)
{
	return x < y;
}
int gao(int n)
{
	int i, j;
	for(i = n-1;i > 0;i--)
		if(num[i-1] < num[i])
			break;
	if(i == 0)
	{
		sort(num, num+n, cmp);
		return 0;
	}
	for(j = n-1;j > 0;j--)
		if(num[i-1] < num[j])
			break;
	swap(i-1, j);
	sort(num+i, num+n, cmp);
}
int fact(int n)
{
	if(n == 1 || n == 0)
		return 1;
	return n*fact(n-1);
}
int main()
{
	int t;
	while(~scanf("%d", &t))
	{
		while(t--)
		{
			int n, k;
			//k %= fact(n);
			scanf("%d%d", &n, &k);
			for(int i = 0;i < n;i++)
				scanf("%d", &num[i]);
			while(k--)
				gao(n);
			pr(n);
		}
	}
}