class Solution {
public:
    bool KMP(vector<int>& str, vector<int>& pattern) {
        int n = str.size(), m = pattern.size();

        if (m == 0)
            return true;
        if (m > n)
            return false;

        vector<int> lps(m, 0);

        // Build LPS array
        int len = 0;
        for (int i = 1; i < m;) {
            if (pattern[i] == pattern[len]) {
                lps[i++] = ++len;
            } else if (len > 0) {
                len = lps[len - 1];
            } else {
                i++;
            }
        }

        // KMP search
        int i = 0, j = 0;

        while (i < n) {
            if (str[i] == pattern[j]) {
                i++;
                j++;

                if (j == m)
                    return true;
            } else if (j > 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }

        return false;
    }

    bool rorationPossible(vector<int>& v1, vector<int>& v2) {
        vector<int>str = v2;
        str.insert(str.end(),v2.begin(),v2.end());
        vector<int>pattern = v1;
        return KMP(str,pattern);
    }

    bool isValid(vector<int>& nums, vector<int>& sortedArray, int k) {
        bool valid = true;
        int n = nums.size();
        for (int src = 0; src < n; src += k) {
            vector<int> v1(nums.begin()+src,nums.begin()+src+k);
            vector<int> v2(sortedArray.begin()+src,sortedArray.begin()+src+k);
            if (!rorationPossible(v1, v2)) {
                valid = false;
                break;
            }
        }
        return valid;
    }
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> sortedArray(nums.begin(), nums.end());
        sort(sortedArray.begin(), sortedArray.end());
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                if (isValid(nums, sortedArray, i)) {
                    ans += i;
                }
            }
        }

        return ans;
    }
};