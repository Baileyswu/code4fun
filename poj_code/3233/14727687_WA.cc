/*--------------------------------------------
 * File Name: POJ 3233
 * Author: Baileys Wu
 * Mail: wulidan0530@live.com
 * Created Time: 2015-09-15 20:34:06
--------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAXN 32
int num[MAXN][MAXN], M, e[MAXN][MAXN];
struct Matrix{
	int n, m;
	int a[MAXN][MAXN];
	Matrix(){}
	Matrix(int p[MAXN][MAXN], int x, int y)
	{
		memcpy(a, p, sizeof(a));
		n = x, m = y;
	}//构造函数，注意调用~
	void clear(){
		n = m = 0;
		memset(a, 0, sizeof(a));
	}
	void pr()
	{
		for(int i = 0;i < n;i++)
			for(int j = 0;j < m;j++)
				printf("%d%c", a[i][j], " \n"[j==m-1]);
	}
	void set(int p[MAXN][MAXN], int x, int y)
	{
		n = x, m = y;
		memcpy(a, p, sizeof(a));
	}
	Matrix operator + (const Matrix &b) const{
		Matrix tmp;
		tmp.n = n; tmp.m = m; //where is n, m, a[i][j] from?
		for(int i = 0;i < n;i++)
			for(int j = 0;j < m;j++)
				tmp.a[i][j] = a[i][j] + b.a[i][j] % M;
		return tmp;
	}
	Matrix operator - (const Matrix &b) const{
		Matrix tmp;
		tmp.n = n; tmp.m = m; //where is n, m, a[i][j] from?
		for(int i = 0;i < n;i++)
			for(int j = 0;j < m;j++)
				tmp.a[i][j] = a[i][j] - b.a[i][j] % M;
		return tmp;
	}
	Matrix operator * (const Matrix &b) const{
		Matrix tmp;
		tmp.clear();
		tmp.n = n; tmp.m = b.m; //where is n, m, a[i][j] from?
		for(int i = 0;i < n;i++)
			for(int j = 0;j < b.m;j++)
				for(int k = 0;k < m;k++)
				{
					tmp.a[i][j] += a[i][k] * b.a[k][j] % M;
					tmp.a[i][j] %= M;
				}
		return tmp;
	}
};
Matrix A, S, I;
Matrix po(Matrix a, int k)
{
	if(k == 0)
		return I;
	if(k == 1)
		return a;
	Matrix s = po(a, k/2);
	s = s*s;
	if(k&1LL)
		s = s*a;
	return s;
}
Matrix solve(Matrix a, int k)
{
	if(k == 1)
		return a;
	Matrix s = solve(a, k/2);
	s = (I+po(a, k/2)) * s;
	if(k&1LL)
		s = s+po(a, k);
	return s;
}
int main()
{
	int n, k;
	memset(e, 0, sizeof(e));
	for(int i = 0;i < MAXN;i++)
		e[i][i] = 1;
	while(~scanf("%d%d%d", &n, &k, &M))
	{
		for(int i = 0;i < n;i++)
			for(int j = 0;j < n;j++)
			{
				scanf("%d", &num[i][j]);
				num[i][j] %= M;
			}
		A.set(num, n, n);
		I.set(e, n, n);
		S = solve(A, k);
		S.pr();
	}
	return 0;
}