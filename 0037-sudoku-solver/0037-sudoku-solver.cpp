class Solution {
public:
    bool rows[9][10] = {};
    bool cols[9][10] = {};
    bool boxs[9][10] = {};

    vector<pair<int, int>> emptyCells;

    int getBoxIdx(int r, int c) {
        return (r / 3) * 3 + c / 3;
    }

    bool solve(vector<vector<char>>& board, int idx) {

        if (idx == emptyCells.size())
            return true;

        int row = emptyCells[idx].first;
        int col = emptyCells[idx].second;
        int box = getBoxIdx(row, col);

        for (int num = 1; num <= 9; num++) {

            if (rows[row][num] ||
                cols[col][num] ||
                boxs[box][num])
                continue;

            board[row][col] = num + '0';

            rows[row][num] = true;
            cols[col][num] = true;
            boxs[box][num] = true;

            if (solve(board, idx + 1))
                return true;

            // Backtrack
            board[row][col] = '.';

            rows[row][num] = false;
            cols[col][num] = false;
            boxs[box][num] = false;
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {

        memset(rows, 0, sizeof(rows));
        memset(cols, 0, sizeof(cols));
        memset(boxs, 0, sizeof(boxs));
        emptyCells.clear();

        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {

                if (board[row][col] == '.') {
                    emptyCells.push_back({row, col});
                }
                else {
                    int num = board[row][col] - '0';
                    int box = getBoxIdx(row, col);

                    rows[row][num] = true;
                    cols[col][num] = true;
                    boxs[box][num] = true;
                }
            }
        }

        solve(board, 0);
    }
};