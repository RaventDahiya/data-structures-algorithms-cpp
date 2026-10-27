class Solution {
public:
    int m;
    int n;
    int x[4] = {-1,1,0,0};
    int y[4] = {0,0,-1,1};

    void dfs(vector<vector<int>>& grid,vector<vector<bool>>& vis,int i,int j,long long &val){
        vis[i][j] = true;
        val += grid[i][j];

        for(int dir=0;dir<4;dir++){
            int I = i + x[dir];
            int J = j + y[dir];
            if(I>=0 && I<m && J>=0 && J<n && grid[I][J]>0 && !vis[I][J]){
                dfs(grid,vis,I,J,val);
            }
        }
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
            if(grid[i][j]>0 && !vis[i][j]){
                long long val = 0;
                dfs(grid,vis,i,j,val);
                if(val%k==0) ans++;
            }}
        }
        return ans;
    }
};