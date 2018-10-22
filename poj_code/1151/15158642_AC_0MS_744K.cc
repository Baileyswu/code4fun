#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 105
#define eps 1e-8
int n;
double a[N*2], ans, len;
int cover[N*8], has[N*8], all;
struct node
{
	double x1, y1, x2, y2;
	int flag;
}s[N*2];
void build(int rt, int l, int r)
{
	all++;
	cover[rt] = has[rt] = 0;
	if(r != l)
	{
		int mid = l+r >> 1;
		build(rt<<1, l, mid);
		build(rt<<1|1, mid+1, r);
	}
}
int get(double x)
{
	for(int i = 0;i < 2*n;i++)
		if(fabs(x-a[i]) < eps)
			return i;
}
void update(int rt, int beg, int end, int l, int r, int flag)
{
	if(l > r || end < l || r < beg) return;
	if(l <= beg && end <= r)
	{
		cover[rt] += flag;
		if(beg == end)
			has[rt] = cover[rt] ? 1 : 0;
		else
			has[rt] = cover[rt]||has[rt<<1]||has[rt<<1|1] ? 1 : 0;
		return;
	}
	int mid = beg + end >> 1;
	update(rt<<1, beg, mid, l, min(r, mid), flag);
	update(rt<<1|1, mid+1, end, max(mid+1, l), r, flag);
	has[rt] = cover[rt]||has[rt<<1]||has[rt<<1|1] ? 1 : 0;
}
double query(int rt, int l, int r)
{
	if(!has[rt])
		return 0;
	if(cover[rt])
		return a[r+1]-a[l];
	int mid = l+r >> 1;
	return query(rt<<1, l, mid) + 
	query(rt<<1|1, mid+1, r);
}
bool cmp(node p, node q)
{
	return p.y1 < q.y1;
}
void pr()
{
	for(int i = 1;i <= all;i++)
		printf("%d ", i);
	printf("\n");
	for(int i = 1;i <= all;i++)
		printf("%d ", cover[i]);
	printf("\n");
	for(int i = 1;i <= all;i++)
		printf("%d ", has[i]);
	printf("\n");
}
int main()
{
	int o = 0;
	while(scanf("%d", &n), n)
	{
		ans = 0;
		for(int i = 0;i < n;i++)
		{
			int d = 2*i;
			scanf("%lf%lf", &s[d].x1, &s[d].y1);
			scanf("%lf%lf", &s[d+1].x2, &s[d+1].y2);
			s[d].x2 = s[d+1].x2;
			s[d].y2 = s[d].y1;
			s[d+1].x1 = s[d].x1;
			s[d+1].y1 = s[d+1].y2;
			a[d] = s[d].x1;
			a[d+1] = s[d].x2;
			s[d].flag = 1;
			s[d+1].flag = -1;
		}
		all = 0;
		sort(a, a+2*n);
		sort(s, s+2*n, cmp);
		build(1, 0, 2*n-2);
		for(int i = 0;i < 2*n-1;i++)
		{
			int l = get(s[i].x1), r = get(s[i].x2)-1;
			//printf("l= %d r=%d\n", l, r);
			update(1, 0, 2*n-2, l, r, s[i].flag);
			len = query(1, 0, 2*n-2);
			ans += len*(s[i+1].y1-s[i].y1);
			//pr();
		}
		printf("Test case #%d\nTotal explored area: %.2f\n\n", ++o, ans);
	}
	return 0;
}