class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        for(int i=0;i<s.length();i++){
            char ch = s[i];
            int Index_in_Reversed_Alphabet = 26 - (ch - 'a');
            ans += Index_in_Reversed_Alphabet * (i+1);
        }
        return ans;
    }
};