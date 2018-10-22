#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 31270
long long sum[N] = {0, 1}, a[N] = {0, 1};
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
	if(sum[a] - sum[a - 1] == n)
		return a;
	if(sum[b] - sum[b - 1] >= n && sum[b - 1] - sum[b - 2] < n)
		return b;
	while(b - a > 0)
	{
		if(sum[a] - sum[a - 1] >= n && sum[a - 1] - sum[a - 2] < n)
			return a;
		if(sum[b] - sum[b - 1] >= n && sum[b - 1] - sum[b - 2] < n)
			return b;
		c = (a + b)/2;
		if(sum[c] - sum[c - 1] >= n && sum[c - 1] - sum[c - 2] < n)
			return c;
		if(n > sum[c] - sum[c - 1])
			a = c;
		else if(n <= sum[c - 1] - sum[c - 2])
			b = c;
	}
}
//f(x) = sum(x) - sum(x - 1);
int main()
{
	int i, head = 1;
	for(i = 2;i < N;i++)
	{	
		head += log(i)/log(10) + 1;
		sum[i] = sum[i - 1] + head;
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
		n -= sum[k - 1] - sum[k - 2];
		if(k == 1)
		{
			printf("1\n");
			continue;
		}
		sprintf(num, "%d", k);
		printf("%c\n", num[n - 1]);
	}
	return 0;
}
