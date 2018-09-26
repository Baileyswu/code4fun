/**************************************************

            模版：莫队分块
            题目：LYDSY 2038 小Z的袜子(hose)

**************************************************/


#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long lint;
const int maxn=50000+10, INF=0x7f7f7f7f;

int n, m, unit, col[maxn], c[maxn];
struct node
{
	int l, r, id;
	lint ans;
	bool operator <(const node&t)const
	{
		int al=l/unit, bl=t.l/unit;
		return al==bl ? r<t.r : al<bl;
	}
}p[maxn];

bool Cmp(node a, node b)
{
	return a.id<b.id;
}

lint Gcd(lint a, lint b)
{
	return b==0ll ? a : Gcd(b, a%b);
}

void Read()
{
	for(int i=1; i<=n; i++)	scanf("%d", &col[i]);
	for(int i=1; i<=m; i++)
	{
		scanf("%d%d", &p[i].l, &p[i].r);
		p[i].id=i;
	}
	unit=(int)sqrt(n);
	sort(p+1, p+1+m);
	return ;
}

void Work()
{
	lint tmp=0;
	memset(c, 0, sizeof c);

	int l=1, r=0;
	for(int i=1; i<=m; i++)
	{
		while(r<p[i].r)
		{
			r++;
			tmp+=2ll*(c[col[r]]++);
		}
		while(r>p[i].r)
		{
			tmp-=2ll*(--c[col[r]]);
			r--;
		}
		while(l<p[i].l)
		{
			tmp-=2ll*(--c[col[l]]);
			l++;
		}
		while(l>p[i].l)
		{
			l--;
			tmp+=2ll*(c[col[l]]++);
		}
		p[i].ans=tmp;
	}

	sort(p+1, p+1+m, Cmp);
	for(int i=1; i<=m; i++)
	{
		if(p[i].ans==0ll || p[i].l==p[i].r)    	printf("0/1\n");
		else
		{
			lint len=(p[i].r-p[i].l+1ll)*(p[i].r-p[i].l);
			lint tmp=Gcd(p[i].ans, len);
			printf("%lld/%lld\n", p[i].ans/tmp, len/tmp);
		}
	}
	return ;
}

int main()
{
	while(scanf("%d%d", &n, &m)!=EOF)	Read(), Work();
	return 0;
}
