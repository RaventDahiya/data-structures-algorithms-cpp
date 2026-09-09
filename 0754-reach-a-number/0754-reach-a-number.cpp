class Solution {
public:
    int reachNumber(int target) {
        int sum=0 , steps=0;
        target = abs(target);

        while(sum < target || (sum-target)%2!=0){
            steps++;
            sum += steps;
        }
        return steps;
    }
};