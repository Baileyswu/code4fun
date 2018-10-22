#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
	int n, k, one[3]={0, 0}, m[3];
	scanf("%d%d", &n, &k);
	for(int i = 1;i <= k;i++)
	{
		scanf("%d%d", &m[0], &m[1]);
		m[2] = i;
		if(m[0] > one[0])
			one[0] = m[0], one[1] = m[1], one[2] = m[2];
	}
	for(int i = k+1;i <= n;i++)
	{
		scanf("%d%d", &m[0], &m[1]);
		m[2] = i;
		if(m[1] > one[1])
			one[1] = m[1], one[2] = m[2];
	}
	printf("%d\n", one[2]);
	return 0;
}
