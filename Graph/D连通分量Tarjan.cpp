void Tarjan(u) {
    dfn[u]=low[u]=++index
    stack.push(u)
    for each (u, v) in E {
        if (v is not visted) { 
            tarjan(v) 
            low[u] = min(low[u], low[v]) 
        } else if (v in stack) { 
            low[u] = min(low[u], dfn[v]) //low[u] = min(low[u], low[v])
        } 
    } 
    if (dfn[u] == low[u]) { //u是一个强连通分量的根 
        repeat 
            v = stack.pop 
            print v 
        until (u == v) 
    } //退栈，把整个强连通分量都弹出来 
} //复杂度是O(E+V)的

/*--------------------------------------------
 * File Name: POJ 3180
 * Author: Danliwoo
 * Mail: Danliwoo@outlook.com
 * Created Time: 2016-07-06 12:47:20
--------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int n, m, ans;
#define N 10100
std::vector<int> v[N];
int vis[N], dfn[N], low[N], stk[N], top, ins[N], clk;
void Tarjon(int x){
    dfn[x] = low[x] = clk++;
    stk[top++] = x;
    vis[x] = ins[x] = 1;
    for(int j = 0;j < v[x].size();j++){
        int y = v[x][j];
        if(!vis[y]){
            Tarjon(y);
            low[x] = min(low[x], low[y]);
        } else if(ins[y]){
            low[x] = min(low[x], dfn[y]);
        }
    }
    if(low[x] == dfn[x]){
        int sz = 0;
        do {
            ins[stk[top-1]] = 0;
            top--;
            sz++;
        } while(stk[top] != x);
        if(sz > 1) ans++;
    }
}
int main()
{
    while(~scanf("%d%d", &n, &m)){
        memset(v, 0, sizeof(v));
        for(int i = 0;i < m;i++){
            int x, y;scanf("%d%d", &x, &y);
            x--; y--;
            v[x].push_back(y);
        }
        memset(vis, 0, sizeof(vis));
        memset(ins, 0, sizeof(ins));
        top = ans = clk = 0;
        for(int i = 0;i < n;i++) if(!vis[i])
            Tarjon(i);
        printf("%d\n", ans);
    }
    return 0;
}
