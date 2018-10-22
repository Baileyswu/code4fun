#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 40010
int stk[N], top;
int find(int x){
	int l = 1, r = top-1, cnt = 64;
	while(l < r && cnt--){
		int mid = l+r >> 1;
		if(stk[mid] == x) return mid;
		if(stk[mid] < x) l = mid;
		else r = mid;
	}
	if(stk[r] >= x) return r;
	return l;
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--){
		int n;
		scanf("%d", &n);
		top = 0;
		stk[top++] = -1;
		for(int i = 0;i < n;i++){
			int t;
			scanf("%d", &t);

			if(t > stk[top-1])
				stk[top++] = t;
			else {
				int s = find(t);
				stk[s] = t;
			}
			// for(int j = 0;j < top;j++)
				// printf("%d%c", stk[j], " \n"[j==top-1]);
		}
		printf("%d\n", top-1);
	}
	return 0;
}