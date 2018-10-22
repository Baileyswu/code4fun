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
		printf("Scenario #%d:\n%.2f\n", t, 2.0*(m+n)-4);
	}
}
