#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 50010
#define rt 1, 0, n-1
#define ls node<<1
#define rs node<<1|1
int a[N], _max[3*N], _min[3*N], x, y;
void build(int node, int l, int r)
{
	if(l == r)
	{
		_max[node] = _min[node] = a[l];
		return;
	}
	int mid = l+r >> 1;
	build(ls, l, mid);
	build(rs, mid+1, r);
	_min[node] = min(_min[ls], _min[rs]);
	_max[node] = max(_max[ls], _max[rs]);
	// printf("%d %d %d min %d max %d\n", node, l, r, _min[node], _max[node]);
}
void query(int node, int beg, int end, int l, int r)
{
	if(r < beg || end < l || l > r) return;
	if(l <= beg && end <= r)
	{
		x = min(x, _min[node]);
		y = max(y, _max[node]);
		// printf("%d %d %d %d %d %d %d\n", node, beg, end,l, r, x, y);
		return;
	}
	int mid = beg+end >> 1;
	query(ls, beg, mid, l, min(mid, r));
	query(rs, mid+1, end, max(mid+1, l), r);
}
int main()
{
	int n, m;
	while(~scanf("%d%d", &n, &m))
	{
		for(int i = 0;i < n;i++)
			scanf("%d", &a[i]);
		build(rt);
		while(m--)
		{
			int l, r;
			scanf("%d%d", &l, &r);
			l--; r--;
			x = y = a[l];
			query(rt, l, r);
			printf("%d\n", y-x);
		}
	}
	return 0;
}