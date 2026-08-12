class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int n = s.length();
        int l = 0;
        int maxLen = 0;
        for(int r=0;r<n;r++){
            char ch = s[r];
            if(mp.count(ch)){
                l = max(l,mp[ch]+1);
            }
            mp[ch] = r;
            maxLen = max(maxLen,r-l+1);
        }
        return maxLen;
    }
};