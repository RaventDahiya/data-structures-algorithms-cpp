class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxs(9);

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') continue;
                char digit = board[r][c];
                int boxNum = (((r / 3) * 3) + (c / 3));

                if(rows[r].count(digit) || cols[c].count(digit) || boxs[boxNum].count(digit)) return false;

                rows[r].insert(digit);
                cols[c].insert(digit);
                boxs[boxNum].insert(digit);
            }
        }
        return true;
    }
};