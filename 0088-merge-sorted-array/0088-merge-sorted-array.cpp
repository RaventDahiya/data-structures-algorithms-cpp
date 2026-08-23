class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(nums2.size() > nums1.size()) return merge(nums2,n,nums1,m);
        int i = m-1; 
        int j = 0;

        while(i>=0 && j<n){
            if(nums1[i] > nums2[j]){
                swap(nums1[i],nums2[j]);
                i--; j++;
            }else{
                break;
            }
        }
        sort(nums1.begin(),nums1.begin()+m);
        sort(nums2.begin(),nums2.begin()+n);
        i = m;
        for(auto&num : nums2){
            nums1[i++] = num;
        }
    }
};