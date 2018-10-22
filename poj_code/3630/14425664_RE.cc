#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define N 100005
int size = 0, sum, v;
struct node
{
	int next[20], lage, cnt;
}tree[N];
int insert(char *str)
{
	char *p = str;
	int s = 0;
	while(*p)
	{
		if(tree[s].cnt)
			return 1;
		if(!tree[s].next[*p-'0'])
		{
			tree[s].lage++;
			tree[s].next[*p-'0'] = ++size;
		}
		s = tree[s].next[*p-'0'];
		p++;
	}
	tree[s].cnt++;
	return 0;
}
void read(int x)
{
	int ok = 0;
	for(int i = 0;i < 27;i++)
	{	
		int s = tree[x].next[i];
		if(s)
		{
			if(tree[s].cnt)
				printf("%c %.4f\n", i+'a', 1.0*tree[s].cnt/sum);
			else
			{
				printf("%c", i+'a');
				read(s);
			}
			if(++ok == tree[x].lage)
				break;
		}
	}
}
int main()
{
	//freopen("in", "r", stdin);
	int T, n;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		memset(tree, 0, sizeof(tree));
		char str[40];
		v = 0;
		while(n--)
		{
			scanf("%s", str);
			if(v)
				continue;
			v = insert(str);
		}
		if(v)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}