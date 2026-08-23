class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int counter1 = INT_MIN;
        int counter2 = INT_MIN;
        int count1 = 0;
        int count2 = 0;

        for(auto& num : nums){
            if(num == counter1){
                count1++;
            }else if(num == counter2){
                count2++;
            }else if(count1 == 0){
                counter1 = num;
                count1 = 1;
            }else if(count2 == 0){
                counter2 = num;
                count2 = 1;
            }else{
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for(auto& num : nums){
            if(num == counter1) count1++;
            if(num == counter2) count2++;
        }
        vector<int>ans;
        int n = nums.size();
        if(count1 > n/3) ans.push_back(counter1);
        if(count2 > n/3) ans.push_back(counter2);
        return ans;
    }
};