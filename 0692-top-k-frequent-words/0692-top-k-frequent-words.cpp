class Solution {
public:
    struct cmp {
        bool operator()(pair<int, string>& a, pair<int, string>& b) {
            if (a.first == b.first)
                return a.second < b.second; // larger string on top

            return a.first > b.first; // smaller frequency on top
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for (auto str : words) {
            mp[str]++;
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;

        for (auto [str,count] : mp) {

            pq.push({count, str});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<string> ans;
        while (!pq.empty()) {
            auto [count, str] = pq.top();
            pq.pop();
            ans.push_back(str);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};