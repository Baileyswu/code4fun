// set.lower_bound(x) 别写成 lower_bound(x,x,x)
// A LegacyForwardIterator is a LegacyIterator that can read data from the pointed-to element.
// set 不属于 LegacyForwardIterator，也不属于其父类 LegacyRandomAccessIterators

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> freq(k, 0);
        set<int> free;
        // {t, id}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > busy;
        for(int i = 0;i < k;i++)
            free.insert(i);
        
        int n = arrival.size();
        for(int i = 0;i < n;i++) {
            while(!busy.empty() && busy.top().first <= arrival[i]) {
                auto pr = busy.top();
                busy.pop();
                free.insert(pr.second);
            }
            if(free.empty()) {
                // printf("skipped\n");
                continue;
            }
            auto pos = free.lower_bound(i%k);
            if(pos == free.end()) pos = free.begin();
            // printf("arr=%d, load=%d, (%d, %d) ->", arrival[i], load[i], id, freeAt[id]);
            // printf("push(%d, %d)\n", id, arrival[i] + load[i]);
            busy.push(make_pair(arrival[i] + load[i], *pos));
            freq[*pos]++;
            free.erase(pos);
        }

        int busiest = 0;
        for(int i = 0;i < k;i++)
            busiest = max(busiest, freq[i]);
        
        vector<int> ans;
        for(int i = 0;i < k;i++)
            if(busiest == freq[i])
                ans.push_back(i);
        return ans;
    }
};