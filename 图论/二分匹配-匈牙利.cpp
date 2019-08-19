int line[N][N];
// x find its friend
bool find(int x){
	for(int i = 1;i <= n;i++){
		if(line[x][i] && !use[i]){
			use[i] = 1;
			if(res[i] == 0 || find(res[i])){
				res[i] = x;
				return true;
			}
		}
	}
	return false;
}

void solve(){
	int ans = 0;
	for(int i = 1;i <= n;i++){
		memset(use, 0, sizeof(use));
		if(find(i))
			ans++;
	}
	printf("%d\n", ans);
}