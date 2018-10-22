#include <iostream>  
#include <cstdio>  
#include <cstring>  
using namespace std;
#define N 1005
int phi[N] = {0, 1}, minDiv[N], ans[N] = {0, 0, 5};
void GetPhi()
{
	for (int i = 0; i < N; ++i)
		minDiv[i] = i;
	for (int i = 2; i*i < N; ++i)
	{
		if (minDiv[i] == i)
		{
			for (int j = i*i; j < N; j += i)
			{
				minDiv[j] = i;
			}
		}
	}
	for (int i = 2; i < N; ++i)
	{
		phi[i] = phi[i/minDiv[i]];
		if((i/minDiv[i]) % minDiv[i])
			phi[i] *= minDiv[i] - 1;
		else
			phi[i] *= minDiv[i];
	}
}
void set()
{
	GetPhi();
	for (int i = 3; i < N; ++i)
		ans[i] = ans[i-1] + 2*phi[i];
}
int main()
{
	set();
	int T, n, o = 0;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		printf("%d %d %d\n", ++o, n, ans[n]);
	}
	return 0;
}