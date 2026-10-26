class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](auto &a,auto &b){
            return a[1]<b[1];
        });
        int lastEnd = INT_MIN;
        int n = intervals.size();
        for(auto &interval : intervals){
            if(interval[0]>=lastEnd){
                n--;
                lastEnd = interval[1];
            }
        }
        return n;
    }
};