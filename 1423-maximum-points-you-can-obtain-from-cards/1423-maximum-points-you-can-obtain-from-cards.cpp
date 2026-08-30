class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        int n = c.size();

        int sum = 0;

        // Initially take all k cards from left
        for (int i = 0; i < k; i++) {
            sum += c[i];
        }

        int maxScore = sum;

        // Gradually remove from left
        // and add from right
        for (int i = 1; i <= k; i++) {
            sum -= c[k - i];
            sum += c[n - i];

            maxScore = max(maxScore, sum);
        }

        return maxScore;
    }
};