class Solution {
public:
    bool ans = false;
    int m;
    int n;
    int x[4] = {-1,1,0,0};
    int y[4] = {0,0,1,-1};

    void bt(vector<vector<char>>& board, string word,vector<vector<bool>>&vis,int i,int j,int idx){
        //base case
        if(idx==word.size()-1){
            ans = true;
            return;
        }

        vis[i][j] = true;

        for(int dir=0;dir<4;dir++){
            int row = i + x[dir];
            int col = j + y[dir];
            if(row>=0 && row<m && col>=0 && col<n && !vis[row][col] && board[row][col]==word[idx+1]){
                bt(board,word,vis,row,col,idx+1);
            }
        }

        vis[i][j] = false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    bt(board,word,vis,i,j,0);
                    if(ans) return true;
                }
            }
        }
        return false;
    }
};