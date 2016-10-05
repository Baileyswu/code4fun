/**************************************************

            模版：二维树状数组
            题目：HDU5892 Resident Evil 

**************************************************/


#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define lowbit(x) ((x)&-(x))
using namespace std;
typedef long long lint;
const int maxn=3000+10, N=50;

int n, m;
lint p[2][2][maxn][maxn];

void Update(int x, int y, lint val)
{
	for(int i=x; i<=n; i+=lowbit(i))
		for(int j=y; j<=n; j+=lowbit(j))
			p[x&1][y&1][i][j]^=val;
	return ;
}

lint Query(int x, int y, lint ans=0ll)
{
	for(int i=x; i; i-=lowbit(i))
		for(int j=y; j; j-=lowbit(j))
			ans^=p[x&1][y&1][i][j];
	return ans;
}

int main()
{
	char opt[2];
	while(scanf("%d%d", &n, &m)!=EOF)
	{
		int x1, x2, y1, y2, k, cnt, x, y;
		memset(p, 0, sizeof p);
		while(m--)
		{
			scanf("%s%d%d%d%d", opt, &x1, &y1, &x2, &y2);
			if(opt[0]=='P')
			{
				++x2, ++y2;
				lint tmp=0ll;
				scanf("%d", &k);
				while(k--)
				{
					scanf("%d%d", &x, &y);
					if(y&1)	tmp^=(1ll<<(x-1));
				}
				Update(x1, y1, tmp);
				Update(x2, y2, tmp);
				Update(x1, y2, tmp);
				Update(x2, y1, tmp);
			}
			else
			{
				--x1, --y1;
				lint tmp=Query(x1, y1)^Query(x2, y2)^Query(x1, y2)^Query(x2, y1);
				for(int i=0; i<N; i++)	printf("%c ", "12"[(tmp>>i)&1]);
				printf("\n");
			}
		}
	}
	return 0;
}
