class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>charCountP(26,0);
        vector<int>charCountS(26,0);
        vector<int>ans;
        if(p.length()>s.length()) return {};
        for(auto& ch : p){
            charCountP[ch-'a']++;
        }
        int k = p.length();
        for(int i=0;i<k;i++){
            char ch = s[i];
            charCountS[ch-'a']++;
        }
        if(charCountP == charCountS) ans.push_back(0);

        for(int i=k;i<s.length();i++){
            char ch = s[i];
            char remove = s[i-k];
            charCountS[ch-'a']++;
            charCountS[remove-'a']--;
            if(charCountP == charCountS) ans.push_back(i-k+1);
        }
        return ans;
    }
};