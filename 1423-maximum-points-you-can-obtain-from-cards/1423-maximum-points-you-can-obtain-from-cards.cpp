class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total = accumulate(cardPoints.begin(),cardPoints.end(),0);
        int windowSize = n - k;

        int sum = 0;
        for(int i=0;i<windowSize;i++){
            sum += cardPoints[i];
        }
        int ans = total - sum;

        for(int i=windowSize;i<n;i++){
            sum += cardPoints[i] - cardPoints[i-windowSize];
            ans = max(ans,total - sum);
        }
        return ans;
    }
};