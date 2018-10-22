#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 31270
long long sum[N] = {1, 1}, a[N] = {1, 1};
int f[N] = {1, 1};
int find(int n)
{
	int a = 1, b = N - 1, c;
	if(sum[a] == n)
		return a;
	if(sum[b] >= n && sum[b - 1] < n)
		return b;
	while(b - a > 0)
	{
		if(sum[a] >= n && sum[a - 1] < n)
			return a;
		if(sum[b] >= n && sum[b - 1] < n)
			return b;
		c = (a + b)/2;
		if(sum[c] >= n && sum[c - 1] < n)
			return c;
		if(n > sum[c])
			a = c;
		else if(n <= sum[c - 1])
			b = c;
	}
}
int order(int n)
{
	int a = 1, b = N - 1, c;
	if(f[a] == n)
		return a;
	if(f[b] >= n && f[b - 1] < n)
		return b;
	while(b - a > 0)
	{
		if(f[a] >= n && f[a - 1] < n)
			return a;
		if(f[b] >= n && f[b - 1] < n)
			return b;
		c = (a + b)/2;
		if(f[c] >= n && f[c - 1] < n)
			return c;
		if(n > f[c])
			a = c;
		else if(n <= f[c - 1])
			b = c;
	}
}
int main()
{
	int i;
	for(i = 2;i < N;i++)
	{	
		f[i] = f[i-1] + log(i)/log(10) + 1;
		sum[i] = sum[i - 1] + f[i];
	}
	int t, n, k;
	char num[10];
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		k = find(n);
		n -= sum[k - 1];
		k = order(n);
		n -= f[k - 1];
		sprintf(num, "%d", k);
		printf("%c\n", num[n - 1]);
	}
	return 0;
}
