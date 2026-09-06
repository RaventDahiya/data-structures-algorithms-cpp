class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int l = 0, r = a.size() - 1;
        if(a.size()==1) return a[0];
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (m == 0) {
                if (a[m] != a[m + 1])
                    return a[m];
            } else if (m == a.size() - 1) {
                if (a[m] != a[m - 1])
                    return a[m];
            } else {
                if (a[m] != a[m + 1] && a[m] != a[m - 1])
                    return a[m];
            }

            if (a[m] == a[m - 1]) { // left match
                int len = m + 1;
                if (len % 2 == 0) { // even len single ele can not be here
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            } else { // right match
                int len = a.size() - m;
                if (len % 2 == 0) { // even len single ele can not be here
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
        }
        return a[r];
    }
};