class Solution {
public:
    int findMin(vector<int>& a) {
        int l = 0, r = a.size() - 1;
        int mini = INT_MAX;
        while (l <= r) {
            int m = l + (r - l) / 2;
            
            if (a[l] <= a[m]) {          // left is sorted
                mini = min(mini,a[l]);
                l = m + 1;
            } else {                          // right side is sorted
                mini = min(mini,a[m]);
                r = m - 1;
            }
        }
        return mini;
    }
};