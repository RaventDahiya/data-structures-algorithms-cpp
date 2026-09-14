class Solution {
public:
    int findMaxEleIndex(vector<int>&arr){
        int maxEle = INT_MIN;
        int maxIndex = -1;

        for(int i=0;i<arr.size();i++){
            if(arr[i]>maxEle){
                maxEle = arr[i];
                maxIndex = i;
            }
        }
        return maxIndex;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int top = 0;
        int bottom = n-1;

        while(top<=bottom){
            int mid = top + (bottom-top)/2;
            int maxEleIndex = findMaxEleIndex(mat[mid]);
            int maxEle = mat[mid][maxEleIndex];
            int topEle = mid-1>=0 ? mat[mid-1][maxEleIndex] : INT_MIN;
            int bottomEle = mid+1<n ? mat[mid+1][maxEleIndex] : INT_MIN;
            if(maxEle > topEle && maxEle > bottomEle) return {mid,maxEleIndex};
            else if(topEle > maxEle){
                bottom = mid -1;
            }else{
                top = mid + 1;
            }
        }

        return {-1,-1};
    }
};