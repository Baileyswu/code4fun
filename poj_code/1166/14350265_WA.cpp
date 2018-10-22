#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define MAXN 15
#define H 10000000
int a[MAXN][MAXN], n = 9, ans[MAXN];
int C[MAXN][MAXN] = {
	{1, 1, 0, 1, 0, 0, 0, 0, 0},
	{1, 1, 1, 0, 1, 0, 0, 0, 0},
	{0, 1, 1, 0, 0, 1, 0, 0, 0},
	{1, 0, 0, 1, 1, 0, 1, 0, 0},
	{1, 0, 1, 0, 1, 0, 1, 0, 1},
	{0, 0, 1, 0, 1, 1, 0, 0, 1},
	{0, 0, 0, 1, 0, 0, 1, 1, 0},
	{0, 0, 0, 0, 1, 0, 1, 1, 1},
	{0, 0, 0, 0, 0, 1, 0, 1, 1},
};
void pr()
{
	for(int i = 0;i < n;i++)
		for(int j = 0;j <= n;j++)
			printf("%d%c", a[i][j], " \n"[j==n]);
	printf("\n");
}
void input()
{
	memcpy(a, C, sizeof(a));
	int x;
	for(int i = 0;i < 9;i++)
	{
		scanf("%d", &x);
		a[i][n] = (4-x)%4;
	}
}
int gcd(int x, int y)
{
	if(x == 0)
		return y;
	if(y == 0)
		return x;
	return gcd(y, x%y);
}
int solve()
{
	//pr();
	int i, j, k;
	for(i = 0, j = 0;i < n, j < n;)
	{
		int id = i;
		for(k = i+1;k < n;k++)
			if(abs(a[k][j]) > abs(a[id][j]))
				id = k;
		if(id != k)
			for(k = j;k <= n;k++)
				swap(a[i][k], a[id][k]);
		if(a[i][j] == 0){j++; continue;}
		for(k = i+1;k < n;k++)
		{
			if(a[k][j] == 0) continue;
			int g = a[k][j] * a[i][j] / gcd(a[k][j], a[i][j]);
			int temp = g / a[i][j];
			g /= a[k][j];
			for(int p = j;p <= n;p++)
				a[k][p] = g * a[k][p] - temp * a[i][p];
		}
		i++, j++;
	}
	for(k = i;k < n;k++)
		if(a[k][n] != 0)
			return -1;
	if(i != n)
		return 0;
	memset(ans, 0, sizeof(ans));
	for(i = n-1;i >= 0;i--)
	{
		int t = a[i][n];
		for(int k = i+1;k < n;k++)
			t -= a[i][k] * ans[k];
		t = (t + 4*H) % 4;
		if((t-a[i][i])%4 == 0)
			ans[i] = 1;
		else if((t-2*a[i][i])%4 == 0)
			ans[i] = 2;
		else if((t-3*a[i][i])%4 == 0)
			ans[i] = 1;
		else
			ans[i] = 0;
	}
	//pr();
	return 1;
}
void topr()
{
	int v = 0;
	for(int i = 0;i < n;i++)
	{
		if(ans[i])
		{
			for(int j = 0;j < ans[i];j++)
			{
				if(v)
					printf(" ");
				printf("%d", i+1);
				v = 1;
			}
		}
	}
	printf("\n");
}
int main()
{
	input();
	int f = solve();
	if(f == -1)
		printf("Impossible\n");
	else if(f == 0)
		printf("Not unique\n");
	else
		topr();
	return 0;
}