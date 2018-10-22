#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
string a, b;
#define N 10100
int dp[N][N];
int main()
{
	while(cin >> a >> b){
		memset(dp, 0, sizeof(dp));
		for(int i = 0;i < a.length();i++)
			for(int j = 0;j < b.length();j++)
				if(a[i] == b[j])
					dp[i+1][j+1] = dp[i][j]+1;
				else
					dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
		printf("%d\n", dp[a.length()][b.length()]);
	}
	return 0;
}