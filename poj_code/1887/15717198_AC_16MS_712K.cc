#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 100100
int a[N], an;
int find(int x){
	int l = 1, r = an-1, cnt = 0;
	while(l < r && cnt++ < 32){
		// printf("l=%d r=%d\n", l, r);
		int mid = l+r >> 1;
		if(a[mid] > x) l = mid;
		else if(a[mid] == x) return mid;
		else r = mid;
	}
	if(a[r] < x) return r;
	return l;
}
void pr(){
	for(int i = 0;i < an;i++)
		printf("%d%c", a[i], " \n"[i==an-1]);
}
int main()
{
	int n, o = 0;
	a[0] = 10000000;
	an = 1;
	int t, cnt = 0;
	while(~scanf("%d", &t)){
		if(t == -1){
			if(cnt == 0) break;
			if(o) printf("\n");
			printf("Test #%d:\n  maximum possible interceptions: %d\n", ++o, an-1);
			a[0] = 10000000;
			an = 1;
			cnt = 0;
			continue;
		}
		cnt++;
		// printf("t = %d\n", t);
		if(t < a[an-1]) {
			a[an++] = t;
		} else{
			int p = find(t);
			// printf("p = %d  \n", p);
			swap(a[p], t);
		}
		// pr();
	}
	return 0;
}