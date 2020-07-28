#include <bits/stdc++.h>
using namespace std;

static const int N = 100010;
static const int M = 26;
int n, l[M], r[M], vis[M], a[M][N];

bool check(int p, int q) {
    if(p > q) return false;
    bool flag = true;
    for(int i = 0;i < M;i++) {
        if(l[i] > q || r[i] < p) continue;
        int c = p>0 ? a[i][q] - a[i][p-1] : a[i][q];
        if(c && c != a[i][n-1]) {
            return false;
        }
    }
    return true;
}

vector<string> maxNumOfSubstrings(string s) {
    memset(vis, false, sizeof(vis));
    memset(a, 0, sizeof(a));
    memset(l, 0, sizeof(l));
    memset(r, 0, sizeof(r));
    n = s.length();
    for(int i = 0;i < n;i++) {
        int c = s[i]-'a';
        if(!vis[c]) {
            r[c] = l[c] = i;
            vis[c] = true;
        } else {
            r[c] = i;
        }
        for(int j = 0;j < M;j++) {
            if(c == j)
                a[j][i] = i>0 ? a[j][i-1]+1 : 1;
            else a[j][i] = i>0 ? a[j][i-1] : 0;
        }
    }

    set<pair<int, int>> st;
    for(int i = 0;i < M;i++) {
        int L = l[i], R = r[i];
        if(check(L, R)) st.insert(make_pair(L, R));
        else for(int j = 0;j < M;j++) if(i != j) {
            if(r[j] < L || R < l[j]) continue;
            L = min(L, l[j]);
            R = max(R, r[j]);
            if(check(L, R)) st.insert(make_pair(L, R));
        }
    }

    memset(vis, false, sizeof(vis));
    vector<pair<int, int>> vec;
    for(auto s : st) vec.push_back(s);
    for(int i = 0;i < vec.size();i++)
        for(int j = i+1;j < vec.size();j++) if(!vis[i] && !vis[j]) {
            int Li = vec[i].first, Ri = vec[i].second;
            int Lj = vec[j].first, Rj = vec[j].second;
            if(Li <= Lj && Rj <= Ri)
                vis[i] = true;
            else if(Lj <= Li && Ri <= Rj)
                vis[j] = true;
            // printf("%d %d [%d, %d] [%d, %d] %s %s\n", i, j, Li, Ri, Lj, Rj, vis[i] ? "true": "false", vis[j] ? "true": "false");
        }
    vector<string> ans;
    for(int i = 0;i < vec.size();i++) if(!vis[i])
        ans.push_back(s.substr(vec[i].first, vec[i].second-vec[i].first+1));

    return ans;
}

int main() {
    int o = 0;
    string str;
    while(cin >> str) {
        printf("\nCase #%d: ", ++o);
        auto ans = maxNumOfSubstrings(str);
        for(auto x : ans) cout << x << " ";
    }
    return 0;
}