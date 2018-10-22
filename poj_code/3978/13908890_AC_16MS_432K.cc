#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 10010
int num[N], m[N];
int set()
{
	memset(num, 1, sizeof(num));
	num[0] = num[1] = m[0] = m[1] = 0;
	for(int i = 2;i < N;i++)
		if(num[i])
			for(int j = 2*i;j < N;j += i)
				num[j] = 0;
	int p = 0;
	for(int i = 2;i < N;i++)
	{
		if(num[i])
			m[i] = ++p;
		else
			m[i] = p;
	}
}
int main()
{
	int a, b;
	set();
	while(scanf("%d%d", &a, &b), !(a==-1&&b==-1))
	{
		int ans = m[b] - m[a];
		if(num[a])
			ans++;
		printf("%d\n", ans);
	}
	return 0;
}
