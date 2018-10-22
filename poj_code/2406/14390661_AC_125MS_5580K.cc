#include <iostream>  
#include <cstdio>  
#include <cstring>  
using namespace std;
#define N 1000005
char s[N];
int pre[N], n;
void set()
{
	int j = -1;
	pre[0] = -1;
	for(int i = 1;i < n;i++)
	{
		if(s[pre[i-1]+1] == s[i])
			pre[i] = pre[i-1] + 1;
		else
			pre[i] = pre[pre[i]];
	}
	/*printf("%d\n", n);
	for(int i = 0;i < n;i++)
		printf("%c %c", s[i], " \n"[i==n-1]);
	for(int i = 0;i < n;i++)
		printf("%2d%c", i, " \n"[i==n-1]);
	for(int i = 0;i < n;i++)
		printf("%2d%c", pre[i], " \n"[i==n-1]);*/
}
int solve()
{
	memset(pre, 0, sizeof(pre));
	set();
	int j = pre[n-1], k = n-1;
	int po = n-1-j;
	while(j != -1)
	{
		int r = k - j;
		if(r != po)
			return 1;
		k = j;
		j = pre[j];
	}
	if(k - j != po)
		return 1;
	return n/po;
}
int main()
{
	//freopen("in", "r", stdin);
	while(~scanf("%s", s))
	{
		if(s[0] == '.')
			break;
		n = strlen(s);
		printf("%d\n", solve());
	}
	return 0;
}