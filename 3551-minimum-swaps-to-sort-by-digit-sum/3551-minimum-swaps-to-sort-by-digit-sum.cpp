
class Solution {
public:
    static bool cmp(int a, int b) {
        int x = a, y = b;
        int sumA = 0, sumB = 0;

        while (x) {
            sumA += x % 10;
            x /= 10;
        }

        while (y) {
            sumB += y % 10;
            y /= 10;
        }

        if (sumA == sumB)
            return a < b;

        return sumA < sumB;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]] = i;
        }

        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end(), cmp);

        vector<bool> vis(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;

            int j = i;
            int cycle = 0;

            while (!vis[j]) {
                vis[j] = true;
                j = mp[sorted[j]];
                cycle++;
            }

            ans += cycle - 1;
        }

        return ans;
    }
};
