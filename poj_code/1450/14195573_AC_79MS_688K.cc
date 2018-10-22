#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
	int t, n, m;
	scanf("%d", &t);
	for(int i = 1;i <= t;i++)
	{
		scanf("%d%d", &n, &m);
		if(n*m % 2)
			printf("Scenario #%d:\n%.2f\n\n", i, 1.0*m*n+0.41);
		else
			printf("Scenario #%d:\n%.2f\n\n", i, 1.0*m*n);
	}
}
