#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 1100
#define M 500000
#define LL long long
LL C[N], L[N];
struct node
{
	int st, ed;	
}p[M];
bool cmp(node a, node b)
{
	return (a.st < b.st) || (a.st == b.st && a.ed < b.ed);
}
void update(int x)
{
	for(;x < N;x += L[x])
		C[x]++;
}
LL sum(int x)
{
	LL r = 0;
	for(;x > 0;x -= L[x])
		r += C[x];
	return r;
}
int main()
{
	for(int i = 0;i < N;i++)
		L[i] = i&(i^(i-1));
	int T, o = 1;
	scanf("%d", &T);
	while(T--)
	{
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		for(int i = 0;i < k;i++)
			scanf("%d%d", &p[i].st, &p[i].ed);
		sort(p, p+k, cmp);
		memset(C, 0, sizeof(C));
		LL ans = 0;
		for(int i = 0;i < k;i++)
		{
			ans += sum(m) - sum(p[i].ed);
			update(p[i].ed);
			// printf("%d\n", ans);
		}
		printf("Test case %d: %lld\n", o++, ans);
	}
	return 0;
}