#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
#define N 15
#define M 25
char str[N][M];
int pre[N][M], len[N], K[N][N], n;
void set(int w)
{
	len[w] = strlen(str[w]);
	pre[w][0] = -1;
	for(int i = 1;i < len[w];i++)
	{
		int j = pre[w][i-1];
		while(j >= 0 && str[w][j+1] != str[w][i])
			j = pre[w][j];
		pre[w][i] = str[w][j+1] == str[w][i] ? j+1:-1;
	}
	//for(int i = 0;i < len[w];i++)
	//	printf("%2d%c", pre[w][i], " \n"[i==len[w]-1]);
}
int KMP(int x, int y)
{
	int i, j = -1;
	for(i = 0;i < len[x];i++)
	{
		while(j >= 0 && str [x][i] != str[y][j+1])
			j = pre[x][j];
		if(str[x][i] == str[y][j+1])
			j++;
		if(j == len[y]-1)
			return i-j;
	}
	return i-j-1;
}
int main()
{
	//freopen("in", "r", stdin);
	int T;
	scanf("%d", &T);
	while(T--)
	{
		memset(pre, 0, sizeof(pre));
		scanf("%d", &n);
		for(int i = 0;i < n;i++)
		{
			scanf("%s", &str[i]);
			set(i);
		}
		for(int i = 0;i < n;i++)
		{
			for(int j = 0;j < n;j++)
			{
				K[i][j] = KMP(i, j);
				//printf("%2d%c", K[i][j], " \n"[j==n-1]);
			}
		}
		int myints[20];
		for(int i = 0;i < 20;i++)
			myints[i] = i;
		sort (myints,myints+n);
		int ans = 1000000000;
		do
		{
			int your[20];
			memcpy(your, myints, sizeof(your));
			int temp = 0, max_ = len[your[0]];
			for(int i = 1;i < n;i++)
			{
				int p = your[i-1], q = your[i];
				temp += K[p][q];
				max_ = max(temp+len[q], max_);
				if(K[p][q] + len[q] <= len[p])
					swap(your[i-1], your[i]);
				if(max_ > ans)
					break;
			}
			ans = min(ans, max_);
			/*f(ans == max_)
			{
				printf("temp %d ans %d max_ %d\n", temp, ans, max_);
				for(int i = 0;i < n;i++)
					printf("%d%c", your[i], " \n"[i==n-1]);
			}*/
		} while ( next_permutation(myints,myints+n) );
		printf("%d\n", ans);
	}
	return 0;
}
