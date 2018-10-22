#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 101000
int a[N], b[N], c[N];
int main()
{
	int n;
	while(scanf("%d", &n), n){
		
		for(int i = 0;i < n;i++)
			scanf("%d", &a[i]);
		for(int i = 0;i < n;i++)
			if(i == 0) b[i] = a[i];
			else b[i] = b[i-1]<0 ? a[i] : b[i-1]+a[i];
		for(int i = n-1;i >= 0;i--)
			if(i == n-1) c[i] = a[i];
			else c[i] = c[i+1]<0? a[i] : c[i+1]+a[i];
		int ans = a[0]+a[1];
		for(int i = 1;i < n;i++)
			b[i] = max(b[i], b[i-1]);
		for(int i = n-2;i >= 0;i--)
			c[i] = max(c[i], c[i+1]);
		for(int i = 0;i < n-1;i++){
			// printf("%d %d %d %d\n", i, a[i], b[i], c[i]);
			ans = max(ans, b[i]+c[i+1]);
		}
		printf("%d\n", ans);
	}
	return 0;
}