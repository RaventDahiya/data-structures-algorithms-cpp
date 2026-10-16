class Solution {
public:
    unordered_map<char, vector<char>> mp;

    vector<string> ans;

    void bt(int i, string& curr, string& d) {
        if (i == d.length()) {
            ans.push_back(curr);
            return;
        }
        for (char ch : mp[d[i]]) {
            curr.push_back(ch);
            bt(i + 1, curr, d);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        mp['2'] = {'a', 'b', 'c'};
        mp['3'] = {'d', 'e', 'f'};
        mp['4'] = {'g', 'h', 'i'};
        mp['5'] = {'j', 'k', 'l'};
        mp['6'] = {'m', 'n', 'o'};
        mp['7'] = {'p', 'q', 'r', 's'};
        mp['8'] = {'t', 'u', 'v'};
        mp['9'] = {'w', 'x', 'y', 'z'};
        string curr = "";
        bt(0, curr, digits);
        return ans;
    }
};