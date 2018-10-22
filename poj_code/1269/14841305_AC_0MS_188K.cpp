/*--------------------------------------------
 * File Name: POJ 1269
 * Author: Danliwoo
 * Mail: Danliwoo@outlook.com
 * Created Time: 2015-10-23 16:36:33
--------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define eps 1e-8
struct point
{
	double x, y;
	void sc(){
		scanf("%lf%lf", &x, &y);
	}
	point operator - (const point &b) const{
		point c;
		c.x = x-b.x, c.y = y-b.y;
		return c;
	}
}A, B, C, D;
double cross(point P, point Q){
	return P.x*Q.y - P.y*Q.x;
}
struct line
{
	double a, b, c;
	void get(point P, point Q){
		a = P.y-Q.y;
		b = Q.x-P.x;
		c = cross(P, Q);
	}
}L, J;
int main()
{
	int T;
	scanf("%d", &T);
	printf("INTERSECTING LINES OUTPUT\n");
	while(T--){
		A.sc(), B.sc(), C.sc(), D.sc();
		double s1 = cross(A-C, A-D);
		double s2 = cross(B-C, B-D);
		if(fabs(s1) < eps && fabs(s2) < eps){
			printf("LINE\n");
			continue;
		}
		if(fabs(s1-s2) < eps){
			printf("NONE\n");
			continue;
		}
		L.get(A, B);
		J.get(C, D);
		double ax = (L.b*J.c-J.b*L.c)/(L.a*J.b-J.a*L.b);
		double ay = -(L.a*J.c-J.a*L.c)/(L.a*J.b-J.a*L.b);
		printf("POINT %.2f %.2f\n", ax, ay);
	}
	printf("END OF OUTPUT\n");
	return 0;
}