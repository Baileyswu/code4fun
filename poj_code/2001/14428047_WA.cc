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
		{
			tree[s].next[*p-'a'] = ++size;
		}
		tree[s].lage++;
		s = tree[s].next[*p-'a'];
		p++;
	}
	if(!tree[s].cnt)
		tree[s].cnt++;
	return 0;
}
void read(char *key)
{
	char *p = key;
	int s = 0;
	while(*p)
	{
		s = tree[s].next[*p-'a'];
		printf("%c", *p);
		if(tree[s].lage == 1)
		{
			printf("\n");
			return;
		}
		p++;
	}
	printf("\n");
}
int main()
{
	//freopen("in", "r", stdin);
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