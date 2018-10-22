#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int n;
#define N 110
struct point{
    double x, y;
    void sc(int i){
        scanf("%lf%lf", &x, &y);
    }
    double dis(point a){
        return sqrt(pow(x-a.x,2) + pow(y-a.y,2));
    }
}p[N];
struct node{
    int u, v;
    double e;
    node(){}
    node(int u, int v, double e):u(u), v(v), e(e){}
}q[N*N];
bool cmp(node a, node b){
    return a.e < b.e;
}
int used[N];
int main(){
    while(~scanf("%d", &n)){
        for(int i = 0;i < n;i++)
            p[i].sc(i);
        memset(used, 0, sizeof(used));
        int cnt = 0;
        for(int i = 0;i < n;i++)
            for(int j = i+1;j < n;j++)
                q[cnt++] = node(i,j,p[i].dis(p[j]));
        sort(q, q+cnt,cmp);
        double ans = 0;
        for(int i = 0;i < cnt;i++){
            int u = q[i].u, v = q[i].v;
            if(used[u] && used[v]) continue;
            used[u] = used[v] = 1;
            ans += q[i].e;
        }
        printf("%.2f\n", ans); 
    }
    return 0;
}