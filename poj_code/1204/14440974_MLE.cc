#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int size, so;
struct node
{
	char ch;
	int next[26], fa, end, pre, have;
	void pr(){
		printf("%c %d %d %d\n", ch, fa, pre, end);
	}
}tree[1000005];
char mp[1005][1005], str[1001][1420], dir[1005];
short ans[1001][2], len[1001];
short dp[8][2] = {1,0,1,-1,0,-1,-1,-1,-1,0,-1,1,0,1,1,1};
int L, C, W;
void insert(char *key, int &x)
{
	char *p = key;
	int s = 0;
	while(*p)
	{
		if(!tree[s].next[*p-'A'])
			tree[s].next[*p-'A'] = ++size;
		int t = s;
		s = tree[s].next[*p-'A'];
		tree[s].fa = t;
		tree[s].ch = *p;
		p++;
	}
	if(tree[s].end)
	{
		x--;
		W--;
	}
	else
	tree[s].end = x;//repeated key words can be calculated more than once
}
int find(int x, char d)
{
	return tree[x].next[d-'A'];
}
void KMP(char *key)
{
	char *p = key;
	int s = find(0, *p);
	tree[s].pre = 0;
	p++;
	while(*p)
	{
		int i = s;
		s = find(s, *p);
		//printf("%d %c\n", s, *p);
		int j = tree[i].pre;
		while(j > 0 && !find(j, *p))
			j = tree[j].pre;
		tree[s].pre = find(j, *p);
		p++;
	}
}
void build()
{
	memset(tree, 0, sizeof(tree));
	size = 0;
	scanf("%d%d%d", &L, &C, &W);
	for (int i = 0; i < L; ++i)
		scanf("%s", mp[i]);
	for (int i = 1; i <= W; ++i)
	{
		scanf("%s", str[i]);
		len[i] = strlen(str[i]);
		insert(str[i], i);
	}
	tree[0].pre = 0;
	for(int i = 1;i <= W ;i++)
		KMP(str[i]);
	/*for(int i = 0;i <= size;i++)
	{
		printf("tree[%d]  ", i);
		tree[i].pr();
	}*/
}
int sig(int x, int d, int i, int j)//visit x, x.pre, x.pre.pre, ....
{
	//printf("sig tree[%d]  have %d  pre %d  end %d\n", 
		//x, tree[x].have, tree[x].pre, tree[x].end);
	if(!x)
		return 0;
	if(tree[x].have)
		return 0;
	tree[x].have = 1;
	if(tree[x].end)
	{
		int p = tree[x].end;
		ans[p][0] = i+dp[d][0]*(len[p]-1);
		ans[p][1] = j+dp[d][1]*(len[p]-1);
		dir[p] = d+'A';
	}
	return sig(tree[x].pre, d, i, j);
}
void ac(char c, int d, int i, int j)
{
	//printf("this  %c  ", c);
	while(so > 0 && !tree[so].next[c-'A'])
	{
		so = tree[so].pre;
		sig(so, d, i, j);
	}
	if(tree[so].next[c-'A'])
	{
		sig(so, d, i, j);
		so = tree[so].next[c-'A'];
	}
	sig(so, d, i, j);
	//printf("so  %d   ans %d\n", so, ans);
}
void clear()
{
	for(int i = 0;i <= size;i++)
		tree[i].have = 0;
	so = 0;
}
void solve()
{
	clear();
	for(int j = 0;j < C;j++)
	{
		for(int i = L-1;i >= 0;i--)
			ac(mp[i][j], 0, i, j);
		for(int i = 0;i < L;i++)
			ac(mp[i][j], 4, i, j);
	}
	for(int i = 0;i < L;i++)
	{
		for(int j = 0;j < C;j++)
			ac(mp[i][j], 2, i, j);
		for(int j = C-1;j >= 0;j--)
			ac(mp[i][j], 6, i, j);
	}
	for(int k = 0;k <= L+C-2;k++)
	{
		int p = min(k, L-1), q = max(0, k-C+1);
		for(int i = p;i >= q;i--)
			ac(mp[i][k-i], 1, i, k-i);
		for(int i = q;i <= p;i++)
			ac(mp[i][k-i], 5, i, k-i);
	}
	for(int k = C-1;k >= 1-L;k--)
	{
		int p = max(0, -k), q = min(L-1, C-1-k);
		for(int i = p;i <= q;i++)
			ac(mp[i][k+i], 3, i, k+i);
		for(int i = q;i >= p;i--)
			ac(mp[i][k+i], 7, i, k+i);
	}
}
void output()
{
	for(int i = 1;i <= W;i++)
		printf("%d %d %c\n", ans[i][0], ans[i][1], dir[i]);
}
int main()
{
	//freopen("in","r",stdin);
	//freopen("aout","w",stdout);

	build();
	solve();
	output();
	return 0;
}