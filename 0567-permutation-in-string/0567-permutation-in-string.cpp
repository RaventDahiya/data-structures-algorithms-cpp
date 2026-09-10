class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        if(m < n) return false;

        vector<int>v1(26,0);
        for(auto ch : s1){
            v1[ch-'a']++;
        }
        vector<int>v2(26,0);
        for(int i=0;i<n;i++){
            char ch = s2[i];
            v2[ch-'a']++;
        }

        if(v1==v2) return true;

        for(int i=n;i<m;i++){
            int ch = s2[i];
            char prev = s2[i-n];
            v2[ch-'a']++;
            v2[prev-'a']--;
            if(v1==v2) return true;
        }
        return false;
    }
};