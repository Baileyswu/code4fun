#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#define N 1000005
char res[N][20] = {"eh"};
int size = 0;
struct node{
	char ch;
	int son, next, word;
	void pr(){
		printf("ch %c son %d next %d word %d\n", ch, son, next, word);
	}
}a[N];
void insert(char *s, int l, int t, int x, int w)
{
	if(t == l)
	{
		a[x].word = w;
		return;
	}
	if(a[x].son == 0)
	{
		size++;
		a[x].son = size;
		a[size].ch = s[t];
		insert(s, l, t+1, size, w);
		return;
	}
	int i = a[x].son;
	while(a[i].ch != s[t] && a[i].next != 0)
		i = a[i].next;
	//printf("%d %d\n", x, i);
	if(a[i].ch != s[t])
	{
		size++;
		//printf("size %d\n", size);
		a[i].next = size;
		a[size].ch = s[t];
		i = size;
	}
	insert(s, l, t+1, i, w);
	return;
}
int find(char *s, int l, int t, int x)
{
	if(l == t)
		return a[x].word;
	int i = a[x].son;
	while(a[i].ch != s[t] && a[i].next != 0)
		i = a[i].next;
	if(a[i].ch != s[t])
		return 0;
	return find(s, l, t+1, i);
}
int main()
{
	//freopen("in", "r", stdin);
	char s[20], str[20];
	int all_word = 0;
	memset(a, 0, sizeof(a));
	while(1)
	{
		scanf("%s%s", str, s);
		getchar();
		strcpy(res[++all_word], str);
		int len = strlen(s);
		insert(s, len, 0, 0, all_word);
		char c = getchar();
		if(c == '\n')
			break;
		else
			ungetc(c, stdin);
	}
	/*for(int i = 0;i <= size;i++)
	{
		printf("a %d ", i);
		a[i].pr();
	}*/
	while(~scanf("%s", str))
	{
		//printf("%s\n", str);
		int len = strlen(str);
		int r = find(str, len, 0, 0);
		printf("%s\n", res[r]);
	}
	return 0;
}