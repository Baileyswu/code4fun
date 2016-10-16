void build(){
	for(int i = 0;i < n;i++){
        dp[i][0] = a[i];
	}
	for(int j = 1;(1<<j) <= n;j++){
		for(int i = 0;i + (1<<j) - 1 < n;i++){
			dp[i][j] = __gcd(dp[i][j-1], dp[i+(1<<j-1)][j-1]);
		}
	}
}
int ask(int l, int r){
    int k = log(1.0*(r-l+1))/log(2);
    return __gcd(dp[l][k], dp[r-(1<<k)+1][k]);
}
