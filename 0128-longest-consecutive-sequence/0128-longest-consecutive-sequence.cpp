class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int maxi = 0;

        for (int num : st) {

            // Only start a sequence from its beginning
            if (!st.count(num - 1)) {

                int curr = num;
                int count = 1;

                while (st.count(curr + 1)) {
                    curr++;
                    count++;
                }

                maxi = max(maxi, count);
            }
        }

        return maxi;
    }
};