#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, stick[80], flag[80], len, k;
int cmp(int x, int y)
{
	return x > y;
}
int ok()
{
	int kk = k, p = 0, l = len;
	while(p < n+1)
	{
		if(!flag[p] && l >= stick[p])
			l -= stick[p], flag[p] = 1;
		p++;
		if(!l)
			p = 0, kk--, l = len;
		if(!kk)
			return 1;
	}
	return 0;
}
int main()
{
	while(~scanf("%d", &n), n)
	{
		int sum = 0;
		for(int i = 0;i < n;i++)
		{
			scanf("%d", &stick[i]);
			sum += stick[i];
		}
		sort(stick, stick+n, cmp);
		for(k = n;k > 0;k--)
		{
			if(sum % k)
				continue;
			len = sum/k;
			if(len < stick[0])
				continue;
			memset(flag, 0, sizeof(flag));
			if(ok())
			{
				printf("%d\n", len);
				break;
			}
		}
	}
	return 0;
}