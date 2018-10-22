#include <iostream>  
#include <cstdio>  
#include <cstring>  
using namespace std;
#define M 10005
char p[M];
int pre[M], n, m;
void set()
{
	int j = -1;
	pre[0] = -1;
	for(int i = 1;i < m;i++)
	{
		if(p[pre[i-1]+1] == p[i])
			pre[i] = pre[i-1] + 1;
		else
			pre[i] = pre[pre[i]];
	}
	/*for(int i = 0;i < m;i++)
		printf("%d%c", pre[i], " \n"[i==m-1]);*/
}
int solve()
{
	memset(pre, 0, sizeof(pre));
	set();
	getchar();
	char c;
	int j = -1, r = 0;
	while((c = getchar()) != '\n')
	{
		//printf("this %c\n", c);
		while(j >= 0 && c != p[j+1])
			j = pre[j];
		if(c == p[j+1])
			j++;
		if(j == m-1)
		{
			r++;
			j = pre[j];
		}
		//printf("j  %d\n", j);
	}
	return r;
}
int main()
{
	//freopen("in", "r", stdin);
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%s", p);
		m = strlen(p);
		printf("%d\n", solve());
	}
	return 0;
}