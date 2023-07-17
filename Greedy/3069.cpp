#include<iostream>
#include<algorithm>
using namespace std;
int a[1010];
int main() {
    int n, r;
    while(cin >> r >> n) {
        if(n == -1) break;
        for(int i = 0;i < n;i++)
            cin >> a[i];
        sort(a, a+n);

        int i = 0;
        int ans = 0;
        while(i < n) {
            int s = a[i++];
            while(i < n && a[i] <= s+r) i++;
            int p = a[i-1];
            while(i<n && a[i]<= p+r) i++;
            ans++;
        }

        cout << ans << endl;
    }
    return 0;
}