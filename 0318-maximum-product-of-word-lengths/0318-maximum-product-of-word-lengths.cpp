class Solution {
public:
    int maxProduct(vector<string>& words) {
        int maxi = 0;
        int n = words.size();
        vector<int> mask(n, 0);

        for (int i = 0; i < n ; i++) {
            string str = words[i];
            for (auto ch : str) {
                int pos = ch - 'a';      // char index/pos
                int bit = 1 << pos;      // shift the pos
                mask[i] = mask[i] | bit; // or is used to add
            }
        }

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((mask[i] & mask[j]) == 0) {
                    int product = words[i].length() * words[j].length();
                    maxi = max(maxi, product);
                }
            }
        }
        return maxi;
    }
};