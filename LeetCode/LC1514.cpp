/* Variants of Dijkstra alg. optimized by priority_queue */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int N = 1e4+10;
    vector< pair<double, int> > mp[N];
    double pb[N];
    double bfs(int start, int end) {
        priority_queue<pair<double, int>, vector<pair<double, int>>, less<pair<double, int>> > Q;
        while(!Q.empty()) Q.pop();
        Q.push(make_pair(1.0, start));
        pb[start] = 1;
        while(!Q.empty()) {
            auto f = Q.top(); Q.pop();
            // cout << f.second << " " << f.first << endl;
            for(auto t : mp[f.second]) if(t.first * f.first > pb[t.second]) {
                // printf("when %.3f * %.3f > %.3f\n", t.first, f.first, pb[t.second]);
                pb[t.second] = t.first * f.first;
                Q.push(make_pair(pb[t.second], t.second));
            }
        }
        return pb[end];
    }
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        for(int i = 0;i < n;i++) {
            mp[i].clear();
            pb[i] = 0;
        }
        for(int i = 0;i < edges.size();i++) {
            mp[edges[i][0]].push_back(make_pair(succProb[i], edges[i][1]));
            mp[edges[i][1]].push_back(make_pair(succProb[i], edges[i][0]));
        }
        return bfs(start, end);
    }
};
