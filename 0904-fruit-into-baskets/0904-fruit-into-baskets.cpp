class Solution {
public:
    int totalFruit(vector<int>& f) {
        int maxLen = 0;
        int left = 0;
        unordered_map<int,int>mp;
        for(int right=0;right<f.size();right++){
            mp[f[right]]++;
            while(mp.size()>2){
                mp[f[left]]--;
                if(mp[f[left]] == 0) mp.erase(f[left]);
                left++;
            }
            maxLen = max(maxLen,right-left+1);
        }
        return maxLen;
    }
};