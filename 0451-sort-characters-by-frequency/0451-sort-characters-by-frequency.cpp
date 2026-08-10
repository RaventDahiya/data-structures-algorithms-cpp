class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(auto& ch : s){
            mp[ch]++;
        }
        map<int,vector<char>>freq;
        
        for(auto& [ch,f] : mp){
           freq[f].push_back(ch);
        }
        string ans = "";
        for(auto& [f,arr] : freq){
            //sort(arr.begin(),arr.end());
            for(auto& ch : arr){
                for(int i=0;i<f;i++){
                    ans += ch;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};