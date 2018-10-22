#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
int n;
struct point
{
	double x, y;
	point(){}
	point(double x, double y):x(x), y(y){}
	point operator - (const point &b) const {
		return point(x - b.x, y - b.y);
	}
	double operator * (const point &b) const {
		return x*b.y - y*b.x;
	}
}p[50];
int dis(double x)
{
	if(fabs(x) < 1e-8) return 0;
	return x > 0 ? 1 : -1;
}
int f(double a, double b, double c, point P)
{
	return dis((a*P.x+c)/(-b)-P.y);
}
double crash(point A, point B, point P, point Q, int k)
{
	double a1 = A.y-B.y, b1 = B.x-A.x, c1 = A*B;
	double a2 = P.y-Q.y, b2 = Q.x-P.x, c2 = P*Q;
	double blow = a1*b2-a2*b1;

	int mm = f(a1, b1, c1, P)*k, nn = f(a1, b1, c1, Q)*k;
	//if((mm>0 && nn>0) || (mm==0 && nn>0) || (mm>0 && nn == 0))
	// printf("mm nn %d %d\n", mm, nn);
	if(mm == 0 && nn > 0)
		return P.x;
	if(mm > 0 && nn > 0)
		return P.x;

	int sa = dis((P-A)*(B-A));
	int sb = dis((Q-A)*(B-A));
	// printf("sa sb %d %d\n", sa, sb);
	if(sa*sb >= 0)
		return p[n-1].x+2;
	
	if(dis(blow) == 0)
		return p[n-1].x+2;
	double x = (-c1*b2+b1*c2)/blow;
	return x > P.x && x < Q.x ? x : p[n-1].x+2;
}
double get(int a, int b)
{
	double x = p[n-1].x+2;
	for(int i = 1;i < n;i++)
	{
		double y = crash(p[a], p[b], p[i-1], p[i], 1);
		x = min(x, y);
		//x = min(x, crash(p[a], p[b], p[i-1], p[i], 1));
		// printf("%d %d %d %.2f\n", a, b, i, y);
		//x = min(x, crash(p[a], p[b], p[i+n-1], p[i+n], -1));
		y = crash(p[a], p[b], p[i+n-1], p[i+n], -1);
		x = min(x, y);
		// printf("%d %d %d %.2f\n", a, b, i+n, y);
		// printf("x %.2f\n", x);
		if(x < p[n-1].x+1)
			return x;
	}
	return x;
}
double solve()
{
	double mmax = p[0].x-1;
	for(int i = 0;i < n;i++)
		for(int j = i+1;j < n;j++)
		{
			mmax = max(mmax, get(i, j));
			// printf("mmax %.2f\n", mmax);
			mmax = max(mmax, get(i+n, j));
			// printf("mmax %.2f\n", mmax);
			mmax = max(mmax, get(i, j+n));
			// printf("mmax %.2f\n", mmax);
			mmax = max(mmax, get(i+n, j+n));
			// printf("mmax %.2f\n", mmax);
			if(mmax > p[n-1].x)
				return mmax;
		}
	return mmax;
};
int main()
{
	while(scanf("%d", &n), n)
	{
		for(int i = 0;i < n;i++)
		{
			double x, y;
			scanf("%lf%lf", &x, &y);
			p[i] = point(x, y);
			p[i+n] = point(x, y-1);
		}
		double ans = solve();
		if(ans > p[n-1].x)
			printf("Through all the pipe.\n");
		else
			printf("%.2f\n", ans);
	}
	return 0;
}