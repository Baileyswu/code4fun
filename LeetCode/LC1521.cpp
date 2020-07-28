#include <bits/stdc++.h>
using namespace std;

static const int N = 1e5+10;
static const int P = 18;
int st[N][P];
int get(int l, int r) {
    int k = log(1.0*(r-l+1)/log(2.0));
    return st[l][k] & st[r-(1<<k)+1][k];
}
int find(int l, int r, int x) {
    int s = l;
    if(l == r) return abs(x-get(l,l));
    if(get(s, l) <= x) return x-get(s,l);
    if(get(s, r) >= x) return get(s,r)-x;
    while(l + 1 < r) {
        int mid = (l+r) >> 1;
        if(get(s, mid) < x) r = mid;
        else l = mid;
    }
    int a = get(s, l) - x;
    int b = x - get(s, r);
    return a < b ? a : b;
}
int closestToTarget(vector<int>& arr, int target) {
    int n = arr.size();
    memset(st, 0, sizeof(st));
    for(int i = 0;i < n;i++) {
        st[i][0] = arr[i];
    }
    for(int k = 0; (1<<(k+1)) < n; k++)
        for(int i = 0;i+(1<<k) < n;i++)
            st[i][k+1] = st[i][k]&st[i+(1<<k)][k];
    int ans = abs(target-arr[0]);
    for(int i = 0;i < n;i++) {
        ans = min(ans, find(i, n-1, target));
    }
    return ans;
}

int main() {
    int o = 0, n;
    while(cin >> n) {
        int t;
        vector<int> a;
        for(int i = 0;i < n;i++) {
            cin >> t;
            a.push_back(t);
        }
        cin >> t;
        cout << closestToTarget(a, t) << endl;
    }
    return 0;
}