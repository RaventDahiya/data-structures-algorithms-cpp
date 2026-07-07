class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>ans(n,vector<int>(m));

        queue<tuple<int,int,int>>q;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int minDis = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j,0});
                    vis[i][j] = true;
                }
            }
        }
        int x[4] = {0,-1,0,1};
        int y[4] = {-1,0,1,0};

        while(!q.empty()){
            int size = q.size();
            minDis++;
            while(size--){
                auto [row,col,dis] = q.front(); q.pop();
                ans[row][col] = dis;
                for(int dir=0;dir<4;dir++){
                    int ni = row + x[dir];
                    int nj = col + y[dir];
                    if(ni>=0 && nj>=0 && ni<n && nj<m && !vis[ni][nj]){
                        q.push({ni,nj,dis+1});
                        vis[ni][nj] = true;
                    }
                }
            }
        }

        return ans;
        
    }
};