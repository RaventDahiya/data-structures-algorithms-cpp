// User function Template for C++

class Solution {
public:
    bool canArrange(vector<int>& stalls, int k, int mid) {
        sort(stalls.begin(), stalls.end());
        int c = 1;
        int prev = stalls[0];
        for (int i = 1;i < stalls.size();i++) {
            if (stalls[i] - prev >= mid) {
                c++;
                prev = stalls[i];
            }
        }
        if (c < k) {
            return false;
        }
        return true;
    }
    int aggressiveCows(vector<int>& stalls, int k) {
        if (stalls.size() < k) return -1;
        int s = 1;
        int e = (*max_element(stalls.begin(), stalls.end())) - (*min_element(stalls.begin(), stalls.end()));
        int ans = -1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (canArrange(stalls, k, mid)) {
                ans = mid;

                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }
        return ans;

    }
};