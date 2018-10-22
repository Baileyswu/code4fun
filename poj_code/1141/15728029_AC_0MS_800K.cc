#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
string str;
#define N 101
int dp[N][N], n, v[N][N];
void pr(){
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			printf("%d%c", dp[i][j], " \n"[j==n-1]);
	printf("\n");
}
void draw(int x, int y){
	// printf("draw(%d,%d)v=%d\n", x,y, v[x][y]);
	if(x > y) return;
	if(x == y){
		if(str[x] == '(' || str[x] == ')') printf("()");
		else printf("[]");
		return;
	}
	if(v[x][y] == -1){
		printf("%c", str[x]);
		draw(x+1, y-1);
		printf("%c", str[y]);
		return;
	}
	draw(x, v[x][y]);
	draw(v[x][y]+1, y);
}
int main()
{
	while(getline(cin, str)){
		if(str == "") {
			cout << str << endl;
			continue;
		}
		memset(dp, 0, sizeof(dp));
		memset(v, 0, sizeof(v));
		n = str.length();
		for(int len = 1;len < n;len++){
			// printf("len = %d\n", len);
			for(int i = 0;i+len < n;i++){
				int j = i+len;
				if((str[i] == '(' && str[j] == ')') || (str[i] == '[' && str[j] == ']')){
					if(dp[i][j] < dp[i+1][j-1]+2){
						v[i][j] = -1;
						dp[i][j] = dp[i+1][j-1]+2;
					}
				}
				for(int k = i;k < j;k++){
					if(dp[i][j] <= dp[i][k]+dp[k+1][j]){
						dp[i][j] = dp[i][k]+dp[k+1][j];
						v[i][j] = k;
					}
				}
			}
		}
		draw(0, n-1);
		printf("\n");
		// printf("%d\n", dp[0][n-1]);
	}
	return 0;
}