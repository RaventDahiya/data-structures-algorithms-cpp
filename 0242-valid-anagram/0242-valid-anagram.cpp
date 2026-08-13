class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n!=m) return false;
        vector<int>vs(26,0);
        vector<int>vt(26,0);
        for(int i=0;i<n;i++){
            vs[s[i]-'a']++;
            vt[t[i]-'a']++;
        }
        if(vs==vt) return true;
        return false;
    }
};