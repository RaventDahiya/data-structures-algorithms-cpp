class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int n = mat.size();
        int m = mat[0].size();

        int l = 0;
        int r = (n * m) - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int i = mid / m;
            int j = mid % m;

            if (mat[i][j] == t) return true;

            if (mat[i][j] > t)
                r = mid - 1;
            else
                l = mid + 1;
        }

        return false;
    }
};