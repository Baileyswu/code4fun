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
}t[4], u[4];
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
bool cover(point O, point A, point B){
	//O.pr(), A.pr(), B.pr();
	//printf("%.3f %.3f %.3f %.3f %.3f %.3f\n", O.x, A.x, B.x, A.x-B.x, A.x-O.x, (A.x-B.x)*(A.x-O.x));
	if(fabs(A.x-O.x) < eps) return fabs(A.x-B.x) < eps;
	return !(((A-O)^(B-O))*(A.x-O.x) < 0 || (A.x-B.x)*(A.x-O.x) > 0);
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
		u[0] = A.s, u[1] = A.e, u[2] = B.s, u[3] = B.e;
		sort(t, t+4, cmp);
		//O.pr();
		//for(int i = 0;i < 4;i++) t[i].pr();
		if(cover(O, t[1], t[0])){
			printf("0.00\n");
			continue;
		}
		point P = point(-(A.c+A.b*t[1].y)/A.a, t[1].y);
		point Q = point(-(B.c+B.b*t[1].y)/B.a, t[1].y);
		
		P = P-O, Q = Q-O;
		double ans = fabs(P^Q)/2;
		printf("%.2f\n", ans);
	}
	return 0;
}