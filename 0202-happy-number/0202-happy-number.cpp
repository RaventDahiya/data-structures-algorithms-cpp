class Solution {
public:
    int sum_of_the_squares_of_its_digits(int n){
        int ans = 0;
        while(n){
            int dig = n%10;
            n = n/10;
            ans += dig * dig;
        }
        return ans;
    }
    bool isHappy(int n) {
        if(n<1) return false;

        unordered_set<int>st;
        st.insert(n);
        while(1){
            int newNum = sum_of_the_squares_of_its_digits(n);
            if(newNum == 1) return true;
            if(st.count(newNum)) return false;
            else st.insert(newNum);
            n = newNum;
        }
    }
};