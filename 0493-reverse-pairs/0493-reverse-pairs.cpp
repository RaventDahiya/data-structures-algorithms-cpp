class Solution {
public:
    int merge(vector<long long>& nums, int low, int mid, int high) {
        int ans = 0;
        vector<long long> temp;
        
        int j = mid + 1;
        for (int i=low;i<=mid;i++) {
            while(j <= high && nums[i]>2*nums[j]){
                j++;
            }
            ans += j-(mid+1);
        }
        int i = low;
        j = mid + 1;
        while (i <= mid && j <= high) {

            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i]);
                i++;
            } else {
                temp.push_back(nums[j]);
                j++;
            }
        }

        while (i <= mid) {
            temp.push_back(nums[i]);
            i++;
        }
        while (j <= high) {
            temp.push_back(nums[j]);
            j++;
        }
        i = 0;
        for (int idx = low; idx <= high; idx++) {
            nums[idx] = temp[i++];
        }
        return ans;
    }
    int mergeSort(vector<long long>& arr, int low, int high) {
        if (low >= high)
            return 0;
        int ans = 0;
        int mid = low + (high - low) / 2;
        ans += mergeSort(arr, low, mid);
        ans += mergeSort(arr, mid + 1, high);
        ans += merge(arr, low, mid, high);
        return ans;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<long long>temp(nums.begin(),nums.end());
        return mergeSort(temp, 0, n - 1);
    }
};