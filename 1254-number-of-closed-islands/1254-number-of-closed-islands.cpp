class Solution {
public:
    int n;
    int m;
    int x[4] = {-1,1,0,0};
    int y[4] = {0,0,-1,1};
    void dfs(vector<vector<int>>& grid,vector<vector<bool>>& vis,int i,int j,bool &closedIslands){
        vis[i][j] = true;

        for(int dir=0;dir<4;dir++){
            int I = i + x[dir];
            int J = j + y[dir];
            if(I>=0 && I<n && J>=0 && J<m && grid[I][J]==0 && !vis[I][J]){
                if(I==0 || I==n-1 || J==0 || J==m-1) closedIslands = false;
                dfs(grid,vis,I,J,closedIslands);
            }
        }

    }
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int closedIslandsCount = 0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(grid[i][j]==0 && !vis[i][j]){
                    bool closedIslands = true;
                    dfs(grid,vis,i,j,closedIslands);
                    if(closedIslands) closedIslandsCount++;
                }
            }
        }
        return closedIslandsCount;
    }
};