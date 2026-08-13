class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int>tempS;
        vector<int>tempT;
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++){
            char ch = s[i];
            if(mp.count(ch)){
                tempS.push_back(mp[ch]);
            }else{
                mp[ch] = i;
                tempS.push_back(mp[ch]);
            }
        }
        mp.clear();
        for(int i=0;i<t.length();i++){
            char ch = t[i];
            if(mp.count(ch)){
                tempT.push_back(mp[ch]);
            }else{
                mp[ch] = i;
                tempT.push_back(mp[ch]);
            }
        }
        if(tempS==tempT) return true;
        return false;
    }
};