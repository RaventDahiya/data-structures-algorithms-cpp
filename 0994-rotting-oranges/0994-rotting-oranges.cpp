class Solution {
public:
    bool isValid(int i,int j,int n,int m){
        if(i<0 || i>=n || j<0 || j>=m) return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1) fresh++;
            }
        }
        int x[4] = {0,-1,0,1};
        int y[4] = {-1,0,1,0};
        if(fresh==0) return 0;
        if(q.empty()) return -1;
        int time = -1;
        while(!q.empty()){
            int size = q.size();
            
            while(size--){
                auto [i,j] = q.front(); q.pop();
                for(int k=0;k<4;k++){
                    int new_i = i + x[k];
                    int new_j = j + y[k];
                    if(isValid(new_i,new_j,n,m) && grid[new_i][new_j]==1){
                        fresh--;
                        grid[new_i][new_j]=2;
                        q.push({new_i,new_j});
                    }
                }
            }
            time++;
        }

        if(fresh) return -1;
        return time;
    }
};