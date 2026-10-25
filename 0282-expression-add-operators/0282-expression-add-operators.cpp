class Solution {
public:
    void solve(string& num, int& target, vector<string>& ans,
               string& path, int i, long sum, long prev) {
        if (i == num.length()) {
            if (sum == target)                    // FIX 1
                ans.push_back(path);
            return;
        }

        for (int j = i; j < num.length(); j++) {
            if (j > i && num[i] == '0') break;   // FIX 2
            
            string sub = num.substr(i, j - i + 1);
            long curr = stol(sub);
            int len = path.size();                // FIX 3

            if (i == 0) {
                path += sub;
                solve(num, target, ans, path, j + 1, curr, curr);
                path.resize(len);
            } else {
                path += '+' + sub;
                solve(num, target, ans, path, j + 1, sum + curr, curr);
                path.resize(len);

                path += '-' + sub;
                solve(num, target, ans, path, j + 1, sum - curr, -curr);
                path.resize(len);

                path += '*' + sub;
                solve(num, target, ans, path, j + 1, sum - prev + prev * curr, prev * curr);
                path.resize(len);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string path = "";
        solve(num, target, ans, path, 0, 0, 0);
        return ans;
    }
};