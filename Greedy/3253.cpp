#include<iostream>
#include<queue>
using namespace std;
int a[20100];
priority_queue<int, vector<int>, greater<int> > Q;
int main() {
    int n;
    while(cin >> n) {
        while(!Q.empty()) Q.pop();
        for(int i = 0;i < n;i++) {
            cin >> a[i];
            Q.push(a[i]);
        }
        long long ans = 0;
        while(!Q.empty() && Q.size() > 1) {
            int x = Q.top();Q.pop();
            int y = Q.top();Q.pop();
            ans += (long long)x+y;
            Q.push(x+y);
            // cout << x << " " << y << endl;
        }
        // if(!Q.empty()) ans += Q.top();
        cout << ans << endl;
    }
    return 0;
}