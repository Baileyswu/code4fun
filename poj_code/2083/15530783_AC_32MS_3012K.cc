#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 7
char str[N][800*800] = {"X\0"};
char ans[N][800][800];
int a[N] = {1}, f[N] = {1};
string tmp, blank;
string gao(string as, string bs, string cs, int d){
	string r = "";
	// printf("gao d = %d\n", d);
	// cout << as << "||" << bs << "||" << cs << endl;
	for(int i = 0;i < d;i++){
		for(int j = 0;j < d;j++)
			r += as[i*d+j];
		for(int j = 0;j < d;j++)
			r += bs[i*d+j];
		for(int j = 0;j < d;j++)
			r += cs[i*d+j];
	}
	// cout << r << endl;
	return r;
}
int main()
{
	for(int i = 1;i < N;i++){
		a[i] = a[i-1] * 3;
		// printf("a[%d] = %d\n", i, a[i]);
	}
	for(int i = 0;i < N;i++){
		f[i] = a[i] * a[i];
		// printf("f[%d] = %d\n", i, f[i]);
	}
	for(int i = 1;i < N;i++){
		blank = tmp = "";
		for(int j = 0;j < f[i-1];j++){
			tmp += str[i-1][j];
			blank += ' ';
		}
		tmp = gao(tmp, blank, tmp, a[i-1]) + gao(blank, tmp, blank, a[i-1]) + gao(tmp, blank, tmp, a[i-1]);
		// cout << tmp << endl;
		for(int j = 0;j < f[i];j++)
			str[i][j] = tmp[j];
		// printf("str[%d] = %s\n", i, str[i]);
	}
	int n;
	while(~scanf("%d", &n)){
		if(n == -1) break;
		n--;
		for(int i = 0;i < f[n];i++){
			if(i && i % a[n] == 0) printf("\n");
			putchar(str[n][i]);
		}
		printf("\n-\n");
	}
	return 0;
}