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
double t[4];
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
};
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
bool cmp(double x, double y){
	return x > y;
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
		t[0] = A.s.y, t[1] = A.e.y, t[2] = B.s.y, t[3] = B.e.y;
		sort(t, t+4, cmp);
		point P = point(-(A.c+A.b*t[1])/A.a, t[1]);
		point Q = point(-(B.c+B.b*t[1])/B.a, t[1]);
		P = P-O, Q = Q-O;
		double ans = fabs(P^Q)/2;
		printf("%.2f\n", ans);
	}
	return 0;
}