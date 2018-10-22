#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define N 100005
int size = 0, sum = 0;
struct node
{
	char name[40];
	int next[53], lage, cnt;
}tree[N];
int find(char c)
{
	if(c >= 'A' && c <= 'Z')
		return c-'A';
	if(c >= 'a' && c <= 'z')
		return c-'c'+26;
	if(c == ' ')
		return 52;
}
int insert(char *str)
{
	char *p = str;
	int s = 0;
	while(*p)
	{
		if(!tree[s].next[find(*p)])
		{
			tree[s].lage++;
			tree[s].next[find(*p)] = ++size;
		}
		s = tree[s].next[find(*p)];
		p++;
	}
	tree[s].cnt++;
	strcpy(tree[s].name, str);
	//printf("%s\n", str);
	return 0;
}
void read(int x)
{
	int ok = 0;
	for(int i = 0;i < 53;i++)
	{	
		int s = tree[x].next[i];
		if(s)
		{
			//printf("tree[s]-----%d\n", s);
			if(tree[s].cnt)
				printf("%s %.4f\n", tree[s].name, 100.0*tree[s].cnt/sum);
			else
				read(s);
			if(++ok == tree[x].lage)
				break;
		}
	}
}
int main()
{
	//freopen("in", "r", stdin);
	memset(tree, 0, sizeof(tree));
	size = 0;
	char str[40];
	while(gets(str) != NULL)
	{
		sum++;
		insert(str);
	}
	read(0);
	return 0;
}