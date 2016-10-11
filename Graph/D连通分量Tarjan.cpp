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
