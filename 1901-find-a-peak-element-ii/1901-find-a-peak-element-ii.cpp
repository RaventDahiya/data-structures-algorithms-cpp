class Solution {
public:
    int findMaxEleInColMidIndx(vector<vector<int>>& mat,int m){
        int n = mat.size();
        int maxi = INT_MIN;
        int idx = -1;
        for(int i=0;i<n;i++){
           if(mat[i][m]>maxi){
            maxi = mat[i][m];
            idx = i;
           }
        }
        return idx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int i = 0;
        int j = m-1;

        while(i<=j){
            int mid = i + (j-i)/2;
            int rowIdx = findMaxEleInColMidIndx(mat,mid);
            int maxEleInColMid = mat[rowIdx][mid];
            int l = mid-1>=0 ? mat[rowIdx][mid-1] : INT_MIN;
            int r = mid+1<m ? mat[rowIdx][mid+1] : INT_MIN;

            if(maxEleInColMid > l && maxEleInColMid > r){
                return {rowIdx,mid};
            }

            if(l > maxEleInColMid){
                j = mid - 1;
            }else{
                i = mid + 1;
            }
            
        }

        return {-1,-1};
    }
};