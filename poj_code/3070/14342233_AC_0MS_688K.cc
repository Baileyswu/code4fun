#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <queue>
#include <algorithm>  
#include <map>
using namespace std;  
#define MAXN 5

const int n = 5;
int e[5][5] = {
		{1,0,0,0,0},
		{0,1,0,0,0},
		{0,0,1,0,0},
		{0,0,0,1,0},
		{0,0,0,0,1}
	};
struct Matrix_{
	int n, m;
	int a[MAXN][MAXN];
	Matrix_(){}
	Matrix_(int p[5][5], int x, int y)
	{
		memcpy(a, p, sizeof(a));
		n = x, m = y;
	}
	void clear(){
		n = m = 0;
		memset(a, 0, sizeof(a));
	}
	void pr()
	{
		for(int i = 0;i < n;i++)
			for(int j = 0;j < m;j++)
				printf("%d%c", a[i][j], " \n"[j==m-1]);
		printf("\n");
	}
	void set(int p[5][5], int x, int y)
	{
		n = x, m = y;
		memcpy(a, p, sizeof(a));
	}
	void mod(int p)
	{
		for(int i = 0;i < n;i++)
			for(int j = 0;j < m;j++)
				a[i][j] %= p;
	}
	Matrix_ operator + (const Matrix_ &b) const{
		Matrix_ tmp;
		tmp.n = n; tmp.m = m; //where is n, m, a[i][j] from?
		for(int i = 0;i < n;i++)
			for(int j = 0;j < m;j++)
				tmp.a[i][j] = a[i][j] + b.a[i][j];
		return tmp;
	}
	Matrix_ operator - (const Matrix_ &b) const{
		Matrix_ tmp;
		tmp.n = n; tmp.m = m; //where is n, m, a[i][j] from?
		for(int i = 0;i < n;i++)
			for(int j = 0;j < m;j++)
				tmp.a[i][j] = a[i][j] - b.a[i][j];
		return tmp;
	}
	Matrix_ operator * (const Matrix_ &b) const{
		Matrix_ tmp;
		tmp.clear();
		tmp.n = n; tmp.m = b.m; //where is n, m, a[i][j] from?
		for(int i = 0;i < n;i++)
			for(int j = 0;j < b.m;j++)
				for(int k = 0;k < m;k++)
					tmp.a[i][j] += a[i][k] * b.a[k][j];
		return tmp;
	}
};
Matrix_ solve(Matrix_ p, int N)
{
	if(N == 1)
		return p;
	Matrix_ tmp = solve(p, N/2);
	tmp = tmp * tmp;
	tmp.mod(10000);
	if(N & 1LL)
		return p * tmp;
	return tmp;
}
int main()
{
	int N;
	while(cin >> N)
	{
		if(N == -1)
			break;
		if(!N)
		{
			printf("0\n");
			continue;
		}
		Matrix_ E(e, 5, 5);
		int c[5][5] = {{1, 1}, {1, 0}};
		//E.pr();
		E.set(c, 2, 2);
		//E.pr();
		E = solve(E, N);
		//E.pr();
		printf("%d\n", E.a[1][0]);
	}
	return 0;	
}
