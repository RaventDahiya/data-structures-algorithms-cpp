class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c = 0;
        int count = 0;
        for(int num : nums){
            if(count == 0){
                c = num;
                count = 1;
            }else if(num == c){
                count++;
            }else{
                count--;
            }
        }
        count = 0;
        for(int num : nums){
            if(num==c) count++;
        }
        if(count > nums.size()/2) return c;
        return -1;
    }
};