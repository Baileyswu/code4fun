#include <bits/stdc++.h>
using namespace std;
int a[1100], st[1100], f[1100], nt[1100], sz;
bool cmp(int x, int y) {
	return x > y;
}
void pr(int n) {
	for(int i = 0;i < n;i++)
		printf("%d%c", a[st[i]], " \n" [i == n-1]);
}
bool pack(int n, int m) {
	int sum = 0;
	sz = 0;
	for(int i = 0;i < n;i++) if(!f[i]) {
		if(sum + a[i] <= m) {
			sum += a[i];
			f[i] = 1;
			st[sz++] = i;
		} else if(i == n-1){
			if(sz == 0) return false;
			int p = st[sz-1];
			sum -= a[p];
			f[p] = 0;
			sz--;
			i = nt[p] - 1;
		}
		if(sum == m) return true;
	}
	return false;
}
bool solve(int n) {
	sort(a, a+n, cmp);
	memset(f, 0, sizeof(f));
	int sum = 0;
	for(int i = n-1;i >= 0;i--) {
		sum += a[i];
		if(i == n-1) nt[i] = i+1;
		else nt[i] = a[i] > a[i+1] ? i+1 : nt[i+1];
	}
	if(sum % 4) return false;
	int len = sum/4;
	for(int i = 0;i < 4;i++){
		if(!pack(n, len)) return false;
		//else pr(sz);
	}
	return true;
}
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		for(int i = 0;i < n;i++)
			scanf("%d", &a[i]);
		if(solve(n)) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
