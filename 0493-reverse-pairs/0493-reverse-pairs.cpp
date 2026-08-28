class Solution {
public:
    void merge(vector<int>& arr, int left, int mid, int right) {
		vector<int> temp;
		
		int leftIndex = left;
		int rightIndex = mid + 1;
		
		while (leftIndex <= mid && rightIndex <= right) {
			if (arr[leftIndex] <= arr[rightIndex]) {
				temp.push_back(arr[leftIndex++]);
			} else {
				temp.push_back(arr[rightIndex++]);
			}
		}
		
		while (leftIndex <= mid) {
			temp.push_back(arr[leftIndex++]);
		}
		
		while (rightIndex <= right) {
			temp.push_back(arr[rightIndex++]);
		}
		
		for (int index = left; index <= right; index++) {
			arr[index] = temp[index - left];
		}
	}
	
	int mergeSort(vector<int>& arr, int left, int right) {
        int pairs = 0;
		if (left >= right)
			return pairs;
		
		int mid = left + (right - left) / 2;
		
		pairs += mergeSort(arr, left, mid);
		pairs += mergeSort(arr, mid + 1, right);
		pairs +=  countPairs(arr,left,mid,right);
		merge(arr, left, mid, right);
        return pairs;
	}
    int  countPairs(vector<int>& arr, int left, int mid, int right){
        int pairs = 0;
        int rightIndex = mid+1;
        for(int leftIndex=left;leftIndex<=mid;leftIndex++){
            while(rightIndex<=right && arr[leftIndex] > (long long)2 * arr[rightIndex]) rightIndex++;
            pairs += rightIndex - (mid + 1);
        }
        return pairs;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums,0,n-1);
    }
};