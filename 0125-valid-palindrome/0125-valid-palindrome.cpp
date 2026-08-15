class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length() - 1;

        while(l<r){
            if(!isalnum(s[l])){
                l++;
                continue;
            }
            if(!isalnum(s[r])){
                r--;
                continue;
            }
            char ch1 = tolower(s[l++]);
            char ch2 = tolower(s[r--]);
            if(ch1!=ch2) return false;
        }
        return true;
    }
};