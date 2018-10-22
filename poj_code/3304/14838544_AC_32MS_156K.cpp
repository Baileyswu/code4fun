/*--------------------------------------------
 * File Name: POJ 3304
 * Author: Danliwoo
 * Mail: Danliwoo@outlook.com
 * Created Time: 2015-10-22 20:29:33
--------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#define N 200
#define eps 1e-8
struct point
{
    double x, y;
    point operator - (const point b) const{
        point c;
        c.x = x-b.x, c.y = y-b.y;
        return c;
    }
    void pr(){
        printf("(%.2f %.2f) ", x, y);
    }
    void scan(){
    	scanf("%lf%lf\n", &x, &y);
    }
}p[2*N];
int det(double x)
{
	if(fabs(x) < eps) return 0;
	return x > 0 ? 1 : -1;
}
double cross(point P, point Q)
{
    return P.x*Q.y-P.y*Q.x;
}
bool check(point P, point Q, point A, point B)
{
    //P.pr();Q.pr();A.pr();B.pr();
    point q = Q-P, a = A-P, b = B-P;
    //q.pr();a.pr();b.pr();printf("\n");
   	//printf("%.2f %.2f %.2f\n", cross(q, a), cross(q, b), cross(q, a)*cross(q, b));
	int ha = det(cross(q, a)), hb = det(cross(q, b));
	//printf("%d %d\n", ha, hb);
    return ha*hb <= 0 ? true : false;
}
bool solve(int n)
{
	//printf("%d ppp\n", n);
    for(int i = 0;i < 2*n;i++)
        for(int j = i+1;j < 2*n;j++)
        {
			if(!det(p[i].x - p[j].x) && !det(p[i].y - p[j].y))
				continue;
            int v = 0;
            for(int k = 0;k < n;k++)
            {	
                if(!check(p[i], p[j],p[2*k], p[2*k+1]))
                {
                    v = 1;
                    break;
                }
            }
            if(!v) return true;
        }
    return false;
}
int main()
{
    int T, n;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 0;i < n;i++)
        {
            p[2*i].scan();
            p[2*i+1].scan();
        }
		if(n == 1 && !det(p[0].x-p[1].x) && !det(p[0].y-p[1].y)) printf("Yes!\n");
        else if(solve(n)) printf("Yes!\n");
        else printf("No!\n");
    }
    return 0;
}