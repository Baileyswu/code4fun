#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 100100
double a[N];
int an;
int find(double x){
	int l = 1, r = an-1, cnt = 0;
	while(l < r && cnt++ < 64){
		// printf("l=%d r=%d\n", l, r);
		int mid = l+r >> 1;
		if(a[mid] > x) r = mid;
		else if(fabs(a[mid]-x) < 1e-8) return mid;
		else l = mid;
	}
	if(a[l] > x) return l;
	return r;
}
void pr(){
	for(int i = 0;i < an;i++)
		printf("%d%c", a[i], " \n"[i==an-1]);
}
int main()
{
	int n;
	while(~scanf("%d", &n)){
		a[0] = -1;
		an = 1;
		for(int i = 1;i <= n;i++){
			double t;
			scanf("%lf", &t);
			if(t > a[an-1]) {
				a[an++] = t;
			} else{
				int p = find(t);
				// printf("p = %d  \n", p);
				swap(a[p], t);
			}
			// pr();
		}
		printf("%d\n", an-1);
	}
	return 0;
}