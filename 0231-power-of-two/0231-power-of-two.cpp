class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0) return false;
        long long N = n;
        return !(N & N-1);
    }
};