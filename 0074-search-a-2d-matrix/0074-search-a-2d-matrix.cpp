class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();

        int left = 0;
        int right = (n * m) - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int i = mid / m;
            int j = mid % m;
            if(mat[i][j]==target){
                return true;
            }else if(mat[i][j]>target){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }

        return false;
    }
};