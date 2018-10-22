/*--------------------------------------------
 * File Name: POJ 2826
 * Author: Danliwoo
 * Mail: Danliwoo@outlook.com
 * Created Time: 2015-10-28 12:58:44
--------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define eps 1e-8
#define N 60
int n, a[N];
struct point{
    double x, y;
    point(){}
    point(double x, double y):x(x), y(y){}
    point operator - (const point &b) const{
        return point(x-b.x, y-b.y);
    }
    double operator  ^ (const point &b)const{
        return x*b.y-y*b.x;
    }
    void sc(){
        scanf("%lf%lf", &x, &y);
    }
    void pr(){
        printf("%.0lf %.0lf\n", x, y);
    }
    double dis(){
        return sqrt(pow(x,2)+pow(y,2));
    }
}t[4];
struct seg
{
	point s, e;
	double a, b, c;
	void get(){
		s.sc(), e.sc();
		a = s.y-e.y;
		b = e.x-s.x;
		c = s^e;
	}
}A, B;
bool cmp(point P, point Q){
	if(fabs(P.y-Q.y) < eps) return P.x < Q.x;
	return P.y > Q.y;
}
bool cover(point O, point P, point Q){
	//O.pr(), P.pr(), Q.pr();
	//printf("%.3f %.3f %.3f %.3f %.3f %.3f\n", O.x, P.x, Q.x, P.x-Q.x, P.x-O.x, (P.x-Q.x)*(P.x-O.x));
	if(fabs(P.x-O.x) < eps) return fabs(P.x-Q.x) < eps;
	double a = P.x-O.x, b = (P-O)^(Q-O), c = P.x-Q.x;
	//printf("%.2f %.2f %.2f\n", a, b, c);
	return (a<0&&b<=0&&c>=0) || (a>0&&b>=0&&c<=0);
}
bool out(point O){
	return O.x < min(A.s.x, A.e.x) ||
			O.y < min(A.s.y, A.e.y) ||
			O.x < min(B.s.x, B.e.x) ||
			O.y < min(B.s.y, B.e.y);
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--){
		A.get(), B.get();
		double az = point(A.a, A.b) ^ point(B.a, B.b);
		if(fabs(az) < eps || fabs(A.a) < eps || fabs(B.a) < eps){
			printf("0.00\n");
			continue;
		}
		double ax = point(-A.c, A.b) ^ point(-B.c, B.b);
		double ay = point(A.a, -A.c) ^ point(B.a, -B.c);
		ax /= az; ay /= az;
		point O = point(ax, ay);
		t[0] = A.s, t[1] = A.e, t[2] = B.s, t[3] = B.e;
		sort(t, t+4, cmp);
		if(out(O) || cover(O, t[1], t[0])){
			printf("0.00\n");
			continue;
		}
		point P = point(-(A.c+A.b*t[1].y)/A.a, t[1].y);
		point Q = point(-(B.c+B.b*t[1].y)/B.a, t[1].y);
		
		P = P-O, Q = Q-O;
		double ans = fabs(P^Q)/2;
		printf("%.2f\n", ans+eps);
	}
	return 0;
}