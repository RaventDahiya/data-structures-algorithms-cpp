class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if (n > m)
            return findMedianSortedArrays(nums2, nums1);

        int half = (n + m + 1) / 2;
        int left = 0;
        int right = n;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int l1 = mid - 1 >= 0 ? nums1[mid - 1] : INT_MIN;
            int l2 = half - mid - 1 >= 0 ? nums2[half - mid - 1] : INT_MIN;
            int r1 = mid < n ? nums1[mid] : INT_MAX;
            int r2 = half - mid < m ? nums2[half - mid] : INT_MAX;

            if (l1 <= r2 && l2 <= r1) {
                if ((n + m) % 2 == 1) return (double)max(l1, l2);
                return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
            } else if (l1 > r2) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return 0;
    }
};