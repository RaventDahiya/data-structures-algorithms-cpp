class Solution {
public:
    int mod = 1e9 + 7;
    long long power(long long x, long long n) {
        if (n == 0)
            return 1LL;

        long long half = power(x, n / 2);

        if (n % 2 == 0)
            return (half * half)%mod;

        return ((x * half)%mod * half)%mod;
    }

    int countGoodNumbers(long long n) {
        long long total = 1;
        long long evenIndex = (n+1)/2;
        long long oddIndex = n/2;
        total = power(5,evenIndex);
        total = (total * power(4,oddIndex))%mod;

        return (int)total;
    }
};