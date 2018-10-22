#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define eps 1e-8
#define N 100
int n;
struct point{
    double x, y;
	int m;
    point(){}
    point(double x, double y):x(x), y(y){}
    point operator - (const point &b) const{
        return point(x-b.x, y-b.y);
    }
    double operator  ^ (const point &b)const{
        return x*b.x+y*b.y;
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
}p[100];
double cross(point A, point B, point C){
	point P = B-A, Q = C-B;
    return (P^Q)/P.dis()/Q.dis();
}
int ans[N], flag[N], cnt;
void get(int s)
{
	flag[s] = 1; cnt = 1, ans[0] = p[s].m;
	point A = point(0, p[s].y);
	point B = p[s];
	while(cnt < n)
	{
		int first = 1, it;
		double t;
		for(int i = 0;i < n;i++) if(!flag[i])
		{
			if(first)
			{
				first = 0;
				t = cross(A,B,p[i]);
				ans[cnt] = p[i].m;
				it = i;
			}
			else
			{
				double k = cross(A,B,p[i]);
				if(t < k)
				{
					t = k;
					ans[cnt] = p[i].m;
					it = i;
				}
			}
		}
		flag[it] = 1;
		cnt++;
		A = B;
		B = p[it];
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i = 0;i < n;i++)
		{
			scanf("%d", &p[i].m);
			p[i].sc();
		}
		int s = 0, low = p[0].y;
		for(int i = 0;i < n;i++) if(p[i].y < low)
		{
			low = p[i].y;
			s = i;
		}
		memset(flag, 0, sizeof(flag));
		get(s);
		printf("%d ", n);
		for(int i = 0;i < n;i++)
			printf("%d%c", ans[i], " \n"[i==n-1]);
	}
	return 0;
}
