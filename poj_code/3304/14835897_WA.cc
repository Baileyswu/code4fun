#include <cstdio>
#include <iostream>
using namespace std;
#define N 200
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
}p[2*N];
struct node
{
    point s, t;
    void scan(){
        scanf("%lf%lf%lf%lf", &s.x, &s.y, &t.x, &t.y);
    }
}seg[N];
double cross(point P, point Q)
{
    return P.x*Q.y-P.y*Q.x;
}
bool check(point P, point Q, point A, point B)
{
    //P.pr();Q.pr();A.pr();B.pr();
    point q = Q-P, a = A-P, b = B-P;
    //q.pr();a.pr();b.pr();
    //printf("%.2f %.2f %.2f\n", cross(q, a), cross(q, b), cross(q, a)*cross(q, b));
    if(cross(q, a)*cross(q, b) > 1e-8) return false;
    return true;
}
bool solve(int n)
{
    for(int i = 0;i < 2*n;i++)
        for(int j = i+1;j < 2*n;j++)
        {
            int v = 0;
            for(int k = 0;k < n;k++)
            {
                if(!check(p[i], p[j], seg[k].s, seg[k].t))
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
            seg[i].scan();
            p[2*i] = seg[i].s;
            p[2*i+1] = seg[i].t;
        }
        if(solve(n)) printf("Yes!\n");
        else printf("No!\n");
    }
    return 0;
}