class Solution {
public:
    bool search(vector<int>& a, int t) {
        int l = 0 , r = a.size()-1;

        while(l<=r){
            int m = l + (r-l)/2;
            if(a[m]==t) return true;
            if(a[l]==a[m] && a[m]==a[r]){
                l++; r--; continue;
            }
            if(a[l]<=a[m]){ //left is sorted
                if(t>=a[l] && t<=a[m]){ //left side
                    r = m;
                }else{
                    l =m+1;
                }
            }else if(a[m]<=a[r]){//right side is sorted
                if(t>=a[m] && t<=a[r]){ //contains 
                    l = m+1;
                }else{
                    r = m;
                }
            }
        }
        return false;
    }
};