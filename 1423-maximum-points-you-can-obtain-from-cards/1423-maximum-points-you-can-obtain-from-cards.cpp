class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        int totalSum = accumulate(c.begin(),c.end(),0);
            
        //constant window minSum

        int left = 0;   
        int sum = 0;
        int minSum = INT_MAX;
        int n = c.size();
        if (k == n) return totalSum;

        for(int right=0;right<n;right++){
            sum += c[right];

            while(right-left+1 == n-k){
                minSum = min(minSum,sum);
                sum -= c[left];
                left++;
            }

        }

        return totalSum - minSum;
    }
};