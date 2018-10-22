#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct node
{
	char c;
	int n;
	int m;
}word[15];
int cmp(struct node x, struct node y)
{
	return x.c < y.c;
};
int cmp2(struct node x, struct node y)
{
	return x.n < y.n;
};
int main()
{
	char key[15];
	while(scanf("%s", key))
	{
		if(strcmp(key, "THEEND") == 0)
			break;
		char secret[105], sq[10][15];
		int i, j, klen = strlen(key);
		scanf("%s", secret);
		int slen = strlen(secret), line = slen/klen;
		for(i = 0;i < slen;i++)
			sq[i/line][i%line] = secret[i];
		for(i = 0;i < klen;i++)
		{
			word[i].c = key[i];
			word[i].n = i;
		}
		sort(word, word + klen, cmp);
		for(j = 0;j < klen;j++)
			word[j].m = j;
		sort(word, word + klen, cmp2);
		for(i = 0;i < line;i++)
			for(j = 0;j < klen;j++)
			{
				int s = word[j].m;
				printf("%c", sq[s][i]);
			}
		printf("\n");
	}
}