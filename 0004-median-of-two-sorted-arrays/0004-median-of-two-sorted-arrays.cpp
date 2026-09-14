class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        if (n > m) return findMedianSortedArrays(nums2, nums1);

        int left = 0;
        int right = n;
        int half = (n + m + 1) / 2;

        while (left <= right) {
            int mid1 = left + (right - left) / 2;
            int mid2 = half - mid1;

            int r1 = mid1 < n ? nums1[mid1] : INT_MAX;
            int r2 = mid2 < m ? nums2[mid2] : INT_MAX;
            int l1 = mid1 - 1 >= 0 ? nums1[mid1 - 1] : INT_MIN;
            int l2 = mid2 - 1 >= 0 ? nums2[mid2 - 1] : INT_MIN;

            if(l1<=r2 && l2<=r1){
                if((n + m ) % 2 == 0){ //even
                    return ((double)max(l1,l2) + (double)min(r1,r2))/2.0;
                }else{
                    return (double)max(l1,l2);
                }
            }else if(l2 > r1){
                left = mid1 + 1;
            }else{
                right = mid1 - 1;
            }
        }

        return -1;
    }
};