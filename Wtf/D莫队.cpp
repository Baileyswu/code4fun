/*--------------------------------------------
 * File Name: Mo's Algorithm
 * Author: Danliwoo
 * Mail: Danliwoo@outlook.com
 * Created Time: 2016-10-03 17:10:42
--------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;
#define N 51000
#define K 1000100
int n, m, k;
int a[N], b[N], pos[N], c[2][K], ans[N], cnt;
struct node {
    int l, r, id;
    void sc(int i){
        scanf("%d%d", &l, &r);
        id = i;
    }
}p[N];
bool cmp(node a, node b) {
    if(pos[a.l] == pos[b.l]) return a.r < b.r;
    return pos[a.l] < pos[b.l];
}
void update(int x, int y) {
    if(a[x] != b[x]) cnt -= min(c[0][a[x]], c[1][a[x]]) + min(c[0][b[x]], c[1][b[x]]);
    else cnt -= min(c[0][a[x]], c[1][a[x]]);
    c[0][a[x]] += y;
    c[1][b[x]] += y;
    if(a[x] != b[x]) cnt += min(c[0][a[x]], c[1][a[x]]) + min(c[0][b[x]], c[1][b[x]]);
    else cnt += min(c[0][a[x]], c[1][a[x]]);
}
void solve() {
    memset(c, 0, sizeof(c));
    int pl = 0, pr = 0;
    cnt = a[0] == b[0] ? 1 : 0;
    c[0][a[0]]++; c[1][b[0]]++;
    for(int i = 0;i < m;i++) {
        int id = p[i].id, l = p[i].l, r = p[i].r;
        for(int j = pr + 1;j <= r;j++)
            update(j, 1);
        for(int j = pr;j > r;j--)
            update(j, -1);
        for(int j = pl;j < l;j++)
            update(j, -1);
        for(int j = pl-1; j >= l;j--)
            update(j, 1);
        pr = r; pl = l;
        ans[id] = cnt;
    }
    for(int i = 0;i < m;i++)
        printf("%d\n", ans[i]);
}
int main() {
    while(~scanf("%d%d%d", &n, &m, &k)) {
        for(int i = 0;i < n;i++)
            scanf("%d", &a[i]);
        for(int i = 0;i < n;i++)
            scanf("%d", &b[i]);
        int bk = sqrt(n + 1.0);
        for(int i = 0;i < n;i++)
            pos[i] = i / bk;
        for(int i = 0;i < m;i++)
            p[i].sc(i);
        sort(p, p+m, cmp);
        solve();
    }
    return 0;
}