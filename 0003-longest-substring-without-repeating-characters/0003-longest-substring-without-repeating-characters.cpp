class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;

        int i=0;
        int maxLen = 0;
        for(int j=0;j<s.length();j++){
            char ch = s[j];
            while(st.count(ch)){
                st.erase(s[i]);
                i++;
            }
            st.insert(ch);
            maxLen = max(maxLen,j-i+1);
        }
        return maxLen;
    }
};