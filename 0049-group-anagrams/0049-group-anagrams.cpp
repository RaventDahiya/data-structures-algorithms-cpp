class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<array<int,26>, vector<string>> mp;

        for (string s : strs) {
            array<int,26> freq{};

            for (char ch : s) {
                freq[ch - 'a']++;
            }

            mp[freq].push_back(s);
        }

        vector<vector<string>> ans;

        for (auto& [key, group] : mp) {
            ans.push_back(group);
        }

        return ans;
    }
};