#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int num[60];
int cmp(int x, int y)
{
	return x < y;
}
int gcd(int x, int y)
{
	if(x==0)
		return y;
	if(y==0)
		return x;
	return gcd(y, x%y);
}
int main()
{
	int n;
	while(scanf("%d", &n), n)
	{
		int ans = 0;
		for(int i = 0;i < n;i++)
			scanf("%d", &num[i]);
		sort(num, num+n, cmp);
		for(int i = 0;i < n;i++)
			for(int j = i+1;j < n;j++)
				if(gcd(num[i], num[j])==1)
					ans++;
		if(!ans)
		{
			printf("No estimate for this data set.\n");
			continue;
		}
		double k = sqrt(3*(n-1)*n/ans);
		printf("%.6f\n", k);
	}
	return 0;
}