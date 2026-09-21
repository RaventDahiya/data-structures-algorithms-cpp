class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count1 = 0;
        int count2 = 0;
        int c1;
        int c2;
        for(auto num : nums){
            if(num==c1) count1++;
            else if(num==c2) count2++;
            else if(count1==0){
                count1 = 1;
                c1 = num;
            }else if(count2==0){
                count2 = 1;
                c2 = num;
            }else{
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for(auto num : nums){
            if(num==c1) count1++;
            if(num==c2) count2++;
        }
        vector<int>ans;
        if(count1>(n/3)) ans.push_back(c1);
        if(count2>(n/3) && c1!=c2) ans.push_back(c2);
        return ans;
    }
};