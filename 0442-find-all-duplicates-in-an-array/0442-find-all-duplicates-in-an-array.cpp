class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        // Cyclic sort: place each number at its correct index
        for (int i = 0; i < n; ) {
            int correctIdx = nums[i] - 1;
            // Only swap if element is in the range and not at its right spot
            if (nums[i] != nums[correctIdx])
                swap(nums[i], nums[correctIdx]);
            else
                ++i;
        }
       for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};