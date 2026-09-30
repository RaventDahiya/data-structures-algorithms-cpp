class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int>ans(n,0);
        int depth = 0;

        for(int i=0;i<n;i++){
            char ch = seq[i];
            if(ch=='('){
                depth++;
                if(depth%2==0){ //even
                    ans[i] = 1;
                }else{
                    ans[i] = 0;
                }
            }else{
                if(depth%2==0){ //even
                    ans[i] = 1;
                }else{
                    ans[i] = 0;
                }
                depth--;
            }
        }

        return ans;
    }
};