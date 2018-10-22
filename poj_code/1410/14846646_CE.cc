#include <cstio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define eps 1e-8
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
}p[10];
int cross(point P, point Q, point O){
	double t = (P-O)^(Q-O);
	if(fabs(t) < eps) return 0;
	return t > 0 ? -1:1;
}
bool h(point A, point B, point C, point D){
	return cross(A,D,C)*cross(B,D,C) <= 0;
}
bool check(point A, point B, point C, point D){
	return max(A.x,B.x) >= min(C.x,D.x)&&
		max(A.y,B.y) >= min(C.y,D.y)&&
		max(C.x,D.x) >= min(A.x,B.x)&&
		max(C.y,D.y) >= min(A.y,B.y)&&
		h(A,B,C,D)&&h(C,D,A,B);
}
int solve()
{
	for(int i = 1;i < 4;i++)
		if(check(p[0], p[1], p[2*i], p[2*i+1]))
			return 1;
	return 0;
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		p[0].sc(), p[1].sc();
		p[2].sc(), p[5].sc();
		p[9] = p[2], p[6] = p[5];
		p[3] = p[4] = point(p[2].x, p[5].y);
		p[7] = p[8] = point(p[5].x, p[2].y);
		printf("%c\n", "FT"[solve()]);
	}
	return 0;
}