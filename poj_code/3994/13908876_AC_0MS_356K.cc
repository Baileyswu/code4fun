#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int n, p = 0;
	while(scanf("%d", &n), n)
	{
		if(n&1LL)
			printf("%d. odd %d\n", ++p, (n-1)/2);
		else
			printf("%d. even %d\n", ++p, n/2);
	}
	return 0;
}
