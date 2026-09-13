class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int i = 0;
        int j = 0;

        int size = 0;
        int midIndex1 = (n+m)/2;
        int midIndex2 = ((n+m)/2) - 1;
        int mid1 = -1;
        int mid2 = -1;
        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                if(size == midIndex1) mid1 = nums1[i];
                if(size == midIndex2) mid2 = nums1[i];
                i++;
                size++;
            }else{
                if(size == midIndex1) mid1 = nums2[j];
                if(size == midIndex2) mid2 = nums2[j];
                j++;
                size++;
            }
        }

        while(i<n){
            if(size == midIndex1) mid1 = nums1[i];
            if(size == midIndex2) mid2 = nums1[i];
            size++; 
            i++;
        }

        while(j<m){
            if(size == midIndex1) mid1 = nums2[j];
            if(size == midIndex2) mid2 = nums2[j];
            size++;
            j++;
        }


        if(size%2==0){
            return ((double)mid1 + (double)mid2 )/2.0;
        }else{
            return (double)mid1;
        }

        return -1;
    }
};