class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>>mp;

        for(auto& str : strs){
            vector<int>dic(26,0);
            for(auto& ch : str){
                dic[ch-'a']++;
            }
            mp[dic].push_back(str);
        }
        vector<vector<string>>ans;
        for(auto& [key,list] : mp){
            ans.push_back(list);
        }
        return ans;
    }
};