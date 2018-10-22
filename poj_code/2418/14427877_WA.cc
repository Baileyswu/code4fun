#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#define N 300005
int size = 0, sum = 0;
struct node{
	char ch, word[40];
	int son, next, end;
	void pr(){
		printf("ch %c son %d next %d word %s\n", ch, son, next, word);
	}
}a[N];
void insert(char *s, int l, int t, int x)
{
	if(t == l)
	{
		strcpy(a[x].word, s);
		a[x].end++;
		return;
	}
	if(a[x].son == 0)
	{
		size++;
		a[x].son = size;
		a[size].ch = s[t];
		insert(s, l, t+1, size);
		return;
	}
	int i = a[x].son;
	if(a[i].ch > s[t])
	{
		size++;
		a[x].son = size;
		a[size].next = i;
		a[size].ch = s[t];
		insert(s, l, t+1, size);
		return;
	}
	int j = i;
	while(a[i].ch < s[t] && a[i].next != 0)
	{
		j = i;
		i = a[i].next;
	}
	if(a[i].ch < s[t])
	{
		size++;
		a[i].next = size;
		a[size].ch = s[t];
		i = size;
	}
	else if(a[i].ch > s[t])
	{
		size++;
		a[j].next = size;
		a[size].next = i;
		a[size].ch = s[t];
		i = size;
	}
	insert(s, l, t+1, i);
	return;
}
void read(int x)
{
	if(a[x].end)
		printf("%s %.4lf\n", a[x].word, 100.0*a[x].end/sum);
	if(a[x].son)
		read(a[x].son);
	if(a[x].next)
		read(a[x].next);
}
int main()
{
	memset(a, 0, sizeof(a));
	size = 0;
	char str[40];
	while(gets(str) != NULL)
	{
		sum++;
		int len = strlen(str);
		insert(str, len, 0, 0);
	}
	read(0);
	return 0;
}