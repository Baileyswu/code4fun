#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define N 25000
int size = 0, sum = 0;
char str[1005][25];
struct node
{
	int next[26], lage, cnt;
}tree[N];

int insert(char *key)
{
	char *p = key;
	int s = 0;
	while(*p)
	{
		if(!tree[s].next[*p-'a'])
			tree[s].next[*p-'a'] = ++size;
		s = tree[s].next[*p-'a'];
		tree[s].lage++;
		p++;
	}
	return 0;
}
void read(char *key)
{
	char *p = key;
	int s = 0;
	while(*p)
	{
		if(tree[s].lage == 1)
			break;
		printf("%c", *p);
		s = tree[s].next[*p-'a'];
		p++;
	}
	printf("\n");
}
int main()
{
	//freopen("in", "r", stdin);
	//freopen("outa", "w", stdout);
	memset(tree, 0, sizeof(tree));
	size = 0;
	while(~scanf("%s", str[sum]))
	{
		insert(str[sum]);
		sum++;
	}
	for(int i = 0;i < sum;i++)
	{
		printf("%s ", str[i]);
		read(str[i]);
	}
	return 0;
}
