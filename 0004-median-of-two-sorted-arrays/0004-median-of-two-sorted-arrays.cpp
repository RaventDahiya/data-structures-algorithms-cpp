class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {

        // Binary search on smaller array
        if (a.size() > b.size())
            return findMedianSortedArrays(b, a);

        int n = a.size();
        int m = b.size();

        int low = 0;
        int high = n;

        while (low <= high) {

            int mid1 = low + (high - low) / 2;
            int mid2 = (n + m + 1) / 2 - mid1;

            int l1 = (mid1 == 0) ? INT_MIN : a[mid1 - 1];
            int r1 = (mid1 == n) ? INT_MAX : a[mid1];

            int l2 = (mid2 == 0) ? INT_MIN : b[mid2 - 1];
            int r2 = (mid2 == m) ? INT_MAX : b[mid2];

            // Correct partition
            if (l1 <= r2 && l2 <= r1) {

                if ((n + m) % 2 == 1) {
                    return max(l1, l2);
                }

                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }

            // Too many elements taken from a
            else if (l1 > r2) {
                high = mid1 - 1;
            }

            // Too few elements taken from a
            else {
                low = mid1 + 1;
            }
        }

        return 0;
    }
};