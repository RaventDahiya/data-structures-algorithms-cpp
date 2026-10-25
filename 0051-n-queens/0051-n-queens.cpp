class Solution {
public:
    vector<vector<string>>res;
    unordered_map<int,bool>digonal2;
    unordered_map<int,bool>col;
    unordered_map<int,bool>digonal1;

    void solve(int n,vector<string>grid,int i){
        if(i==n){
            res.push_back(grid);
        }

        for(int j=0;j<n;j++){
            if(!col[j] && !digonal1[i+j] && !digonal2[i-j]){
                grid[i][j] = 'Q';
                col[j] = true;
                digonal1[i+j] = true;
                digonal2[i-j] = true;

                solve(n,grid,i+1);

                grid[i][j] = '.';
                col[j] = false;
                digonal1[i+j] = false;
                digonal2[i-j] = false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string str = "";
        for(int i=0;i<n;i++) str += '.';

        vector<string>grid(n,str);

        solve(n,grid,0);

        return res;
    }
};