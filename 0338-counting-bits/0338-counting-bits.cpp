class Solution {
public:
    int countBitsHelper(int n){
        int count = 0;
        while(n){
            n = n & n-1;
            count++;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++){
            ans.push_back(countBitsHelper(i));
        }
        return ans;
    }
};