class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        int f = 0;
        while (s < n && f < n) {
            while (s < n && nums[s] != 0)
                s++;
            f = s + 1;
            while (f < n && nums[f] == 0)
                f++;
            if (f < n && s < n) {
                swap(nums[s], nums[f]);
                s++;
                f++;
            }
        }
    }
};