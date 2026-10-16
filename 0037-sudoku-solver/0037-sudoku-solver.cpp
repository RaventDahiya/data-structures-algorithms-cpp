class Solution {
public:
    unordered_map<int,unordered_set<char>>rows;
    unordered_map<int,unordered_set<char>>cols;
    unordered_map<int,unordered_set<char>>boxs;

    int getBoxIdx(int r, int c) { return (r / 3) * 3 + c / 3; }

    bool bt(vector<vector<char>>& board){
        for(int row=0;row<9;row++){
            for(int col=0;col<9;col++){
                int box = getBoxIdx(row,col);
                if(board[row][col]=='.'){
                    for(char num='1';num<='9';num++){
                        if(rows[row].count(num) || cols[col].count(num) || boxs[box].count(num)) continue;

                        board[row][col] = num;
                        rows[row].insert(num);
                        cols[col].insert(num);
                        boxs[box].insert(num);
                        if(bt(board)) return true;
                        board[row][col] = '.';
                        rows[row].erase(num);
                        cols[col].erase(num);
                        boxs[box].erase(num);
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        //insert initial numbers in map
        for(int row=0;row<9;row++){
            for(int col=0;col<9;col++){
                int box = getBoxIdx(row,col);
                if(board[row][col] !='.'){
                    char ch = board[row][col];
                    rows[row].insert(ch);
                    cols[col].insert(ch);
                    boxs[box].insert(ch);
                }
            }
        }
        bt(board);
    }
};