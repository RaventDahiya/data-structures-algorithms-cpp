class Solution {
public:
    vector<vector<string>>res;
    unordered_set<int>cols;
    unordered_set<int>diag1;
    unordered_set<int>diag2; 

    void bt(int row,int n,vector<string>&board){
        if(row==n){
            res.push_back(board);
            return;
        }

        for(int col=0;col<n;col++){
            //check col and digonals
            if (cols.count(col) || diag1.count(row - col) || diag2.count(row + col)) {
                continue;
            }
            board[row][col] = 'Q';
            cols.insert(col);
            diag1.insert(row-col);
            diag2.insert(row+col);
            bt(row+1,n,board);
            board[row][col] = '.';
            cols.erase(col);
            diag1.erase(row-col);
            diag2.erase(row+col);

        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        bt(0,n,board);
        return res;
    }
};