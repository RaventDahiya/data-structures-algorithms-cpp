class Solution {
public:
    int minChanges(string s) {
        int ans = 0;
        int i = 1;
        int n = s.length();
        while(i<n){
            if(s[i]!=s[i-1]) ans++;
            i += 2;
        }
        return ans;
    }
};