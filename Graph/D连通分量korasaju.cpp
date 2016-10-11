/*
Korasaju算法
1. 在图G随便选择起点dfs，记录访问时间。
2. 在图G^T根据1得到的访问时间最大的点作为起点dfs，得到若干个树。
3. 每棵树在原图里都是一个强连通分量（由对称在转置图中同样也是）。
*/
/*--------------------------------------------
 * File Name: POJ 2186
 * Author: Danliwoo
 * Mail: Danliwoo@outlook.com
 * Created Time: 2016-07-05 08:13:21
--------------------------------------------*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
#define N 10100
std::vector<int> v[N], w[N];
int vis[N], a[2*N], flag[N], clk, tuan[N], out[N], fn, n, m;
void dfs(int x){
    vis[x] = 1;
    a[clk++] = x;
    for(int j = 0;j < v[x].size();j++)
        if(!vis[v[x][j]])
            dfs(v[x][j]);
    a[clk++] = x;
}
void strong(int x, int f){
    vis[x] = 1;
    flag[x] = f;
    tuan[f]++;
    for(int j = 0;j < w[x].size();j++)
        if(!vis[w[x][j]])
            strong(w[x][j], f);
}
void solve(){
    if(fn == 1){
        printf("%d\n", n);
        return;
    }
    memset(out, 0, sizeof(out));
    for(int i = 0;i < n;i++)
        for(int j = 0;j < v[i].size();j++)
            if(flag[i] != flag[v[i][j]])
                out[flag[i]]++;
    int ans = 0, cc = 0;
    for(int i = 1;i <= fn;i++){
        if(out[i] == 0){
            ans = i;
            cc++;
        }
    }
    if(cc > 1) ans = 0;
    else ans = tuan[ans];
    printf("%d\n", ans);
}
int main()
{
    while(~scanf("%d%d", &n, &m)){
        for(int i = 0;i < n;i++){
            v[i].clear();
            w[i].clear();
        }
        memset(a, 0, sizeof(a));
        memset(vis, 0, sizeof(vis));
        memset(flag, 0, sizeof(flag));
        memset(tuan, 0, sizeof(tuan));
        while(m--){
            int x, y;
			scanf("%d%d", &x, &y);
            x--; y--;
            v[x].push_back(y);
            w[y].push_back(x);
        }
        clk = 0;
        for(int i = 0;i < n;i++){
            if(vis[i]) continue;
            dfs(i);
        }
        memset(vis, 0, sizeof(vis));
        fn = 0;
        for(int i = 2*n-1;i >= 0;i--) 
            if(!vis[a[i]])
                strong(a[i], ++fn);
        solve();
    }
    return 0;
}


