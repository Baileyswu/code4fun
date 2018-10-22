/*--------------------------------------------
 * File Name: 
 * Author: Danliwoo
 * Mail: Danliwoo@outlook.com
 * Created Time: 2015-11-14 15:17:32
--------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 1000
int n;
double r;
struct point
{
	double x, y;
	point(){}
	point(double x, double y):x(x), y(y){}
	void pr(){
		printf("(%.2f, %.2f) ", x, y);
	}
	void sc(){
		scanf("%lf%lf", &x, &y);
	}
	point operator - (const point &b) const {
		return point(x - b.x, y - b.y);
	}
	point operator + (const point &b) const {
		return point(x + b.x, y + b.y);
	}
	double operator * (const point &b) const {
		return x*b.y - y*b.x;
	}
	double dis(const point &b) const{
		return sqrt(pow(x-b.x,2)+pow(y-b.y,2));
	}
}R, L, p[N];
int dis(double x)
{
	if(fabs(x) < 1e-8)
		return 0;
	return x > 0 ? 1 : -1;
}
bool polygon()
{
	int k, i, t;
	for(i = 0;i < n;i++)
	{
		t = dis((p[i+1]-p[i])*(p[i+2]-p[i+1]));
		if(t)
		{
			k = t;
			break;
		}
	}
	for(;i < n;i++)
	{
		int t = dis((p[i+1]-p[i])*(p[i+2]-p[i+1]));
		if(t && t != k)
			return false;
	}
	return true;
}
bool out()
{
	//round exactly in bian is regard as outside of polygon
	int k = dis((p[0]-R)*(p[1]-R));
	if(k == 0) return true;
	for(int i = 1;i < n;i++)
	{
		int t = dis((p[i]-R)*(p[i+1]-R));
		if(t != k)
			return true;
	}
	return false;
}
bool putok()
{
	for(int i = 0;i < n;i++)
	{
		double sum = fabs((p[i]-R)*(p[i+1]-R))/p[i].dis(p[i+1]);
		if(dis(sum - r) < 0)
			return false;
	}
	return true;
}
int main()
{
	while(scanf("%d", &n))
	{
		scanf("%lf", &r);
		R.sc();
		if(n < 3) break;
		for(int i = 0;i < n;i++)
			p[i].sc();
		p[n] = p[0]; p[n+1] = p[1]; p[n+2] = p[2];
		if(!polygon())
			printf("HOLE IS ILL-FORMED\n");
		else if(out())
			printf("PEG WILL NOT FIT\n");
		else if(putok())
			printf("PEG WILL FIT\n");
		else
			printf("PEG WILL NOT FIT\n");
	}
	return 0;
}