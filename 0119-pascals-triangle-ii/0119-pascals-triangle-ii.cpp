class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans;
        int numRows = rowIndex+1;
        if (numRows >= 1)
            ans.push_back({1});
        if (numRows >= 2)
            ans.push_back({1, 1});
        int n = 3;
        while (n <= numRows) {
            vector<int> temp(n, 1);
            vector<int> back = ans.back();
            for (int i = 0; i < n; i++) {
                if (i == 0 || i == n - 1)
                    continue;
                temp[i] = back[i] + back[i - 1];
            }
            ans.push_back(temp);
            n++;
        }
        return ans[rowIndex];
    }
};