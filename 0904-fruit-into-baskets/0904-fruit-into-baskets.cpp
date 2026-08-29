class Solution {
public:
    int totalFruit(vector<int>& f) {
        int left = 0;
        int maxLen = 0;
        unordered_map<int,int>mp;
        int n = f.size();
        for(int right=0;right<n;right++){
            mp[f[right]]++;

            while(mp.size()>2){
                mp[f[left]]--;
                if(mp[f[left]]==0) mp.erase(f[left]);
                left++;
            }

            maxLen = max(maxLen,right-left+1);
        }
        return maxLen;
    }
};