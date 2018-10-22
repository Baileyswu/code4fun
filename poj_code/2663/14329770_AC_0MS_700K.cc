#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

int bas[31] = {0, 0, 3};
int ans[31] = {1, 0, 3};
int set()
{
	for(int i = 4;i < 31;i += 2)
	{
		bas[i] = 2;
		ans[i] = 0;
	}
	for(int i = 4;i < 31;i += 2)
	{
		for(int j = 2;j <= i;j += 2)
			ans[i] += bas[j] * ans[i-j];
	}
}
int main()
{
	int n;
	set();
	while(scanf("%d", &n))
	{
		if(n==-1)
			break;
		if(n & 1LL)
			printf("0\n");
		else
			printf("%d\n", ans[n]);
	}
	return 0;
}