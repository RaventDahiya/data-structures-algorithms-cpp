class Solution {
public:
    int solve(int startValue, int target) {
        if (target <= startValue)
            return startValue - target;

        if (target % 2 == 0)
            return 1 + solve(startValue, target / 2);
        else
            return 1 + solve(startValue, target + 1);
    }
    int brokenCalc(int startValue, int target) {
        return solve(startValue,target);
    }
};