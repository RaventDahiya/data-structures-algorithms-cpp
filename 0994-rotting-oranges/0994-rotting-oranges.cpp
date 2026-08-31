class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int freshCount = 0;
        queue<pair<int,int>>q;
        int m = grid.size();
        int n = grid[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2) q.push({i,j});
                else if(grid[i][j]==1) freshCount++;
            }
        }
        int time = 0;
        int rottenedCount = 0;
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        while(!q.empty() && freshCount>0){
            int size = q.size();
            for(int i=0;i<size;i++){
                auto [row,col] = q.front(); q.pop();
                for(int dir=0;dir<4;dir++){
                    int newRow = row + dx[dir];
                    int newCol = col + dy[dir];
                    if(newRow>=0 && newRow<m && newCol>=0 && newCol<n && grid[newRow][newCol]==1){
                        grid[newRow][newCol]=2;
                        freshCount--;
                        q.push({newRow,newCol});
                    }

                }
            }
            time++;
        }
        if(freshCount<=0) return time;
        return -1;
    }
};