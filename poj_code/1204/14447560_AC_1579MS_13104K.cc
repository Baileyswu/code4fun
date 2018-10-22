/*-------------------------------
 * File Name: ACauto
 * Author: Bailey Wu
 * Mail: wulidan0530@live.com
 * Created Time: 2015/07/21
--------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define WN 500000
#define AL 26
#define N 1005
char mp[N][N];
short dp[8][2] = {1,0,1,-1,0,-1,-1,-1,-1,0,-1,1,0,1,1,1};
int L, C, W;
int dir[1005], ans[1001][2], len[1001];
struct Trie
{
    int next[WN][AL], fail[WN], end[WN];
    int root, L;
    int newnode()
    {
        for(int i = 0;i < AL;i++)
            next[L][i] = -1;
        end[L++] = 0;
        return L-1;
    }
    void init()
    {
        L = 0;
        root = newnode();
    }
    void insert(char buf[], int x)
    {
        int len = strlen(buf);
        int now = root;
        for(int i = 0;i < len;i++)
        {
            if(next[now][buf[i]-'A'] == -1)
                next[now][buf[i]-'A'] = newnode();
            now = next[now][buf[i]-'A'];
        }
        end[now] = x;
    }
    void build()
    {
        queue<int> Q;
        fail[root] = root;
        for(int i = 0;i < AL;i++)
            if(next[root][i] == -1)
                next[root][i] = root;
            else
            {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        while(!Q.empty())
        {
            int now = Q.front();
            Q.pop();
            for(int i = 0;i < 26;i++)
                if(next[now][i] == -1)
                    next[now][i] = next[fail[now]][i];
                else
                {
                    fail[next[now][i]] = next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }
    int r()
    {
        return root;
    }
    int query(char buf, int d, int i, int j, int &now)
    {
        now = next[now][buf-'A'];
        int temp = now;
        while(temp != root)
        {
            //res += end[temp];
            //end[temp] = 0;
            int p = end[temp];
            ans[p][0] = i+dp[d][0]*(len[p]-1);
            ans[p][1] = j+dp[d][1]*(len[p]-1);
            dir[p] = d+'A';
            temp = fail[temp];
        }
    }
}ac;
char str[N][1420];
void solve()
{
    for(int j = 0;j < C;j++)
    {
        int now = ac.r();
        for(int i = L-1;i >= 0;i--)
            ac.query(mp[i][j], 0, i, j, now);
        now = ac.r();
        for(int i = 0;i < L;i++)
            ac.query(mp[i][j], 4, i, j, now);
    }
    for(int i = 0;i < L;i++)
    {
        int now = ac.r();
        for(int j = 0;j < C;j++)
            ac.query(mp[i][j], 2, i, j, now);
        now = ac.r();
        for(int j = C-1;j >= 0;j--)
            ac.query(mp[i][j], 6, i, j, now);
    }
    for(int k = 0;k <= L+C-2;k++)
    {
        int p = min(k, L-1), q = max(0, k-C+1);
        int now = ac.r();
        for(int i = p;i >= q;i--)
            ac.query(mp[i][k-i], 1, i, k-i, now);
        now = ac.r();
        for(int i = q;i <= p;i++)
            ac.query(mp[i][k-i], 5, i, k-i, now);
    }
    for(int k = C-1;k >= 1-L;k--)
    {
        int p = max(0, -k), q = min(L-1, C-1-k);
        int now = ac.r();
        for(int i = p;i <= q;i++)
            ac.query(mp[i][k+i], 3, i, k+i, now);
        now = ac.r();
        for(int i = q;i >= p;i--)
            ac.query(mp[i][k+i], 7, i, k+i, now);
    }
}
int main()
{
    scanf("%d%d%d", &L, &C, &W);
    for(int i = 0;i < L;i++)
        scanf("%s", mp[i]);
    ac.init();
    for(int i = 1;i <= W;i++)
    {
        scanf("%s", str[i]);
        len[i] = strlen(str[i]);
        ac.insert(str[i], i);
    }
    ac.build();
    solve();
    for(int i = 1;i <= W;i++)
        printf("%d %d %c\n", ans[i][0], ans[i][1], dir[i]);
    return 0;
}