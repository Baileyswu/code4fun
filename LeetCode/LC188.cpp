#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    static const int INF = 1e9;
    int greedy(int n, vector<int>& prices) {
        int sum = 0;
        for(int i = 1;i < n;i++) if(prices[i] > prices[i-1])
            sum += prices[i] - prices[i-1];
        return sum;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(k > n/2) return greedy(n, prices);

        k = min(n, k<<1);
        if(k&1) k--;
        if(!n || !k) return 0;

        int dp[k+1];
        for(int j = 0;j <= k;j++) dp[j] = -INF;
        dp[0] = 0;
        if(k > 0) dp[1] = -prices[0];
        for(int i = 1;i < n;i++) {
            for(int j = k;j > 0;j -= 2) {
                dp[j] = max(dp[j], dp[j-1] + prices[i]);
                dp[j-1] = max(dp[j-1], dp[j-2]-prices[i]);
            }
            // for(int j = 1;j <= k && j <= i+1;j++) cout << dp[j] << " "; cout << endl;
        }
        int ans = 0;
        for(int j = 0;j <= k;j+=2) ans = max(ans, dp[j]);
        return ans;
    }
};