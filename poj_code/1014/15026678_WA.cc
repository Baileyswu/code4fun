#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int dp[100100];
int a[7];
void zero(int m, int x)
{
	//printf("%d %d\n", m, x);
	for(int i = m;i >= x;i--)
		dp[i] |= dp[i-x];
}
bool solve(int m)
{
	for(int i = 1;i < 7;i++) if(a[i])
	{
		//printf("i == %d\n", i);
		int t = 1, sum = 1;
		while(sum <= a[i])
		{
			zero(m, t*i);
			t <<= 1;
			sum += t;
		}
		if(sum-a[i] < a[i])
			zero(m, (sum-a[i])*i);
		if(dp[m])
			return true;
	}
	return false;
}
int main()
{
	int o = 0;
	while(scanf("%d", &a[1]))
	{
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		int sum = a[1];
		for(int i = 2;i < 7;i++)
		{
			scanf("%d", &a[i]);
			sum += i*a[i];
		}
		//printf("sum %d\n", sum);
		if(!sum) break;
		if(sum%2==0 && solve(sum/2))
			printf("Collection #%d:\nCan be divided.\n\n", ++o);
		else
			printf("Collection #%d:\nCan't be divided.\n\n", ++o);
	}
	return 0;
}