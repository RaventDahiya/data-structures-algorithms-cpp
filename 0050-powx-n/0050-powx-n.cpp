class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1.0;

        long long N = n;
        long double base = x;

        if(N<0){
            N = -N;
            base = 1.0L/base;
        }
        long double res = 1.0;

        while(N){
            if(N&1){ //odd
                res *= base;
            }
            base *= base;
            N = N/2;
        }

        return (double)res;
    }
};