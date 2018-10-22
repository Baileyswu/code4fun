#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
string str;
int a[110][110], n;
void update(int x, int y){
	// printf("up %d %d %d\n", x, y, a[x][y]);
	for(int i = 0;i <= x;i++)
		for(int j = y;j < n;j++){
			if(i == x && j == y) continue;
			if(j == y) a[i][j] = max(a[i][j], a[i][x-1] + a[x][y]);
			else if(i == x ) a[i][j] = max(a[i][j], a[x][y]+a[y+1][j]);
			else a[i][j] = max(a[i][j], a[i][x-1]+a[x][y]+a[y+1][j]);
		}
	// for(int i = 0;i < n;i++)
	// 	for(int j = i+1;j < n;j++)
	// 		printf("%d %d %d\n", i, j, a[i][j]);
}
int main()
{
	while(cin >> str){
		if(str == "end") break;
		memset(a, 0, sizeof(a));
		n = str.length();
		for(int i = 0;i < n;i++) 
			for(int j = 0;j < i;j++){
				if((str[i] == ')' && str[j] == '(')||
					(str[i] == ']' && str[j] == '[')){
					// printf("%d-%d  %c %c", j, i, str[j], str[i]);
					if(j+1 == i) a[j][i] = 1;
					else a[j][i] = max(a[j][i], a[j+1][i-1]+1);
					update(j, i);
				}
			}
		printf("%d\n", a[0][n-1]*2);
	}
	return 0;
}