class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int>mp;
        int left = 0;
        int count = 0;
        int n = s.length();
        for(int right=0;right<n;right++){
            mp[s[right]]++;
            while(mp.size() == 3){
                count += n-right;
                mp[s[left]]--;
                if(mp[s[left]] == 0) mp.erase(s[left]);
                left++;
            }
        }
        return count;
    }
};