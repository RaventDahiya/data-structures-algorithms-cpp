class Solution {
private:
    int x[4] = {1,-1,0,0};
    int y[4] = {0,0,1,-1};
public:
    void dfs(vector<vector<char>>& grid,int i,int j,vector<vector<bool>>&vis){
        int m = grid.size();
        int n = grid[0].size();

        vis[i][j] = true;

        for(int dir=0;dir<4;dir++){
            int newX = i + x[dir];
            int newY = j + y[dir];
            if(newX>=0 && newX<m && newY>=0 && newY<n && !vis[newX][newY] && grid[newX][newY]=='1'){
                dfs(grid,newX,newY,vis);
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        int islandCount = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    islandCount++;
                    dfs(grid,i,j,vis);
                }
            }
        }
        return islandCount;
    }
};