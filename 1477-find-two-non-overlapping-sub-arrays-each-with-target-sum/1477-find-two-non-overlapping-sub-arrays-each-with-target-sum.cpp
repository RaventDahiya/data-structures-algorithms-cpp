class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int currSum = 0;
        int result = INT_MAX;
        int bestMin = INT_MAX;
        vector<int>minLenTillIndex(n,INT_MAX);
        int i =0;
        for(int j=0;j<n;j++){
            currSum += arr[j];
            while(currSum > target){ //if invalid
                currSum -= arr[i++];
            }
            if(currSum==target){
                int len = j-i+1;
                if(i>0 &&minLenTillIndex[i-1]!=INT_MAX){
                    result = min(result,len + minLenTillIndex[i-1]);
                }
                bestMin = min(bestMin,len);
            }
            minLenTillIndex[j]=bestMin;
        }
        return result==INT_MAX ? -1 : result;
    }
};