class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int n = mat.size();
        int m = mat[0].size();

        int i = 0;
        int j = m-1;

        while(i<n && j>=0){
            if(mat[i][j]==t) return true;

            if(mat[i][j] > t){
                j--;
            }else{
                i++;
            }
        }

        return false;
    }
};