#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
int a[100];
int main()
{
	int T;
	scanf("%d", &T);
	while(T--){
		int n;
		scanf("%d", &n);
		int an = 0;
		int m = n;
		while(n){
			a[an++] = n%2;
			n /= 2;
		}
		int p = 0;
		for(int i = 0;i < an;i++)
			if(a[i]){
				p = i;
				break;
			}
		a[p] = a[0] = 1;
		int r = 1;
		while(p){
			r <<= 1;
			p--;
		}
		r--;
		printf("%d %d\n", m-r, m+r);
	}
	return 0;
}