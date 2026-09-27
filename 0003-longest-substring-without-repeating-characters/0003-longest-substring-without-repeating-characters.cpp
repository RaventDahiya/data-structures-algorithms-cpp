class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int n = s.size();
        if(n==1) return 1;
        unordered_map<char,int>mp;
        int maxLen = INT_MIN;
        for(int j=0;j<n;j++){
            mp[s[j]]++;
            while(mp[s[j]]>1){
                mp[s[i]]--;
                i++;
            }
            maxLen = max(maxLen,j-i+1);
        }
        return maxLen==INT_MIN ? 0 : maxLen;
    }
};