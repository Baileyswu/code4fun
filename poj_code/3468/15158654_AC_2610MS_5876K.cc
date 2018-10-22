#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 100001
#define LL long long

LL a[N], tree[3*N], inc[3*N];
void add(int node, int beg, int end, int l, int r, LL d)
{
	if(r < beg || l > end || l > r) return;
	if(l <= beg && end <= r)
	{
		inc[node] += d;
		// printf("inc %d %d %d %I64d\n", node, beg, end, inc[node]);
		return;
	}
	tree[node] += (r-l+1)*d;
	// printf("add node, beg, end, l, r, d, %d %d %d %d %d %I64d tree[node]=%I64d, inc = %I64d\n", node, beg, end, l, r, d, tree[node], inc[node]);
	int mid = (beg+end) >> 1;
	add(node*2, beg, mid, l, min(r, mid), d);
	add(node*2+1, mid+1, end, max(mid+1, l), r, d);
}
void build(int node, int l, int r)
{
	if(l == r)
		tree[node] = a[l];
	else{
		int mid = (l + r) >> 1;
		build(node*2, l, mid);
		build(node*2+1, mid+1, r);
		tree[node] = tree[node*2] + tree[node*2+1];
	}
	// printf("build %d %d %d %I64d\n", node, l, r, tree[node]);
}

LL query(int node, int beg, int end, int l, int r)
{
	if(r < beg || l > end || l > r) return 0;
	// printf("q %d %d %d %d %d\n", node, beg, end, l, r);
	if(l <= beg && end <= r)
		return tree[node] + (end-beg+1)*inc[node];
	int mid = (beg+end) >> 1;
	tree[node] += inc[node]*(end-beg+1);
	if(inc[node])
	{
		add(node*2, beg, mid, beg, mid, inc[node]);
		add(node*2+1, mid+1, end, mid+1, end, inc[node]);
		inc[node] = 0;
	}
	return query(node*2, beg, mid, l, min(mid, r))
		+ query(node*2+1, mid+1, end, max(mid+1,l), r);
}

int main()
{
	int n, m;
	while(~scanf("%d%d", &n, &m))
	{
		for(int i = 0;i < n;i++)
			scanf("%I64d", &a[i]);
		memset(inc, 0, sizeof(inc));
		build(1, 0, n-1);
		// printf("\n");
		char str[10];
		while(m--)
		{
			int l, r, d;
			scanf("%s%d%d", str, &l, &r);
			if(str[0] == 'Q')
			{
				LL ans = query(1, 0, n-1, l-1, r-1);
				printf("%I64d\n", ans);
			}
			else
			{
				scanf("%d", &d);
				add(1, 0, n-1, l-1, r-1, d);
			}
			// printf("\n");
		}		
	}
	return 0;
}