class Solution {
public:
    void mergeSort(vector<int>& arr, int s, int e, int& count) {
        if (s >= e)
            return;
        int mid = s + (e - s) / 2;
        mergeSort(arr, s, mid, count);
        mergeSort(arr, mid + 1, e, count);
        merge(arr, s, mid, e, count);
    }

    void merge(vector<int>& arr, int s, int mid, int e, int& count) {
        int l1 = mid - s + 1;
        int l2 = e - mid;

        vector<int> arr1(l1);
        vector<int> arr2(l2);

        for (int i = 0; i < l1; i++) {
            arr1[i] = arr[s + i];
        }

        for (int i = 0; i < l2; i++) {
            arr2[i] = arr[mid + 1 + i];
        }

        int j = 0;
        for (int i = 0; i < l1; i++) {
            while (j < l2 && arr1[i] > (long long)2 * arr2[j])
                j++;
            count += j;
        }

        int i = 0, k = s;
        j = 0;
        while (i < l1 && j < l2) {
            if (arr1[i] < arr2[j]) {
                arr[k++] = arr1[i++];

            } else {
                arr[k++] = arr2[j++];
            }
        }

        while (i < l1) {
            arr[k++] = arr1[i++];
        }

        while (j < l2) {
            arr[k++] = arr2[j++];
        }
    }
    int reversePairs(vector<int>& nums) {
        int count = 0;
        mergeSort(nums, 0, nums.size() - 1, count);
        return count;
    }
};