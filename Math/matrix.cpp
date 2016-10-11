#define M 10
struct Matrix{
	int n, m;
	int a[M][M];
	Matrix(){}
	Matrix(int p[M][M], int x, int y) {
		memcpy(a, p, sizeof(a));
		n = x, m = y;
	}
	void clear(){
		n = m = 0;
		memset(a, 0, sizeof(a));
	}
	void pr() {
		for(int i = 0;i < n;i++)
			for(int j = 0;j < m;j++)
				printf("%d%c", a[i][j], " \n"[j==m-1]);
		printf("\n");
	}
	void set(int p[M][M], int x, int y) {
		n = x, m = y;
		memcpy(a, p, sizeof(a));
	}
	Matrix operator + (const Matrix &b) const{
		Matrix tmp;
		tmp.n = n; tmp.m = m;
		for(int i = 0;i < n;i++)
			for(int j = 0;j < m;j++)
				tmp.a[i][j] = a[i][j] + b.a[i][j];
		return tmp;
	}
	Matrix operator - (const Matrix &b) const{
		Matrix tmp;
		tmp.n = n; tmp.m = m;
		for(int i = 0;i < n;i++)
			for(int j = 0;j < m;j++)
				tmp.a[i][j] = a[i][j] - b.a[i][j];
		return tmp;
	}
	Matrix operator * (const Matrix &b) const{
		Matrix tmp;
		tmp.clear();
		tmp.n = n; tmp.m = b.m;
		for(int i = 0;i < n;i++)
			for(int j = 0;j < b.m;j++)
				for(int k = 0;k < m;k++) if(a[i][k] && b.a[k][j]) //avoid TLE
					tmp.a[i][j] += a[i][k] * b.a[k][j];
		return tmp;
	}
};
