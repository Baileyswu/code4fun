#include <bits/stdc++.h>
using namespace std;
#define N 100010
#define M 20
int n, m, a[N], p[N], dp[N][M][2];
void init() {
	for(int i = 0;i < n;i++) {
		cin >> a[i];
		// cout << a[i] << " ";
	}
	cout << endl;
	p[0] = a[0];
	for(int i = 1;i < n;i++)
		p[i] = p[i-1] + a[i];
	for(int i = 0;i < n;i++)
		for(int k = 0;k < 2;k++)
			dp[i][0][k] = a[i];
	for(int j = 1;(1<<j) <= n;j++) 
		for(int i = 0;i + (1<<j) - 1 < n;i++) {
			dp[i][j][0] = max(dp[i][j-1][0], dp[i+(1<<j-1)][j-1][0]);
			dp[i][j][1] = min(dp[i][j-1][1], dp[i+(1<<j-1)][j-1][1]);
		}
}
int find(int l, int r, int type) {
	int k = log(1.0*(r-l+1)) / log(2);
	return type ? 
			min(dp[l][k][type], dp[r-(1<<k)+1][k][type]) :
			max(dp[l][k][type], dp[r-(1<<k)+1][k][type]) ;
}
int get_sum(int l, int r) {
	return l == 0 ? p[r] : p[r] - p[l-1];
}
int main() {
	while(cin >> n >> m) {
		init();
		double ans = 0;
		for(int i = 0;i <= n-m;i++) {
			int largest = find(i, i+m-1, 0);
			int smallest = find(i, i+m-1, 1);
			double sum = get_sum(i, i+m-1);
			ans = max(ans, (sum - largest - smallest)/(m-2));
			// printf("[%d, %d], %d %d %.6f %.6f\n", i, i+m-1, largest, smallest, sum, ans);
		}
		printf("%.6f\n", ans);
	}
	return 0;
}